#include<stdio.h>
int main()
{
	int t, i, a[100], sum;
	scanf("%d", &t);
	while(t--)
	{
		for (i = 0;i < 3;i++)
		{
			scanf("%d", &a[i]);
		}
		if ((a[0] + a[1] > a[2]) && (a[1] == a[2]))
			sum = 1;
		else
			sum = 0;
		printf("%d\n", sum);
	}
	return 0;
}
/*题目描述
对以下表达式进行求值，a、b、c是三个变量，它们都是小于100的自然数

a+b>c&&b==c

输入
第一行输入T，表示后续有T个测试示例

第二行开始，每行输入3个变量值，输入T行

输出
每行输出计算结果

样例输入
3
5 6 7
4 5 5
6 1 9
样例输出
0
1
0*/