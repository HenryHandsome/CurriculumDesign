#pragma once

#include<string>
using namespace std;
#include "Staff.h"


class Teacher :public Staff {
private:
	string department;
	string major;
	string title;
public:
	void set_department(string dep);
	void set_major(string maj);
	void set_title(string title);
	void set_all();
	void read_set(string line);
	void write_to_file();

	string get_department();
	string get_major();
	string get_title();
	void get_all();
	string get_line();
};
