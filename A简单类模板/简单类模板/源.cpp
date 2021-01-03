#include<iostream>
using namespace std;
template<class T>
class List
{
protected:
	T value[100];
	T length;
public:
	List(T* v, int l)
	{
		length = l;
		for (int i = 0; i <length; i++)
		{
			value[i] = v[i];
		}
	}
	void insert(T v, int p)
	{
		T m1, m2;
		length++;
		for (int i = p; i < length; i++)
		{
			if (i == p)
			{
				m1 = value[i];
				m2 = value[i + 1];
				value[i] = v;
			}
			else if (i == (length - 1))
			{
				value[i] = m1;
			}
			else
			{
				value[i] = m1;
				m1 = m2;
				m2 = value[i + 1];
			}
		}
	}
	void d(T p)
	{
		T m1, m2;
		length--;
		for (int i = p; i < length; i++)
		{
			value[i] = value[i + 1];
		}
	}
	void printf()
	{
		for (int i = 0; i < length; i++)
		{
			if (i == (length - 1))
				cout << value[i] << endl;
			else
				cout << value[i] << " ";
		}
	}
};
int main()
{
	int n1, insertp1, insertvalue1, deletep1;
	cin >> n1;
	int* v1 = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		cin >> v1[i];
	}
	List<int> a(v1, n1);
	cin >> insertp1 >> insertvalue1 >> deletep1;
	a.insert(insertvalue1, insertp1);
	a.d(deletep1);
	a.printf();
	int n2, insertp2, deletep2;
	double insertvalue2;
	cin >> n2;
	double* v2 = new double[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> v2[i];
	}
	List<double> b(v2, n2);
	cin >> insertp2 >> insertvalue2 >> deletep2;
	b.insert(insertvalue2, insertp2);
	b.d(deletep2);
	b.printf();
	return 0;
}
/*题目描述
定义一个列表类，该列表包含属性：数值列表（用长度为100的数组表示），数据长度（实际的数据个数）；包含的方法：初始化、插入、删除、打印，方法定义为：

1）初始化，接受外来参数，把数据保存在数值列表中，未使用的列表部分全部初始化为-1

2）插入，接受外来参数的插入位置和插入数值，插入位置从0开始计算，注意从插入位置开始，原有数据都要往后移动一位，且数据长度+1

3）删除，接受外来参数的删除位置，删除位置从0开始计算，注意从删除位置后一位开始，原有数据都要往前移动一位，且数据长度-1

4）打印，把包含的数据按位置顺序输出一行，数据之间单个空格隔开

使用类模板的方法，使得这个类支持整数int类型和浮点数double类型

输入
第一行先输入参数n表示有n个数据，接着输入n个整数

第二行输入两个参数，表示插入位置和插入数值，数值为整数

第三行输入删除位置

第四行先输入参数n表示有n个数据，接着输入n个浮点数

第五行输入两个参数，表示插入位置和插入数值，数值为浮点数

第六行输入删除位置

输出
针对头三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的整数数据

针对接着的三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的浮点数数据

样例输入
5 11 22 33 44 55
2 888
4
5 1.1 2.2 3.3 4.4 5.5
2 88.8
3
样例输出
11 22 888 33 55
1.1 2.2 88.8 4.4 5.5*/