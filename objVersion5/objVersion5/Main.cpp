#include "string.h"
#include <stdio.h>
#include "obj.h"


void main()
{
	// Calls all functions
	obj v;
	v.vCount();
	v.vtCount();
	v.vnCount();

	v.vector();
	v.vectorText();
	v.vectorNorm();

	v.vectorFaces();
	v.materialObj();
	v.otherMaterialObj();
	/*v.kdCount();
	v.kaCount();
	v.tfCount();
	v.niCount();


	v.kdMaterial();*/


}