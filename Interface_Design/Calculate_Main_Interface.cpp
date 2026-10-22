#include "Interfaces.hpp"

void Calculate_Main_Interface(void)
{
	RECT fullRect = {0, 0, HD1366, HD768};
	FillMyRectangle(Control_Surface.getHDC(), fullRect, Gris);
	
	// --- 1 Retreiving Main (Control) Window Width & Height:
	RECT rect;
	GetClientRect(hwnd_CONTROL, &rect);
	int CLIENT_WIDTH_CONTROL  = rect.right  - rect.left;
	int CLIENT_HEIGHT_CONTROL = rect.bottom - rect.top;
	
	// --- Calcule Barre de Menu:
	

	// --- 2 Calcule de la zone info:
	INTERFACE_RECTANGLE[INFO_ZONE].left   = MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].top    = MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[INFO_ZONE].bottom = 150;

	// --- 3 Calculer ies rectangles(zones) de preview et program:
	int Largeur = (int)(((float)((INTERFACE_RECTANGLE[INFO_ZONE].right - INTERFACE_RECTANGLE[INFO_ZONE].left) - Button_Transition_Dimension))/2.0);
	int Hauteur  = (int)((9.0/16.0)*((float)Largeur));

	// --- 4 Two Screens(Preview & Program) Zone:
	INTERFACE_RECTANGLE[TWO_SCREENS].left   = MARGIN;
	INTERFACE_RECTANGLE[TWO_SCREENS].top    = MARGIN + INTERFACE_RECTANGLE[INFO_ZONE].bottom;
	INTERFACE_RECTANGLE[TWO_SCREENS].right  = CLIENT_WIDTH_CONTROL - MARGIN;
	INTERFACE_RECTANGLE[TWO_SCREENS].bottom = MARGIN + INTERFACE_RECTANGLE[INFO_ZONE].bottom  + Hauteur;	
	
	// --- 5 Ecran Preview:
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].left   = MARGIN;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].top    = MARGIN + INTERFACE_RECTANGLE[INFO_ZONE].bottom;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].right  = MARGIN + Largeur;
	INTERFACE_RECTANGLE[PREVIEW_SCREEN].bottom = INTERFACE_RECTANGLE[PREVIEW_SCREEN].top + Hauteur;

	// --- 6 Ecran Program:
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].left   = CLIENT_WIDTH_CONTROL - MARGIN - Largeur;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].top    = INTERFACE_RECTANGLE[PREVIEW_SCREEN].top;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].right  = INTERFACE_RECTANGLE[PROGRAM_SCREEN].left + Largeur;
	INTERFACE_RECTANGLE[PROGRAM_SCREEN].bottom = INTERFACE_RECTANGLE[PROGRAM_SCREEN].top  + Hauteur;
	
	// --- 7 Down Section:
	INTERFACE_RECTANGLE[DOWN_SECTION].left   = MARGIN;
	INTERFACE_RECTANGLE[DOWN_SECTION].top    = MARGIN + INTERFACE_RECTANGLE[TWO_SCREENS].bottom;
	INTERFACE_RECTANGLE[DOWN_SECTION].right  = CLIENT_WIDTH_CONTROL  - MARGIN;
	INTERFACE_RECTANGLE[DOWN_SECTION].bottom = CLIENT_HEIGHT_CONTROL - MARGIN;
	
	// --- 8 Buttons Position:
	
	// Bouton Transition:
	BOUTTON[ID_BTN_TRANSITION].getDimensions(Largeur, Hauteur);
	int x = INTERFACE_RECTANGLE[PREVIEW_SCREEN].right;
	int y = (int)(((float)(INTERFACE_RECTANGLE[PROGRAM_SCREEN].top + INTERFACE_RECTANGLE[PROGRAM_SCREEN].bottom - Largeur))/2.0);
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
	BOUTTON[ID_TEAMS_EDIT_PAGE].Move(x, y);
	
								
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