#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

#include "Administrator.h"
#include "Teacher.h"
#include "Tester.h"
#include "Adteacher.h"
#include "fun.h"


//begin--------------------------------添加功能-----------------------------------------

void fun_of_add()
{
	while (true)
	{
		system("cls");
		cout << "************************************************************" << endl;
		cout << "**                     请选择员工类别                     **" << endl;
		cout << "**--------------------------------------------------------**" << endl;
		cout << "**                     0.退出                             **" << endl;
		cout << "**                     1.教师                             **" << endl;
		cout << "**                     2.实验员                           **" << endl;
		cout << "**                     3.行政人员                         **" << endl;
		cout << "**                     4.教师兼行政人员                   **" << endl;
		cout << "************************************************************" << endl;
		cout << "请输入序号：";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		for (; type[0] < '0' || type[0]>'4'; cin >> type)
		{
			cout << "输入有误，请重新输入：";
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
			cout << "请确认信息：" << endl;
			temp.get_all();
			cout << "确认写入请输入1，输入任意内容取消写入：";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "添加成功！" << endl;
			}
			file.close();
		}
		else if (type == "2")
		{
			fstream file;
			file.open("Tester.txt", ios::app);
			Tester temp;
			temp.set_all();
			cout << "请确认信息：" << endl;
			temp.get_all();
			cout << "确认写入请输入1，输入任意内容取消写入：";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "添加成功！" << endl;
			}
			file.close();
		}
		else if (type == "3")
		{
			fstream file;
			file.open("Administrator.txt", ios::app);
			Administrator temp;
			temp.set_all();
			cout << "请确认信息：" << endl;
			temp.get_all();
			cout << "确认写入请输入1，输入任意内容取消写入：";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "添加成功！" << endl;
			}
			file.close();
		}
		else if (type == "4")
		{
			fstream file;
			file.open("Adteacher.txt", ios::app);
			Adteacher temp;
			temp.set_all();
			cout << "请确认信息：" << endl;
			temp.get_all();
			cout << "确认写入请输入1，输入任意内容取消写入：";
			string n;
			cin >> n;
			if (n == "1")
			{
				temp.write_to_file();
				cout << "添加成功！" << endl;
			}
			file.close();
		}
		system("pause");
	}	
}



//-----------------------------------查询--------------------------------------------


void fun_of_search()
{
	while (true)
	{
		system("cls");
		cout << "**************************************************" << endl;
		cout << "***             欢迎进入查询系统               ***" << endl;
		cout << "**************************************************" << endl;
		cout << "****              0.退出                       ***" << endl;
		cout << "****              1.按编号查询                 ***" << endl;
		cout << "****              2.按姓名查询                 ***" << endl;
		cout << "**************************************************" << endl;
		cout << "请输入：";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			int flag = 0;
			string id;
			cout << "请输入编号：";
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
				cout << "查无此人！" << endl;
			}

		}
		else if (type == "2")
		{
			int flag = 0;
			string name;
			cout << "请输入姓名：";
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
				cout << "查无此人！" << endl;
			}
		}
		system("pause");
	}
}


//---------------------------------查询编号是否存在----------------------------------


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





//--------------------------------查询姓名是否存在-----------------------------------

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




//----------------------------------------删除---------------------------------------

void fun_of_delete()
{
	while (true)
	{
		system("cls");
		cout << "*******************************************************" << endl;
		cout << "***                 0.退出                          ***" << endl;
		cout << "***                 1.输入编号删除                  ***" << endl;
		cout << "***                 2.输入姓名删除                  ***" << endl;
		cout << "*******************************************************" << endl;
		cout << "请输入序号：";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			cout << "请输入编号：";
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
				}
			}
			else
			{
				cout << "该员工不存在！" << endl;
			}
		}
		else if (type == "2")
		{
			cout << "请输入姓名：";
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
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
				cout << "是否删除该员工信息：" << endl;
				temp.get_all();
				cout << "输入1删除，输入任意内容取消删除，请输入：";
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
					cout << "删除成功！" << endl;
				}
			}
			else
			{
				cout << "该员工不存在！" << endl;
			}
		}
		system("pause");
	}
	
}




