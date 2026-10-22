//														file: ControlProcedure.cpp version: 00
#include "ControlProcedure.hpp"

// --- LOGIQUE DE LA FENÊTRE DE CONTRÔLE --- //
LRESULT CALLBACK ControlProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static class myLittleScore	PetitScore;
	static class myBigScore 	BigScore;

	static int my_interface = MAIN_INTERFACE;
	//static int my_interface = TEAMS_INTERFACE;
	
	switch (uMsg)
	{
		case WM_CREATE:
		{
			hwnd_CONTROL = hwnd;
			
			SetTimer(hwnd, 1, 1000, NULL); // Timer pour le chronomètre (1 seconde)
			
			HDC hdc = GetDC(hwnd);
				Preview_Surface.init(hdc);
				Program_Surface.init(hdc);
				Control_Surface.init(hdc);
				PetitScore.init(hdc);
				BigScore.init(hdc);
				ReleaseDC(hwnd, hdc);
			hdc = NULL;
			if( ErrorsExist() ) return -1;
			
			// Buttons Creation Section:
			Buttons_Creation(); 
			if( ErrorsExist() ) return -1;// if there is an error:
			
			Calculate_Interface(TEAMS_INTERFACE);

			Show_Interface(MAIN_INTERFACE,  TRUE);
			Show_Interface(TEAMS_INTERFACE, FALSE);
		}
		return 0;

		case WM_TIMER:
		{
			if (Chrono_Active)
			{
				++CHRONO[TOTAL_SECONDES];
				CHRONO[MINUTES]  = CHRONO[TOTAL_SECONDES] / 60;
				CHRONO[SECONDES] = CHRONO[TOTAL_SECONDES] % 60;
				StringCchPrintf(Time, ARRAYSIZE(Time), TEXT("%02d:%02d"), CHRONO[MINUTES], CHRONO[SECONDES]);
				
				PetitScore.display();
				BigScore.display();
				if(my_interface == MAIN_INTERFACE)
				{
					Draw_Info_Zone();
					two_screens();
					InvalidateRect(hwnd, NULL, false);
				}
				InvalidateRect(hwnd_PROGRAM, NULL, FALSE);
			}
		}
		return 0;
		
		case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
				case ID_BTN_TRANSITION:
                {
                    Show_Program_Little_Score = Show_Preview_Little_Score;
					Show_Program_Big_Score	  = Show_Preview_Big_Score;
                    GOALS[LOCALS]	= GOALS[LOCALS_PREVIEW];
					GOALS[VISITORS]	= GOALS[VISITORS_PREVIEW];
					StringCchPrintf(LOCALS_GOALS_STRING,   ARRAYSIZE(LOCALS_GOALS_STRING),   L"%d", GOALS[LOCALS]   );
					StringCchPrintf(VISITORS_GOALS_STRING, ARRAYSIZE(VISITORS_GOALS_STRING), L"%d", GOALS[VISITORS] );
						PetitScore.display();
						BigScore.display();
						two_screens();
					InvalidateRect(hwnd, NULL, FALSE);
					InvalidateRect(hwnd_PROGRAM, NULL, FALSE);
				}
				return 0;

				case ID_CHRONO_PAGE:
				case ID_SCORE_PAGE:
				{
					bool ShowMe = TRUE;
					if(wmId == ID_SCORE_PAGE) ShowMe = FALSE;

					BOUTTON[ID_START_CHRONO].Show(ShowMe);
					BOUTTON[ID_RESET_1st_HALF].Show(ShowMe);
					BOUTTON[ID_RESET_2nd_HALF].Show(ShowMe);
					BOUTTON[ID_RESET_1st_ExtTime].Show(ShowMe);
					BOUTTON[ID_RESET_2nd_ExtTime].Show(ShowMe);						

					BOUTTON[ID_BTN_LITTLE_SCORE].Hide(ShowMe);
					BOUTTON[ID_BTN_BIG_SCORE].Hide(ShowMe);
					BOUTTON[ID_BTN_ADD_GOAL_LOCALS].Hide(ShowMe);
					BOUTTON[ID_BTN_MIN_GOAL_LOCALS].Hide(ShowMe);
					BOUTTON[ID_BTN_ADD_GOAL_VISITORS].Hide(ShowMe);
					BOUTTON[ID_BTN_MIN_GOAL_VISITORS].Hide(ShowMe);

					Draw_Down_Section();
					InvalidateRect(hwnd, NULL, false);
				}
				return 0;

				case ID_BTN_LITTLE_SCORE:
				{
					Show_Preview_Little_Score = !Show_Preview_Little_Score;
					SetWindowText(BOUTTON[ID_BTN_LITTLE_SCORE].getHWND(), Show_Preview_Little_Score ? L"Cacher Petit Score" : L"Afficher Petit Score");
						PetitScore.display();
						two_screens();
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;

				case ID_BTN_BIG_SCORE:
				{
					Show_Preview_Big_Score = !Show_Preview_Big_Score;
					SetWindowText(BOUTTON[ID_BTN_BIG_SCORE].getHWND(), Show_Preview_Big_Score ? L"Cacher Grand Score" : L"Afficher Grand Score");
						BigScore.display();
						two_screens();
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;

				case ID_START_CHRONO:
				{
					Chrono_Active = !Chrono_Active;
					SetWindowText(BOUTTON[ID_START_CHRONO].getHWND(), Chrono_Active ? L"Pause" : L"Start");
				}
				return 0;

				case ID_RESET_1st_HALF:
				case ID_RESET_2nd_HALF:
				case ID_RESET_1st_ExtTime:
				case ID_RESET_2nd_ExtTime:
				{
					Chrono_Active = false;
					if      (wmId == ID_RESET_1st_HALF)    CHRONO[TOTAL_SECONDES] = 0;
					else if (wmId == ID_RESET_2nd_HALF)    CHRONO[TOTAL_SECONDES] = 45 * 60;
					else if (wmId == ID_RESET_1st_ExtTime) CHRONO[TOTAL_SECONDES] = 90 * 60;
					else if (wmId == ID_RESET_2nd_ExtTime) CHRONO[TOTAL_SECONDES] = 105 * 60;

					CHRONO[MINUTES]  = CHRONO[TOTAL_SECONDES] / 60;
					CHRONO[SECONDES] = CHRONO[TOTAL_SECONDES] % 60;
					StringCchPrintf(Time, ARRAYSIZE(Time), L"%02d:%02d", CHRONO[MINUTES], CHRONO[SECONDES]);

					SetWindowText(BOUTTON[ID_START_CHRONO].getHWND(), L"Start");
					
						PetitScore.display();
						BigScore.display();
						two_screens();//Control_Surface.getHDC()
						Draw_Info_Zone();
					InvalidateRect(hwnd, NULL, false);
				}
				return 0;

                case ID_BTN_ADD_GOAL_LOCALS:
                {
                    StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), L"%d",  ++GOALS[LOCALS_PREVIEW] );
						PetitScore.display();
						BigScore.display();
						two_screens();
						Draw_Down_Section();
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
                
                case ID_BTN_MIN_GOAL_LOCALS:
                {
                    if (GOALS[LOCALS_PREVIEW] > 0) 
					StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), L"%d",  --GOALS[LOCALS_PREVIEW] );
						PetitScore.display();
						BigScore.display();
						two_screens();
						Draw_Down_Section();
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
            
                case ID_BTN_ADD_GOAL_VISITORS:
                {
                    StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), L"%d",  ++GOALS[VISITORS_PREVIEW] );
						PetitScore.display();
						BigScore.display();
						two_screens();
						Draw_Down_Section();
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
                
                case ID_BTN_MIN_GOAL_VISITORS:
                {
                    if (GOALS[VISITORS_PREVIEW] > 0)
					StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), L"%d",  --GOALS[VISITORS_PREVIEW] );
						PetitScore.display();
						BigScore.display();
						two_screens();
						Draw_Down_Section();
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;

				case ID_TEAMS_EDIT_PAGE:
				{
					RECT fullRect = {0, 0, HD1366, HD768};
					FillMyRectangle(Control_Surface.getHDC(), fullRect, Gris);
					FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[TEAMS_SECTION], DarkBlue);

					// Calculate_Interface(TEAMS_INTERFACE);
					
					my_interface = TEAMS_INTERFACE;
					Show_Interface(MAIN_INTERFACE, FALSE);
					Show_Interface(TEAMS_INTERFACE, TRUE);
					InvalidateRect(hwnd, NULL, FALSE);
				}
                return 0;
				
				case ID_BTN_RETURN:
				{
						RECT fullRect = {0, 0, HD1366, HD768};
						FillMyRectangle(Control_Surface.getHDC(), fullRect, Noir);					
					
						Calculate_Interface(MAIN_INTERFACE);					
						Draw_Info_Zone();
						PetitScore.display();
						BigScore.display();
						two_screens();
						Draw_Down_Section();
						
					destroy_player_inputs(hwnd);					
					my_interface = MAIN_INTERFACE;
					Show_Interface(TEAMS_INTERFACE, FALSE);
					Show_Interface(MAIN_INTERFACE, TRUE);

					

					


					InvalidateRect(hwnd, NULL, FALSE);
					
					
				}
                return 0;

				case ID_BTN_NEW_TEAM:
				{
					create_player_inputs(hwnd);
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;
				
				case ID_BTN_SAVE_TEAM:
				{
					save_team(hwnd);
					//InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;
			}
        }
		return 0;
		
		case WM_SIZE:
        {
			Calculate_Interface(my_interface);
			switch(my_interface)
			{
				case MAIN_INTERFACE:
				{
					PetitScore.display();
					BigScore.display();
					two_screens();
					Draw_Down_Section();
					Draw_Info_Zone();
				}
				break;
				case TEAMS_INTERFACE:
				{
					RECT fullRect = {0, 0, HD1366, HD768};
					FillMyRectangle(Control_Surface.getHDC(), fullRect, Gris);
					FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[TEAMS_SECTION], DarkBlue);
					Calculate_Interface(TEAMS_INTERFACE);
				}
				break;
				default:
				
				break;
			}
			RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
        }
        return 0;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			// Copie finale vers l'écran (Double buffering via Control_Surface)
			RECT rect;
			GetClientRect(hwnd, &rect);
			BitBlt(hdc, 0, 0, rect.right, rect.bottom, Control_Surface.getHDC(), 0, 0, SRCCOPY);
			EndPaint(hwnd, &ps);
		}
		return 0;
		
		case WM_DESTROY:
		{
			PostQuitMessage(0); // Fermer l'appli si on ferme le contrôle
		}
		return 0;
	}
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}