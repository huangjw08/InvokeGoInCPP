#include <Windows.h>
#include <stdio.h>
#include "godll.h"

typedef GoInt(*funcPtrWriteData)(GoSlice p0);

int main() {
	HMODULE h = LoadLibraryA("godll.dll");

	if (NULL == h || INVALID_HANDLE_VALUE == h)
	{
		return -1;
	}

	funcPtrWriteData pfWriteData = (funcPtrWriteData)GetProcAddress(h, "WriteData");


	if (pfWriteData)
	{
		/* LargeStruct ls;

		ls.ID = "100001";

		ls.Name = "Peter";

		Pet pet;

		pet.Type = "Dog";

		pet.Name = "WangCai";

		pet.Age = 5;

		ls.Pets.push_back(pet);*/

		GoString go_string[6];
		for (int i=0;i<6;i++)
		{
			go_string[i].p = "nice";
			go_string[i].n = strlen("nice");
		}

		GoSlice p0 = { go_string,6,6};

		//p0.data = "";  //serial ls to binary
		//

		//p0.len = p0.cap = 0;  //binary len

		pfWriteData(p0);
	}
	
	FreeLibrary(h);

	system("pause");
	return 0;

}