//----------------------------------显示-------------------------------------

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
		cout << "无数据！请先添加！" << endl;
	}
}



//---------------------------------------编辑-------------------------------------


void fun_of_edit()
{
	while (true)
	{
		system("cls");
		cout << "*************************************************" << endl;
		cout << "***           0.退出                          ***" << endl;
		cout << "***           1.根据编号查询并编辑            ***" << endl;
		cout << "***           2.根据姓名查询并编辑            ***" << endl;
		cout << "*************************************************" << endl;
		cout << "请输入序号：";
		string type;
		for (cin >> type; type.length() != 1; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		for (; type[0] < '0' || type[0]>'2'; cin >> type)
		{
			cout << "输入有误，请重新输入：";
		}
		if (type == "0")
		{
			return;
		}
		else if (type == "1")
		{
			cout << "请输入编号：";
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
					temp.get_all();
				}
			}
			else
			{
				cout << "该员工不存在！" << endl;
			}
		}
		else if (type == "2")
		{
			cout << "请输入姓名：";
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
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
				cout << "是否修改该员工信息：" << endl;
				temp.get_all();
				cout << "输入1修改，输入任意内容取消修改，请输入：";
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
					cout << "修改成功！" << endl;
					cout << "修改后内容为：" << endl;
					temp.get_all();
				}
			}
			else
			{
				cout << "该员工不存在！" << endl;
			}
		}
		system("pause");
	}
	
}






//---------------------------------------统计-----------------------------------



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
			if (cursex == "男")
				man++;
			else if (cursex == "女")
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
			if (cursex == "男")
				man++;
			else if (cursex == "女")
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
			if (cursex == "男")
				man++;
			else if (cursex == "女")
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
			if (cursex == "男")
				man++;
			else if (cursex == "女")
				women++;
		}
	}
	file.close();

	cout << "教师人数：" << teacher << endl;
	cout << "实验员人数：" << tester << endl;
	cout << "行政人员人数：" << administrator << endl;
	cout << "教师兼行政人员人数：" << adteacher << endl;
	cout << "总人数：" << teacher+administrator+tester+adteacher << endl;
	cout << "男员工人数：" << man << endl;
	cout << "女员工人数：" << women << endl;
}





//-----------------------------------主菜单------------------------------------

void fun_of_menu()
{
	while (true)
	{
		system("cls");
		cout << "**********************************************************************************" << endl;
		cout << "***                        欢迎进入高校人员信息管理系统                        ***" << endl;
		cout << "**********************************************************************************" << endl;
		cout << "***                             0.退出本系统                                   ***" << endl;
		cout << "***                             1.添加新员工                                   ***" << endl;
		cout << "***                             2.查询信息                                     ***" << endl;
		cout << "***                             3.显示所有员工信息                             ***" << endl;
		cout << "***                             4.编辑员工信息                                 ***" << endl;
		cout << "***                             5.删除员工信息                                 ***" << endl;
		cout << "***                             6.统计所有员工信息                             ***" << endl;
		cout << "**********************************************************************************" << endl;
		string cmd;
		cout << "请输入序号：";
		for (cin >> cmd; cmd.length()!=1; cin >> cmd)
		{
			cout << "输入有误，请重新输入：";
		}
		for (; cmd[0] < '0' || (cmd[0] > '6'&&cmd[0] != '9'); cin >> cmd)
		{
			cout << "输入有误，请重新输入：";
		}
		if (cmd == "0")
		{
			cout << "感谢使用本系统，欢迎再次使用！" << endl;
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
			cout << "张轩华真帅！" << endl;
			system("pause");
		}
	}	
}
