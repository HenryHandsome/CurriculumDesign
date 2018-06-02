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
	cout << "������������ò��";
	cin >> pol;
	this->politics_status = pol;
	cout << "������ְ�ƣ�";
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
	cout << "ְλ��������Ա  ";
	cout << "��ţ�" << get_idnumber() << "  ";
	cout << "������" << get_name() << "  ";
	cout << "�Ա�" << get_sex() << "  ";
	cout << "���䣺" << get_age() << "  ";
	cout << "������ò����" << this->politics_status << "  ";
	cout << "ְ�ƣ�" << this->title << "  ";
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