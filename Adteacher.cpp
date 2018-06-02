#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

#include "Adteacher.h"
#include "fun.h"

void Adteacher::set_politics(string pol)
{
	this->politics_status = pol;
}

void Adteacher::set_all()
{
	string id, name, sex, age, department, major, title, pol;
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
	cout << "请输入所在系部：";
	cin >> department;
	set_department(department);
	cout << "请输入专业：";
	cin >> major;
	set_major(major);
	cout << "请输入职称：";
	cin >> title;
	set_title(title);
	cout << "请输入政治面貌：";
	cin >> pol;
	set_politics(pol);
}

void Adteacher::read_set(string line)
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
	set_department(temp);
	ss >> temp;
	set_major(temp);
	ss >> temp;
	set_title(temp);
	ss >> temp;
	set_politics(temp);
}


void Adteacher::write_to_file()
{
	fstream file;
	file.open("Adteacher.txt", ios::app);
	file << get_idnumber() << " " << get_name();
	file << " " << get_sex() << " " << get_age() << " ";
	file << get_department() << " " << get_major() << " ";
	file << get_title() << " " << get_politic() << endl;
}

string Adteacher::get_politic()
{
	return this->politics_status;
}

void Adteacher::get_all()
{
	cout << "职位：教师兼行政人员" << "  ";
	cout << "编号：" << get_idnumber() << "  ";
	cout << "姓名：" << get_name() << "  ";
	cout << "性别：" << get_sex() << "  ";
	cout << "年龄：" << get_age() << "  ";
	cout << "所在系部：" << get_department() << "  ";
	cout << "所在专业：" << get_major() << "  ";
	cout << "职称：" << get_title() << "  ";
	cout << "政治面貌：" << get_politic() << "  ";
	cout << endl;
}

string Adteacher::get_line()
{
	string line;
	line = get_idnumber() + ' ' + get_name() + ' ' +
		get_sex() + ' ' + get_age() + ' ' + get_department() +
		' ' + get_major() + ' ' + get_title() + ' ' +
		get_politic() ;
	return line;
}