#pragma once
#include "Globals & Functions/Unicode.hpp"
#include "Globals & Functions/Logging.hpp"
#include "myFont.hpp"
#include "myBitmap.hpp"
#include "mySurface.hpp"
#include "Interface_Design/Interfaces.hpp"

namespace app
{
	extern int  TextToHDC(HDC hdc, int x, int y, const myFont& font, COLORREF color, LPCWSTR format, ...);
	extern void rectang(HDC hdc, RECT* rectangle, COLORREF Couleur); // Dessine un rectangle plein
}

class myLittleScore
{
	private:
	class myBitmap PetitScoreBmp;
	int	  largeur, hauteur;
	class myFont FontScore24, FontScore40, FontScore54;
	
	public:
    myLittleScore(const myLittleScore&) = delete;
	myLittleScore& operator=(const myLittleScore&) = delete;

    // Constructeur par défaut:
    myLittleScore() : largeur(0), hauteur(0) {}

    // Destructeur:
    ~myLittleScore()
    {

    }

    bool init(HDC hdc)
	{
		PetitScoreBmp.init(hdc, L"resources/PetitScore.bmp");
		PetitScoreBmp.getDimensions(largeur, hauteur);
		
		FontScore24.init  ( 24, FW_BOLD, L"Arial" );
		FontScore40.init  ( 40, FW_BOLD, L"Arial" );
		FontScore54.init  ( 54, FW_BOLD, L"Arial" );
		return true;
	}

	void display(void)
	{
		if(Show_Preview_Little_Score)
		{
			BitBlt(	Preview_Surface.getHDC(), MARGIN, MARGIN, largeur, hauteur, PetitScoreBmp.getHDC(), 0, 0, SRCCOPY );
			//StretchBlt(	Preview_Surface.getHDC(), MARGIN, MARGIN, largeur*2.5, hauteur*2.5, PetitScoreBmp.getHDC(), 0, 0, largeur, hauteur, SRCCOPY );
			
			// Writing Time On Little Score:
			if(CHRONO[TOTAL_SECONDES] < (100*60))	app::TextToHDC(Preview_Surface.getHDC(), 240,  80, FontScore24, Blanc, Time);
			else									app::TextToHDC(Preview_Surface.getHDC(), 233,  80, FontScore24, Blanc, Time);
			
			//Writting Local Team Goals:
			if(GOALS[LOCALS_PREVIEW] > 9)	app::TextToHDC(Preview_Surface.getHDC(), 182, 21, FontScore40, Noir, LOCALS_PREVIEW_STRING);
			else 							app::TextToHDC(Preview_Surface.getHDC(), 188, 14, FontScore54, Noir, LOCALS_PREVIEW_STRING);
			
			if(GOALS[VISITORS_PREVIEW] > 9)	app::TextToHDC(Preview_Surface.getHDC(), 182, 65, FontScore40, Noir, VISITORS_PREVIEW_STRING);
			else							app::TextToHDC(Preview_Surface.getHDC(), 188, 58, FontScore54, Noir, VISITORS_PREVIEW_STRING);
		}
		else
		{
			RECT rect = {MARGIN, MARGIN, MARGIN+largeur, MARGIN+hauteur };
			app::rectang(Preview_Surface.getHDC(), &rect, Noir);
		}
		
		if(Show_Program_Little_Score)
		{
			BitBlt(	Program_Surface.getHDC(), MARGIN, MARGIN, largeur, hauteur, PetitScoreBmp.getHDC(), 0, 0, SRCCOPY );
			
			if(CHRONO[TOTAL_SECONDES] < (100*60))	app::TextToHDC(Program_Surface.getHDC(), 240, 80, FontScore24, Blanc, Time);
			else									app::TextToHDC(Program_Surface.getHDC(), 233, 80, FontScore24, Blanc, Time);

			if(GOALS[LOCALS] > 9)	app::TextToHDC(Program_Surface.getHDC(), 182, 21, FontScore40, Noir, LOCALS_GOALS_STRING);
			else 					app::TextToHDC(Program_Surface.getHDC(), 188, 14, FontScore54, Noir, LOCALS_GOALS_STRING);
			
			if(GOALS[VISITORS] > 9)	app::TextToHDC(Program_Surface.getHDC(), 182, 65, FontScore40, Noir, VISITORS_GOALS_STRING);
			else					app::TextToHDC(Program_Surface.getHDC(), 188, 58, FontScore54, Noir, VISITORS_GOALS_STRING);
		}
		else
		{
			RECT rect = {MARGIN, MARGIN, MARGIN+largeur, MARGIN+hauteur };
			app::rectang(Program_Surface.getHDC(), &rect, Noir);
		}

		return;
	}
};
