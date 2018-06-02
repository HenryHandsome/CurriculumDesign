#pragma once

#include<string>
using namespace std;

#include "Teacher.h"


class Adteacher :public Teacher{
private:
	string politics_status;
public:
	void set_politics(string pol);
	void set_all();
	void read_set(string line);
	void write_to_file();
	
	string get_politic();
	void get_all();
	string get_line();
};

