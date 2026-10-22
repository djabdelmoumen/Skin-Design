#pragma once

#include "unicode.hpp"
#define	ERROR_TEXT_SIZE 128
//********************************************************* CLASS myDebugging ********************************************************************************//
class myDebugging
{
	private:
		TCHAR ErrorText[ERROR_TEXT_SIZE];

		// Empêcher la copie:
		myDebugging(const myDebugging&) = delete;
		myDebugging& operator=(const myDebugging&) = delete;

	public:
		// Constructeur par défaut - ne fait rien (objet non initialisé)
		myDebugging()
		{
			ErrorText[0] = _T('\0');
			
			//size_t size = sizeof(TCHAR) * ERROR_TEXT_SIZE;
			//void* malloc(size);
		
		
		}

		// Destructeur - nettoie les ressources si nécessaire.
		~myDebugging()
		{
			cleanup();
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// Fonction pour formater l'erreur dans le buffer global ErrorText:
		int LogError(LPCWSTR format, ...)
		{
			va_list args;
			va_start(args, format);

				// On utilise la version générique qui respecte le mode du projet
				HRESULT hr = StringCchVPrintf(ErrorText, ARRAYSIZE(ErrorText), format, args);
				// On envoie le résultat final DIRECTEMENT au fichier
			va_end(args);

			if (SUCCEEDED(hr))
			{
				   // WritePanicLog(ErrorText);
				   return 1;
			}

			// En cas d'erreur de paramètre, on s'assure que le buffer n'est pas "sale"
			if (hr == STRSAFE_E_INVALID_PARAMETER) {
				// Optionnel : mettre une chaîne vide pour éviter d'afficher n'importe quoi
				ErrorText[0] = _T('\0');
				return 0;
			}

			if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) return 2;

			return 3; 
		}
		
		bool ErrorsExist()
		{
			if (_tcslen(ErrorText) == 0) return false;
			else return true;
		}
		
		bool ErrorsNotExist()
		{
			if (_tcslen(ErrorText) == 0) return TRUE;
			else return FALSE;
		}
		
		const TCHAR* Errors()
		{
			return ErrorText;
		}
		
		// Fonction d'initialisation - retourne bool (true = succès, false = échec)
		bool init(HDC winHDC)
		{
			// Nettoyer d'abord si déjà initialisé
			cleanup();
			

			
			return true;  // Initialisation réussie
		}
		
		// Vérifier si l'objet est initialisé (optionnel, mais peut être utile)
		bool isInitialised() const
		{
			return true;
		}
		
		// Méthode pour réinitialiser (reset avec nettoyage)
		bool reset(HDC winHDC = nullptr)
		{
			cleanup();
			
			return true;  // Reset sans réinitialisation
		}
		
	private:
		// Méthode de nettoyage commune:
		void cleanup()
		{

		}
};