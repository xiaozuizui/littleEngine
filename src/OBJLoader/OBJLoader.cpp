// OBJLoader.cpp : Defines the exported functions for the DLL.
//

#include "OBJLoader.h"
#include <ostream>
#include <iostream>


// This is an example of an exported variable
OBJLOADER_API int nOBJLoader=0;

// This is an example of an exported function.
OBJLOADER_API int fnOBJLoader(void)
{
    return 0;
}




extern"C"  OBJLOADER_API WaveOBJ LoadWaveOBJ(std::string name, std::string basepath)
{
	WaveOBJ obj;
	std::string warn;
	std::string err;
	bool ret = tinyobj::LoadObj(&obj.attrib, &obj.shapes, &obj.materials, &warn, &err, name.c_str(),
		basepath.c_str(), true);

	if (!warn.empty()) {
		std::cout << "WARN: " << warn << std::endl;
	}

	if (!err.empty()) {
		std::cerr << "ERR: " << err << std::endl;
	}

	if (!ret) {
		printf("Failed to load/parse .obj.\n");
		return obj;
	}
	else
	{
		return obj;
	}

}
