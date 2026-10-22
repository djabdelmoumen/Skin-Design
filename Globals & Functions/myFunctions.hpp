//														file: myFunctions.hpp version: 00
#pragma once
#include "../Globals & Functions/Unicode.hpp"
#include <fstream>
#include <chrono>
#include <iomanip>
#include "../Globals & Functions/global_variables.hpp"
#include "../Globals & Functions/Logging.hpp"
#include "../myFont.hpp"
	
	extern void FillMyRectangle(HDC hdc, RECT& rectangle, COLORREF Couleur);
	
	namespace app
	{
		extern int	TextToHDC(HDC hdc, int x, int y, const myFont& font, COLORREF color, LPCWSTR format, ...);
		extern void rectang(HDC hdc, RECT* rectangle, COLORREF Couleur); // Dessine un rectangle plein
		extern void myGetLastErrorFromWindow(void);
	}
