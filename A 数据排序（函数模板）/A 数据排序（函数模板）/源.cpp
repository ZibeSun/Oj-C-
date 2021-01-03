#include<iostream>
using namespace std;
template<class T>
T* sort(T* p,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < (n - 1); k++)
		{
			if (p[k] > p[k + 1])
			{
				T mid = p[k];
				p[k] = p[k + 1];
				p[k + 1] = mid;
			}
		}
	}
	return p;
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
			int* p = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			int* m = sort(p, n);
			for (int i = 0; i < n; i++)
			{
				cout << m[i] << " ";
			}
			delete[] p;
		}
		else if (type == 'C')
		{
			char* p = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			for (int i = 0; i < n; i++)
			{
				cout << sort(p, n)[i] << " ";
			}
			delete[] p;
		}
		else if (type == 'S')
		{
			string* p = new string[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			string* m = sort(p, n);
			for (int i = 0; i < n; i++)
			{
				cout << m[i] << " ";
			}
			delete[] p;
		}
		else if (type == 'D')
		{
			double* p = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			for (int i = 0; i < n; i++)
			{
				cout << sort(p, n)[i] << " ";
			}
			delete[] p;
		}
		cout << endl;
	}
	return 0;
}
/*题目描述
编写一个进行升序排序的函数模板，其中数组为具有n个元素，类型为T。

注意：必须使用模板函数

输入
第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符型，S表示字符串型，D表示双精度数类型；然后输入n表示数组长度。

第三行输入n个数据

依次输入t个实例

输出
每行输出一个结果

样例输入
4
I 10
15 3 51 27 9 35 78 14 65 8
D 3
-11.3 25.42 13.2
C 6
a b g e u q
S 4
sandy david eason cindy
样例输出
3 8 9 14 15 27 35 51 65 78 
-11.3 13.2 25.42 
a b e g q u 
cindy david eason sandy */