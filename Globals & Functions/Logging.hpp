//														File: Logging.hpp version: 00
#pragma once
#include "Unicode.hpp"
#include <strsafe.h>
#include <cstdarg>
#include <vector>

#define ERROR_TEXT_SIZE 128

// Codes de retour:
#define SUCCESS             0
#define INVALID_PARAMETER   1
#define OVER_BUFFER         2
#define UNKNOWN_ERROR       3
#define TRUNKED_BUFFER      4

extern void Init_Logging(void);
extern int LogErrorOut(LPCWSTR format, ...);
extern std::wstring GetMyLastError(void);
extern bool ErrorsExist(void);