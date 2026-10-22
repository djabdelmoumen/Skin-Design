//														file: create_player_inputs.cpp version: 00
#include "Teams.hpp"

// ==========================================
// 1. Fonction de création des 30 fenêtres
// ==========================================
void create_player_inputs(HWND hwnd)
{
	if(initialized == TRUE) return;
    initialized = TRUE;
	
	//const int PLAYER_COUNT = 15;
    g_playersInputs.resize(PLAYER_COUNT);
	
	// --- 1 Retreiving Main (Control) Window Width & Height:
	RECT Rect;
	GetClientRect(hwnd_CONTROL, &Rect);
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left;
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;
	
	int L = 240;
	int startX = (int)((CLIENT_WIDTH_CONTROL - L)/2.0);
	
	
	
    //int startX = 0;
    int startY = 75; // On commence plus haut pour le nom de l'équipe
    int rowHeight = 30;

    // ==========================================
    // 0. Ajout du champ pour le Nom de l'équipe
    // ==========================================
    g_hStaticTeamLabel = CreateWindowW
	(
        L"STATIC", L"Nom de l'équipe :", 
        WS_CHILD | WS_VISIBLE,
        startX, startY, 110, 22, 
        hwnd, NULL, NULL, NULL
    );

    // TextBox pour saisir le nom de l'équipe (ID unique par exemple : 999)
    g_hEditTeamName = CreateWindowExW(
        WS_EX_CLIENTEDGE, L"EDIT", L"",
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        startX + 120, startY, 200, 22,
        hwnd, (HMENU)999, NULL, NULL
    );

    // On décale le départ des joueurs vers le bas pour laisser de la place au bloc équipe:
    startY += 45;

    // ==========================================
    // 1. Création des 30 fenêtres de joueurs (15 numéros + 15 noms)
    // ==========================================
    for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		// Label indicatif pour le joueur (ex: "1.", "2."...)
		std::wstring indexLabel = std::to_wstring(i + 1) + L".";
		g_playersInputs[i].hStaticLabel = CreateWindowW(
			L"STATIC", indexLabel.c_str(), 
            WS_CHILD | WS_VISIBLE,
            startX, startY + (i * rowHeight), 22, 22, 
            hwnd, NULL, NULL, NULL
        );

        // Champ Numéro (IDs de 101 à 115)
        g_playersInputs[i].hEditNum = CreateWindowExW(
            WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_CENTER,
            startX + 25, startY + (i * rowHeight), 40, 22,
            hwnd, (HMENU)(INT_PTR)(101 + i), NULL, NULL
        );

        // Champ Nom (IDs de 201 à 215)
        g_playersInputs[i].hEditName = CreateWindowExW(
            WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            startX + 70, startY + (i * rowHeight), 180, 22,
            hwnd, (HMENU)(INT_PTR)(201 + i), NULL, NULL
        );
    }
	
	BOUTTON[ID_BTN_SAVE_TEAM].Move(startX, startY + (PLAYER_COUNT * rowHeight));
	BOUTTON[ID_BTN_SAVE_TEAM].Show();
}