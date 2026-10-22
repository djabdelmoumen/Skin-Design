//														file: ProgramProcedure.cpp version:0
#include "ProgramProcedure.hpp"

// --- LOGIQUE DE LA FENÊTRE PROGRAMME (TV) ---
LRESULT CALLBACK ProgramProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			hwnd_PROGRAM = hwnd;
		}
		return 0;

		case WM_SIZE:
		{
			RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
		}

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			RECT fullRect = {0, 0, HD1366, HD768};
            BitBlt(hdc, 0, 0, HD1366, HD768, Program_Surface.getHDC(), 0, 0, SRCCOPY);
			EndPaint(hwnd, &ps);			
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}