//														file: Teams.hpp version: 00
#pragma once
#include "../Globals & Functions/Unicode.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt> // Pour gérer l'encodage UTF-8 si nécessaire (ou sortie texte standard)
#include "../myButtons/Boutons.hpp"

// Structure pour garder les références de chaque ligne de joueur:
	struct PlayerInput
	{
		HWND hStaticLabel; 
		HWND hEditNum;
		HWND hEditName;
	};

	#define PLAYER_COUNT 15

	// Variable globale supplémentaire pour stocker le TextBox du nom de l'équipe:
	extern HWND g_hEditTeamName;
	extern HWND g_hStaticTeamLabel;
	extern bool initialized;

	// Vecteur global pour stocker les handles des fenêtres de saisie
	extern std::vector<PlayerInput> g_playersInputs;

	extern void create_player_inputs(HWND hwnd);
	extern void Move_player_inputs(void);
	extern void destroy_player_inputs(HWND hwnd);
	extern void save_team(HWND hwnd);