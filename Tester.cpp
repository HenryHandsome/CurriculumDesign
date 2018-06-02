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
	cout << "����������ʵ���ң�";
	cin >> lab;
	this->laboratory = lab;
	cout << "������ְ��";
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
	cout << "ְλ��ʵ��Ա  ";
	cout << "��ţ�" << get_idnumber() << "  ";
	cout << "������" << get_name() << "  ";
	cout << "�Ա�" << get_sex() << "  ";
	cout << "���䣺" << get_age() << "  ";
	cout << "����ʵ���ң�" << this->laboratory << "  ";
	cout << "ְ��" << this->duty << "  ";
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