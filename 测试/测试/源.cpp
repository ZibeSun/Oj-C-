//#include<stdio.h>
#include<iostream>
using namespace std;
int test(int& a, int& b, int& c)
{
	a++;
	b++;
	c++;
	return c;
}
int main()
{
	int a = 5, b = 5, c = 10, d;
	string s, t;
	s = "test";
	t = s;
	d = test(a, b, c);
	cout << s << " " << t << endl;
	printf("%d %d %d %d", a, b, c, d);
}