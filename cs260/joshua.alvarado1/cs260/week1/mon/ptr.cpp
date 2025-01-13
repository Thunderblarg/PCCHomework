#include "ptr.h"

void reviewPtrBasics() {
	int 	number = 0;
	int* 	intPtr = nullptr;

	intPtr = &number; //& = address-of operator
	*intPtr = 10; // dereference

	int** ptr = nullptr;
	ptr = &intPtr;
	**ptr = 20;
}
