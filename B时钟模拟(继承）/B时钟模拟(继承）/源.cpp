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
/*��Ŀ����
����������࣬�����������ݳ�Աvalue,���к���increment������1��

����ѭ���������̳м������࣬����˽�����ݳ�Ա����Сֵmin_value�����ֵmax_value,

��д���к���increment��ʹ��value��min_value~max_value������ѭ��+1��

����ʱ���࣬���ݳ�Ա��˽��ѭ������������Сʱhour������minute����second�����к���time(int s)���㵱ǰʱ�侭��s��֮���ʱ�䣬��hour,minute,second����valueֵ��

����ʱ����������뵱ǰʱ��;���������,����time����������ʱ�䡣

������ĿҪ�����ӱ�Ҫ�Ĺ��캯���������������������躯����

��Ϊclock��ϵͳ���ú�����Ϊ�˱����������벻Ҫʹ��clock��Ϊ�������ߺ�����

����
��һ�в��Դ���n

2��һ�飬��һ��Ϊ��ǰʱ�䣨Сʱ ���� �룩���ڶ���Ϊ������������

���
���n��

ÿ�ж�Ӧÿ�鵱ǰʱ��;������������õ�����ʱ�䣨Сʱ�����ӣ��룩��

��������
2
8 19 20
20
23 30 0
1801
�������
8:19:40
0:0:1*/