#include<iostream>
#include<string.h>
using namespace std;
int bj(char* S, char* T)
{
	int a, b, i=0, d = 0, x = 0;
	a = strlen(S);
	b = strlen(T);
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else if (a == b)
	{
		while (*(S + i) != '\0')
		{
			if (*(S + i) > * (T + i))
				d++;
			else if (*(S + i) < *(T + i))
				x++;
			i++;
		}
		if (d > x)
			return 1;
		else if (d < x)
			return -1;
		else if (d == x)
			return 0;
	}
}
int main()
{
	int t,s;
	char h[999], k[999];
	char *S, *T;
	cin >> t;
	while (t--)
	{
		cin >> h;
		cin >> k;
		S = h;
		T = k;
		s = bj(S,T);
		if (s == 0)
			cout << 0 << endl;
		else if (s > 0)
			cout << 1 << endl;
		else if (s < 0)
			cout << -1 << endl;
	}
	return 0;
}
/*��Ŀ����
��дһ�������Ƚ������ַ����������������ַ�ָ�루Ҫ����ʽ���壬����char *S, char *T)���Ƚ��ַ���S��T�Ĵ�С�����S����T���򷵻�1�����SС��T�򷵻�-1�����S��T����򷵻�0��

�ȽϹ���

1.�������ַ�������ͬλ���ϵ��ַ����бȽϣ��ַ��Ĵ�С�Ƚ���ASCIIֵΪ׼

2.�ڱȽ��У�����ַ���S���ַ������ַ���T���ַ�����������С�ڵ�����������ΪS����T�����������S����T�����С����SС��T

����SΪaaccdd��TΪeebbbb��ÿ��λ�ñȽϵõ�Sǰ������ĸ��С��T������4����ĸ������T��������ΪS����T

3.��������ַ������Ȳ�ͬ����������ַ���Ϊ��

�������������������ַ����������øú��������жϣ����жϺ����б���ʹ�ú���������ָ������ַ��Ƚ�

����
����t��ʾ��t������ʵ��

����ÿ�������������ַ���

��������t��ʵ��

���
ÿ�����һ��ʵ���ıȽϽ��

��������
3
aaccdd
eebbbb
AAbb++
aaEE*-
zznnkk
aaaaaaa
�������
1
0
-1*/