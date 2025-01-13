#include "data.h"

Data::Data():name(nullptr), gpa(0) //initializer
{
}

Data::Data(const char * name)
{
	init(name, 0);
}

Data::Data(const char * name, float gpa)
{
	init(name, gpa);
}

void Data::init(const char * name, float gpa)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->gpa = gpa;
}
	
Data::~Data()
{
	if(this->name)
		delete [] this->name;
}

const char * Data::getName() const
{
	return this->name;
}

float Data::getGpa() const
{
	return gpa;
}

void Data::setName(const char * name)
{
	if(this->name)
		delete [] this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void Data::setGpa(float gpa)
{
	this->gpa = gpa;
}

void Data::print(ostream& out) const
{
	if(!this->name)
		out << "No Name Yet" << "--" << this->gpa << endl;
	else
		out << this->name << "--" << this->gpa << endl;
}
