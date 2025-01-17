// dotnetHost.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdlib>

// dotnet host headers
#include "inc/coreclr_delegates.h"
#include "inc/hostfxr.h"
#include "inc/nethost.h"

#ifdef _WIN32
#include <Windows.h>  // For HMODULE and LoadLibraryA
#else
#include <dlfcn.h>    // For dlopen on Linux/macOS
#endif

// TODO: Reference additional headers your program requires here.
