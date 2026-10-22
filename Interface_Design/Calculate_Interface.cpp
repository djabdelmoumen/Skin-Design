#include "Interfaces.hpp"

void Calculate_Interface(int interface_id)
{
	switch(interface_id)
	{
		case MAIN_INTERFACE:
			Calculate_Main_Interface ();
		break;
		case TEAMS_INTERFACE:
			Calculate_Teams_Interface();
		break;
		default:
		
		break;
	}
	return;
}