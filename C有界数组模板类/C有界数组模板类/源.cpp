#include<iostream>
using  namespace std;
template<class T>
class BoundArray
{
protected:
	int num;
	T value[100];
public:
	BoundArray(int n, T* v)
	{
		num = n;
		for (int i = 0; i < num; i++)
		{
			value[i] = v[i];
		}
	}
	void sort()
	{
		T mid;
		for (int i = 0; i < num; i++)
		{
			for (int k = 0; k < (num - 1); k++)
			{
				if (value[k] > value[k + 1])
				{
					mid = value[k];
					value[k] = value[k + 1];
					value[k + 1] = mid;
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			if (i == (num - 1))
				cout << value[i] << endl;
			else
				cout << value[i] << " ";
		}
	}
	void search(T vs)
	{
		int i;
		for (i = 0; i < num; i++)
		{
			if (value[i] == vs)
			{
				cout << i << endl;
				break;
			}
		}
		if(i==num)
			cout << -1 << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char type;
		int n;
		cin >> type;
		cin >> n;
		if (type == 'I')
		{
			int* v = new int[n];
			int vs;
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			cin >> vs;
			BoundArray<int> a(n, v);
			a.sort();
			a.search(vs);
			delete[] v;
		}
		else if (type == 'D')
		{
			double* v = new double[n];
			double vs;
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			cin >> vs;
			BoundArray<double> a(n, v);
			a.sort();
			a.search(vs);
			delete[] v;
		}
		else if (type == 'C')
		{
			char* v = new char[n];
			char vs;
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			cin >> vs;
			BoundArray<char> a(n, v);
			a.sort();
			a.search(vs);
			delete[] v;
		}
	}
	return 0;
}
/*题目描述
编写有界数组模板BoundArray（即检查对数组元素下标引用并在下标越界时终止程序的执行），能够存储各种类型的数据。要求实现对数组进行排序的方法sort，及对数组进行查找的方法search。

输入
第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入数组的元素个数

然后输入每个元素

最后输入要查找的元素

输出
首先输出从小到大排序的元素

然后输出查找元素的结果，找到则输出下标，下标为排序后的下标，没找到则输出-1

样例输入
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1
样例输出
1 2 
1
2.9 3.5 6.2 
-1*/