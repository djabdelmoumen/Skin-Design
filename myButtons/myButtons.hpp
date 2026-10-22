//														file: myButtons.hpp version: 00
#pragma once
class myButtons
{
	private:
		HWND hwnd;
		int id;
		int x;
		int y;
		int Width;
		int Height;
		//bool Default_Visible;
		bool Visible;

	public:
	// Empêcher la copie pour éviter d'avoir deux objets gérant le même HWND.
	myButtons(const myButtons&) = delete;
	myButtons& operator=(const myButtons&) = delete;

	// Constructeur par défaut:
	myButtons() : hwnd(nullptr), id(0), x(0), y(0), Width(0), Height(0) {}

    // Destructeur
    ~myButtons()
    {
        // On ne détruit pas le HWND ici car Windows le fait via le parent,
        // mais on nettoie l'objet C++.
        hwnd = nullptr;
        id = 0;
    }

    // Fonction d'initialisation - Utilise LPCWSTR pour la compatibilité ANSI/Unicode
	bool init(int ID_BOUTON, LPCWSTR lpWindowName, HWND hWndParent, int xp, int yp, int Wp, int Hp, bool visible )
	{
		if (hWndParent == nullptr)
		{
			LogErrorOut(L"[ERROR] Échec de L'initialisation du Bouton [id: %d], Paramètre HWND NULL.", ID_BOUTON);
			return false;
		}

		hwnd = CreateWindowW(
								L"BUTTON",           // Correction : "BUTTON" est la classe système correcte
								lpWindowName, 
								WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
								xp, yp, Wp, Hp,
								hWndParent,
								(HMENU)(INT_PTR)ID_BOUTON, // Cast plus sûr pour les architectures
								GetModuleHandle(NULL),
								NULL
							);
		
		if (!hwnd)
		{
			app::myGetLastErrorFromWindow();
			return false;
		}

		id = ID_BOUTON;
		x = xp; y = yp; Width = Wp; Height = Hp;            
		
		Visible = visible;
		ShowWindow(hwnd, Visible ? SW_SHOW : SW_HIDE);
		return true;
	}

	// Getters
	HWND getHWND()		 const { return hwnd; }
	int  getID()		 const { return id; }
	bool estInitialise() const { return (hwnd != nullptr); }

	// Dimensions et Position:
	bool getDimensions(int& largeur, int& hauteur) const
	{
		if (!hwnd) return false;
		largeur = Width;
		hauteur = Height;
		return true;
	}

	bool getPosition(int& xPos, int& yPos) const
	{
		if (!hwnd) return false;
		xPos = x;
		yPos = y;
		return true;
	}

	// Affichage
	void Show(bool visible = TRUE) { if (hwnd) { Visible = visible; ShowWindow(hwnd, visible ? SW_SHOW : SW_HIDE); } }
	
	void ForceToHide(void) { if (hwnd) ShowWindow(hwnd, SW_HIDE); }
	
	void isShow(void) { if (hwnd) { ShowWindow(hwnd, Visible ? SW_SHOW : SW_HIDE); } }

    void Hide(bool hide = TRUE) { if (hwnd) { Visible = !hide; ShowWindow(hwnd, Visible ? SW_SHOW : SW_HIDE); } }
    
    // État
    void Enable(bool enabled = true)
    {
        if (hwnd) {
            EnableWindow(hwnd, enabled ? TRUE : FALSE);
        }
    }
    
    // Texte - Utilise LPCWSTR et TString
    void SetText(LPCWSTR texte)
    {
        if (hwnd && texte) {
            SetWindowText(hwnd, texte);
        }
    }
    
    std::wstring GetText()
    {
        if (!hwnd) return L"";

        int len = GetWindowTextLength(hwnd);
        if (len == 0) return L"";

        // Utilisation de TCHAR pour le buffer interne
        std::vector<TCHAR> buffer(len + 1);
        GetWindowText(hwnd, buffer.data(), len + 1);
        
        return std::wstring(buffer.data());
	}

	// Géométrie
	void Resize(int newWidth, int newHeight)
	{
		if(hwnd)
		{
			SetWindowPos(hwnd, NULL, 0, 0, newWidth, newHeight, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
			Width = newWidth;
			Height = newHeight;
		}
	}

	void Move(int newX, int newY)
	{
		if (hwnd)
		{
			SetWindowPos(hwnd, NULL, newX, newY, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
			x = newX;
			y = newY;
		}
	}

    // Destruction manuelle:
    void Destroy()
    {
		if (hwnd)
		{
			DestroyWindow(hwnd);
			hwnd = nullptr;
			id = 0;
		}
	}
};