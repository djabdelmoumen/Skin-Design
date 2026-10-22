//														file: destroy_player_inputs.cpp version: 00
#include "Teams.hpp"

// ==========================================
// 2. Fonction de destruction de toutes les fenêtres
// ==========================================
void destroy_player_inputs(HWND hwnd) 
{
	if(initialized == false) return;
    initialized = false;
	
    // Nettoyer le champ du nom de l'équipe
    if (g_hStaticTeamLabel && IsWindow(g_hStaticTeamLabel)) {
        DestroyWindow(g_hStaticTeamLabel);
        g_hStaticTeamLabel = NULL;
    }
    if (g_hEditTeamName && IsWindow(g_hEditTeamName)) {
        DestroyWindow(g_hEditTeamName);
        g_hEditTeamName = NULL;
    }

    // Nettoyer les joueurs
    for (const auto& player : g_playersInputs) {
        if (player.hStaticLabel && IsWindow(player.hStaticLabel)) {
            DestroyWindow(player.hStaticLabel);
        }
        if (player.hEditNum && IsWindow(player.hEditNum)) {
            DestroyWindow(player.hEditNum);
        }
        if (player.hEditName && IsWindow(player.hEditName)) {
            DestroyWindow(player.hEditName);
        }
    }
    
    g_playersInputs.clear();
	BOUTTON[ID_BTN_SAVE_TEAM].Hide();
}