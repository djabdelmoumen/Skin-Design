//														file: save_team.cpp version: 00
#include "Teams.hpp"

void save_team(HWND hwnd)
{
    wchar_t teamNameBuffer[256] = { 0 };

    // 1. Récupérer le nom de l'équipe depuis le TextBox dédié (ID 999)
    if (g_hEditTeamName && IsWindow(g_hEditTeamName)) {
        GetWindowTextW(g_hEditTeamName, teamNameBuffer, 256);
    }

    // 2. Si le champ est vide, on attribue un nom par défaut
    std::wstring teamName = teamNameBuffer;
    if (teamName.empty()) {
        teamName = L"team_default";
    }

    // 3. Construire le nom dynamique du fichier
    std::wstring fileName = teamName + L".Team";

    // 4. Utilisation de .c_str() pour que le compilateur accepte le chemin en wchar_t*
    std::wofstream file(fileName.c_str(), std::ios::out | std::ios::trunc);
    
    if (!file.is_open()) {
        MessageBoxW(hwnd, L"Erreur : Impossible de créer ou d'ouvrir le fichier de l'équipe.", L"Erreur", MB_OK | MB_ICONERROR);
        return;
    }

    // Configurer le fichier pour supporter l'encodage UTF-8 (gère l'arabe)
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>()));

    int savedCount = 0;

    // 5. Enregistrer les joueurs sous le format NUMERO;NOM
    for (size_t i = 0; i < g_playersInputs.size(); ++i) {
        wchar_t numBuffer[16] = { 0 };
        wchar_t nameBuffer[256] = { 0 };

        GetWindowTextW(g_playersInputs[i].hEditNum, numBuffer, 16);
        GetWindowTextW(g_playersInputs[i].hEditName, nameBuffer, 256);

        // On n'enregistre que si le nom du joueur n'est pas vide
        if (wcslen(nameBuffer) > 0) {
            std::wstring numStr = (wcslen(numBuffer) > 0) ? numBuffer : L"0";
            file << numStr << L";" << nameBuffer << L"\n";
            savedCount++;
        }
    }

    file.close();

    // 6. Message de confirmation
    if (savedCount > 0) {
        std::wstring msg = L"Équipe sauvegardée avec succès dans le fichier : " + fileName + 
                           L" (" + std::to_wstring(savedCount) + L" joueurs).";
        MessageBoxW(hwnd, msg.c_str(), L"Succès", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBoxW(hwnd, L"Aucun joueur n'a été saisi. Le fichier est vide.", L"Attention", MB_OK | MB_ICONWARNING);
    }
}