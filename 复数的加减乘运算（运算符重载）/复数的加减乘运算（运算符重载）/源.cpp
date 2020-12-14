#include<iostream>
using namespace std;
class Complex
{
protected:
	float Real, Image;
public:
	Complex(float x = 0, float y = 0) :Real(x), Image(y){}
	void set(float x, float y)
	{
		Real = x;
		Image = y;
	}
	friend Complex operator+(Complex& a, Complex& b);
	friend Complex operator-(Complex& a, Complex& b);
	friend Complex operator*(Complex& a, Complex& b);
	void show()
	{
		cout << "Real=" << Real << " " << "Image=" << Image << endl;
	}
};
Complex operator+(Complex& a, Complex& b)
{
	Complex sum;
	sum.Real = a.Real + b.Real;
	sum.Image = a.Image + b.Image;
	return sum;
}
Complex operator-(Complex& a, Complex& b)
{
	Complex sum;
	sum.Real = a.Real - b.Real;
	sum.Image = a.Image - b.Image;
	return sum;
}
Complex operator*(Complex& a, Complex& b)
{
	Complex sum;
	sum.Real = a.Real * b.Real - a.Image * b.Image;
	sum.Image = a.Image * b.Real + a.Real * b.Image;
	return sum;
}
int main()
{
	float  r1, i1, r2, i2;
	cin >> r1 >> i1 >> r2 >> i2;
	Complex a;
	Complex b;
	a.set(r1, i1);
	b.set(r2, i2);
	operator+(a, b).show();
	operator-(a, b).show();
	operator*(a, b).show();
	return 0;
}/*��Ŀ����
����һ�������࣬ͨ�������������+��-��*��ʵ����������֮��ĸ������㡣



Ҫ�����£�
1.ʵ��Complex�ࣻ
2.��дmain��������ʼ������Complex���󣬼�������֮��ļӼ��ˣ�����������
������˵��������
��z1=a+bi��z2=c+di(a��b��c��d��R)������������������ô���ǵĻ�(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
����
��1�У�����������ֵ���ֱ�Ϊ��һ��Complex�����ʵ�����鲿��
��2�У�����������ֵ���ֱ�Ϊ�ڶ���Complex�����ʵ�����鲿��
���
��1�У�����Complex������Ӻ����������
��2�У�����Complex������������������
��3�У�����Complex������˺����������
��������
10 20
50 40
�������
Real=60 Image=60
Real=-40 Image=-20
Real=-300 Image=1400*/