//														file: myFont.hpp version: 00
#pragma once
#include "Globals & Functions/Unicode.hpp"

class myFont 
{
	private:
		HFONT hFont;

	public:
		// 1. Constructeur principal : Initialise et crée la police immédiatement
		myFont(int taille, int poids = FW_NORMAL, LPCWSTR faceName = L"Arial")
		{
			hFont =	CreateFont( taille, 0, 0, 0, poids, FALSE, FALSE, FALSE,DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, 
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, 
					VARIABLE_PITCH, faceName);
		}

		// 2. Constructeur par défaut (Optionnel : si vous voulez l'initialiser plus tard)
		myFont() : hFont(NULL) {}

		// Destructeur : Nettoyage automatique
		~myFont() {
			if (hFont) {
				DeleteObject(hFont);
			}
		}
		
		HFONT init(int taille, int poids = FW_NORMAL, LPCWSTR faceName = L"Arial")
		{
			hFont =	CreateFont( taille, 0, 0, 0, poids, FALSE, FALSE, FALSE,DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, 
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, 
					VARIABLE_PITCH, faceName);
					return hFont;
		}

		// Empêcher la copie (pour éviter de supprimer deux fois le même handle GDI)
		myFont(const myFont&) = delete;
		myFont& operator=(const myFont&) = delete;

		// Accesseur
		HFONT getHandle() const { return hFont; }
};

	// Fonts:
	extern myFont FontStandard12;
	extern myFont FontStandard20;