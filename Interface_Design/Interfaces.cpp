#include "Interfaces.hpp"

RECT INTERFACE_RECTANGLE[NUMBER_OF_RECTANGLES];

void Inteface_Rect_Dimensions(int id, RECT& rect) { CopyRect(&rect, &INTERFACE_RECTANGLE[id]); }

void Show_Or_Hide_Page( int ID_of_the_page, int Show_or_Hide )
{
	switch (ID_of_the_page)
	{
		case ID_CHRONO_PAGE:
			ShowWindow(BOUTTON[ID_START_CHRONO].getHWND(),      Show_or_Hide);
			ShowWindow(BOUTTON[ID_RESET_1st_HALF].getHWND(),    Show_or_Hide);
			ShowWindow(BOUTTON[ID_RESET_2nd_HALF].getHWND(),    Show_or_Hide);
			ShowWindow(BOUTTON[ID_RESET_1st_ExtTime].getHWND(), Show_or_Hide);
			ShowWindow(BOUTTON[ID_RESET_2nd_ExtTime].getHWND(), Show_or_Hide);
		break;
		case ID_SCORE_PAGE:
			ShowWindow(BOUTTON[ID_BTN_LITTLE_SCORE].getHWND(),    Show_or_Hide);
			ShowWindow(BOUTTON[ID_BTN_BIG_SCORE].getHWND(),   	  Show_or_Hide);
			ShowWindow(BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getHWND(),  Show_or_Hide);
			ShowWindow(BOUTTON[ID_BTN_MIN_GOAL_LOCALS].getHWND(),  Show_or_Hide);
			ShowWindow(BOUTTON[ID_BTN_ADD_GOAL_VISITORS].getHWND(), Show_or_Hide);
			ShowWindow(BOUTTON[ID_BTN_MIN_GOAL_VISITORS].getHWND(), Show_or_Hide);
		break;
	}
	return;
}

static void Execute_Show_Interface(int debut, int fin, bool Visibility)
{
	for(int i = debut; i <= fin; ++i)
	{
		if(Visibility)	BOUTTON[i].isShow();
		else			BOUTTON[i].ForceToHide();
	}
}

void Show_Interface(int interface_id, bool Visibility)
{
	switch (interface_id)
	{
			case MAIN_INTERFACE:
				//if(Visibility) FillmyRectangle(Control_Surface.getHDC(), {0, 0, HD1366, HD768}, Gris);
				Execute_Show_Interface(ID_BTN_TRANSITION, ID_TEAMS_EDIT_PAGE, Visibility);
			break;
			case TEAMS_INTERFACE:
				//if(Visibility) FillmyRectangle(Control_Surface.getHDC(), {0, 0, HD1366, HD768}, Noir);
				Execute_Show_Interface(ID_BTN_HOME, ID_BTN_SAVE_TEAM, Visibility);
			break;
	}
	return;
}


