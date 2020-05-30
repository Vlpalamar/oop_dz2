#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include"book_class.h"
using namespace std;

template<class T>
T* Create_Din_Arr(T*& p, int& size)
{
	if (!p)
	{
		p = new T[size];
	}
	return p;
}

template<class T>
void delElemPosArray(T*& p, int& size, int pos)
{
	T* t = new T[size - 1];
	for (int i = 0; i < pos; i++)
	{
		t[i] = p[i];
	}
	for (int i = pos + 1; i < size; i++)
	{
		t[i - 1] = p[i];
	}
	delete[]p;
	p = t;
	size--;
}

template<class T>
int  serch(T *arr,int size,string cl_serch_name)
{
	for (size_t i = 0; i < size; i++)
	{
		string massName = arr[i].NumbBook::GetName();

		if (massName == cl_serch_name)
		{
			arr[i].NumbBook::Show();
			return i;
		}
	}
	
}
template<class T>
T* addElemArray(T*& p, int& size, T elem)
{
	T* t = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		t[i] = p[i];

	}

	t[size] = elem;
	(size)++;
	delete[] p;
	p = t;

	return p;
}
template<class T>
void add(T*& p, int& size)
{
	int MobNumb;
	int HomeNumb;
	int WorkNumb;
	char info[256];
	NumbBook elem;
	addElemArray(p, size, elem);
	char name[256];
	cout << "введите Фио(в одну строчку)" << endl;
	cin>>name;

	cout << "введите мобильный номмер телефона" << endl;

	cin >> MobNumb;
	cout << "введите домашний номмер телефона" << endl;

	cin >> HomeNumb;
	cout << "введите робочий номмер телефона" << endl;

	cin >> WorkNumb;
	cout << "введите доп.информацию(без пробелов)" << endl;
	cin >> info;

	elem.setData(name, MobNumb, HomeNumb, WorkNumb, info);
	

	
}

int main()
{
	setlocale(0, "");
	int size=5 ;
	NumbBook *class_arr=nullptr;
	Create_Din_Arr(class_arr, size);
	class_arr[0].setData("Alexandr_Ivan_Grexhkin", 1664416643, 1664416643, 234576, "лопазщ");
	class_arr[1].setData("Ivan_Ivanovich_Plushkin", 1543313642, 1543313642, 233576, "пвапврщфкорх");
	class_arr[2].setData("ne_pomnu", 1264416643, 1664416643, 234576, "пропропар");
	class_arr[3].setData("Vladimir_Vladimirovich_Pupka", 1664416643, 1664416643, 234576, "опарароа");
	class_arr[4].setData("Tar_Ivanovich_Plushkin", 1543313642, 1543313642, 233576, "пвапврщфкорх");
	string cl_serch_name;
	ofstream fout;
	ifstream fin;
	NumbBook elem;
	int ch;
	
	while (true)
	{

	
	cout << "1.serch\n2.del\n3.add\n4.show_all\n5.safe data\n6.download";
	cin >> ch;
		switch (ch)
		{
		case 1:
		
			cout << "введите имя транслитом и слитно" << endl;
			 cin>>cl_serch_name ;
			 serch(class_arr, size, cl_serch_name);
			
		case 2:
			cout << "введите имя транслитом и слитно" << endl;
			cin >> cl_serch_name;
			delElemPosArray(class_arr, size, serch(class_arr, size, cl_serch_name));
			break;
		case 3:
			add(class_arr, size);
			break;
		case 4:
			for (size_t i = 0; i < size; i++)
			{
				class_arr[i].Show();
				cout << endl;
			}
				break;
		case 5:
			
			fout.open("fout.txt");
			for (size_t i = 0; i < size; i++)
			{
				fout << class_arr[i].GetName()<<endl;
				fout << class_arr[i].GetMobNumb() << endl;
				fout << class_arr[i].GetHomeNumb() << endl;
				fout << class_arr[i].GetInfo() << endl;
			}
			fout.close();
			
			break;
		case 6:

			//fin.open("fin.txt");
			//addElemArray(class_arr, size, elem);
			//if (fin.is_open())
			//{
			//	while (fin.eof())
			//	{
			//		char* name1;
			//		fin >> name1;
			//		class_arr[size].TakeName(name1);
			//		int mobNumb1;
			//		fin >> mobNumb1;
			//		class_arr[size].TakeMobNumb(mobNumb1);
			//		int workNumb1;
			//		fin >>workNumb1;
			//		class_arr[size].TakeWorkNumb(workNumb1);
			//		int HomeNumb1;
			//		fin >> HomeNumb1;
			//		class_arr[size].TakeHomeNumb(HomeNumb1);
			//		char* info1;
			//		fin >> info1;
			//		class_arr[size].TakeInfo(info1);
			//		
			//	}
			//	
			//}
			//else
			//{
			//	cout << "file not found" << endl;
			//}
			//fin.close();
			//break;
		default:
			break;
		}
	
	}
}