#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Hotel
{
public:
	void Set(char* a_Customer)
	{
		strcpy(m_CustomerName, a_Customer);
		m_TotalCustNum++;
		m_TotalEearning += m_Rent;
		m_CustomrrerID = 20150000 + m_TotalCustNum;
	}
	void SetRent(float l)
	{
		m_Rent = l;
	}
	~Hotel()
	{
		delete []m_CustomerName;
	}
	void Display()
	{
		cout << m_CustomerName << " " << m_CustomrrerID << " " << m_TotalCustNum << " " << m_TotalEearning << endl;
	}
private:
	static int m_TotalCustNum;
	static float m_TotalEearning;
	static float m_Rent;
	char* m_CustomerName=new char[99];
	int m_CustomrrerID=0;
};
int Hotel::m_TotalCustNum = 0;
float Hotel::m_TotalEearning = 0;
float Hotel::m_Rent = 0;
int main()
{
	float m;
	cin >> m;
	Hotel a[999];
	int i = 0;
	for (;; i++)
	{
		char* n = new char[99];
		cin >> n;
		if (n[0] == '0')
		{
			break;
		}
		else
		{
			//cout << n << endl;
			a[i].SetRent(m);
			//cout << n << endl;
			a[i].Set(n);
			//cout << n << endl;
			a[i].Display();
		}
		//delete[]n;
	}
	return 0;
}/*题目描述
编写程序，统计某旅馆住宿客人的总数和收入总额。要求输入客人的姓名，输出客人编号（2015+顺序号，顺序号4位，如第1位为0001，第2位为0002，依此类推）、姓名、总人数以及收入总额。总人数和收入总额用静态成员，其他属性采用普通的数据成员。旅馆类声明如下：




输入
第1行：输入旅馆单个顾客房租

第2行开始，依次输入顾客姓名，0表示输入结束。

输出
每行依次输出顾客信息和当前旅馆信息。包括顾客姓名，顾客编号，旅馆当前总人数，旅馆当前总收入。

样例输入
150  
张三 李四 王五 0
样例输出
张三 20150001 1 150
李四 20150002 2 300
王五 20150003 3 450*/