//														file: main.cpp version:0
#include "main.hpp"

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrev, PWSTR lpCmd, int nShow) // ----- POINT D'ENTRÉE ----- //
{
	Init_Logging();
	
    // --- 1. Enregistrement de la classe "CONTROL"
    WNDCLASSW wcCtrl = {0};
    wcCtrl.lpfnWndProc   = ControlProcedure;
    wcCtrl.hInstance     = hInst;
    wcCtrl.lpszClassName = L"CtrlClass";
    wcCtrl.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1); // Gris standard
    wcCtrl.hCursor       = LoadCursor(NULL, IDC_ARROW);
    RegisterClassW(&wcCtrl);

    // --- 2. Enregistrement de la classe "PROGRAM"
    WNDCLASSW wcProg = {0};
	
	wcProg.lpfnWndProc   = ProgramProcedure;
    wcProg.hInstance     = hInst;
    wcProg.lpszClassName = L"ProgClass";
    wcProg.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // Fond noir (TV)
    wcProg.hCursor       = LoadCursor(NULL, IDC_ARROW);
    RegisterClassW(&wcProg);
	
    // --- 3. Création de la fenêtre de CONTRÔLE:
	hwnd_CONTROL = CreateWindowExW(0, L"CtrlClass", L"PANNEAU DE CONTROLE",WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,0,0,683,728, NULL, NULL, hInst, NULL);

    // --- 4. Création de la fenêtre de PROGRAMME (Sortie TV):
	hwnd_PROGRAM = CreateWindowExW(0, L"ProgClass", L"SORTIE PROGRAMME"   ,WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,683,0,683,728,NULL, NULL, hInst, NULL);

    if (!hwnd_CONTROL || !hwnd_PROGRAM) return 0;
	
	// --- 5. TESTS DE COMPATIBILITÉ ÉCRAN ---
	{
		HDC hdc1 = GetDC(hwnd_CONTROL);
		HDC hdc2 = GetDC(hwnd_PROGRAM);
		if (hdc1 && hdc2)
		{
			int bpp1 = GetDeviceCaps(hdc1, BITSPIXEL);
			int bpp2 = GetDeviceCaps(hdc2, BITSPIXEL);
			if (bpp1 != bpp2) 
			{
				LogErrorOut(L"[WARNNING] Les deux écrans ont des profondeurs de couleurs différentes (%d vs %d bpp).", bpp1, bpp2);
			}
		}
		ReleaseDC(hwnd_CONTROL, hdc1);
		ReleaseDC(hwnd_PROGRAM, hdc2);
		hdc1 = hdc2 = NULL;
	}

    ShowWindow(hwnd_CONTROL, nShow);
    ShowWindow(hwnd_PROGRAM, nShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage (&msg);
    }
    return 0;
}