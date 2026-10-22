//														file: Move_player_inputs.cpp version: 00
#include "Teams.hpp"

void Move_player_inputs()
{
	if(initialized == FALSE) return;
    
	// --- 1 Retreiving Main (Control) Window Width & Height:
	RECT Rect;
	GetClientRect(hwnd_CONTROL, &Rect);
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left;
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;
	
	int L = 240;
	int startX = (int)((CLIENT_WIDTH_CONTROL - L)/2.0);
	
	//int startX = 500;
    int startY = 75; // On commence plus haut pour le nom de l'équipe
    int rowHeight = 30;

	SetWindowPos(g_hStaticTeamLabel, NULL, startX,		 startY, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
	SetWindowPos(g_hEditTeamName,	 NULL, startX + 120, startY, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
    // On décale le départ des joueurs vers le bas pour laisser de la place au bloc équipe:
    startY += 45;

    for (int i = 0; i < PLAYER_COUNT; ++i)
	{
		SetWindowPos(g_playersInputs[i].hStaticLabel, NULL, startX,		 startY + (i * rowHeight), 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
		SetWindowPos(g_playersInputs[i].hEditNum	, NULL, startX + 25, startY + (i * rowHeight), 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
		SetWindowPos(g_playersInputs[i].hEditName	, NULL, startX + 70, startY + (i * rowHeight), 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
    }
	
	BOUTTON[ID_BTN_SAVE_TEAM].Move(startX, startY + (PLAYER_COUNT * rowHeight));
	BOUTTON[ID_BTN_SAVE_TEAM].Show();
}