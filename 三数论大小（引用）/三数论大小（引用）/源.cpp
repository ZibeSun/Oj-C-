#include<iostream>
using namespace std;
void bj(int p1, int p2, int p3)
{
	int max, h, min;
	if (p1 > p2)
	{
		if (p1 >  p3)
		{
			max = p1;
			if (p2 < p3)
			{
				min = p2;
				h = p3;
			}
			else if (p2 > p3)
			{
				min = p3;
				h = p2;
			}
		}
		else if (p1 < p3)
		{
			max = p3;
			min = p2;

		}
	}
	else if (p1 < p2)
	{
		if (p2 > p3)
		{
			max = p2;
			if (p1 > p3)
			{
				min = p3;
				h = p1;
			}
			else if (p1 < p3)
			{
				min = p1;
				h = p3;
			}
		}
		else if (p2 < p3)
		{
			max = p3;
			min = p1;
			h = p2;
		}
	}
	cout << max << " " << h<< " "<<min << endl;
}
int main()
{
	int t,a,b,c;
	int& p1 = a;
	int& p2 = b;
	int& p3 = c;
	cin >> t;
	while (t--)
	{
		cin >> a
			>> b
			>> c;
		bj(p1, p2, p3);
	}
	return 0;
}
/*题目描述
输入三个整数，然后按照从大到小的顺序输出数值。

要求：定义一个函数，无返回值，函数参数是三个整数参数的引用，例如int &a, int &b, int &c。在函数内通过引用方法来对三个参数进行排序。主函数调用这个函数进行排序。

要求：不能直接对三个整数进行排序，必须通过函数而且是引用的方法。

输入
第一行输入t表示有t个测试实例

第二行起，每行输入三个整数

输入t行

输出
每行按照从大到小的顺序输出每个实例，三个整数之间用单个空格隔开

样例输入
3
2 4 6
88 99 77
111 333 222
样例输出
6 4 2
99 88 77
333 222 111*/