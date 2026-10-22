//														file: two_screens.cpp version: 00
#include "Drawing.hpp"
bool two_screens()
{
		int Largeur = INTERFACE_RECTANGLE[PREVIEW_SCREEN].right  - INTERFACE_RECTANGLE[PREVIEW_SCREEN].left; // la largeure des rectangles screen
		int Hauteur = INTERFACE_RECTANGLE[PREVIEW_SCREEN].bottom - INTERFACE_RECTANGLE[PREVIEW_SCREEN].top;  // la Hauteur  des rectangles screen

		SetStretchBltMode(Control_Surface.getHDC(), HALFTONE);
		SetBrushOrgEx(Control_Surface.getHDC(), 0, 0, NULL);

		StretchBlt(	Control_Surface.getHDC(), INTERFACE_RECTANGLE[PREVIEW_SCREEN].left, INTERFACE_RECTANGLE[PREVIEW_SCREEN].top, Largeur, Hauteur,
					Preview_Surface.getHDC(), 0, 0, HD1366, HD768, SRCCOPY );

		StretchBlt(	Control_Surface.getHDC(), INTERFACE_RECTANGLE[PROGRAM_SCREEN].left, INTERFACE_RECTANGLE[PROGRAM_SCREEN].top, Largeur, Hauteur,
					Program_Surface.getHDC(), 0, 0, HD1366, HD768, SRCCOPY );

		return true;
}