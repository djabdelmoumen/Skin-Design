#include "Interfaces.hpp"
void Calculate_Teams_Interface()
{
	//RECT fullRect = {0, 0, HD1366, HD768}; MyRectangle(Control_Surface.getHDC(), fullRect, Gris); // Draw Main Teams Interface:
	RECT Rect; // --- 1 Retreiving Main (Control) Window Width & Height:
	GetClientRect(hwnd_CONTROL, &Rect);
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left;
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;

	// TEAMS_SECTION:
	INTERFACE_RECTANGLE[TEAMS_SECTION].left	  = MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].top	  = MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].right  = CLIENT_WIDTH_CONTROL  - MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].bottom = CLIENT_HEIGHT_CONTROL - MARGIN;

	// Buttons Positionning:
	int x, y, Largeur, Hauteur;

	// ID_BTN_RETURN:
	x = y = 2 * MARGIN;
	BOUTTON[ID_BTN_RETURN].Move(x, y);
	
	// ID_BTN_NEW_TEAM:
	BOUTTON[ID_BTN_RETURN].getDimensions(Largeur, Hauteur);
	x = x + Largeur + MARGIN;
	BOUTTON[ID_BTN_NEW_TEAM].Move(x, y);
	
	// ID_BTN_LISTE_TEAMS:
	BOUTTON[ID_BTN_NEW_TEAM].getDimensions(Largeur, Hauteur);
	x = x + Largeur + MARGIN;
	BOUTTON[ID_BTN_LISTE_TEAMS].Move(x, y);
	
	Move_player_inputs();
}