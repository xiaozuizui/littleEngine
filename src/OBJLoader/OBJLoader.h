// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the OBJLOADER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// OBJLOADER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef OBJLOADER_EXPORTS
#define OBJLOADER_API __declspec(dllexport)
#else
#define OBJLOADER_API __declspec(dllimport)
#endif
#include <string>
#include "tiny_obj_loader.h"

// This class is exported from the dll
 class OBJLOADER_API WaveOBJ {
public:
	WaveOBJ(void)
	{
		
	}

	~WaveOBJ()
	{

	}

	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	// TODO: add your methods here.
};


extern"C" OBJLOADER_API WaveOBJ LoadWaveOBJ(std::string name,std::string basepath);
