#include<iostream>
using namespace std;
class complex
{
public:
	complex()
	{

	}
	complex(double r, double i)
	{
		real = r;
		imag = i;
	}
	~complex()
	{
		real = 0;
		imag = 0;
	}
	void copy(complex& s)
	{
		real = s.real;
		imag = s.imag;
	}
	double getr()
	{
		return real;

	}
	double geti()
	{
		return imag;
	}
	friend complex addCom(complex c1, complex c2);
	friend void outCom(complex c);
	friend complex minusCom(complex c1, complex c2);
private:
	double real;
	double imag;
};
complex addCom(complex c1, complex c2)
{
	double r, i;
	r = c1.real + c2.real;
	i = c1.imag + c2.imag;
	complex c(r, i);
	return c;
}
void outCom(complex c)
{
	cout << "(" << c.real << "," << c.imag << ")" << endl;
}
complex minusCom(complex c1, complex c2)
{
	double r, i;
	r = c1.real - c2.real;
	i = c1.imag - c2.imag;
	complex c(r, i);
	return c;
}
int main()
{
	double p, q;
	int n;
	cin >> p >> q >> n;
	complex a(p, q);
	while (n--)
	{
		char x;
		double r, i;
		cin >> x >> r >> i;
		complex b(r, i);
		if (x == '+')
		{
			complex c(addCom(a, b).getr(), addCom(a, b).geti());
			outCom(c);
			a.copy(c);
		}
		else if (x == '-')
		{
			complex c(minusCom(a, b).getr(), minusCom(a, b).geti());
			outCom(c);
			a.copy(c);
		}
	}
	return 0;
}
/*��Ŀ����
��������������£�



Ҫ�����£�

1.     ʵ�ָ��������Ԫ����addCom��outCom��


2.   �ο�addCom����Ϊ����������һ����Ԫ����minusCom������ʵ�����������ļ���

3.     ��main�����У�ͨ����Ԫ������ʵ�ָ����ļӼ����͸����������


����
��1�У���1��������ʵ�����鲿

��2�У����������Ĵ�����ע�⣺���������㡣�������ɲο�����

  ��3�п�ʼ��ÿ�������������ͣ��Լ���������ĸ�����ʵ�����鲿����+����ʾ������ӣ���-����ʾ���������

���
 ÿ��������������Ľ�������������ʽΪ��(ʵ��,�鲿)����

��������
10 10
3
+ 20 10
- 15 5
+ 5 25
�������
(30,20)
(15,15)
(20,40)*/