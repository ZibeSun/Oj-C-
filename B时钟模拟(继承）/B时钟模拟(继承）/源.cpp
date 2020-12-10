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
};
class LoopCounter:public Counter
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
	LoopCounter(int v,int min_v,int max_v):Counter(v)
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
};
class shizhong
{
private:
	LoopCounter hour;
	LoopCounter minute;
	LoopCounter second;
public:
	shizhong(LoopCounter &h, LoopCounter &m, LoopCounter &sec)
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
		if (((s-m*60) + second.get()) >= 60)
			minute.incrse();
		if (((m-h*60) + minute.get()) >= 60)
			hour.incrse();
		second.increment(s);
		minute.increment(m);
		hour.increment(h);
		hour.print();
		cout << ":";
		minute.print();
		cout << ":";
		second.print();
		cout << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int h, m, sec, s;
		cin >> h >> m >> sec >> s;
		LoopCounter h1(h, 0, 24);
		LoopCounter m1(m, 0, 60);
		LoopCounter sec1(sec, 0, 60);
		/*int m2;
		int h2;
		m2 = s / 60;
		h2 = m2 / 60;
		h1.increment(h);
		m1.increment(m);
		sec1.increment(s);
		h1.print();
		cout << ":";
		m1.print();
		cout << ":";
		sec1.print();
		cout << endl;*/
		shizhong sz(h1, m1, sec1);
		sz.time(s);
	}
	return 0;
}
/*题目描述
定义计数器类，包含保护数据成员value,公有函数increment计数加1。

定义循环计算器继承计数器类，增加私有数据成员：最小值min_value，最大值max_value,

重写公有函数increment，使得value在min_value~max_value区间内循环+1。

定义时钟类，数据成员是私有循环计数器对象小时hour、分钟minute、秒second，公有函数time(int s)计算当前时间经过s秒之后的时间，即hour,minute,second的新value值。

定义时钟类对象，输入当前时间和经过的秒数,调用time函数计算新时间。

根据题目要求，增加必要的构造函数、析构函数和其他所需函数。

因为clock是系统内置函数，为了避免重名，请不要使用clock作为类名或者函数名

输入
第一行测试次数n

2行一组，第一行为当前时间（小时 分钟 秒），第二行为经过的秒数。

输出
输出n行

每行对应每组当前时间和经过秒数后计算得到的新时间（小时：分钟：秒）。

样例输入
2
8 19 20
20
23 30 0
1801
样例输出
8:19:40
0:0:1*/