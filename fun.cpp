#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

#include "Administrator.h"
#include "Teacher.h"
#include "Tester.h"
#include "Adteacher.h"
#include "fun.h"


//begin--------------------------------��ӹ���-----------------------------------------

void fun_of_add()
{
	while (true)
	{
		system("cls");
		cout << "************************************************************" << endl;
		cout << "**                     ��ѡ��Ա�����                     **" << endl;
		cout << "**--------------------------------------------------------**" << endl;
		cout << "**                     0.�˳�                             **" << endl;
		cout << "**                     1.��ʦ                             **" << endl;
		cout << "**                     2.ʵ��Ա                           **" << endl;
		cout << "**                     3.������Ա                         **" << endl;
		cout << "**                     4.��ʦ��������Ա                   **" << endl;
		cout << "************************************************************" << endl;
		cout << "��������ţ�";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "�����������������룺";
		}
		for (; type[0] < '0' || type[0]>'4'; cin >> type)
		{
			cout << "�����������������룺";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			fstream file;
			file.open("Teacher.txt", ios::app);
			Teacher temp;
			temp.set_all();
			cout << "��ȷ����Ϣ��" << endl;
			temp.get_all();
			cout << "ȷ��д��������1��������������ȡ��д�룺";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "��ӳɹ���" << endl;
			}
			file.close();
		}
		else if (type == "2")
		{
			fstream file;
			file.open("Tester.txt", ios::app);
			Tester temp;
			temp.set_all();
			cout << "��ȷ����Ϣ��" << endl;
			temp.get_all();
			cout << "ȷ��д��������1��������������ȡ��д�룺";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "��ӳɹ���" << endl;
			}
			file.close();
		}
		else if (type == "3")
		{
			fstream file;
			file.open("Administrator.txt", ios::app);
			Administrator temp;
			temp.set_all();
			cout << "��ȷ����Ϣ��" << endl;
			temp.get_all();
			cout << "ȷ��д��������1��������������ȡ��д�룺";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "��ӳɹ���" << endl;
			}
			file.close();
		}
		else if (type == "4")
		{
			fstream file;
			file.open("Adteacher.txt", ios::app);
			Adteacher temp;
			temp.set_all();
			cout << "��ȷ����Ϣ��" << endl;
			temp.get_all();
			cout << "ȷ��д��������1��������������ȡ��д�룺";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "��ӳɹ���" << endl;
			}
			file.close();
		}
		system("pause");
	}	
}



//-----------------------------------��ѯ--------------------------------------------


