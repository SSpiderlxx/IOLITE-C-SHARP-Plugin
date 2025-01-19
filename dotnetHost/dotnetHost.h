// dotnetHost.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>
#include <thread>
#include <vector>


// dotnet host headers
#include "inc/coreclr_delegates.h"
#include "inc/hostfxr.h"
#include "inc/nethost.h"

//Iolite headers
#include "inc/iolite_api.h"

#ifdef _WIN32
#include <Windows.h>  // For HMODULE and LoadLibraryA
#define STR(s) L ## s
#define CH(c) L ## c
#define DIR_SEPARATOR L'\\'

#define string_compare wcscmp
#else
#include <dlfcn.h>    // For dlopen on Linux/macOS
#include <limits.h>
#define STR(s) s
#define CH(c) c
#define DIR_SEPARATOR '/'
#define MAX_PATH PATH_MAX

#define string_compare strcmp
#endif

// TODO: Reference additional headers your program requires here.
