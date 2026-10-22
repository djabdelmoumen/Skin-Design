//														file: global_variables.hpp version:0
#pragma once
#include "Unicode.hpp"
	
	// Surfaces:
	#define HD1366 1366
	#define HD768  768

	// Chronomètre:
	#define TOTAL_SECONDES 0
	#define MINUTES        1
	#define SECONDES       2
	extern int  CHRONO[3];
	extern bool Chrono_Active;
	extern WCHAR Time[7];

	// Score:
	#define LOCALS			 0
	#define LOCALS_PREVIEW	 1
	#define VISITORS		 2
	#define VISITORS_PREVIEW 3
	extern int GOALS[4];

	extern WCHAR LOCALS_PREVIEW_STRING   [3];
	extern WCHAR LOCALS_GOALS_STRING     [3];
	extern WCHAR VISITORS_PREVIEW_STRING [3];
	extern WCHAR VISITORS_GOALS_STRING   [3];

	// TAGS:
	extern bool Show_Program_Little_Score;
	extern bool Show_Program_Big_Score;
	extern bool Show_Preview_Little_Score;
	extern bool Show_Preview_Big_Score;

	// Windows Handles:
	extern HWND hwnd_CONTROL;
	extern HWND hwnd_PROGRAM;
	
	// Couleurs GDI:
	#define Blanc		RGB(255, 255, 255)
	#define Rouge		RGB(255,   0,   0)
	#define Vert		RGB(  0, 255,   0)
	#define Bleu		RGB(  0,   0, 255)
	#define Noir		RGB(  0,   0,   0)
    #define Gris		RGB( 50,  50,  50)
    #define DarkBlue	RGB( 5,   28,  36)
	#define Canard		RGB( 74, 145, 158)
	#define RougeBrique	RGB(156,  43,  27)
	#define Corail		RGB(232,  84,  63)
	

	/* -- IDENTIFIANTS DES BOUTONS -- */
			// Main Interface
	#define ID_BTN_TRANSITION		  1
	#define ID_SCORE_PAGE			  2
	#define ID_BTN_LITTLE_SCORE		  3
	#define ID_BTN_BIG_SCORE		  4
	#define ID_CHRONO_PAGE		      5
	#define ID_START_CHRONO			  6
	#define ID_RESET_1st_HALF		  7
	#define ID_RESET_2nd_HALF		  8
	#define ID_RESET_1st_ExtTime	  9
	#define ID_RESET_2nd_ExtTime	 10
	#define ID_BTN_ADD_GOAL_LOCALS   11
	#define ID_BTN_MIN_GOAL_LOCALS   12
	#define ID_BTN_ADD_GOAL_VISITORS 13
	#define ID_BTN_MIN_GOAL_VISITORS 14
	#define ID_TEAMS_EDIT_PAGE       15
			// Teams Interface
	#define ID_BTN_RETURN            16
	#define ID_BTN_NEW_TEAM			 17
	#define ID_BTN_LISTE_TEAMS		 18
	#define ID_BTN_SAVE_TEAM		 19

	#define NUMBER_OF_BUTTONS		 20

	/* ----- INTERFACE DESIGN ----- */
	#define MARGIN         				10
	#define Button_Transition_Dimension 50
	
	// Main Interface IDs:
	#define MAIN_INTERFACE  1	
	#define TEAMS_INTERFACE 2

	// Main Interface Resctangles:
	#define MENU_BAR		6
	#define INFO_ZONE       0
	#define PREVIEW_SCREEN  1
	#define PROGRAM_SCREEN  2
	#define TWO_SCREENS	    3
	#define DOWN_SECTION    4
	// Teams Interface Resctangles:
	#define TEAMS_SECTION	5
	
	#define NUMBER_OF_RECTANGLES 7

	