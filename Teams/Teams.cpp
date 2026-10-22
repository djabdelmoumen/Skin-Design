//														file: Teams.cpp version: 00
#include "Teams.hpp"

	// Variable globale supplémentaire pour stocker le TextBox du nom de l'équipe
	HWND g_hEditTeamName = NULL;
	HWND g_hStaticTeamLabel = NULL;
	bool initialized = FALSE;
	
	// Vecteur global pour stocker les handles des fenêtres de saisie
	std::vector<PlayerInput> g_playersInputs;