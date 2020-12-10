#include<iostream>
#include<cstring>
using namespace std;
class Phone
{
protected:
	char type;
	char* number;
	int state;
public:
	Phone(char ty, char* n, int st)
	{
		type = ty;
		number = new char[12];
		number = n;
		state = st;
	}
	Phone(Phone& s)
	{
		type = 'D';
		number = new char[12];
		for (int i = 0; i < 12; i++)
		{
			number[i] = s.number[i];
		}
		number[11] = 'X';
		number[12] = '\0';
		state = s.state;
	}
	void stop()
	{
		state = 3;
	}
	void print()
	{
		if (type == 'A')
		{
			cout << "类型=机构";
		}
		else if (type == 'B')
		{
			cout << "类型=企业";
		}
		else if (type == 'C')
		{
			cout << "类型=个人";
		}
		else if (type == 'D')
		{
			cout << "类型=备份";
		}
		cout << "||号码=" << number;
		if (state == 1)
		{
			cout << "||State=在用" << endl;
		}
		else if (state == 2)
		{
			cout << "||State=未用" << endl;
		}
		else if (state == 3)
		{
			cout << "||State=停用";
		}
	}
};
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void print()
	{
		cout << "||停机日期=" << year << "." << month << "." << day << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char ty;
		char* n=new char[11];
		int st,y,m,d;
		cin >> ty >> n >> st >> y >> m >> d;
		Phone p1(ty, n, st);
		Phone p2(p1);
		Date a(y, m, d);
		cout << "Construct a new phone " << n << endl;
		p1.print();
		cout << "Construct a copy of phone " << n << endl;
		p2.print();
		cout << "Stop the phone " << n << endl;
		p1.stop();
		p1.print();
		a.print();
		cout << "----" << endl;
	}
	return 0;
}
/*题目描述
设计一个类来实现手机的功能。它包含私有属性：号码类型、号码、号码状态、停机日期；包含方法：构造、拷贝构造、打印、停机。
1、号码类型表示用户类别，只用单个字母，A表示机构，B表示企业、C表示个人
2、号码是11位整数，用一个字符串表示
3、号码状态用一个数字表示，1、2、3分别表示在用、未用、停用
4、停机日期是一个日期对象指针，在初始化时该成员指向空，该日期类包含私有属性年月日，以及构造函数和打印函数等
----------------------------------------
5、构造函数的作用就是接受外来参数，并设置各个属性值,并输出提示信息，看示例输出
6、拷贝构造的作用是复制已有对象的信息，并输出提示信息，看示例输出。
      想一下停机日期该如何复制，没有停机如何复制？？已经停机又如何复制？？
7、打印功能是把对象的所有属性都输出，输出格式看示例
8、停机功能是停用当前号码，参数是停机日期，无返回值，操作是把状态改成停用，并停机日期指针创建为动态对象，并根据参数来设置停机日期，最后输出提示信息，看示例输出
-------------------------------------------
要求：在主函数中实现号码备份的功能，对已有的虚拟手机号的所有信息进行复制，并将号码类型改成D表示备份；将手机号码末尾加字母X
输入
第一行输入t表示有t个号码

第二行输入6个参数，包括号码类型、号码、状态、停机的年、月、日，用空格隔开

依次输入t行

输出
每个示例输出三行，依次输出原号码信息、备份号码信息和原号码停机后的信息

每个示例之间用短划线（四个）分割开，看示例输出

样例输入
2
A 15712345678 1 2015 1 1
B 13287654321 2 2012 12 12
样例输出
Construct a new phone 15712345678
类型=机构||号码=15712345678||State=在用
Construct a copy of phone 15712345678
类型=备份||号码=15712345678X||State=在用
Stop the phone 15712345678
类型=机构||号码=15712345678||State=停用||停机日期=2015.1.1
----
Construct a new phone 13287654321
类型=企业||号码=13287654321||State=未用
Construct a copy of phone 13287654321
类型=备份||号码=13287654321X||State=未用
Stop the phone 13287654321
类型=企业||号码=13287654321||State=停用||停机日期=2012.12.12
----*/