# Exemple de Makefile simple:
all:
	i686-w64-mingw32-g++ \
		-DUNICODE -D_UNICODE \
		"Globals & Functions/globale_variables.cpp" \
		"Globals & Functions/Logging.cpp" \
		"Globals & Functions/myFunctions.cpp" \
		myButtons/Boutons.cpp \
		mySurface.cpp \
		myFont.cpp \
		"Draw Functions/Draw_Info_Zone.cpp" \
		"Draw Functions/two_screens.cpp" \
		"Draw Functions/Draw_Down_Section.cpp" \
		Interface_Design/Interfaces.cpp	\
		Interface_Design/Calculate_Interface.cpp \
		Interface_Design/Calculate_Main_Interface.cpp \
		"Interface_Design/Calculate_Teams_Interface.cpp" \
		Teams/Teams.cpp \
		Teams/create_player_inputs.cpp \
		Teams/destroy_player_inputs.cpp \
		Teams/save_team.cpp \
		Teams/Move_player_inputs.cpp \
		main.cpp \
		ControlProcedure.cpp \
		ProgramProcedure.cpp \
		-o ../Executable/Overlay_Reboot.exe -lgdi32 -lcomctl32 -mwindows -static -static-libgcc -municode