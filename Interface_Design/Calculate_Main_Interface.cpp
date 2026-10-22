#include "Interfaces.hpp"
void Calculate_Main_Interface(void)
{
	int x, y, Largeur, Hauteur;

	RECT fullRect = {0, 0, HD1366, HD768};
	FillMyRectangle(Control_Surface.getHDC(), fullRect, Gris);
	
	// --- 1 Retreiving Main (Control) Window Width & Height:
	RECT Rect;
	GetClientRect(hwnd_CONTROL, &Rect); 
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left; 
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;

	// --- 1 Calcule Barre de Menu:
	BOUTTON[ID_TEAMS_EDIT_PAGE].getDimensions(Largeur, Hauteur);
	
	INTERFACE_RECTANGLE[MENU_BAR].left   = MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].top    = MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[MENU_BAR].bottom = INTERFACE_RECTANGLE[MENU_BAR].top + Hauteur;
	
	BOUTTON[ID_TEAMS_EDIT_PAGE].Move(INTERFACE_RECTANGLE[MENU_BAR].left, INTERFACE_RECTANGLE[MENU_BAR].top);
	
	
	//FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[MENU_BAR], Canard);
	
	
	// --- 2 Calcule de la zone info:
	INTERFACE_RECTANGLE[INFO_ZONE].left   = MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].top    = INTERFACE_RECTANGLE[MENU_BAR].bottom + MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].bottom = INTERFACE_RECTANGLE[INFO_ZONE].top + 100;

	// --- 3 Calculer ies rectangles(zones) de preview et program:
	Largeur = (int)(((float)((INTERFACE_RECTANGLE[INFO_ZONE].right - INTERFACE_RECTANGLE[INFO_ZONE].left) - Button_Transition_Dimension))/2.0);
	Hauteur = (int)((9.0f/16.0f)*((float)Largeur));

	// --- 4 Two Screens(Preview & Program) Zone:
	INTERFACE_RECTANGLE[TWO_SCREENS].left   = MARGIN;
	INTERFACE_RECTANGLE[TWO_SCREENS].top    = MARGIN + INTERFACE_RECTANGLE[INFO_ZONE].bottom;
	INTERFACE_RECTANGLE[TWO_SCREENS].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[TWO_SCREENS].bottom = INTERFACE_RECTANGLE[TWO_SCREENS].top + Hauteur;

	//FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[TWO_SCREENS], Jaune);

	// --- 5 Ecran Preview:
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].left   = INTERFACE_RECTANGLE[TWO_SCREENS].left;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].top    = INTERFACE_RECTANGLE[TWO_SCREENS].top;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].right  = INTERFACE_RECTANGLE[TWO_SCREENS].left + Largeur;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].bottom = INTERFACE_RECTANGLE[TWO_SCREENS].bottom;

	//FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[PREVIEW_SCREEN], Vert);

	// --- 6 Ecran Program:
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].left   = INTERFACE_RECTANGLE[TWO_SCREENS].right - Largeur;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].top    = INTERFACE_RECTANGLE[TWO_SCREENS].top;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].right  = INTERFACE_RECTANGLE[TWO_SCREENS].right;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].bottom = INTERFACE_RECTANGLE[TWO_SCREENS].bottom;

	//FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[PROGRAM_SCREEN], Rouge);
	
	// --- 7 Down Section:
	INTERFACE_RECTANGLE[DOWN_SECTION].left   = MARGIN;
	INTERFACE_RECTANGLE[DOWN_SECTION].top    = MARGIN + INTERFACE_RECTANGLE[TWO_SCREENS].bottom;
	INTERFACE_RECTANGLE[DOWN_SECTION].right  = CLIENT_WIDTH_CONTROL  - MARGIN;
	INTERFACE_RECTANGLE[DOWN_SECTION].bottom = CLIENT_HEIGHT_CONTROL - MARGIN;
	
	// --- 8 Buttons Position:
	
	// Bouton Transition:
	BOUTTON[ID_BTN_TRANSITION].getDimensions(Largeur, Hauteur);
	x = INTERFACE_RECTANGLE[PREVIEW_SCREEN].right;
	y = (INTERFACE_RECTANGLE[TWO_SCREENS].top + INTERFACE_RECTANGLE[TWO_SCREENS].bottom - Hauteur)/2.0;
	

	
	//y = (int)(((float)(INTERFACE_RECTANGLE[PROGRAM_SCREEN].top + INTERFACE_RECTANGLE[PROGRAM_SCREEN].bottom - Largeur))/2.0);

	BOUTTON[ID_BTN_TRANSITION].Move(x, y);

	// bouton de la page chrono:
	BOUTTON[ID_CHRONO_PAGE].getDimensions(Largeur, Hauteur);
	x = INTERFACE_RECTANGLE[DOWN_SECTION].left + MARGIN;
	y = INTERFACE_RECTANGLE[DOWN_SECTION].top  + MARGIN;
	BOUTTON[ID_CHRONO_PAGE].Move(x, y);
	
	// bouton de la page score:
	x = x + Largeur + MARGIN;
	BOUTTON[ID_SCORE_PAGE].Move(x, y);
	
	// Bouton de la Page Big Score:
	x = x + Largeur + MARGIN;
	//BOUTTON[ID_TEAMS_EDIT_PAGE].Move(x, y);
	
								
	// --- La page Chrono: --- //
	{
		// ID_START_CHRONO:
		BOUTTON[ID_CHRONO_PAGE].getPosition(x, y);
		BOUTTON[ID_CHRONO_PAGE].getDimensions(Largeur, Hauteur);
		y = y + Hauteur + MARGIN;
		BOUTTON[ID_START_CHRONO].Move(x, y);
		
		// ID_RESET_1st_HALF:
		BOUTTON[ID_START_CHRONO].getDimensions(Largeur, Hauteur);
		x = x + Hauteur + MARGIN;
		BOUTTON[ID_RESET_1st_HALF].Move(x, y);
		
		// ID_RESET_2nd_HALF:
		BOUTTON[ID_RESET_1st_HALF].getDimensions(Largeur, Hauteur);
		x = x + Largeur + MARGIN;
		BOUTTON[ID_RESET_2nd_HALF].Move(x, y);

		// ID_RESET_1st_ExtTime:
		BOUTTON[ID_RESET_2nd_HALF].getDimensions(Largeur, Hauteur);
		x = x + Largeur + MARGIN;
		BOUTTON[ID_RESET_1st_ExtTime].Move(x, y);

		// ID_RESET_2nd_ExtTime:
		BOUTTON[ID_RESET_1st_ExtTime].getDimensions(Largeur, Hauteur);
		x = x + Largeur + MARGIN;
		BOUTTON[ID_RESET_2nd_ExtTime].Move(x, y);
	}

	// La Page Score:
	{
		// ID_BTN_LITTLE_SCORE:
		BOUTTON[ID_CHRONO_PAGE].getPosition(x, y);
		BOUTTON[ID_CHRONO_PAGE].getDimensions(Largeur, Hauteur);
		y = y + Hauteur + MARGIN;
		BOUTTON[ID_BTN_LITTLE_SCORE].Move(x, y);
		
		// ID_BTN_BIG_SCORE:
		BOUTTON[ID_BTN_LITTLE_SCORE].getPosition(x, y);
		BOUTTON[ID_BTN_LITTLE_SCORE].getDimensions(Largeur, Hauteur);
		y = y + Hauteur + MARGIN;
		BOUTTON[ID_BTN_BIG_SCORE].Move(x, y);
		
		// ID_BTN_ADD_GOAL:
		BOUTTON[ID_BTN_LITTLE_SCORE].getDimensions(Largeur, Hauteur);
		BOUTTON[ID_BTN_LITTLE_SCORE].getPosition(x, y);
		x = x + Largeur + MARGIN + 60;
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].Move(x, y);
		
		// ID_BTN_MIN_GOAL:
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getDimensions(Largeur, Hauteur);
		x = x + 60;
		BOUTTON[ID_BTN_MIN_GOAL_LOCALS].Move(x, y);
	
									// VISITORS
		// ID_BTN_ADD_GOAL:
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getPosition(x, y);
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getDimensions(Largeur, Hauteur);
		//x = x + 150;
		y = y + MARGIN + Hauteur;
		BOUTTON[ID_BTN_ADD_GOAL_VISITORS].Move(x, y);
		
		
		// ID_BTN_MIN_GOAL:
		BOUTTON[ID_BTN_MIN_GOAL_LOCALS].getPosition(x, y);
		BOUTTON[ID_BTN_MIN_GOAL_LOCALS].getDimensions(Largeur, Hauteur);
		y = y + MARGIN + Hauteur;
		BOUTTON[ID_BTN_MIN_GOAL_VISITORS].Move(x, y);
	}	
}