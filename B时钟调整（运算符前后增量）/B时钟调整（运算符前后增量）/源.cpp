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
/*��Ŀ����
�ٶ�һ��ʱ�Ӱ���ʱ���֡����������ԣ�ȡֵ��Χ�ֱ�Ϊ0~11��0~59��0~59������Ҫ�����£�

1����һԪ�����++��������ǰ�����ķ�����ʵ��ʱ�ӵĵ������������Ҫ��ʱ�ӵ���5�룬��ִ��5�Ρ�  ++<����> �� �Ĳ���

2����һԪ�����--�������Ǻ������ķ�����ʵ��ʱ�ӵĵ�������������Ҫ��ʱ�ӵ���10�룬��ִ��10�Ρ� <����>-- ���Ĳ���

3���ù��캯���ķ���ʵ��ʱ�Ӷ���ĳ�ʼ�������������ʵ��ʱ����Ϣ�����

clock��time��ϵͳ�ڲ����������Բ�Ҫ������������������

����
��һ������ʱ�ӵĵ�ǰʱ��ʱ���֡���

�ڶ�������t��ʾ��t��ʾ��

����������t������x�����xΪ�����������ʾִ�е��������ʹ�����������++�����xΪ�����������ʾִ�е���������ʹ�����������--

ÿ�εĵ��������������ǳн���һ�ε�����Ľ�����У������ȵ���10�룬�ٵ���2�룬��ô����2���ǽ��ŵ���10���Ľ�����е�

���
ÿ�����ÿ��ʱ�ӵ����������ʱ����

��������
11 58 46
4
5 70 -22 -55
�������
11:58:51
0:0:1
11:59:39
11:58:44*/