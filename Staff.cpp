#include<iostream>
#include<string>
using namespace std;
#include "Staff.h"

void Staff::set_idnumber(string num)
{
	this->idnumber = num;
}

void Staff::set_name(string name)
{
	this->name = name;
}

void Staff::set_sex(string sex)
{
	this->sex = sex;
}

void Staff::set_age(string age)
{
	this->age = age;
}

string Staff::get_idnumber()
{
	return this->idnumber;
}

string Staff::get_name()
{
	return this->name;
}

string Staff::get_sex()
{
	return this->sex;
}

string Staff::get_age()
{
	return this->age;
}