#include "global_variables.hpp"

	// Windows Handles:
	HWND hwnd_CONTROL = NULL;
	HWND hwnd_PROGRAM = NULL;
	
	// TAGS:
	bool Show_Preview_Little_Score  = false;
	bool Show_Preview_Big_Score 	= false;
    bool Show_Program_Little_Score  = false;
	bool Show_Program_Big_Score		= false;
	
	// Chronomètre:
	bool Chrono_Active = true;
	int  CHRONO[3] = { 0, 0, 0 };
	WCHAR Time[7] = {TEXT("00:00")};
	
	// Score:
	int   GOALS[4] = { 0, 0, 0, 0 };
	WCHAR LOCALS_PREVIEW_STRING   [3] = { L"0" };
	WCHAR LOCALS_GOALS_STRING     [3] = { L"0" };
	WCHAR VISITORS_PREVIEW_STRING [3] = { L"0" };
	WCHAR VISITORS_GOALS_STRING   [3] = { L"0" };