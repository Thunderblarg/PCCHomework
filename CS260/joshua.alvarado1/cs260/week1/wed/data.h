#pragma once
#include "myutil.h"


class Data
{
public:
	Data();
	Data(const char* name);
	Data(const char* name, float gpa);
	~Data();

	const char* getName() const;
	float getGpa() const;
	void setName(const char* name);
	void setGpa(float gpa);
	void print(ostream& out) const;

private:
	char* 	name; //needs to be just big enough
	float	 gpa;

	void init(const char* name, float gpa);
};
