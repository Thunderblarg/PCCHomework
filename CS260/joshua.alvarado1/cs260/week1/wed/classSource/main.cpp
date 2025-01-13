#include "myutil.h"
#include "data.h"
//void oops(Data d) {}
int main()
{
	Data	s1;
	Data	s2("jack");
	Data	s3("mary", 3.8);
	Data *	s4 = new Data("joackson", 3.9);
	Data * 	aList = new Data[10];

	cout << "invoking default constructor ..." << endl;
	s1.print(cout);

	cout << "invoking two parameter constructor ..." << endl;
	s3.print(cout);

	cout << "s2 before ...";
	s2.print(cout);
	s2.setName("new name");
	s2.setGpa(3.8);
	cout << "s2 after ...";
	s2.print(cout);

	cout << "s4: " << s4->getName() << ": " << s4->getGpa() << endl;
	delete s4;
	delete [] aList;

/*

	oops(s3);

	s2 = s3;
	s2.print(cout);
*/
	return 0;
}
