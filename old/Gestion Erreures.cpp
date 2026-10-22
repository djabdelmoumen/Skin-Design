// "Gestion Erreures.cpp" Version:0

// Fonction pour formater l'erreur dans le buffer global ErrorText:
int LogErrorOut(LPCWSTR format, ...)
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
