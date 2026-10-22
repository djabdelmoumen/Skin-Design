//														file: mySurface.hpp version: 00
#pragma once
#include "Globals & Functions/Unicode.hpp"
#include "Globals & Functions/global_variables.hpp"
//********************************************************* CLASS mySurface ********************************************************************************//

class mySurface
	{
	private:
		HDC hdc;
		HBITMAP hbmp;
		HGDIOBJ oldHbmp;
		
		// Empêcher la copie
		mySurface(const mySurface&) = delete;
		mySurface& operator=(const mySurface&) = delete;
		
	public:
		// Constructeur par défaut - ne fait rien (objet non initialisé)
		mySurface() : hdc(nullptr), hbmp(nullptr), oldHbmp(nullptr)
		{
		}
		
		// Destructeur - nettoie les ressources si nécessaire
		~mySurface()
		{
			cleanup();
		}
		
		// Fonction d'initialisation - retourne bool (true = succès, false = échec)
		bool init(HDC winHDC)
		{
			// Nettoyer d'abord si déjà initialisé
			cleanup();
			
			if (winHDC == nullptr) return false;

			hdc = CreateCompatibleDC(winHDC);
			if (hdc == nullptr) return false;
				
			hbmp = CreateCompatibleBitmap(winHDC, HD1366, HD768);
			if (hbmp == nullptr)
			{
				DeleteDC(hdc);
				hdc = nullptr;
				return false;
			}
			
			oldHbmp = SelectObject(hdc, hbmp);
			if (oldHbmp == nullptr || oldHbmp == HGDI_ERROR) {
				DeleteObject(hbmp);
				DeleteDC(hdc);
				hdc = nullptr;
				hbmp = nullptr;
				return false;
			}
			
			return true;  // Initialisation réussie
		}
		
		// Getter pour le HDC
		HDC getHDC() const
		{
			return hdc;
		}
		
		void getDimensions(int& W, int& H)
		{
			W = HD1366;
			H = HD768;			
		}
		
		// Vérifier si l'objet est initialisé (optionnel, mais peut être utile)
		bool isInitialised() const
		{
			return (hdc != nullptr && hbmp != nullptr && oldHbmp != nullptr);
		}
		
		// Méthode pour réinitialiser (reset avec nettoyage)
		bool reset(HDC winHDC = nullptr)
		{
			cleanup();
			
			if (winHDC != nullptr) {
				return init(winHDC);  // Réutilisation de init
			}
			
			return true;  // Reset sans réinitialisation
		}
		
	private:
		// Méthode de nettoyage commune:
		void cleanup()
		{
			if (hdc != nullptr) {
				if (oldHbmp != nullptr) {
					SelectObject(hdc, oldHbmp);
					oldHbmp = nullptr;
				}
				
				if (hbmp != nullptr) {
					DeleteObject(hbmp);
					hbmp = nullptr;
				}
				
				DeleteDC(hdc);
				hdc = nullptr;
			}
		}
};

    // mySurface:
    extern class mySurface Preview_Surface;
    extern class mySurface Program_Surface;
    extern class mySurface Control_Surface;

