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
}/*题目描述
定义一个复数类，通过重载运算符：+、-、*，实现两个复数之间的各种运算。



要求如下：
1.实现Complex类；
2.编写main函数，初始化两个Complex对象，计算它们之间的加减乘，并输出结果。
复数相乘的运算规则
设z1=a+bi，z2=c+di(a、b、c、d∈R)是任意两个复数，那么它们的积(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
输入
第1行：输入两个数值，分别为第一个Complex对象的实部和虚部。
第2行：输入两个数值，分别为第二个Complex对象的实部和虚部。
输出
第1行：两个Complex对象相加后的输出结果。
第2行：两个Complex对象相减后的输出结果。
第3行：两个Complex对象相乘后的输出结果。
样例输入
10 20
50 40
样例输出
Real=60 Image=60
Real=-40 Image=-20
Real=-300 Image=1400*/