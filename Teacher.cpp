#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

#include "Teacher.h"
#include "fun.h"

void Teacher::set_department(string dep)
{
	this->department = dep;
}

void Teacher::set_major(string maj)
{
	this->major = maj;
}

void Teacher::set_title(string title)
{
	this->title = title;
}

void Teacher::set_all()
{
	string id, name, sex, department, major, title, age;
	cout << "�������ţ�";
	cin >> id;
	set_idnumber(id);
	while (fun_of_idfind("Teacher.txt", get_idnumber()) != -1)
	{
		cout << "�ñ���Ѿ����ڣ����������룺";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Tester.txt", get_idnumber()) != -1)
	{
		cout << "�ñ���Ѿ����ڣ����������룺";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Administrator.txt", get_idnumber()) != -1)
	{
		cout << "�ñ���Ѿ����ڣ����������룺";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	while (fun_of_idfind("Adteacher.txt", get_idnumber()) != -1)
	{
		cout << "�ñ���Ѿ����ڣ����������룺";
		string idnum;
		cin >> idnum;
		set_idnumber(idnum);
	}
	cout << "������������";
	cin >> name;
	set_name(name);
	cout << "�������Ա�";
	for (cin >> sex; sex != "��" && sex != "Ů"; cin >> sex)
	{
		cout << "�����롰�С���Ů����";
	}
	set_sex(sex);
	cout << "���������䣺";
	cin >> age;
	set_age(age);
	cout << "����������ϵ����";
	cin >> department;
	this->department = department;
	cout << "������רҵ��";
	cin >> major;
	this->major = major;
	cout << "������ְ�ƣ�";
	cin >> title;
	this->title = title;
}

void Teacher::read_set(string line)
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
}

void Teacher::write_to_file()
{
	fstream file;
	file.open("Teacher.txt", ios::app);
	file <<get_idnumber() << " " << get_name();
	file << " " << get_sex() << " " <<get_age() << " ";
	file << get_department() << " " << get_major() << " ";
	file << get_title() << endl;
}

string Teacher::get_department()
{
	return this->department;
}

string Teacher::get_major()
{
	return this->major;
}

string Teacher::get_title()
{
	return this->title;
}

void Teacher::get_all()
{
	cout << "ְλ����ʦ" << "  ";
	cout << "��ţ�" << get_idnumber() << "  ";
	cout << "������" << get_name() << "  ";
	cout << "�Ա�" << get_sex() << "  ";
	cout << "���䣺" << get_age() << "  ";
	cout << "����ϵ����" << this->department << "  ";
	cout << "����רҵ��" << this->major << "  ";
	cout << "ְ�ƣ�" << this->title << "  ";
	cout << endl;
}

string Teacher::get_line()
{
	string line;
	line = get_idnumber() + ' ' + get_name() + ' ' +
		get_sex() + ' ' + get_age() + ' ' + get_department() +
		' ' + get_major() + ' ' + get_title() ;
	return line;
}