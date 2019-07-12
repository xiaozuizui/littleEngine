#pragma once

#ifdef RENDERDLL_EXPORTS
#define RENDERDLL_API __declspec(dllexport)
#else
#define RENDERDLL_API __declspec(dllimport)
#endif
#include <string>
#include <windows.h>



extern"C"  RENDERDLL_API bool InitModelViewer(HWND hwnd, int w, int h);
extern"C"  RENDERDLL_API bool LoadObj(char* name);
extern"C"  RENDERDLL_API int testADD(int a, int b)
{
	return a + b;
}
extern"C" void RENDERDLL_API Prasent();