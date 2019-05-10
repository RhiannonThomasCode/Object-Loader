#pragma once
class obj
	// Structs are created to contain data
{
	struct sVert {
		float x, y, z;
	};


	struct sTextCoords {
		float x, y;
	};

	struct sNorm {
		float x, y, z;

	};

	struct sFaces {
		char newString[32];

		int v;
		int vt;
		int vn;

	};

	struct materials {
		char materialName[32];
		float r, g, b;
	};

private:

	int vCounter;
	int vtCounter;
	int vnCounter;
	/*char kdCounter;
	char kaCounter;
	char tfCounter;
	char niCounter;*/

public:
	obj();
	int vCount();
	int vtCount();
	int vnCount();
	// Creating a struct variable 
	materials example;
	materials temp;
	sVert *sVertArray;
	sTextCoords *sTextCoordsArray;
	sNorm *sNormArray;
	int vector();
	int vectorText();
	int vectorNorm();
	int vectorFaces();
	int materialObj();
	int otherMaterialObj();
	/*int kdMaterial();
	int kdCount();*/
	//int kaCount();
	//int tfCount();
	//int niCount();
	/*sMaterials *kdArray;
	sMaterials *kaArray;
	sMaterials *tfArray;
	sMaterials *niArray;
	char getkdCounter();*/

	~obj();



};


