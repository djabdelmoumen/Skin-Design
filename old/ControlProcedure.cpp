#include "ControlProcedure.hpp"

// --- LOGIQUE DE LA FENÊTRE DE CONTRÔLE --- //
LRESULT CALLBACK ControlProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static class myLittleScore	PetitScore;
	static class myBigScore 	BigScore;

	static int Main_Down_Page_id = CRONO_PAGE;
	
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
			
			// Buttons Creation Section:
			Buttons_Creation();
			InterfaceID = MAIN_INTERFACE;
			Hide_Show_interface(InterfaceID, TRUE);
			Calculate_Control_Interface(MAIN_INTERFACE);
			
			//if there is an error:
			if( app::ErrorsExist() ) return -1;
			
			//RECT fullRect = {0, 0, HD1366, HD768}; // Taille HD par défaut.
			//app::rectang(Control_Surface.getHDC(), &fullRect, Gris);
			
			Draw_Info_Zone(Control_Surface.getHDC());
			InvalidateRect(hwnd, NULL, false);
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
				if(InterfaceID == MAIN_INTERFACE)
				{
					Draw_Info_Zone(Control_Surface.getHDC());
					two_screens(Control_Surface.getHDC());
					InvalidateRect(hwnd, NULL, false);
				}
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
					StringCchPrintf(LOCALS_GOALS_STRING,   ARRAYSIZE(LOCALS_GOALS_STRING),   TEXT("%d"), GOALS[LOCALS]   );
					StringCchPrintf(VISITORS_GOALS_STRING, ARRAYSIZE(VISITORS_GOALS_STRING), TEXT("%d"), GOALS[VISITORS] );
					
					
					PetitScore.display();
					BigScore.display();
					two_screens(Control_Surface.getHDC());
					
					InvalidateRect(hwnd_PROGRAM, NULL, FALSE);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;

                case ID_CHRONO_PAGE:
				{
					BOUTONS[ID_START_CHRONO].Show();		  BOUTONS[ID_START_CHRONO].Set_Default_Visibility(TRUE);
					BOUTONS[ID_RESET_1st_HALF].Show();		  BOUTONS[ID_RESET_1st_HALF].Set_Default_Visibility(TRUE);
					BOUTONS[ID_RESET_2nd_HALF].Show();		  BOUTONS[ID_RESET_2nd_HALF].Set_Default_Visibility(TRUE);
					BOUTONS[ID_RESET_1st_ExtTime].Show();	  BOUTONS[ID_RESET_1st_ExtTime].Set_Default_Visibility(TRUE);
					BOUTONS[ID_RESET_2nd_ExtTime].Show();	  BOUTONS[ID_RESET_2nd_ExtTime].Set_Default_Visibility(TRUE);
					
					BOUTONS[ID_BTN_LITTLE_SCORE].Hide();	  BOUTONS[ID_BTN_LITTLE_SCORE].Set_Default_Visibility(FALSE);
					BOUTONS[ID_BTN_BIG_SCORE].Hide();		  BOUTONS[ID_BTN_BIG_SCORE].Set_Default_Visibility(FALSE);
					BOUTONS[ID_BTN_ADD_GOAL_LOCALS].Hide();   BOUTONS[ID_BTN_ADD_GOAL_LOCALS].Set_Default_Visibility(FALSE);
					BOUTONS[ID_BTN_MIN_GOAL_LOCALS].Hide();	  BOUTONS[ID_BTN_MIN_GOAL_LOCALS].Set_Default_Visibility(FALSE);
					BOUTONS[ID_BTN_ADD_GOAL_VISITORS].Hide(); BOUTONS[ID_BTN_ADD_GOAL_VISITORS].Set_Default_Visibility(FALSE);
					BOUTONS[ID_BTN_MIN_GOAL_VISITORS].Hide(); BOUTONS[ID_BTN_MIN_GOAL_VISITORS].Set_Default_Visibility(FALSE);
					
					Draw_Down_Section(CRONO_PAGE);
					InvalidateRect(hwnd, NULL, false);
				}
                return 0;
				
				case ID_SCORE_PAGE:
				{
					BOUTONS[ID_START_CHRONO].Hide();      		BOUTONS[ID_START_CHRONO].Set_Default_Visibility(FALSE);
					BOUTONS[ID_RESET_1st_HALF].Hide();    		BOUTONS[ID_RESET_1st_HALF].Set_Default_Visibility(FALSE);
					BOUTONS[ID_RESET_2nd_HALF].Hide();    		BOUTONS[ID_RESET_2nd_HALF].Set_Default_Visibility(FALSE);
					BOUTONS[ID_RESET_1st_ExtTime].Hide(); 		BOUTONS[ID_RESET_1st_ExtTime].Set_Default_Visibility(FALSE);
					BOUTONS[ID_RESET_2nd_ExtTime].Hide(); 		BOUTONS[ID_RESET_2nd_ExtTime].Set_Default_Visibility(FALSE);

					BOUTONS[ID_BTN_LITTLE_SCORE].Show();		BOUTONS[ID_BTN_LITTLE_SCORE].Set_Default_Visibility(TRUE);
					BOUTONS[ID_BTN_BIG_SCORE].Show();			BOUTONS[ID_BTN_BIG_SCORE].Set_Default_Visibility(TRUE);
					BOUTONS[ID_BTN_ADD_GOAL_LOCALS].Show();		BOUTONS[ID_BTN_ADD_GOAL_LOCALS].Set_Default_Visibility(TRUE);
					BOUTONS[ID_BTN_MIN_GOAL_LOCALS].Show();		BOUTONS[ID_BTN_MIN_GOAL_LOCALS].Set_Default_Visibility(TRUE);
					BOUTONS[ID_BTN_ADD_GOAL_VISITORS].Show();	BOUTONS[ID_BTN_ADD_GOAL_VISITORS].Set_Default_Visibility(TRUE);
					BOUTONS[ID_BTN_MIN_GOAL_VISITORS].Show();	BOUTONS[ID_BTN_MIN_GOAL_VISITORS].Set_Default_Visibility(TRUE);

					Draw_Down_Section(SCORE_PAGE);
					InvalidateRect(hwnd, NULL, false);
				}
                return 0;
				
				case ID_BTN_LITTLE_SCORE:
                {
					Show_Preview_Little_Score = !Show_Preview_Little_Score;
					SetWindowText(BOUTONS[ID_BTN_LITTLE_SCORE].getHWND(), Show_Preview_Little_Score ? _T("Cacher Petit Score") : _T("Afficher Petit Score"));

					PetitScore.display();
					two_screens(Control_Surface.getHDC());
					InvalidateRect(hwnd, NULL, FALSE);
				}
                return 0;
				
				case ID_BTN_BIG_SCORE:
                {
					Show_Preview_Big_Score = !Show_Preview_Big_Score;
					SetWindowText(BOUTONS[ID_BTN_BIG_SCORE].getHWND(), Show_Preview_Big_Score ? _T("Cacher Grand Score") : _T("Afficher Grand Score"));
					BigScore.display();
					two_screens(Control_Surface.getHDC());
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;

                case ID_START_CHRONO:
                {
                    Chrono_Active = !Chrono_Active;
                    SetWindowText(BOUTONS[ID_START_CHRONO].getHWND(), Chrono_Active ? _T("Pause") : _T("Start"));
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
					StringCchPrintf(Time, ARRAYSIZE(Time), TEXT("%02d:%02d"), CHRONO[MINUTES], CHRONO[SECONDES]);
                    
                    SetWindowText(BOUTONS[ID_START_CHRONO].getHWND(), _T("Start"));
					
					Draw_Info_Zone(Control_Surface.getHDC());
					PetitScore.display();
					BigScore.display();
					two_screens(Control_Surface.getHDC());
					
                    InvalidateRect(hwnd, NULL, false);
                }
                return 0;

                case ID_BTN_ADD_GOAL_LOCALS:
                {
                    StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), TEXT("%d"),  ++GOALS[LOCALS_PREVIEW] );
					Draw_Down_Section(SCORE_PAGE);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
                
                case ID_BTN_MIN_GOAL_LOCALS:
                {
                    if (GOALS[LOCALS_PREVIEW] > 0) 
					StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), TEXT("%d"),  --GOALS[LOCALS_PREVIEW] );
					Draw_Down_Section(SCORE_PAGE);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
            
                case ID_BTN_ADD_GOAL_VISITORS:
                {
                    StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), TEXT("%d"),  ++GOALS[VISITORS_PREVIEW] );
					Draw_Down_Section(SCORE_PAGE);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
                
                case ID_BTN_MIN_GOAL_VISITORS:
                {
                    if (GOALS[VISITORS_PREVIEW] > 0)
					StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), TEXT("%d"),  --GOALS[VISITORS_PREVIEW] );
					Draw_Down_Section(SCORE_PAGE);
                    InvalidateRect(hwnd, NULL, FALSE);
                }
                return 0;
			    
				case BTN_TEAMS_EDIT_PAGE:
				{
					Hide_Show_interface( InterfaceID,  FALSE);
					InterfaceID = TEAMS_INTERFACE;
					Hide_Show_interface( InterfaceID, TRUE);
					
					
					Calculate_Control_Interface(TEAMS_INTERFACE);
					Draw_Teams_Interface(OLD_PAGE);
					//RECT fullRect = {0, 0, HD1366, HD768};
					//app::rectang(Control_Surface.getHDC(), &fullRect, SkyBlue);
					
					InvalidateRect(hwnd, NULL, false);

				}
                return 0;
				
				case ID_BTN_RETURN:
                {
					Hide_Show_interface( TEAMS_INTERFACE, FALSE);
                	Hide_Show_interface( MAIN_INTERFACE,  TRUE); // hide InterfaceID
					InterfaceID = MAIN_INTERFACE;
					Calculate_Control_Interface(MAIN_INTERFACE);
					Draw_Info_Zone(Control_Surface.getHDC());
					two_screens(Control_Surface.getHDC());
					Draw_Down_Section(OLD_PAGE);
					
					destroy_player_inputs(hwnd);
					InvalidateRect(hwnd, NULL, false);
				}
				return 0;
				
				case ID_BTN_NEW_TEAM:
				{
					create_player_inputs(hwnd);
					Calculate_Control_Interface(TEAMS_INTERFACE);
					InvalidateRect(hwnd, NULL, false);
				}
				return 0;
			}
        }
		return 0;
		
		case WM_SIZE:
        {
			Calculate_Control_Interface(InterfaceID);

			switch(InterfaceID)
			{
				case MAIN_INTERFACE:
				{
					RECT fullRect = {0, 0, HD1366, HD768};
					FillmyRectangle(Control_Surface.getHDC(), fullRect, DarkBlue);
					Draw_Info_Zone(Control_Surface.getHDC());
					two_screens(Control_Surface.getHDC());
					Draw_Down_Section(OLD_PAGE);
					
				}
				break;
				case TEAMS_INTERFACE:
				{
					//RECT fullRect = {0, 0, HD1366, HD768};
					//app::rectang(Control_Surface.getHDC(), &fullRect, SkyBlue);
					//app::rectang(Control_Surface.getHDC(), &INTERFACE_RECT[TEAM_SQUARE], SkyBlue);
					//DisplayTeam (Control_Surface.getHDC(), false);
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