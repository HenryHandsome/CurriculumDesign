#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

#include "Tester.h"
#include "fun.h"

void Tester::set_laboratory(string lab)
{
	this->laboratory = lab;
}

void Tester::set_duty(string duty)
{
	this->duty = duty;
}

void Tester::set_all()
{
	string id, name, sex, age, lab, duty;
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
	cout << "请输入所在实验室：";
	cin >> lab;
	this->laboratory = lab;
	cout << "请输入职务：";
	cin >> duty;
	this->duty = duty;
}

void Tester::read_set(string line)
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
	set_laboratory(temp);
	ss >> temp;
	set_duty(temp);
}

void Tester::write_to_file()
{
	fstream file;
	file.open("Tester.txt", ios::app);
	file << get_idnumber() << " " << get_name();
	file << " " << get_sex() << " " << get_age() << " ";
	file << get_laboratory() << " " << get_duty() << endl;
}



string Tester::get_laboratory()
{
	return this->laboratory;
}

string Tester::get_duty()
{
	return this->duty;
}

void Tester::get_all()
{
	cout << "职位：实验员  ";
	cout << "编号：" << get_idnumber() << "  ";
	cout << "姓名：" << get_name() << "  ";
	cout << "性别：" << get_sex() << "  ";
	cout << "年龄：" << get_age() << "  ";
	cout << "所在实验室：" << this->laboratory << "  ";
	cout << "职务：" << this->duty << "  ";
	cout << endl;
}

string Tester::get_line()
{
	string line;
	line = get_idnumber() + ' ' + get_name() + ' ' +
		get_sex() + ' ' + get_age() + ' ' + get_laboratory() +
		' ' + get_duty() ;
	return line;
}