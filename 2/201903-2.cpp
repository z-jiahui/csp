#include <bits/stdc++.h>
using namespace std;

int calculate(int n1, int n2, char op)
{
	int result;
	switch(op)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case 'x':
			result = n1 * n2;
			break;
		case '/':
			result = n1 / n2;
			break;
		default :
			break;
	}
	
	return result;
 } 

int main()
{
	int n;
	int lenth = 7;	//���幫ʽ���� 
	string buffs;
	vector<string> str;
	 
	
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> buffs;
		str.push_back(buffs);
	}
	
	//��str�д�ŵ����б��ʽ���ν��д��� 
	for(int m=0;m<n;m++)
	{ 
		stack<char> sym;	//�������ջ 
		stack<int> opr;		//��׺���㸨��
		string rpn; 
		//����׺���ʽ�л�Ϊ��׺���ʽ 
		buffs = str[m];
		for(int i=0;i<lenth;i++)
		{
			//����ֱ�Ӽӵ�rpn�� 
			if(buffs[i] >= '0' && buffs[i] <= '9')
			{
				rpn.push_back(buffs[i]);
			}
			/*1.����������ţ���ջ�գ���ջ�� 
			* 2.����ǰ�������ȼ�����ջ������ջ��
			* 3.����ǰ���ȼ����ڻ����ջ������ջ�����ż���rpn����ǰ������ջ
			* 4.���ջ��ʣ��Ԫ�����μ���rpn 
			*/ 
			else
			{
				if(sym.empty())	//ջΪ�� 
					sym.push(buffs[i]);
				else if(buffs[i]=='x' || buffs[i]=='/')	//ֻ������������ţ���* /����ȼ���ߣ�ֻ�ж��Ƿ���� 
				{
					if(sym.top()=='x' || sym.top()=='/')
					{
						rpn.push_back(sym.top());
						sym.pop();
					}
					sym.push(buffs[i]);
//debug
//cout << buffs[i] << endl; 
				}
				 
				else if(buffs[i]=='+' || buffs[i]=='-')	 //ֻ������������ţ���+ -����ȼ���ͣ�����3����
				{
					rpn.push_back(sym.top());
					sym.pop();
					sym.push(buffs[i]);
				 } 
			 } 
		}
		//������Ŵ�����4
		while(!sym.empty())
		{
			rpn.push_back(sym.top());
			sym.pop();
		} 
		
//debug
//cout << rpn << endl;
		
		//�����׺���ʽ
		int num1=0, num2=0, res=0;
		for(int i=0;i<lenth;i++)
		{
			//����������ţ�����ջ���������ֽ������㣬�������ѹ��ջ�� 
			if(rpn[i]<'0' || rpn[i]>'9')
			{
				num1 = opr.top();
				opr.pop();
				num2 = opr.top();
				opr.pop();
				res = calculate(num2, num1, rpn[i]);
				opr.push(res);
				
//debug
//cout << num1 << ' ' << num2 << ' '<< res << endl;
			}
			//��������ֱ����oprջ 
			else
			{
				opr.push(rpn[i] - '0');
			}
		}
		//�ж�24��
		if(res==24)
			cout <<"Yes" << endl;
		else
			cout << "No" << endl;
		
		//��ظ���ջ���ַ�������
		//�򱾴���ĸ���������forѭ���ڳ�ʼ�����ʲ������㣻 
			 
	}
	
	 
	return 0;
}
