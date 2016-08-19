#include <vcclr.h>
#include "ExampleObj.h"

using namespace CSharpLibrary;
using namespace System;
using namespace System::Runtime::InteropServices;

gcroot<ExampleObject^> exampleObject = gcnew ExampleObject();
void(*evenNumberOccurred)(ExampleStruct);
void(*oddNumberOccurred)(ExampleStruct);

char* convertString(String^ str)
{
	char* converted = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	return converted;
}

ExampleStruct getStruct(Object^ obj, EventArgs^ args)
{
	ExampleObject^ castedObj = safe_cast<ExampleObject^>(obj);
	CustomArgs^ castedArgs = safe_cast<CustomArgs^>(args);
	ExampleStruct exStruct;

	exStruct.Number = castedObj->CurrentInt;
	exStruct.Message = convertString(castedArgs->Message);
	return exStruct;
}

void evenNumberUpdate(Object^ obj, EventArgs^ args)
{
	evenNumberOccurred(getStruct(obj, args));
}

void oddNumberUpdate(Object^ obj, EventArgs^ args)
{
	oddNumberOccurred(getStruct(obj, args));
}

EXAMPLE_OBJECT_DEC int example_print(char* message)
{
	return exampleObject->Print(gcnew String(message));
}

EXAMPLE_OBJECT_DEC void example_add(int num)
{
	exampleObject->Add(num);
}

EXAMPLE_OBJECT_DEC void example_subtract(int num)
{
	exampleObject->Subtract(num);
}

EXAMPLE_OBJECT_DEC void example_subscribe_even(void(*funcPtr)(ExampleStruct))
{
	evenNumberOccurred = funcPtr;
	exampleObject->EvenNumberAchieved += gcnew EventHandler(&evenNumberUpdate);
}

EXAMPLE_OBJECT_DEC void example_subscribe_odd(void(*funcPtr)(ExampleStruct))
{
	oddNumberOccurred = funcPtr;
	exampleObject->OddNumberAchieved += gcnew EventHandler(&oddNumberUpdate);
}