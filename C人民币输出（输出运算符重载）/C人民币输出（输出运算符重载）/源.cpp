#include<iostream>
using namespace std;
class rmb
{
protected:
	int yuan;
	int jiao;
	int fen;
	int money;
public:
	rmb()
	{
		yuan = 0;
		jiao = 0;
		fen = 0;
	}
	void set(double m)
	{
		m = m * 100;
		money = (int)m;
	}
	void separate()
	{
		yuan = money / 100;
		fen = money % 10;
		jiao = (money % 100 - fen) / 10;
	}
	friend ostream& operator<<(ostream& oo, rmb& a);
};
ostream& operator<<(ostream& oo, rmb& a)
{
	oo << "yuan=" << a.yuan << " " << "jiao=" << a.jiao << " " << "fen=" << a.fen << endl;
	return oo;
}
int main()
{
	int t;
	cin >> t;
	rmb* p = new rmb[t];
	for(int i=0;i<t;i++)
	{
		double m;
		cin >> m;
		p[i].set(m);
		p[i].separate();
		cout << p[i];
	}
	return 0;
}

/*��Ŀ����
����һ��������࣬����Ԫ���ǡ��������Ǹ��������ԣ�����������ʼ�������

��ʼ���ù��캯��ʵ�֣�����һ������������������ΪС�������λ������ת��ΪԪ���ǡ��֣���������1.23Ԫ���������캯��תΪ1Ԫ��2�ǡ�3��

���������Ԫ�Ƿֽ�������������ʽ��ʾ��

����OJ��������doubleǿ������ת����int�Ĵ�������ƫ������һ����С����(��0.000001)����(��������1.38�����������ڴ��еĴ洢ֵΪ1.379999��

������ȫ�ֺ������ط����α����ܵģ���������Ԫ���������ַ���������ʵ��

����
��һ������t��ʾ��t��ʵ��

�ڶ���������t����������������λС����ÿ����ֵ��ʾ��ԪΪ��λ������ҽ��

���
ÿ������Ѹ�����������ҽ�ת��ΪԪ�Ƿֵ�������ʽ�����忴���

��������
2
2.45
1.38
�������
yuan=2 jiao=4 fen=5
yuan=1 jiao=3 fen=8*/