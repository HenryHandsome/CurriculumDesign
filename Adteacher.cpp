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
	set_department(department);
	cout << "������רҵ��";
	cin >> major;
	set_major(major);
	cout << "������ְ�ƣ�";
	cin >> title;
	set_title(title);
	cout << "������������ò��";
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
	cout << "ְλ����ʦ��������Ա" << "  ";
	cout << "��ţ�" << get_idnumber() << "  ";
	cout << "������" << get_name() << "  ";
	cout << "�Ա�" << get_sex() << "  ";
	cout << "���䣺" << get_age() << "  ";
	cout << "����ϵ����" << get_department() << "  ";
	cout << "����רҵ��" << get_major() << "  ";
	cout << "ְ�ƣ�" << get_title() << "  ";
	cout << "������ò��" << get_politic() << "  ";
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