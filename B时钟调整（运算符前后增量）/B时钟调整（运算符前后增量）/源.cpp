#include<iostream>
using namespace std;
class Counter
{
protected:
	int value;
public:
	Counter()
	{
		value = 20;
	}
	Counter(int v)
	{
		value = v;
	}
	void print()
	{
		cout << value;
	}
	int get()
	{
		return value;
	}
	void incrse()
	{
		value++;
	}
	void reduce()
	{
		value--;
	}
};
class LoopCounter :public Counter
{
private:
	int min_value;
	int max_value;
public:
	LoopCounter()
	{
		min_value = 0;
		max_value = 100;
	}
	LoopCounter(int v, int min_v, int max_v) :Counter(v)
	{
		min_value = min_v;
		max_value = max_v;
	}
	void increment(int k)
	{
		if (value >= max_value)
			value = min_value;
		for (int i = 0; i < k; i++)
		{
			if ((value >= min_value) && (value < max_value))
			{
				if (value >= max_value)
					value = min_value;
				value++;
				if (value >= max_value)
					value = min_value;
			}
		}
		if (value >= max_value)
			value = min_value;
	}
	void reducement(int k)
	{
		if (value <= min_value)
			value = max_value-1;
		for (int i = 0; i < k; i++)
		{
			if ((value >= min_value) && (value <= max_value))
			{
				if (value <= min_value)
					value = max_value;
				value--;
				if (value <= min_value)
					value = max_value;
			}
		}
		if (value <= min_value)
			value = max_value-1;
	}
};
class shizhong
{
private:
	LoopCounter hour;
	LoopCounter minute;
	LoopCounter second;
public:
	shizhong(LoopCounter& h, LoopCounter& m, LoopCounter& sec)
	{
		hour = h;
		minute = m;
		second = sec;
	}
	void time(int s)
	{
		int m;
		int h;
		m = s / 60;
		h = s / 3600;
		if (((s - m * 60) + second.get()) >= 60)
			minute.incrse();
		if (((m - h * 60) + minute.get()) >= 60)
			hour.incrse();
		second.increment(s);
		minute.increment(m);
		hour.increment(h);
	}
	void s_time(int s)
	{
		int m;
		int h;
		m = s / 60;
		h = s / 3600;
		if ((second.get()-(s - m * 60)) <= 0)
			minute.reduce();
		if ((minute.get()-(m - h * 60)) <= 0)
			hour.reduce();
		second.reducement(s);
		minute.reducement(m);
		hour.reducement(h);
	}
	void show()
	{
		hour.print();
		cout << ":";
		minute.print();
		cout << ":";
		second.print();
		cout << endl;
	}
	friend shizhong operator++(shizhong& a);
	friend shizhong operator--(shizhong& a, int);
};
shizhong operator++(shizhong& a)
{
	a.time(1);
	return a;
}
shizhong operator--(shizhong& a, int)
{
	a.s_time(1);
	return a;
}
int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	LoopCounter h1(h, 0, 12);
	LoopCounter m1(m, 0, 60);
	LoopCounter s1(s, 0, 60);
	shizhong sz(h1, m1, s1);
	int n;
	cin >> n;
	while (n--)
	{
		int p;
		cin >> p;
		if (p > 0)
		{
			for (int i = 0; i < p; i++)
			{
				++sz;
			}
		}
		else
		{
			for (int i = 0; i > p; i--)
			{
				sz--;
			}
		}
		sz.show();
	}
	return 0;
}
/*题目描述
假定一个时钟包含时、分、秒三个属性，取值范围分别为0~11，0~59，0~59，具体要求如下：

1、用一元运算符++，并且是前增量的方法，实现时钟的调快操作。例如要把时钟调快5秒，则执行5次”  ++<对象> “ 的操作

2、用一元运算符--，并且是后增量的方法，实现时钟的调慢操作。例如要把时钟调慢10秒，则执行10次” <对象>-- “的操作

3、用构造函数的方法实现时钟对象的初始化，用输出函数实现时钟信息的输出

clock和time是系统内部函数，所以不要用来做类名或者其他

输入
第一行输入时钟的当前时间时、分、秒

第二行输入t表示有t个示例

第三行输入t个整数x，如果x为正整数，则表示执行调快操作，使用重载运算符++；如果x为负整数，则表示执行调慢操作，使用重载运算符--

每次的调快或调慢操作都是承接上一次调整后的结果进行，例如先调快10秒，再调慢2秒，那么调慢2秒是接着调快10秒后的结果进行的

输出
每行输出每个时钟调整操作后的时分秒

样例输入
11 58 46
4
5 70 -22 -55
样例输出
11:58:51
0:0:1
11:59:39
11:58:44*/