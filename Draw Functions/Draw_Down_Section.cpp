//														file: Draw_Down_Section.cpp version: 00
#include "Drawing.hpp"
bool Draw_Down_Section()
{
	FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[DOWN_SECTION], DarkBlue);
	
	if(IsWindowVisible( BOUTTON[ID_BTN_LITTLE_SCORE].getHWND() ))
	{
		int x, y, Largeur, Hauteur;

		BOUTTON[ID_BTN_LITTLE_SCORE].getPosition(x, y);
		BOUTTON[ID_BTN_LITTLE_SCORE].getDimensions(Largeur, Hauteur);		
				
		x = x + MARGIN + Largeur;
		y = y + 5;
		app::TextToHDC(Control_Surface.getHDC(), x, y, FontStandard20, Blanc, L"Locals");
		
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getPosition(x, y);
		BOUTTON[ID_BTN_ADD_GOAL_LOCALS].getDimensions(Largeur, Hauteur);
		
		x = x + MARGIN + Largeur;
		y = y + MARGIN;
		// Convert int to String of Locals Preview Goals:
		WCHAR  LOCALS_PREVIEW_STRING[3];
		StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), L"%d", GOALS[LOCALS_PREVIEW] );
		app::TextToHDC(Control_Surface.getHDC(), x, y, FontStandard20, Blanc, LOCALS_PREVIEW_STRING);
		
		BOUTTON[ID_BTN_LITTLE_SCORE].getPosition(x, y);
		BOUTTON[ID_BTN_LITTLE_SCORE].getDimensions(Largeur, Hauteur);
		
		x = x + MARGIN + Largeur;
		y = y + MARGIN + Hauteur;
		app::TextToHDC(Control_Surface.getHDC(), x, y, FontStandard20, Blanc, L"الزائر");
		
		BOUTTON[ID_BTN_ADD_GOAL_VISITORS].getPosition(x, y);
		BOUTTON[ID_BTN_ADD_GOAL_VISITORS].getDimensions(Largeur, Hauteur);

		x = x + MARGIN + Largeur;
		y = y + MARGIN;
		// Convert int to String of Visitors Preview Goals:
		WCHAR  VISITORS_PREVIEW_STRING[3];
		StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), L"%d", GOALS[VISITORS_PREVIEW] );
		app::TextToHDC(Control_Surface.getHDC(), x, y, FontStandard20, Blanc, VISITORS_PREVIEW_STRING);
	}
	
	return true;
}