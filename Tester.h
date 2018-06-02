#pragma once

#include<string>
using namespace std;
#include "Staff.h"


class Tester :public Staff {
private:
	string laboratory;
	string duty;
public:
	void set_laboratory(string lab);
	void set_duty(string duty);
	void set_all();
	void read_set(string line);
	void write_to_file();


	string get_laboratory();
	string get_duty();
	void get_all();
	string get_line();
};

