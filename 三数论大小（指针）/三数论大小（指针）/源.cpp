#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int *p1, * p2, * p3, * max, * min, * h;
	int t, a, b, c, i;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		p1 = &a, p2 = &b, p3 = &c;
		if (*p1 > *p2)
		{
			if (*p1 > *p3)
			{
				max = p1;
				if (*p2 < *p3)
				{
					min = p2;
					h = p3;
				}
				else if (*p2 > *p3)
				{
					min = p3;
					h = p2;
				}
			}
			else if (*p1 < *p3)
			{
				max = p3;
				min = p2;

			}
		}
		else if (*p1 < *p2)
		{
			if (*p2 > *p3)
			{
				max = p2;
				if (*p1 > *p3)
				{
					min = p3;
					h = p1;
				}
				else if (*p1 < *p3)
				{	min = p1;
					h = p3;
				}
			}
			else if (*p2 < *p3)
			{
				max = p3;
				min = p1;
				h = p2;
			}
		}
		cout << *max<<" "<<*h;

		printf(" ");
		cout << *min << endl;
	}
}
/*题目描述
输入三个整数，然后按照从大到小的顺序输出数值。

要求：用三个指针分别指向这三个整数，排序过程必须通过这三个指针来操作，不能直接访问这三个整数

输出时，必须使用这三个指针，不能使用存储三个整数的变量

输入
第一行输入t表示有t个测试实例

第二行起，每行输入三个整数

输入t行

输出
每行按照从大到小的顺序输出每个实例

在每行中，每个数据输出后都带有一个空格，即使该行最后一个数据输出后也要再输出一个空格

样例输入
3
2 4 6
88 99 77
111 333 222
样例输出
6 4 2 
99 88 77 
333 222 111 */