#include<iostream>
using namespace std;
class HomeMachine
{
protected:
	int number;
	int power;
public:
	HomeMachine()
	{

	}
	HomeMachine(int in_number,int in_power)
	{
		number = in_number;
		power = in_power;
	}
	virtual void printf()
	{

	}
};
class Fan :virtual public HomeMachine
{
protected:
	int wind_direction;
	int wind_level;
public:
	Fan(int wd, int wl)
	{
		wind_direction = wd;
		wind_level = wl;
	}
	void wdcontrol(int wd)
	{
		wind_direction = wd;
	}
	void wlcontrol(int wl)
	{
		wind_level = wl;
	}
};
class Humidifier :virtual public HomeMachine
{
protected:
	float actual_water;
	float max_water;
public:
	Humidifier(int aw, int mw)
	{
		actual_water = aw;
		max_water = mw;
	}
	int warning()
	{
		if (actual_water >= (max_water / 2))
			return 1;
		else if ((actual_water < (max_water / 2)) && (actual_water >= (max_water / 10)))
			return 2;
		else
			return 3;
	}
};
class HumidifierFan :public Fan, public Humidifier
{
protected:
	int mode;
public:
	HumidifierFan(int in_number, int in_power, int wd, int wl, int aw, int mw, int m) : HomeMachine(in_number, in_power), Fan(wd, wl), Humidifier(aw, mw)
	{
		mode = m;
	}
	void modecontrol(int m)
	{
		if (m == 1)
		{
			wdcontrol(0);
			wlcontrol(1);
			mode = m;
		}
		else if (m == 2)
		{
			wdcontrol(1);
			wlcontrol(2);
			mode = m;
		}
		else if (m == 3)
		{
			wdcontrol(1);
			wlcontrol(3);
			mode = m;
		}
	}
	virtual void printf()
	{
		cout << "��ʪ����--��λ" << mode << endl << "���" << number << "--����" << power << "W" << endl;
		if (wind_direction == 0)
			cout << "���򴵷�--";
		else
			cout << "��ת����--";
		cout << "����" << wind_level << "��" << endl;
		cout << "ʵ��ˮ����" << actual_water << "��--";
		if (warning() == 1)
			cout << "ˮ������" << endl;
		else if(warning() == 2)
			cout << "ˮ��ƫ��" << endl;
		else if (warning() == 3)
			cout << "ˮ������" << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, p, wd, wl, aw, mw, m;
		int c_m;
		cin >> n >> p >> wd >> wl >> aw >> mw >> m >> c_m;
		HumidifierFan a(n, p, wd, wl, aw, mw, m);
		a.modecontrol(c_m);
		a.printf();
	}
	return 0;
}
/*��Ŀ����
��֪�ҵ��б�š����ʵ����ԣ����Զ���������������������ʹ�ӡ��

����ȼ̳мҵ���ص㣬�����������ԣ�������������ͷ��������з���Ϊ0��ʾ���򴵷磬״̬Ϊ1��ʾ��ת���硣
���Ȱ��������²�����������ƺͷ�������
1��������ƺ�һ�������������޷��أ��ѷ�������Ϊ����ֵ������Ϊ0��ʾ���򴵷磬Ϊ1��ʾ��ת���硣
2���������ƺ�һ�������������޷��أ��ѷ�������Ϊ����ֵ��������ʾ������������1����2����3���ȡ�
��ʪ���̳мҵ���ص㣬�����������ԣ�����������ʵ��ˮ���������ˮ����
����������Ԥ�����޲���������ֵΪ��������ʵ��ˮ������С�����ˮ������50%���򷵻�1��С��50%�Ҳ�С��10%�򷵻�2��С��10%�򷵻�3
��ʪ���ȼ̳��˷��Ⱥͼ�ʪ�����ص㣬�������Ե�λ��������
��������������λ����һ���������޷���ֵ�������õ�λΪ����ֵ���ٵ��÷�����ƺͷ�������������������ԣ�������
1������Ϊ0���������������޸�
2������Ϊ1�����ö��򴵷��ҷ���1��
3������Ϊ2��������ת�����ҷ���2��
4������Ϊ3��������ת�����ҷ���3��
��λֻ������0��1��2��3�ĸ���ֵ��������ֵ���ԡ�
��ʪ�������ش�ӡ�����������ʽ�ο����������Ҫ�����£�
1���������Ϊ0����������򴵷磬����Ϊ1�������ת���硣
2������Ԥ�������������ݷ��ؽ��1��2��3�����ͬ��Ϣ���ֱ��ǣ�ˮ��������ˮ��ƫ�͡�ˮ������
����Ҫ��
1����������̳л���ʵ�����������Ĺ�ϵ����ȷ˭������ࡢ���ࡢ������
2�������������Ĺ���Ҫ��������ࡢ��������Թ���
�������������Զ�����public�����������˼���C++����ʵ������Ҫ��
����
��һ������t����ʾ��t��ʵ��
�ڶ�������һ����ʪ���ȵ���Ϣ�����ΰ�����š����ʡ����򡢷�����ʵ��ˮ���������ˮ���� ��λ
����������һ����������ʾ���������ĵ�λ��Ȼ��ִ�е���������
�Դ����ƣ�����t��ʵ��
���
����ÿ��ʵ�������ô�ӡ���������ʪ���ȵ�����״̬

��������
3
1001 1000 1 2 3 4 0
1
2002 2000 0 1 1 12 0
3
3003 3000 0 3 2 10 0
0
�������
��ʪ����--��λ1
���1001--����1000W
���򴵷�--����1��
ʵ��ˮ����3��--ˮ������
��ʪ����--��λ3
���2002--����2000W
��ת����--����3��
ʵ��ˮ����1��--ˮ������
��ʪ����--��λ0
���3003--����3000W
���򴵷�--����3��
ʵ��ˮ����2��--ˮ��ƫ��*/