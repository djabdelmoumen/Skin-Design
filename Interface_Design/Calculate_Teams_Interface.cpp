#include "Interfaces.hpp"
void Calculate_Teams_Interface()
{
	//RECT fullRect = {0, 0, HD1366, HD768}; MyRectangle(Control_Surface.getHDC(), fullRect, Gris); // Draw Main Teams Interface:

	// --- 1 Retreiving Main (Control) Window Width & Height:
	RECT Rect;
	GetClientRect(hwnd_CONTROL, &Rect);
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left;
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;

	int x, y, Largeur, Hauteur;

	// --- 2 Calcule Barre de Menu:
	BOUTTON[ID_BTN_HOME].getDimensions(Largeur, Hauteur);

	INTERFACE_RECTANGLE[MENU_BAR].left   = MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].top    = MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].bottom = INTERFACE_RECTANGLE[MENU_BAR].top + Hauteur;



	//FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[MENU_BAR], Canard);

	// TEAMS_SECTION:
	INTERFACE_RECTANGLE[TEAMS_SECTION].left	  = MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].top	  = INTERFACE_RECTANGLE[MENU_BAR].top + MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].right  = CLIENT_WIDTH_CONTROL  - MARGIN;
	INTERFACE_RECTANGLE[TEAMS_SECTION].bottom = CLIENT_HEIGHT_CONTROL - MARGIN;

	// Buttons Positionning:
	
	// ID_BTN_HOME:
	x = INTERFACE_RECTANGLE[MENU_BAR].left;
	y = INTERFACE_RECTANGLE[MENU_BAR].top;
	BOUTTON[ID_BTN_HOME].Move(x,y);

	// ID_BTN_NEW_TEAM:
	//BOUTTON[ID_BTN_HOME].getDimensions(Largeur, Hauteur);
	x = x + Largeur + (4*MARGIN);
	BOUTTON[ID_BTN_NEW_TEAM].Move(x, y);
	
	// ID_BTN_LISTE_TEAMS:
	BOUTTON[ID_BTN_NEW_TEAM].getDimensions(Largeur, Hauteur);
	x = x + Largeur + MARGIN;
	BOUTTON[ID_BTN_LISTE_TEAMS].Move(x, y);
	
	Move_player_inputs();
}