//														file: Interfaces.hpp version: 00
#pragma once
#include "../Globals & Functions/Unicode.hpp"
#include "../Globals & Functions/global_variables.hpp"
#include "../Globals & Functions/myFunctions.hpp"
#include "../myButtons/Boutons.hpp"
#include "../mySurface.hpp"
#include "../Teams/Teams.hpp"

extern RECT INTERFACE_RECTANGLE[NUMBER_OF_RECTANGLES];
extern void Inteface_Rect_Dimensions(int id, RECT& rect);
extern void Show_Or_Hide_Page( int ID_of_the_page, int Show_or_Hide );
extern void Show_Interface(int interface_id, bool Visibility);
extern void Calculate_Interface(int interface_id);
extern void Calculate_Main_Interface(void);
extern void Calculate_Teams_Interface();
