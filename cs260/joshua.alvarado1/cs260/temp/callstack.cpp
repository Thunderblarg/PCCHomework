#include <iostream>
using namespace std;


int three(){
	cout << "this is three!" << endl;

	return 0;
}

int two() {
	cout << "this one is two" << endl;
	three();
	return 0;
}

int one() {
	cout << "this be one" << endl;
	two();
	return 0;
}

int main() {
	cout << "starting here in main" << endl;
	one();

	return 0;
}