void fun_of_search()
{
	while (true)
	{
		system("cls");
		cout << "**************************************************" << endl;
		cout << "***             ��ӭ�����ѯϵͳ               ***" << endl;
		cout << "**************************************************" << endl;
		cout << "****              0.�˳�                       ***" << endl;
		cout << "****              1.����Ų�ѯ                 ***" << endl;
		cout << "****              2.��������ѯ                 ***" << endl;
		cout << "**************************************************" << endl;
		cout << "�����룺";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "�����������������룺";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "�����������������룺";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			int flag = 0;
			string id;
			cout << "�������ţ�";
			cin >> id;
			fstream file;
			if (fun_of_idfind("Teacher.txt", id) != -1)//search in teacher
			{
				flag = 1;
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Teacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_idfind("Tester.txt", id) != -1)//search in tester
			{
				flag = 1;
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Tester.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_idfind("Administrator.txt", id) != -1)//search in admin
			{
				flag = 1;
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Administrator.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_idfind("Adteacher.txt", id) != -1)//search in adteacher
			{
				flag = 1;
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Adteacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			if (flag == 0)
			{
				cout << "���޴��ˣ�" << endl;
			}

		}
		else if (type == "2")
		{
			int flag = 0;
			string name;
			cout << "������������";
			cin >> name;
			fstream file;
			if (fun_of_namefind("Teacher.txt", name) != -1)//search in teacher
			{
				flag = 1;
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Teacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_namefind("Tester.txt", name) != -1)//search in tester
			{
				flag = 1;
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Tester.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_namefind("Administrator.txt", name) != -1)//search in admin
			{
				flag = 1;
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Administrator.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			else if (fun_of_namefind("Adteacher.txt", name) != -1)//search in adteacher
			{
				flag = 1;
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Adteacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				temp.read_set(line);
				temp.get_all();
			}
			if (flag == 0)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		system("pause");
	}
}


//---------------------------------��ѯ����Ƿ����----------------------------------


int fun_of_idfind(const char *filename, string id)
{
	fstream file;
	file.open(filename, ios::in | ios::binary);
	if (!file.is_open())
	{		
		return -1;
	}
	else
	{
		stringstream ss;
		while (file.peek() != EOF)
		{
			int start = file.tellg();
			string line;
			getline(file, line);
			ss << line;
			string curid;
			ss >> curid;
			if (curid == id)
			{
				file.close();
				return start;
			}
			ss.str("");
		}
		file.close();
	}
	return -1;
}





//--------------------------------��ѯ�����Ƿ����-----------------------------------

int fun_of_namefind(const char *filename, string name)
{
	fstream file;
	file.open(filename, ios::in | ios::binary);
	if (!file.is_open())
	{
		return -1;
	}
	else
	{
		stringstream ss;
		while (file.peek() != EOF)
		{
			int start = file.tellg();
			string line;
			getline(file, line);
			ss << line;
			string curname;
			ss >> curname;
			ss >> curname;
			if (curname == name)
			{
				file.close();
				return start;
			}
			ss.str("");
		}
		file.close();
	}
	return -1;
}




//----------------------------------------ɾ��---------------------------------------

void fun_of_delete()
{
	while (true)
	{
		system("cls");
		cout << "*******************************************************" << endl;
		cout << "***                 0.�˳�                          ***" << endl;
		cout << "***                 1.������ɾ��                  ***" << endl;
		cout << "***                 2.��������ɾ��                  ***" << endl;
		cout << "*******************************************************" << endl;
		cout << "��������ţ�";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "�����������������룺";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "�����������������룺";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			cout << "�������ţ�";
			string id;
			cin >> id;
			fstream file;
			if (fun_of_idfind("Teacher.txt", id) != -1)
			{
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Teacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Teacher.txt", ios::in);
					string copy;
					stringstream ss;
					string curid;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curid;
						if (curid != id)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Teacher.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_idfind("Tester.txt", id) != -1)
			{
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Tester.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Tester.txt", ios::in);
					string copy;
					stringstream ss;
					string curid;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curid;
						if (curid != id)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Tester.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_idfind("Administrator.txt", id) != -1)
			{
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Administrator.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Administrator.txt", ios::in);
					string copy;
					stringstream ss;
					string curid;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curid;
						if (curid != id)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Administrator.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_idfind("Adteacher.txt", id) != -1)
			{
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Adteacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Adteacher.txt", ios::in);
					string copy;
					stringstream ss;
					string curid;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curid;
						if (curid != id)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Adteacher.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else
			{
				cout << "��Ա�������ڣ�" << endl;
			}
		}
		else if (type == "2")
		{
			cout << "������������";
			string name;
			cin >> name;
			fstream file;
			if (fun_of_namefind("Teacher.txt", name) != -1)
			{
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Teacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Teacher.txt", ios::in);
					string copy;
					stringstream ss;
					string curname;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curname;
						ss >> curname;
						if (curname != name)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Teacher.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_namefind("Tester.txt", name) != -1)
			{
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Tester.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Tester.txt", ios::in);
					string copy;
					stringstream ss;
					string curname;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curname;
						ss >> curname;
						if (curname != name)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Tester.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_namefind("Administrator.txt", name) != -1)
			{
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Administrator.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				int n;
				cin >> n;
				if (n == 1)
				{
					file.open("Administrator.txt", ios::in);
					string copy;
					stringstream ss;
					string curname;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curname;
						if (curname != name)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Administrator.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else if (fun_of_namefind("Adteacher.txt", name) != -1)
			{
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Adteacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1ɾ����������������ȡ��ɾ���������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Adteacher.txt", ios::in);
					string copy;
					stringstream ss;
					string curname;
					while (file.peek() != EOF)
					{
						getline(file, line);
						ss << line;
						ss >> curname;
						ss >> curname;
						if (curname != name)
						{
							copy += line + '\n';
						}
						ss.str("");
						ss.clear();
					}
					file.close();
					file.open("Adteacher.txt", ios::out | ios::trunc);
					file << copy;
					file.close();
					cout << "ɾ���ɹ���" << endl;
				}
			}
			else
			{
				cout << "��Ա�������ڣ�" << endl;
			}
		}
		system("pause");
	}
	
}




//----------------------------------��ʾ-------------------------------------

void fun_of_display()
{
	fstream file;
	int flag = 0;


	file.open("Teacher.txt", ios::in);
	if (!file.is_open())
	{

	}
	else
	{
		Teacher temp;
		string line;
		while (file.peek() != EOF)
		{
			flag = 1;
			getline(file, line);
			temp.read_set(line);
			temp.get_all();
		}
	}
	file.close();


	file.open("Tester.txt", ios::in);
	if (!file.is_open())
	{

	}
	else
	{
		Tester temp;
		string line;
		while (file.peek() != EOF)
		{
			flag = 1;
			getline(file, line);
			temp.read_set(line);
			temp.get_all();
		}
	}
	file.close();


	file.open("Administrator.txt", ios::in);
	if (!file.is_open())
	{

	}
	else
	{
		Administrator temp;
		string line;
		while (file.peek() != EOF)
		{
			flag = 1;
			getline(file, line);
			temp.read_set(line);
			temp.get_all();
		}
	}
	file.close();


	file.open("Adteacher.txt", ios::in);
	if (!file.is_open())
	{
		
	}
	else
	{
		Adteacher temp;
		string line;
		while (file.peek() != EOF)
		{
			flag = 1;
			getline(file, line);
			temp.read_set(line);
			temp.get_all();
		}
	}
	file.close();
	if (flag == 0)
	{
		cout << "�����ݣ�������ӣ�" << endl;
	}
}



//---------------------------------------�༭-------------------------------------


void fun_of_edit()
{
	while (true)
	{
		system("cls");
		cout << "*************************************************" << endl;
		cout << "***           0.�˳�                          ***" << endl;
		cout << "***           1.���ݱ�Ų�ѯ���༭            ***" << endl;
		cout << "***           2.����������ѯ���༭            ***" << endl;
		cout << "*************************************************" << endl;
		cout << "��������ţ�";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "�����������������룺";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "�����������������룺";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			cout << "�������ţ�";
			string id;
			cin >> id;
			fstream file;
			if (fun_of_idfind("Teacher.txt", id) != -1)
			{
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Teacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Teacher.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_idfind("Tester.txt", id) != -1)
			{
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Tester.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Tester.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_idfind("Administrator.txt", id) != -1)
			{
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Administrator.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Administrator.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_idfind("Adteacher.txt", id) != -1)
			{
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_idfind("Adteacher.txt", id);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Adteacher.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else
			{
				cout << "��Ա�������ڣ�" << endl;
			}
		}
		else if (type == "2")
		{
			cout << "������������";
			string name;
			cin >> name;
			fstream file;
			if (fun_of_namefind("Teacher.txt", name) != -1)
			{
				Teacher temp;
				file.open("Teacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Teacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Teacher.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_namefind("Tester.txt", name) != -1)
			{
				Tester temp;
				file.open("Tester.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Tester.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Tester.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_namefind("Administrator.txt", name) != -1)
			{
				Administrator temp;
				file.open("Administrator.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Administrator.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Administrator.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else if (fun_of_namefind("Adteacher.txt", name) != -1)
			{
				Adteacher temp;
				file.open("Adteacher.txt", ios::in | ios::binary);
				int pos = fun_of_namefind("Adteacher.txt", name);
				string line;
				file.seekg(pos, ios::beg);
				getline(file, line);
				file.close();
				temp.read_set(line);
				cout << "�Ƿ��޸ĸ�Ա����Ϣ��" << endl;
				temp.get_all();
				cout << "����1�޸ģ�������������ȡ���޸ģ������룺";
				string n;
				cin >> n;
				if (n == "1")
				{
					file.open("Adteacher.txt", ios::in | ios::out | ios::binary);
					file.seekg(pos, ios::beg);
					string newinfo;
					stringstream ss;
					temp.set_all();
					newinfo = temp.get_line();
					file << newinfo;
					file.close();
					cout << "�޸ĳɹ���" << endl;
					cout << "�޸ĺ�����Ϊ��" << endl;
					temp.get_all();
				}
			}
			else
			{
				cout << "��Ա�������ڣ�" << endl;
			}
		}
		system("pause");
	}
	
}






//---------------------------------------ͳ��-----------------------------------



void fun_of_count()
{
	int teacher = 0, tester = 0, administrator = 0, adteacher = 0, man = 0, women = 0;
	fstream file;

	file.open("Teacher.txt", ios::in);
	if (!file.is_open())
	{
		
	}
	else
	{
		Teacher temp;
		string line, cursex;
		while (file.peek() != EOF)
		{
			teacher++;
			stringstream ss;
			getline(file, line);
			ss << line;
			ss >> cursex;
			ss >> cursex;
			ss >> cursex;
			if (cursex == "��")
				man++;
			else if (cursex == "Ů")
				women++;
		}
	}
	file.close();


	file.open("Tester.txt", ios::in);
	if (!file.is_open())
	{
		
	}
	else
	{
		Tester temp;
		string line, cursex;
		while (file.peek() != EOF)
		{
			tester++;
			stringstream ss;
			getline(file, line);
			ss << line;
			ss >> cursex;
			ss >> cursex;
			ss >> cursex;
			if (cursex == "��")
				man++;
			else if (cursex == "Ů")
				women++;
		}
	}
	file.close();


	file.open("Administrator.txt", ios::in);
	if (!file.is_open())
	{
		
	}
	else
	{
		Administrator temp;
		string line, cursex;
		while (file.peek() != EOF)
		{
			administrator++;
			stringstream ss;
			getline(file, line);
			ss << line;
			ss >> cursex;
			ss >> cursex;
			ss >> cursex;
			if (cursex == "��")
				man++;
			else if (cursex == "Ů")
				women++;
		}
	}
	file.close();


	file.open("Adteacher.txt", ios::in);
	if (!file.is_open())
	{
		
	}
	else
	{
		Adteacher temp;
		string line, cursex;
		while (file.peek() != EOF)
		{
			adteacher++;
			stringstream ss;
			getline(file, line);
			ss << line;
			ss >> cursex;
			ss >> cursex;
			ss >> cursex;
			if (cursex == "��")
				man++;
			else if (cursex == "Ů")
				women++;
		}
	}
	file.close();

	cout << "��ʦ������" << teacher << endl;
	cout << "ʵ��Ա������" << tester << endl;
	cout << "������Ա������" << administrator << endl;
	cout << "��ʦ��������Ա������" << adteacher << endl;
	cout << "��������" << teacher+administrator+tester+adteacher << endl;
	cout << "��Ա��������" << man << endl;
	cout << "ŮԱ��������" << women << endl;
}





//-----------------------------------���˵�------------------------------------

void fun_of_menu()
{
	while (true)
	{
		system("cls");
		cout << "**********************************************************************************" << endl;
		cout << "***                        ��ӭ�����У��Ա��Ϣ����ϵͳ                        ***" << endl;
		cout << "**********************************************************************************" << endl;
		cout << "***                             0.�˳���ϵͳ                                   ***" << endl;
		cout << "***                             1.�����Ա��                                   ***" << endl;
		cout << "***                             2.��ѯ��Ϣ                                     ***" << endl;
		cout << "***                             3.��ʾ����Ա����Ϣ                             ***" << endl;
		cout << "***                             4.�༭Ա����Ϣ                                 ***" << endl;
		cout << "***                             5.ɾ��Ա����Ϣ                                 ***" << endl;
		cout << "***                             6.ͳ������Ա����Ϣ                             ***" << endl;
		cout << "**********************************************************************************" << endl;
		string cmd;
		cout << "��������ţ�";
		for (cin >> cmd; cmd.length()!=1; cin >> cmd)
		{
			cout << "�����������������룺";
		}
		for (; cmd[0] < '0' || (cmd[0] > '6'&&cmd[0] != '9'); cin >> cmd)
		{
			cout << "�����������������룺";
		}
		if (cmd == "0")
		{
			cout << "��лʹ�ñ�ϵͳ����ӭ�ٴ�ʹ�ã�" << endl;
			system("pause");
			return;
		}
		else if (cmd == "1")
		{
			system("cls");
			fun_of_add();
		}
		else if (cmd == "2")
		{
			system("cls");
			fun_of_search();
		}
		else if (cmd == "3")
		{
			system("cls");
			fun_of_display();
			system("pause");
		}
		else if (cmd == "4")
		{
			system("cls");
			fun_of_edit();
		}
		else if (cmd == "5")
		{
			system("cls");
			fun_of_delete();
		}
		else if (cmd == "6")
		{
			system("cls");
			fun_of_count();
			system("pause");
		}
		else if (cmd == "9")
		{
			system("cls");
			cout << "��������˧��" << endl;
			system("pause");
		}
	}	
}
