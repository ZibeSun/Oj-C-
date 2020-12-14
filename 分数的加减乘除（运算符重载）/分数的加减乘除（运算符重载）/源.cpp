#include<iostream>
using namespace std;
class Fraction
{
protected:
	int numerator, denominator;
	int common_divisor();
	void contracted();
public:
	Fraction(int n = 0, int d = 1)
	{
		numerator = n;
		denominator = d;
	}
	Fraction(Fraction& f)
	{
		numerator = f.numerator;
		denominator = f.denominator;
	}
	Fraction operator +(Fraction& a)
	{
		Fraction sum;
		sum.denominator = a.denominator * denominator;
		sum.numerator = a.numerator * denominator + numerator * a.denominator;
		return sum;
	}
	Fraction operator-(Fraction& a)
	{
		Fraction sum;
		sum.denominator = a.denominator * denominator;
		sum.numerator = numerator * a.denominator - a.numerator * denominator;
		return sum;
	}
	Fraction operator*(Fraction& a)
	{
		Fraction sum;
		sum.denominator = a.denominator * denominator;
		sum.numerator = numerator * a.numerator;
		return sum;
	}
	Fraction operator/(Fraction& a)
	{
		Fraction sum;
		sum.denominator = denominator * a.numerator;
		sum.numerator = a.denominator* numerator;
		return sum;
	}
	void Set(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
	void disp()
	{
		cout << "fraction=" << numerator << "/" << denominator << endl;
	}
};
int main()
{
	int n1, d1, n2, d2;
	cin >> n1 >> d1 >> n2 >> d2;
	Fraction a;
	Fraction b;
	a.Set(n1, d1);
	b.Set(n2, d2);
	a.operator+(b).disp();
	a.operator-(b).disp();
	a.operator*(b).disp();
	a.operator/(b).disp();
	return 0;
}/*题目描述
Fraction类的基本形式如下：



要求如下：
1.实现Fraction类；common_divisor()和contracted()函数体可为空，不实现具体功能。
2.编写main函数，初始化两个Fraction对象的，计算它们之间的加减乘除。
输入
第1行：依次输入第1个和第2个Fraction对象的分子和分母值。

输出
每行依次分别输出加减乘除计算后的Fraction对象（直接输出分数值，不需要约简）。

样例输入
1 3 2 5
样例输出
fraction=11/15
fraction=-1/15
fraction=2/15
fraction=5/6*/