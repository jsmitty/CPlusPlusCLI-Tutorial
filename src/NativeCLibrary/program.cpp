// program.cpp

#include <iostream>
#include <ExampleObj.h>

using namespace std;

void displayWhenOddNumberOccurs(ExampleStruct exStruct)
{
	cout << "Number: " << exStruct.Number << ", Message: " << exStruct.Message << endl;
}

void displayWhenEvenNumberOccurs(ExampleStruct exStruct)
{
	cout << "Number: " << exStruct.Number << ", Message: " << exStruct.Message << endl;
}

int main()
{
	// initiate application at the beginning, subscribe to your events with the functions
	// we wrote above.
	example_subscribe_even(&displayWhenEvenNumberOccurs);
	example_subscribe_odd(&displayWhenOddNumberOccurs);

	int result = example_print("Print this through C# Library...");

	if (result == EXAMPLE_PRINT_SUCCESS)
		cout << "Result was successful, so it's equal to 'EXAMPLE_PRINT_SUCCESS'" << endl;

	result = example_print(""); // won't print, will error because it's empty
	
	if (result == EXAMPLE_PRINT_ERROR_NULLOREMPTY)
		cout << endl << "Result failed and was equal to 'EXAMPLE_PRINT_ERROR_NULLOREMPTY" << endl << endl;

	// will add 2 via the C# libary, this will fire the even number event
	// when it does, our callback method that we declared above 'displayWhenEvenNumberOccurs'
	// will fire and be executed.
	example_add(2); 

	// we will now add 7 to the number, firing the odd number event in the C# library
	// this, like the even number will execute our callback function that we
	// wrote above.
	example_add(7);

	// for fun, we will call add and subtract a few more times to show that
	// everytime we do our callback function will be executed successfully.
	example_subtract(8);
	example_add(22);
	example_subtract(7);
	example_subtract(5);
	example_add(101);

	cin.get();
}