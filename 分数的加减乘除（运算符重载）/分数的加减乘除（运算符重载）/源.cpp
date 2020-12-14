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
}/*��Ŀ����
Fraction��Ļ�����ʽ���£�



Ҫ�����£�
1.ʵ��Fraction�ࣻcommon_divisor()��contracted()�������Ϊ�գ���ʵ�־��幦�ܡ�
2.��дmain��������ʼ������Fraction����ģ���������֮��ļӼ��˳���
����
��1�У����������1���͵�2��Fraction����ķ��Ӻͷ�ĸֵ��

���
ÿ�����ηֱ�����Ӽ��˳�������Fraction����ֱ���������ֵ������ҪԼ�򣩡�

��������
1 3 2 5
�������
fraction=11/15
fraction=-1/15
fraction=2/15
fraction=5/6*/