//														file: Boutons.cpp version: 00
#include "Boutons.hpp"
class myButtons BOUTTON[NUMBER_OF_BUTTONS]; // Tableau des Reunissant tous les Bouttons:
void Buttons_Creation()
{
	// Main Interface Buttons:
	// ID_BTN_TRANSITION:
	BOUTTON[ID_BTN_TRANSITION].init	   (ID_BTN_TRANSITION,	TEXT(">"), hwnd_CONTROL, 10, 500, Button_Transition_Dimension,Button_Transition_Dimension,TRUE);
	// Page Chronometre:
	BOUTTON[ID_CHRONO_PAGE].init			(ID_CHRONO_PAGE,		TEXT("Chrono"),hwnd_CONTROL, 0, 0, 75, 30, TRUE);
	BOUTTON[ID_START_CHRONO].init			(ID_START_CHRONO,		TEXT("Start"), hwnd_CONTROL, 0, 0, 50, 50, FALSE);
	BOUTTON[ID_RESET_1st_HALF].init			(ID_RESET_1st_HALF,		TEXT("00:00"), hwnd_CONTROL, 0, 0, 50, 50, FALSE);
	BOUTTON[ID_RESET_2nd_HALF].init			(ID_RESET_2nd_HALF,		TEXT("45:00"), hwnd_CONTROL, 0, 0, 50, 50, FALSE);
	BOUTTON[ID_RESET_1st_ExtTime].init		(ID_RESET_1st_ExtTime,	TEXT("90:00"), hwnd_CONTROL, 0, 0, 50, 50, FALSE);
	BOUTTON[ID_RESET_2nd_ExtTime].init		(ID_RESET_2nd_ExtTime,	TEXT("105:00"),hwnd_CONTROL, 0, 0, 50, 50, FALSE);
	// Page du Score:
	BOUTTON[ID_SCORE_PAGE].init				(ID_SCORE_PAGE,			TEXT("SCORE"),	hwnd_CONTROL, 0, 0, 75, 30, TRUE);
	BOUTTON[ID_BTN_LITTLE_SCORE].init		(ID_BTN_LITTLE_SCORE,	TEXT("Afficher Petit Score!"),	hwnd_CONTROL, 0, 0, 150, 30, FALSE);
	BOUTTON[ID_BTN_BIG_SCORE].init			(ID_BTN_BIG_SCORE,		TEXT("Afficher Grand Score!"),	hwnd_CONTROL, 0, 0, 150, 30, FALSE);
	BOUTTON[ID_BTN_ADD_GOAL_LOCALS].init	(ID_BTN_ADD_GOAL_LOCALS,TEXT("+"),	hwnd_CONTROL, 0, 0, 30, 30, FALSE);
	BOUTTON[ID_BTN_MIN_GOAL_LOCALS].init	(ID_BTN_MIN_GOAL_LOCALS,TEXT("-"),	hwnd_CONTROL, 0, 0, 30, 30, FALSE);
	BOUTTON[ID_BTN_ADD_GOAL_VISITORS].init	(ID_BTN_ADD_GOAL_VISITORS,TEXT("+"),	hwnd_CONTROL, 0, 0, 30, 30, FALSE);
	BOUTTON[ID_BTN_MIN_GOAL_VISITORS].init	(ID_BTN_MIN_GOAL_VISITORS,TEXT("-"),	hwnd_CONTROL, 0, 0, 30, 30, FALSE);
	// Page d'édition des équipes:
	BOUTTON[ID_TEAMS_EDIT_PAGE].init		(ID_TEAMS_EDIT_PAGE,	TEXT("Teams List"),hwnd_CONTROL, 0, 0, 100, 30, TRUE);
	BOUTTON[ID_BTN_HOME].init				(ID_BTN_HOME,			TEXT("Return"),hwnd_CONTROL, 0, 0, 100, 30, TRUE);
	BOUTTON[ID_BTN_NEW_TEAM].init			(ID_BTN_NEW_TEAM,		TEXT("New Team"),hwnd_CONTROL, 0, 0, 100, 30, TRUE);
	BOUTTON[ID_BTN_LISTE_TEAMS].init		(ID_BTN_LISTE_TEAMS,	TEXT("Teams Edition"),hwnd_CONTROL, 0, 0, 100, 30, TRUE);
	BOUTTON[ID_BTN_SAVE_TEAM].init			(ID_BTN_SAVE_TEAM,		TEXT("Save Team"),hwnd_CONTROL, 0, 0, 100, 30, FALSE);
	return;
}