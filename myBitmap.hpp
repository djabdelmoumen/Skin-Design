#pragma once
#include "Globals & Functions/Unicode.hpp"

namespace app 
{
	extern void myGetLastErrorFromWindow(void);
}

//********************************************************* CLASS myBitmap ********************************************************************************//
class myBitmap
{
	private:
		HDC hdc;
		HBITMAP hBitmap;        // Corrigé: HBitmap -> hBitmap (cohérence)
		HGDIOBJ oldHbmp;
		
		// Empêcher la copie
		myBitmap(const myBitmap&) = delete;
		myBitmap& operator=(const myBitmap&) = delete;
		
	public:
		// Constructeur par défaut - ne fait rien (objet non initialisé)
		myBitmap() : hdc(nullptr), hBitmap(nullptr), oldHbmp(nullptr)  // Corrigé
		{
		}
		
		// Destructeur - nettoie les ressources si nécessaire
		~myBitmap()
		{
			cleanup();
		}
		
		// Fonction d'initialisation - retourne bool (true = succès, false = échec)
		bool init(HDC winHDC, const TCHAR* bmp_path)
		{
			// Nettoyer d'abord si déjà initialisé
			cleanup();
			
			if (winHDC == nullptr)
			{
				//OutPutError(_T("HWND parameter is nullptr"));
				LogErrorOut(L"[ERROR] HWND parameter is nullptr");
				return false;
			}
			
			// 1. Charger la bitmap
			hBitmap = (HBITMAP)LoadImage(NULL, bmp_path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			if (hBitmap == nullptr)
			{
				app::myGetLastErrorFromWindow();
				return false;
			}
		
			// 2. Créer un DC compatible
			hdc = CreateCompatibleDC(winHDC);
			if (hdc == nullptr) 
			{
				app::myGetLastErrorFromWindow();
				bool res = DeleteObject(hBitmap);  // Nettoyer la bitmap si échec.
				if(!res) app::myGetLastErrorFromWindow();
				hBitmap = nullptr;
				return false;
			}		
		
			// 3. Sélectionner la bitmap dans le DC
			oldHbmp = SelectObject(hdc, hBitmap);
			if (oldHbmp == nullptr || oldHbmp == HGDI_ERROR) 
			{
				app::myGetLastErrorFromWindow();
				bool res = DeleteDC(hdc);
				if(!res) app::myGetLastErrorFromWindow();
				res = DeleteObject(hBitmap);
				if(!res) app::myGetLastErrorFromWindow();
				hdc = NULL;
				hBitmap = NULL;
				return false;
			}
			return true;  // Initialisation réussie
		}
		
		// Getter pour le HDC
		HDC getHDC() const
		{
			return hdc;
		}
		
		// Getter pour le HBITMAP (optionnel mais utile)
		HBITMAP getHBITMAP() const
		{
			return hBitmap;
		}
		
		// Vérifier si l'objet est initialisé
		bool isInitialise() const
		{
			return (hdc != nullptr && hBitmap != nullptr && oldHbmp != nullptr);  // Corrigé
		}
		
		// Obtenir les dimensions de la bitmap
		bool getDimensions(int& largeur, int& hauteur) const
		{
			if (hBitmap == nullptr)
				return false;
				
			BITMAP bmp;
			if (GetObject(hBitmap, sizeof(BITMAP), &bmp)) {
				largeur = bmp.bmWidth;
				hauteur = bmp.bmHeight;
				return true;
			}
			return false;
		}
		
		// Méthode pour réinitialiser (reset avec nettoyage)
		bool reset(HDC winHDC, const WCHAR* bmp_path = nullptr)  // Ajout du paramètre
		{
			cleanup();
			
			if (winHDC != nullptr && bmp_path != nullptr) {
				return init(winHDC, bmp_path);
			}
			
			return true;  // Reset sans réinitialisation
		}
		
	private:
		// Méthode de nettoyage commune:
		void cleanup()
		{
			if (hdc != nullptr) {
				// Restaurer l'ancienne bitmap si nécessaire
				if (oldHbmp != nullptr) {
					SelectObject(hdc, oldHbmp);
					oldHbmp = nullptr;
				}
				
				DeleteDC(hdc);
				hdc = nullptr;
			}
			
			// Supprimer la bitmap
			if (hBitmap != nullptr) {
				DeleteObject(hBitmap);
				hBitmap = nullptr;
			}
		}
};
