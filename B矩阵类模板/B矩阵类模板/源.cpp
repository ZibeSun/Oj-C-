#include<iostream>
using namespace std;
template<class T>
class Matrix
{
protected:
	int m;
	int n;
	T** data;
	T** transdata;
public:
	Matrix(int x, int y)
	{
		m = x;
		n = y;
		data = new T* [m];			  //先创建m行
		for (int i = 0; i < m; i++)
		{
			data[i] = new T[n];       //再创建n列
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
		transdata = new T * [n];			  //先创建m行
		for (int i = 0; i < n; i++)
		{
			transdata[i] = new T[m];       //再创建n列
		}
	}
	~Matrix()
	{
		delete[] data;
	}
	void transpose()     //矩阵转置
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				transdata[i][j] = data[j][i];
		}
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << transdata[i][j] << " ";
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
		char type;
		int m, n;
		cin >> type;
		if (type == 'I')
		{
			cin >> m >> n;
			Matrix<int> a(m, n);
			a.transpose();
			a.show();
		}
		else if (type == 'D')
		{
			cin >> m >> n;
			Matrix<double> a(m, n);
			a.transpose();
			a.show();
		}
		else if (type == 'C')
		{
			cin >> m >> n;
			Matrix<char> a(m, n);
			a.transpose();
			a.show();
		}
	}
	return 0;
}
/*题目描述
设计一个矩阵类模板Matrix，支持任意数据类型的数据。

要求至少包含2个成员函数：矩阵转置函数transport、以及打印输出函数print

编写main函数进行测试，调用类的成员函数完成转置和输出。

输入
第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入两个参数m和n，分别表示矩阵的行和列

接下来输入矩阵的元素，一共m行，每行n个数据

输出
输出转置后的矩阵

样例输入
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i
样例输出
1 4
2 5
3 6
a d g
b e h
c f i*/