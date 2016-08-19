// ExampleObject.h

#ifdef EXAMPLE_OBJECT
#define EXAMPLE_OBJECT_DEC __declspec(dllexport)
#else
#define EXAMPLE_OBJECT_DEC __declspec(dllimport)
#endif

#ifndef EXAMPLE_OBJECT_H
#define EXAMPLE_OBJECT_H

#ifdef __cplusplus
extern "C"
{
#endif

	EXAMPLE_OBJECT_DEC typedef struct ExampleStruct
	{
		ExampleStruct() //default initializer
			: Number(0), Message("") { }

		int Number;
		char* Message;
	} ExampleStruct;

	//Define int returns from C# library here. Allows to easily decode them in
	//Native C/C++
	const int EXAMPLE_PRINT_SUCCESS = 0;
	const int EXAMPLE_PRINT_ERROR_NULLOREMPTY = 1;

	EXAMPLE_OBJECT_DEC int example_print(char* message); // returns int, defined above
	EXAMPLE_OBJECT_DEC void example_add(int num);
	EXAMPLE_OBJECT_DEC void example_subtract(int num);

	//Define functions that allow us to subscribe to C# events using callbacks
	EXAMPLE_OBJECT_DEC void example_subscribe_even(void(*funcPtr)(ExampleStruct));
	EXAMPLE_OBJECT_DEC void example_subscribe_odd(void(*funcPtr)(ExampleStruct));

#ifdef __cplusplus
}
#endif

#endif

