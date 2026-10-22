#pragma once
#include "Globals & Functions/Unicode.hpp"
#include "Globals & Functions/Logging.hpp"

class myBigScore
{
	private:
	class myBitmap BigScoreBmp;
	int largeur, hauteur;
	class myFont FontScore24, FontScore40, FontScore54;

	public:
    myBigScore(const myBigScore&) = delete;
    myBigScore& operator=(const myBigScore&) = delete;

    // Constructeur par défaut
    myBigScore() : largeur(0), hauteur(0) {}

    // Destructeur:
    ~myBigScore()
    {

    }

    bool init(HDC hdc)
	{
		BigScoreBmp.init(hdc, TEXT("resources/BigScore.bmp"));
		BigScoreBmp.getDimensions(largeur, hauteur);

		FontScore24.init  ( 24, FW_BOLD, TEXT("Arial") );
		FontScore40.init  ( 40, FW_BOLD, TEXT("Arial") );
		FontScore54.init  ( 54, FW_BOLD, TEXT("Arial") );
		return true;
	}

	private:
	void Screen_display(bool Show, HDC Screen_hdc, int Local_Goals, int Visitors_Goals, TCHAR* Locals, TCHAR* Visitors) const
	{
		static int x = ( HD1366 - largeur )  / 2;
		static int y = ( HD768  - hauteur - 40 );

		RECT rect = {x, y - 45, largeur + x, hauteur + y };
		app::rectang(Screen_hdc, &rect, Noir);

		if( Show )
		{
			BitBlt(	Screen_hdc, x, y, largeur, hauteur, BigScoreBmp.getHDC(), 0, 0, SRCCOPY );
			//StretchBlt(	Screen_hdc, MARGIN, MARGIN, largeur*2.5, hauteur*2.5, PetitScoreBmp.getHDC(), 0, 0, largeur, hauteur, SRCCOPY );

			// Writing Time On Little Score:
			if(CHRONO[TOTAL_SECONDES] < (100*60))	app::TextToHDC(Screen_hdc, x + 500, y - 40, FontScore40, Blanc, Time);
			else									app::TextToHDC(Screen_hdc, x + 500, y - 40, FontScore40, Blanc, Time);

			//Writting Local Team Goals:
			if( Local_Goals > 9)	app::TextToHDC(Screen_hdc, x + 480, y + 35, FontScore54, Blanc, Locals);
			else 					app::TextToHDC(Screen_hdc, x + 480, y + 35, FontScore54, Blanc, Locals);

			if( Visitors_Goals > 9)	app::TextToHDC(Screen_hdc, x + 550, y + 35, FontScore54, Blanc, Visitors);
			else					app::TextToHDC(Screen_hdc, x + 570, y + 35, FontScore54, Blanc, Visitors);
		}
	}

	public:
	void display(void)
	{
		// Retreive Time minutes:secondes:
		//TCHAR Time[16] = {0};
		//Time[6] = _T('\0');
		//StringCchPrintf(Time, ARRAYSIZE(Time), TEXT("%02d:%02d"), CHRONO[MINUTES], CHRONO[SECONDES]);

		// Convert int to String of Locals Preview Goals:
		//TCHAR  LOCALS_PREVIEW_STRING[3];
		//StringCchPrintf(LOCALS_PREVIEW_STRING, ARRAYSIZE(LOCALS_PREVIEW_STRING), TEXT("%d"),  GOALS[LOCALS_PREVIEW] );
		
		// Convert int to String of Locals Goals:
		//TCHAR LOCALS_GOALS_STRING[3];
		//StringCchPrintf(LOCALS_GOALS_STRING, ARRAYSIZE(LOCALS_GOALS_STRING), TEXT("%d"), GOALS[LOCALS] );
		
		// Convert int to String of Visitors Preview Goals:
		//TCHAR VISITORS_PREVIEW_STRING[3];
		//StringCchPrintf(VISITORS_PREVIEW_STRING, ARRAYSIZE(VISITORS_PREVIEW_STRING), TEXT("%d"),  GOALS[VISITORS_PREVIEW] );
		
		// Convert int to String of Visitors Goals:
		//TCHAR VISITORS_GOALS_STRING[3];
		//StringCchPrintf(VISITORS_GOALS_STRING, ARRAYSIZE(VISITORS_GOALS_STRING), TEXT("%d"), GOALS[VISITORS] );

		// Positions of the left up Corner of :

		
		Screen_display( Show_Preview_Big_Score, Preview_Surface.getHDC(),
											GOALS[LOCALS_PREVIEW], GOALS[VISITORS_PREVIEW], LOCALS_PREVIEW_STRING, VISITORS_PREVIEW_STRING);
		Screen_display( Show_Program_Big_Score, Program_Surface.getHDC(),
											GOALS[LOCALS], GOALS[VISITORS], LOCALS_GOALS_STRING  , VISITORS_GOALS_STRING);
		return;
	}
};