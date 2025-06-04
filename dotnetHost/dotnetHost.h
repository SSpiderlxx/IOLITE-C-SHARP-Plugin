// dotnetHost.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring> // Use C++ header for string functions
#include <cstdio>
#include <cstdint>
#include <cassert>
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
#include <windows.h>  // For HMODULE and LoadLibraryW
#else
#include <dlfcn.h>    // For dlopen on Linux/macOS
#include <limits.h>
#endif

// TODO: Reference additional headers your program requires here.
