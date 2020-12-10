#include<iostream>
#include<math.h>
using namespace std;
int isNumber(char *p)
{
	int c = 0, d = 0, k = 0,sum=0;
	while (p[k] != '\0')
	{
		if ((p[k] < 48) || (p[k] > 57))
			c++;
		else if ((p[k] >= 48) || (p[k] <= 57))
			d++;
		k++;
	}
	if (c == 0)
	{
		k = 0;
		while (d!=0)
		{
			if (p[k] == 48)
			{
				d--;
				k++;
			}
			else
			{
				while (d!=0)
				{
					sum = sum +  (p[k] - 48)*pow(10,d-1);
					d--;
					k++;
				}
			}
		}
		return sum;
		
	}
	else if (c > 0)
		return -1;
}
int main()
{
	int t;
	char a[999];
	char* p = a;
	cin >> t;
	while (t--)
	{
		int i = 0;
		cin >> a;
		cout << isNumber(p)<<endl;
	}
	return 0;
}
/*题目描述
输入一个字符串，判断这个字符串是否一个完全整数值的字符串，例如输入"1234"，那么表示整数1234，输入"12a3"就表示只是一个字符串，不是一个整数

要求编写函数isNumber，参数是一个字符指针，返回值是整数类型

如果字符串表示一个整数，则计算出这个整数并且返回

如果字符串不是表示一个整数，则返回-1

主函数必须调用isNumber来判断字符串，不能使用任何C++自带或第三方的类似函数

输入
输入t表示有t个测试实例

每行输入一个字符串

依次输入t行

输出
每行输出判断结果

样例输入
3
1234
567a
0890
样例输出
1234
-1
890*/