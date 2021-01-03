#include<iostream>
using namespace std;
template<class T>
void wudi(T* yitian, T* tulong,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tulong[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << yitian[i];
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		char type;
		cin >> type >> n;
		if (type == 'I')
		{
			int* yitian = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			int* tulong = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
		else if (type == 'C')
		{
			char* yitian = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			char* tulong = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
		else if (type == 'D')
		{
			double* yitian = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			double* tulong = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
	}
	return 0;
}
/*题目描述
江湖中有一个传言，只要倚天剑和屠龙刀中暗藏的秘密拼到一起，就能得到天下无敌的内功秘笈。设计一个函数模板，完成拼凑的功能（将倚天剑的秘密连接到屠龙刀的后面），并将秘笈输出. 其中每个秘密由n个元素组成，类型为T。

输入
第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数据类型，I表示整数类型，D表示双精度数类型，C表示字符型；然后输入n表示数据个数。

第三行输入倚天剑的n个数据

第四行输入屠龙刀的n个数据

依次输入t个实例

输出
每行输出一个结果

样例输入
2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello
样例输出
2700515351279
hellokitty*/