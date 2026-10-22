#pragma once

#ifndef UNICODE // 1. Définition des modes (AVANT les includes)
    #define UNICODE
#endif
#ifndef _UNICODE
    #define _UNICODE
#endif

// 2. Headers Standard C/C++
#include <string>
#include <memory>
#include <cstdio>
#include <cstdarg>
#include <vector>

// 3. Headers Windows et TCHAR
#include <windows.h>
#include <strsafe.h>

// Vérification de la configuration:
#if !defined(UNICODE) || !defined(_UNICODE)
    #error "Attention: UNICODE ou _UNICODE n'est pas défini correctement !"
#endif