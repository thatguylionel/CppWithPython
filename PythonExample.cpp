#include "stdafx.h"
#include <iostream>
#include <Python.h>

int main(int argc, _TCHAR* argv[])
{
    // Initialize the Python interpreter.
	Py_Initialize();

    // Create some Python objects that will later be assigned values.
    PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pValue;

    // Convert the file name to a Python string.
    pName = PyUnicode_FromString("Sample");

    // Import the file as a Python module.
    pModule = PyImport_Import(pName);

    // Create a dictionary for the contents of the module.
    pDict = PyModule_GetDict(pModule);

    // Get the add method from the dictionary.
    pFunc = PyDict_GetItemString(pDict, "add");

    // Create a Python tuple to hold the arguments to the method.
    pArgs = PyTuple_New(2);
    
	printf("Calling Python to find the sum of 111 and 333.\n");
	// Convert 111 to a Python integer.
    pValue = PyLong_FromLong(111);
    // Set the Python int as the first argument to the method.
    PyTuple_SetItem(pArgs, 0, pValue);
    
	// Convert 333 to a Python integer.
	pValue = PyLong_FromLong(333);
	// Set the Python int as the second argument to the method.
	PyTuple_SetItem(pArgs, 1, pValue);

    // Call the function with the arguments.
	PyObject* pResult = PyObject_CallObject(pFunc, pArgs);

    // Print a message if calling the method failed.
    if(pResult == NULL)
		printf("Calling the add method failed.\n");

    // Convert the result to a long from a Python object.
    long result = PyLong_AsLong(pResult);

    // Destroy the Python interpreter.
    Py_Finalize();

    // Print the result.
    printf("The result is %d.\n", result); 
	std::cin.ignore(); 
	return 0; 
}