#include "obj.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


obj::obj()
{
	// Setting a count to 0 for when the file reads in the numbers
	vCounter = 0;
	vtCounter = 0;
	vnCounter = 0;

}


int obj::vCount(void)
{
	// Open the file
	FILE *fp;

	fp = fopen("myObjFile2.obj", "r");

	if (fp == NULL)
		return 0;;

	char buffer[64];

	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		// This finds the letter "v" in the file 
		if (strcmp(buffer, "v") == 0)
		{
			// vCounter is incremented to output the correct value
			vCounter++;
		}

	};

	// Prints out value
	printf("Number of Verticies: %d\n", vCounter);
	fclose(fp);
	return vCounter;
}

int obj::vtCount(void)
{
	FILE *fp;

	fp = fopen("myObjFile2.obj", "r");
	char buffer[64];
	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		// This finds the letter "vt" in the file 
		if (strcmp(buffer, "vt") == 0)
		{
			vtCounter++;
		}

	};

	printf("Number of Texture Coords: %d\n", vtCounter);
	fclose(fp);
	return vtCounter;
}

int obj::vnCount(void)
{
	FILE *fp;

	fp = fopen("myObjFile2.obj", "r");
	char buffer[64];
	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		// This finds the letter "vn" in the file 
		if (strcmp(buffer, "vn") == 0)
		{
			vnCounter++;
		}

	};
	printf("Number of Vertex Normals: %d\n", vnCounter);
	fclose(fp);
	return vnCounter;
}

int obj::vector(void)
{

	FILE *fp;
	fp = fopen("myObjFile2.obj", "r");
	char buffer[64];
	int i = 0;
	sVertArray = new sVert[vCounter];

	// Rewind restarts the file from the beginning
	rewind(fp);

	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		if (strcmp(buffer, "v") == 0)
		{
			// This will output the numbers into each array
			fscanf(fp, "%f%f%f", &sVertArray[i].x, &sVertArray[i].y, &sVertArray[i].z);
			i++;
		}
	}

	for (int i = 0; i < vCounter; i++)
	{
		// Prints the arrays
		printf("Vertex Stucture: %f %f %f \n", sVertArray[i].x, sVertArray[i].y, sVertArray[i].z);

	}

	fclose(fp);
	return 0;

}

int obj::vectorText(void)
{
	FILE *fp;
	fp = fopen("myObjFile2.obj", "r");
	char buffer[64];
	int j = 0;
	sTextCoordsArray = new sTextCoords[vtCounter];

	rewind(fp);

	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		if (strcmp(buffer, "vt") == 0)
		{
			fscanf(fp, "%f%f", &sTextCoordsArray[j].x, &sTextCoordsArray[j].y);
			j++;
		}
	}

	for (int i = 0; i < vtCounter; i++)
	{
		printf("Text Coords Stucture: %f %f \n", sTextCoordsArray[i].x, sTextCoordsArray[i].y);

	}

	fclose(fp);
	return 0;
}

int obj::vectorNorm(void)
{
	FILE *fp;
	fp = fopen("myObjFile2.obj", "r");
	char buffer[64];
	int k = 0;
	sNormArray = new sNorm[vnCounter];

	rewind(fp);

	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		if (strcmp(buffer, "vn") == 0)
		{
			fscanf(fp, "%f%f%f", &sNormArray[k].x, &sNormArray[k].y, &sNormArray[k].z);
			k++;
		}
	}

	for (int i = 0; i < vnCounter; i++)
	{
		printf("Normal Stucture: %f %f %f \n", sNormArray[i].x, sNormArray[i].y, sNormArray[i].z);

	}

	fclose(fp);
	return 0;

}

int obj::vectorFaces(void)
{
	//int i;
	//FILE *fp;
	//fp = fopen("myObjFile2.obj", "r");
	//char newString[] = "1/2/3";
	//char *f;
	//scanf("%s", newString);
	////	f = strtok(newString "/");
	//f = strtok(NULL, "/");

	//
	//i = atoi(0);
	//printf("Faces: %s", i);

	//fclose(fp);
	return 0;


}

int obj::materialObj(void)
{
	// Opens material file
	FILE *m;

	m = fopen("myObjFile2.mtl", "r");

	if (m == NULL)
		return 0;

	char mbuffer[10];


	while (!feof(m))
	{
		fscanf(m, "%s", &mbuffer);
		// This finds the words "newmtl"
		if (strcmp(mbuffer, "newmtl") == 0)
			fscanf(m, "%s", &example.materialName);

	}
	printf("Material Name: %s \n ", example.materialName);

	rewind(m);
	char Kdbuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &Kdbuffer);
		if (strcmp(Kdbuffer, "Kd") == 0)
			// Outputs RGB
			fscanf(m, "%f %f %f", &example.r, &example.g, &example.b);

	}
	printf("Kd : %f %f %f \n ", example.r, example.g, example.b);

	rewind(m);
	char kabuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &kabuffer);
		if (strcmp(kabuffer, "Ka") == 0)
			fscanf(m, "%f %f %f", &example.r, &example.g, &example.b);

	}
	printf("Ka : %f %f %f \n ", example.r, example.g, example.b);

	rewind(m);
	char tfbuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &tfbuffer);
		if (strcmp(tfbuffer, "Tf") == 0)
			fscanf(m, "%f %f %f", &example.r, &example.g, &example.b);

	}
	printf("Tf : %f %f %f \n ", example.r, example.g, example.b);

	fclose(m);
}

int obj::otherMaterialObj(void)
{
	FILE *m;

	m = fopen("myObjFile2.mtl", "r");

	if (m == NULL)
		return 0;

	char mbuffer[10];


	while (!feof(m))
	{
		fscanf(m, "%s", &mbuffer);
		if (strcmp(mbuffer, "newmtl") == 0)
			fscanf(m, "%s", &temp.materialName);

	}
	printf("Material Name: %s \n ", temp.materialName);

	rewind(m);
	char Kdbuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &Kdbuffer);
		if (strcmp(Kdbuffer, "Kd") == 0)
			fscanf(m, "%f %f %f", &temp.r, &temp.g, &temp.b);

	}
	printf("Kd : %f %f %f \n ", temp.r, temp.g, temp.b);

	rewind(m);
	char kabuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &kabuffer);
		if (strcmp(kabuffer, "Ka") == 0)
			fscanf(m, "%f %f %f", &temp.r, &temp.g, &temp.b);

	}
	printf("Ka : %f %f %f \n ", temp.r, temp.g, temp.b);

	rewind(m);
	char tfbuffer[14];
	while (!feof(m))
	{
		fscanf(m, "%s", &tfbuffer);
		if (strcmp(tfbuffer, "Tf") == 0)
			fscanf(m, "%f %f %f", &temp.r, &temp.g, &temp.b);

	}
	printf("Tf : %f %f %f \n ", temp.r, temp.g, temp.b);



	fclose(m);
}



obj::~obj()
{
}
