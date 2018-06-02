#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
#include "Administrator.h"
#include "fun.h"

void Administrator::set_politics(string pol)
{
	this->politics_status = pol;
}

void Administrator::set_title(string title)
{
	this->title = title;
}

void Administrator::set_all()
{
	string id, name, sex, age, pol, title;
	cout << "请输入编号：";
	cin >> id;
	set_idnumber(id);
	while (fun_of_idfind("Teacher.txt", get_idnumber()) != -1)
	{
		cout << "该编号已经存在，请重新输入：";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Tester.txt", get_idnumber()) != -1)
	{
		cout << "该编号已经存在，请重新输入：";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Administrator.txt", get_idnumber()) != -1)
	{
		cout << "该编号已经存在，请重新输入：";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Adteacher.txt", get_idnumber()) != -1)
	{
		cout << "该编号已经存在，请重新输入：";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	cout << "请输入姓名：";
	cin >> name;
	set_name(name);
	cout << "请输入性别：";
	for (cin >> sex; sex != "男" && sex != "女"; cin >> sex)
	{
		cout << "请输入“男”或“女”：";
	}
	set_sex(sex);
	cout << "请输入年龄：";
	cin >> age;
	set_age(age);
	cout << "请输入政治面貌：";
	cin >> pol;
	this->politics_status = pol;
	cout << "请输入职称：";
	cin >> title;
	this->title = title;
}

void Administrator::read_set(string line)
{
	stringstream ss;
	string temp;
	ss << line;
	ss >> temp;
	set_idnumber(temp);
	ss >> temp;
	set_name(temp);
	ss >> temp;
	set_sex(temp);
	ss >> temp;
	set_age(temp);
	ss >> temp;
	set_politics(temp);
	ss >> temp;
	set_title(temp);
}

void Administrator::write_to_file()
{
	fstream file;
	file.open("Administrator.txt", ios::app);
	file << get_idnumber() << " " << get_name();
	file << " " << get_sex() << " " << get_age() << " ";
	file << get_politics() << " ";
	file << get_title() << endl;
}

string Administrator::get_politics()
{
	return politics_status;
}

string Administrator::get_title()
{
	return this->title;
}


void Administrator::get_all()
{
	cout << "职位：行政人员  ";
	cout << "编号：" << get_idnumber() << "  ";
	cout << "姓名：" << get_name() << "  ";
	cout << "性别：" << get_sex() << "  ";
	cout << "年龄：" << get_age() << "  ";
	cout << "政治面貌：：" << this->politics_status << "  ";
	cout << "职称：" << this->title << "  ";
	cout << endl;
}

string Administrator::get_line()
{
	string line;
	line = get_idnumber() + ' ' + get_name() + ' ' +
		get_sex() + ' ' + get_age() + ' ' + get_politics() +
		' ' + get_title() ;
	return line;
}