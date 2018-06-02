#pragma once

#include<string>
using namespace std;


class Staff {
private:
	string idnumber;
	string name;
	string sex;  
	string age;
public:
	void set_idnumber(string num);
	void set_name(string name);
	void set_sex(string sex);
	void set_age(string age);

	string get_idnumber();
	string get_name();
	string get_sex();
	string get_age();

};

