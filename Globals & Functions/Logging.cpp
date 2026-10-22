//														File: Logging.cpp
//														version: 00
#include "Logging.hpp"

// Buffer final : 127 caracteres utiles + '\0'
static WCHAR ErrorBuffer[ERROR_TEXT_SIZE];

void Init_Logging()
{
	ErrorBuffer[ERROR_TEXT_SIZE-1] = L'\0';
	return;
}

// Ecriture complete dans le fichier:
static bool WriteAll(HANDLE hFile, const void* data, size_t bytes)
{
    const BYTE* p = static_cast<const BYTE*>(data);

    while (bytes > 0)
    {
        DWORD chunk = bytes > 1024 * 1024 ? 1024 * 1024 : static_cast<DWORD>(bytes);
        DWORD written = 0;

        if (!WriteFile(hFile, p, chunk, &written, nullptr)) return false;
        if (written == 0) return false;
        p += written;
        bytes -= written;
    }
    return true;
}

// Ajoute le message complet dans ErrorOutput.txt.
static bool WriteLogFile(LPCWSTR message)
{
    HANDLE hFile = CreateFile(L"ErrorOutput.txt",FILE_APPEND_DATA,FILE_SHARE_READ | FILE_SHARE_WRITE,nullptr,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);

    if (hFile == INVALID_HANDLE_VALUE) return false;

    bool ok = false;
    LARGE_INTEGER fileSize = {};

    if (!GetFileSizeEx(hFile, &fileSize)) goto cleanup;

    // Ajouter un BOM UTF-16 LE si le fichier Unicode est neuf.
#ifdef UNICODE
    if (fileSize.QuadPart == 0)
    {
        const WORD bom = 0xFEFF;

        if (!WriteAll(hFile, &bom, sizeof(bom)))
            goto cleanup;
    }
#endif

    // Ecrire le message complet.
    {
        size_t length = wcslen(message);

        if (!WriteAll(
                hFile,
                message,
                length * sizeof(TCHAR)))
            goto cleanup;

        static const TCHAR newline[] = L"\r\n";

        if (!WriteAll(
                hFile,
                newline,
                (_countof(newline) - 1) * sizeof(TCHAR)))
            goto cleanup;
    }

    ok = true;

cleanup:
    CloseHandle(hFile);
    return ok;
}

int LogErrorOut(LPCWSTR format, ...)
{
    // 1. Verification du parametre
    ErrorBuffer[0] = L'\0';

    if (format == nullptr) return INVALID_PARAMETER;

    va_list args;
    va_start(args, format);

    int result = UNKNOWN_ERROR;

    try
    {
        std::vector<TCHAR> buffer(128); // 2. Buffer temporaire initial de 128 caracteres

        while (true)
        {
            // Copier va_list pour chaque tentative
            va_list copy;
            va_copy(copy, args);

            HRESULT hr = StringCchVPrintf(
                buffer.data(),
                buffer.size(),
                format,
                copy
            );

            va_end(copy);

            // 3. Formatage reussi
            if (SUCCEEDED(hr))
            {
                size_t length = wcslen(buffer.data());

                // 4. Copier les 127 premiers caracteres maximum
                HRESULT copyHr = StringCchCopyN(
                    ErrorBuffer,
                    ARRAYSIZE(ErrorBuffer),
                    buffer.data(),
                    ERROR_TEXT_SIZE - 1
                );

                if (FAILED(copyHr))
                {
                    ErrorBuffer[0] = L'\0';
                    result = UNKNOWN_ERROR;
                    break;
                }

                // 5. Enregistrer le message COMPLET dans le fichier:
                if (!WriteLogFile(buffer.data()))
                {
                    result = UNKNOWN_ERROR;
                    break;
                }

                // 6. Determiner le code de retour
                if (length >= ERROR_TEXT_SIZE)
                    result = TRUNKED_BUFFER;
                else
                    result = SUCCESS;

                break;
            }

            // 7. Parametre invalide
            if (hr == STRSAFE_E_INVALID_PARAMETER)
            {
                result = INVALID_PARAMETER;
                break;
            }

            // 8. Autre erreur de formatage
            if (hr != STRSAFE_E_INSUFFICIENT_BUFFER)
            {
                result = UNKNOWN_ERROR;
                break;
            }

            // 9. Agrandir le buffer temporaire
            if (buffer.size() > buffer.max_size() / 2)
            {
                result = OVER_BUFFER;
                break;
            }

            buffer.resize(buffer.size() * 2);
        }
    }
    catch (...)
    {
        ErrorBuffer[0] = L'\0';
        result = UNKNOWN_ERROR;
    }

    va_end(args);

    return result;
}

// Fonction pour récupérer le contenu de ErrorBuffer sous forme de chaîne
std::wstring GetMyLastError()
{
    // Sécurité optionnelle : s'assurer que le buffer est bien terminé par un zéro
    ErrorBuffer[ERROR_TEXT_SIZE - 1] = L'\0';
    
    return std::wstring(ErrorBuffer);
}

// Retourne true s'il y a une erreur dans le buffer, false sinon false:
bool ErrorsExist()
{
    return ErrorBuffer[0] != L'\0';
}