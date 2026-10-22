//														file: Drawing.cpp version: 00
#include "Drawing.hpp"
void Draw_Info_Zone()
{
    // Dessin du fond de la zone:
    FillMyRectangle(Control_Surface.getHDC(), INTERFACE_RECTANGLE[INFO_ZONE], Canard);

    int Largeur = INTERFACE_RECTANGLE[INFO_ZONE].right  - INTERFACE_RECTANGLE[INFO_ZONE].left;
    int Hauteur = INTERFACE_RECTANGLE[INFO_ZONE].bottom - INTERFACE_RECTANGLE[INFO_ZONE].top;

    static WCHAR str[256];
    size_t textlength = 0;

	int x = INTERFACE_RECTANGLE[INFO_ZONE].left + MARGIN; // Utiliser le décalage de la zone.
	int y = INTERFACE_RECTANGLE[INFO_ZONE].top  + MARGIN;

    // 1. CHRONOMÈTRE
	app::TextToHDC(Control_Surface.getHDC(), x, y,	   FontStandard20, Blanc, L"Play Time: [%s]", Time);
	app::TextToHDC(Control_Surface.getHDC(), x, y+=20, FontStandard20, Blanc, L"Largeure = %02dpx, Hauteure = %02dpx", Largeur, Hauteur);

	RECT Rect;
	GetClientRect(hwnd_CONTROL, &Rect);
	int CLIENT_WIDTH_CONTROL  = Rect.right  - Rect.left;
	int CLIENT_HEIGHT_CONTROL = Rect.bottom - Rect.top;
	app::TextToHDC(Control_Surface.getHDC(), x, y+=20, FontStandard20, Blanc, L"W = %02dpx, H = %02dpx", CLIENT_WIDTH_CONTROL, CLIENT_HEIGHT_CONTROL);
	
	if ( ErrorsExist() )
	app::TextToHDC(Control_Surface.getHDC(), x, y+=20, FontStandard20, Blanc, L"[Les Erreures]:%s", GetMyLastError() );
	else
	app::TextToHDC(Control_Surface.getHDC(), x, y+=20, FontStandard20, Blanc, L"Pas d'erreures jusqu'a a ce moment!" );
	
	//app::TextToHDC(Control_Surface.getHDC(), x, y+=20, FontStandard20, Blanc, L"[Show_Preview_Little_Score]:%d", Show_Preview_Little_Score );
}