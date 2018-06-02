#pragma once

#include<string>
using namespace std;

#include "Staff.h"

class Administrator :public Staff {
private:
	string politics_status;
	string title;
public:
	void set_politics(string pol);
	void set_title(string title);
	void set_all();
	void read_set(string line);
	void write_to_file();

	string get_politics();
	string get_title();
	void get_all();
	string get_line();
};

