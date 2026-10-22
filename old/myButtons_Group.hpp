#pragma once
#include "myButtons.hpp"

	/*--IDENTIFIANTS DES BOUTONS--*/

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
	#define BTN_TEAMS_EDIT_PAGE      15
            // Teams Interface
	#define ID_BTN_RETURN            16
	#define ID_BTN_NEW_TEAM			 17

	#define NUMBER_OF_BUTTONS		 18

// Tableau des Reunissant tous les Bouttons:
extern class myButtons BOUTTON[NUMBER_OF_BUTTONS];