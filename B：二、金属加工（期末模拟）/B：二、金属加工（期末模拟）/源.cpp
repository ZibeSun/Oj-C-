#include<iostream>
using namespace std;
class Metal
{
protected:
	int hardness;
	int weight;
	int volume;
public:
	Metal()
	{
		hardness = 0;
		weight = 0;
		volume = 0;
	}
	Metal(int h,int w,int v)
	{
		hardness = h;
		weight = w;
		volume = v;
	}
	friend Metal operator+(Metal& a, Metal& b);  //�ϲ�
	friend Metal operator*(Metal& a, int b);     //�޻�
	friend Metal operator++(Metal& a);           //Ӳ����ǰ����
	friend Metal operator--(Metal& a, int);      //����������
	void printf()
	{
		cout << "Ӳ��" << hardness << "--����" << weight << "--���" << volume << endl;
	}
};
Metal operator+(Metal& a, Metal& b)
{
	Metal sum;
	sum.hardness = a.hardness + b.hardness;
	sum.volume = a.volume + b.volume;
	sum.weight = a.weight + b.weight;
	return sum;
}
Metal operator*(Metal& a, int b)
{
	Metal sum; 
	sum.hardness = a.hardness;
	sum.volume = a.volume * b;
	sum.weight = a.weight;
	return sum;
}
Metal operator++(Metal& a)
{
	++a.hardness;
	a.volume = a.volume * 1.1;
	a.weight = a.weight * 1.1;
	return a;
}
Metal operator--(Metal& a, int)
{
	a.hardness--;
	a.volume = a.volume * 0.9;
	a.weight = a.weight * 0.9;
	return a;
}
int main()
{
	int h1, w1, v1, h2, w2, v2, n;
	cin >> h1 >> w1 >> v1 >> h2 >> w2 >> v2 >> n;
	Metal a(h1, w1, v1);
	Metal b(h2, w2, v2);
	(a + b).printf();
	(a * n).printf();
	(++a).printf();
	(b--).printf();
	return 0;
}
/*��Ŀ����
�ڽ����ӹ��У���������Ӳ�ȡ���������������ԣ��������������������ֲ�����
1���ϲ���ÿ����������Ժϲ���һ���µĽ������½�������������ԭ�������������֮�ͣ������Ӳ��Ҳ���Ƽ��㡣
2���޻�������ͨ�������紵�ķ�����޻���������n����������Ӳ�Ȳ���
3��Ӳ�����ڽ����м���߷��Ӳ��Ͽ���Ӳ��������ÿ����Ӳ��һ�������������������10%��
4�������ڽ����м������⻯ѧ��Һ���Խ��ͽ���Ӳ�ȣ�ÿ����Ӳ��һ�������������������10%
��������������������������ط�ʽʵ�ֽ��������ֲ������������ӡ����������Ҫ������
1���üӷ����������Ԫ�ķ�ʽʵ�ֺϲ�
2���ó˷����������Ԫ�ķ�ʽʵ�־޻����������������������󡢾޻�����
3����++���������Ա������ǰ�����ķ�ʽʵ��Ӳ��
4����--���������Ա�������������ķ�ʽʵ����
5����ӡ�������������������Ϣ�������ʽ���ο�����
  

�������������Ե���������ֻ�����������֡�

�������������Զ�����public�����������˼���C++����ʵ������Ҫ��

����
��һ�������һ���������Ϣ������Ӳ�ȡ����������

�ڶ�������ڶ����������Ϣ������Ӳ�ȡ����������

����������һ������n����ʾ�޻�n��

���
��һ�������������ϲ������Ϣ

�ڶ��������һ������޻�n������Ϣ

�����������һ���������Ӳ��һ�������Ϣ

����������ڶ����������Ӳ��һ�������Ϣ

��������
3 3000 300
5 5000 500
2
�������
Ӳ��8--����8000--���800
Ӳ��3--����3000--���600
Ӳ��4--����3300--���330
Ӳ��4--����4500--���450*/