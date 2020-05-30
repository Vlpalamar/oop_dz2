#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
class NumbBook
{
	
	char *m_name;
	int m_MobNumb;
	int m_HomeNumb;
	int m_WorkNumb;
	char* m_info;

	public:
	
	NumbBook() :NumbBook("no name") {  }

	NumbBook(const char* name) :NumbBook(name,0,0,0, "no info") {  }

	NumbBook(const char* name, int MobNumb) :NumbBook(name, MobNumb,0,0, "no info") {  }

	NumbBook(const char* name, int MobNumb, int WorkNumb) :NumbBook(name, MobNumb, WorkNumb, 0, "no info") {  }

	NumbBook(const char* name, int MobNumb, int WorkNumb, int HomeNumb) :NumbBook(name, MobNumb, WorkNumb, HomeNumb, "no info") {  }

	NumbBook(const char* name, int MobNumb, int WorkNumb , int HomeNumb, const char* info)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);	

		m_info = new char[strlen(info) + 1];
		strcpy(m_info, info);
		if (MobNumb >= pow(10, 9) and MobNumb < pow(10, 10))
		{
			m_MobNumb = MobNumb;
		}
		else
		{
			m_MobNumb = 0;
		}

		if (WorkNumb > pow(10, 9) and WorkNumb < pow(10, 10))
		{
			m_WorkNumb = WorkNumb;
		}
		else
		{
			m_WorkNumb = 0;
		}

		if (HomeNumb > pow(10, 5) and HomeNumb < pow(10, 6))
		{
			m_HomeNumb = HomeNumb;
		}
		else
		{
			m_HomeNumb = 0;
		}
		
	}
	void Show()
	{
		cout << "Ôèî :" << m_name<<"\n";
		if (m_MobNumb!=0)
		{
			cout << "Mobile Number :" << m_MobNumb << "\n";
		}
		
		if (m_WorkNumb!=0)
		{
			cout << "work Number :" << m_WorkNumb << "\n";
		}
		if (m_HomeNumb != 0)
		{
			cout << "Home Number :" << m_HomeNumb << "\n";
		}
		cout   << m_info<<endl;
	}
	
	void setData(const char* name, int MobNumb=0, int WorkNumb=0, int HomeNumb=0, const char* info="no info")
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);

		m_info = new char[strlen(info) + 1];
		strcpy(m_info, info);
		if (MobNumb >= pow(10, 9) and MobNumb < pow(10, 10))
		{
			m_MobNumb = MobNumb;
		}
		else
		{
			m_MobNumb = 0;
		}

		if (WorkNumb > pow(10, 9) and WorkNumb < pow(10, 10))
		{
			m_WorkNumb = WorkNumb;
		}
		else
		{
			m_WorkNumb = 0;
		}

		if (HomeNumb > pow(10, 5) and HomeNumb < pow(10, 6))
		{
			m_HomeNumb = HomeNumb;
		}
		else
		{
			m_HomeNumb = 0;
		}
	}
	
	inline char* GetName();
	inline int GetMobNumb();
	inline int GetHomeNumb();
	inline int GetWorkNumb();
	inline char* GetInfo();


	inline void* TakeName(char*name);
	inline void TakeMobNumb(int MobNumb);
	inline void TakeHomeNumb(int HomeNumb);
	inline void TakeWorkNumb(int WorkNumb);
	inline void* TakeInfo(char* Info);
	~NumbBook();
};
 char* NumbBook::GetInfo()
{
	return m_info;
}
 int NumbBook::GetWorkNumb()
{
	return m_WorkNumb;
}
 int NumbBook::GetHomeNumb()
{
	return m_HomeNumb;
}
 int NumbBook::GetMobNumb()
{
	return m_MobNumb;
}
char* NumbBook::GetName()
{
	return m_name;
}




void *NumbBook::TakeName(char* name)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}
void NumbBook::TakeMobNumb(int  MobNumb)
{
	m_MobNumb = MobNumb;
}

void NumbBook::TakeHomeNumb(int HomeNumb)
{
	m_HomeNumb = HomeNumb;
}

void NumbBook::TakeWorkNumb(int WorkNumb)
{
	m_WorkNumb = WorkNumb;
}

void* NumbBook::TakeInfo(char* Info)
{
	m_info = new char[strlen(Info) + 1];
	strcpy(m_info, Info);
}



NumbBook::~NumbBook()
{
	delete m_info;
	delete m_name;
}

