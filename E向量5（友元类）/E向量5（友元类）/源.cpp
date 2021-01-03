#include<iostream>
using namespace std;
class CVector
{
private:
	int* date;
	int m;
public:
	friend class CMatrix;
	CVector()
	{
		m = 5;
		int d[5] = { 0,1,2,3,4 };
		date = new int[m];
		for (int i = 0; i < m; i++)
		{
			date[i] = d[i];
		}
	}
	CVector(int m1)
	{
		m = m1;
		date = new int[m];
		for (int i = 0; i < m; i++)
		{
			cin >> date[i];
		}
	}
	~CVector()
	{
		delete[] date;
	}
	void printf()
	{
		for (int i = 0; i < m; i++)
		{
			if (i == (m - 1))
				cout << date[i] << endl;
			else
				cout << date[i] << " ";
		}
	}
};
class CMatrix
{
private:
	int n;
	int** data;
public:
	CMatrix(int x)
	{
		n = x;
		data = new int * [n];			  //先创建m行
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[n];       //再创建n列
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
	}
	~CMatrix()
	{
		delete[] data;
	}
	CVector multi(CVector& v)
	{
		CVector s;
		s.m = n;
		for (int i = 0; i < n; i++)
		{
			s.date[i] = 0;
			for (int k = 0; k < n; k++)
			{
				s.date[i] += data[i][k] * v.date[k];
			}
		}
		return s;
	}
	bool judge(CVector& v)
	{
		if (v.m == n)
			return true;
		else
		{
			return false;
		}
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		CMatrix a(n);
		cin >> m;
		CVector b(m);
		if (a.judge(b))
		{
			a.multi(b).printf();
		}
		else
			cout << "error" << endl;
	}
	return 0;
}
/*题目描述


在向量CVector类的代码上，定义n阶矩阵类CMatrix，包含私有数据成员M存储矩阵数据，n存储矩阵阶数。

将CMatrix定义为CVector的友元类。

为CMatrix添加成员函数：CVector Multi(const CVector &V1)，计算n阶矩阵与n维向量V1的乘积。

为CMatrix添加成员函数，判定矩阵与向量V1是否可计算乘积。

为CMatrix添加需要的构造函数、析构函数和其它成员函数。

主函数输入数据，测试矩阵与向量的乘积。

附：n阶矩阵包含n*

输入
测试次数t

对每组测试数据，格式如下

第一行，矩阵阶数n 向量维数m

n阶矩阵

m维向量

输出
对每组测试数据，若矩阵与向量不能计算乘积，输出error；否则输出计算结果

样例输入
1
3
1 0 0
0 1 0
0 0 1
3
1 2 3
样例输出
1 2 3*/