#include "myFunctions.hpp"

// Dessine un rectangle plein
void FillMyRectangle(HDC hdc, RECT& rectangle, COLORREF Couleur)
{
	HBRUSH hBrush = CreateSolidBrush(Couleur);
	FillRect(hdc, &rectangle, hBrush);
	DeleteObject(hBrush);
}

namespace app 
{
	// Affiche du texte sur un HDC avec une police spécifique:
	int TextToHDC(HDC hdc, int x, int y, const myFont& font, COLORREF color, LPCWSTR format, ...)
	{
		if (!hdc || !font.getHandle()) return 0;

		TCHAR str[256];
		va_list args;
		va_start(args, format);
			HRESULT hr = StringCchVPrintf(str, ARRAYSIZE(str), format, args);
		va_end(args);

		if (SUCCEEDED(hr)) 
		{
			size_t len;
			StringCchLength(str, ARRAYSIZE(str), &len);

			SetTextColor(hdc, color);
			SetBkMode(hdc, TRANSPARENT);

			HFONT hOldFont = (HFONT)SelectObject(hdc, font.getHandle());
			TextOut(hdc, x, y, str, (int)len);
			SelectObject(hdc, hOldFont); 
			
			return 1;
		}
		return 0;
	}
		
	// Dessine un rectangle plein
	void rectang(HDC hdc, RECT* rectangle, COLORREF Couleur)
	{
		HBRUSH hBrush = CreateSolidBrush(Couleur);
		FillRect(hdc, rectangle, hBrush);
		DeleteObject(hBrush);
	}

	void myGetLastErrorFromWindow(void)
	{
		DWORD err = GetLastError();
		
		if (err == 0) 
		{
			LogErrorOut(L"[WARNNING] No Error detected by myGetLastErrorFromWindow.");
			return;
		}

		LPWSTR msgBuf = nullptr;

		// FormatMessage:
		DWORD len = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr, 
			err, 
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)&msgBuf,
			0, 
			nullptr);

		std::wstring message;
		if (len && msgBuf) 
		{
			// Nettoyage des retours à la ligne souvent ajoutés par Windows (\r\n):
			// On retire les \r\n à la fin si ils existent
			while (len > 0 && (msgBuf[len - 1] == L'\n' || msgBuf[len - 1] == L'\r'))
			{
				len--;
			}
			message.assign(msgBuf, len);
			LocalFree(msgBuf);
		} 
		else 
		{
			TCHAR buf[64];
			// StringCchPrintf respecte le mode TCHAR du projet
			StringCchPrintf(buf, _countof(buf), L"Unknown error %lu", err);
			message = buf;
		}
		
		//OutPutError(_T("%s"), message.c_str());
		LogErrorOut(L"[Windows ERROR] %s", message.c_str());
		return;
	}
}

void WritePanicLog(const TCHAR* messageComplet)
{
    // Utilisation de std::wofstream pour supporter l'Unicode/TCHAR de ton projet
    // std::ios::app : ajoute le texte à la fin du fichier sans effacer l'ancien
    std::wofstream logFile(L"PanicLog.txt", std::ios::app);
    
    if (logFile.is_open()) 
	{
        logFile << messageComplet << std::endl;
		logFile.close();
    }
}