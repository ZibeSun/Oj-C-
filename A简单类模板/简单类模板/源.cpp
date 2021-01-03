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
/*��Ŀ����
����һ���б��࣬���б�������ԣ���ֵ�б��ó���Ϊ100�������ʾ�������ݳ��ȣ�ʵ�ʵ����ݸ������������ķ�������ʼ�������롢ɾ������ӡ����������Ϊ��

1����ʼ�����������������������ݱ�������ֵ�б��У�δʹ�õ��б���ȫ����ʼ��Ϊ-1

2�����룬�������������Ĳ���λ�úͲ�����ֵ������λ�ô�0��ʼ���㣬ע��Ӳ���λ�ÿ�ʼ��ԭ�����ݶ�Ҫ�����ƶ�һλ�������ݳ���+1

3��ɾ������������������ɾ��λ�ã�ɾ��λ�ô�0��ʼ���㣬ע���ɾ��λ�ú�һλ��ʼ��ԭ�����ݶ�Ҫ��ǰ�ƶ�һλ�������ݳ���-1

4����ӡ���Ѱ��������ݰ�λ��˳�����һ�У�����֮�䵥���ո����

ʹ����ģ��ķ�����ʹ�������֧������int���ͺ͸�����double����

����
��һ�����������n��ʾ��n�����ݣ���������n������

�ڶ�������������������ʾ����λ�úͲ�����ֵ����ֵΪ����

����������ɾ��λ��

���������������n��ʾ��n�����ݣ���������n��������

����������������������ʾ����λ�úͲ�����ֵ����ֵΪ������

����������ɾ��λ��

���
���ͷ�������룬�ֱ�ִ�г�ʼ�������������ɾ�����������ô�ӡ��������б��������������

��Խ��ŵ��������룬�ֱ�ִ�г�ʼ�������������ɾ�����������ô�ӡ��������б�����ĸ���������

��������
5 11 22 33 44 55
2 888
4
5 1.1 2.2 3.3 4.4 5.5
2 88.8
3
�������
11 22 888 33 55
1.1 2.2 88.8 4.4 5.5*/