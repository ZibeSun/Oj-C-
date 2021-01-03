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
/*��Ŀ����
��д�н�����ģ��BoundArray������������Ԫ���±����ò����±�Խ��ʱ��ֹ�����ִ�У����ܹ��洢�������͵����ݡ�Ҫ��ʵ�ֶ������������ķ���sort������������в��ҵķ���search��

����
��һ��������t����ʾ��t����������

�ӵڶ��п�ʼ����ÿ���������������ݡ�

���������������ͣ�I��ʾint��D��ʾdouble��C��ʾchar���������������Ԫ�ظ���

Ȼ������ÿ��Ԫ��

�������Ҫ���ҵ�Ԫ��

���
���������С���������Ԫ��

Ȼ���������Ԫ�صĽ�����ҵ�������±꣬�±�Ϊ�������±꣬û�ҵ������-1

��������
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1
�������
1 2 
1
2.9 3.5 6.2 
-1*/