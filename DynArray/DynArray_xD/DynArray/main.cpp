#include <iostream>
#include "DynArray.hh"

// CONSTANTS
const int sizeArray (5);

int main(){
	// TO INITIATE
	int *xD = new int[sizeArray];
	int num = 1;
	for (int i = 0; i < sizeArray; i++){
		xD[i] = num++;
	}
	
	//The two constructors
	DynArray *dynArray1 = new DynArray();
	DynArray *dynArray2 = new DynArray(xD, sizeArray);
	DynArray *dynArray3 = new DynArray(4, 100);
	std::cout << *dynArray3;

	//Assignment operator
	std::cout << "\nAssignment operator.\n";
	*dynArray1 = *dynArray2;
	std::cout << *dynArray1;

	//Iterator methods
	std::cout << "\nIterator methods.\n";
	for (int *it = dynArray2->begin(); it != dynArray2->end(); it++){
		std::cout << *it << std::endl;
	}

	//Two capacity methods
	std::cout << "\nTwo capacity methods.\n";
	dynArray1->resize(2);
	std::cout << "dynArray1 with a length of " << dynArray1->size() << std::endl;
	std::cout << *dynArray1;

	//Modifiers methods
	std::cout << "\nModifiers methods.\n";
	dynArray1->push(10);
	dynArray1->insert(0, 200);
	std::cout << *dynArray1;

	dynArray2->clear();
	std::cout << *dynArray2;

	//Relational operators
	std::cout << "\nRelational operators.\n";
	if (*dynArray1 == *dynArray2){
		std::cout << "Arrays are equal!\n";
	}
	else{
		std::cout << "Arrays are not equal!\n";
	}

	*dynArray1 = *dynArray2;
	if (*dynArray1 == *dynArray2){
		std::cout << "Arrays are equal!\n";
	}
	else{
		std::cout << "Arrays are not equal!\n";
	}

	//Deallocate memory
	delete xD;
	delete dynArray1;
	delete dynArray2;	

	std::cin.get();


	return 0;
}