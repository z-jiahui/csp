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
	int lenth = 7;	//定义公式长度 
	string buffs;
	vector<string> str;
	 
	
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> buffs;
		str.push_back(buffs);
	}
	
	//对str中存放的所有表达式依次进行处理 
	for(int m=0;m<n;m++)
	{ 
		stack<char> sym;	//运算符号栈 
		stack<int> opr;		//后缀计算辅助
		string rpn; 
		//将中缀表达式切换为后缀表达式 
		buffs = str[m];
		for(int i=0;i<lenth;i++)
		{
			//数字直接加到rpn中 
			if(buffs[i] >= '0' && buffs[i] <= '9')
			{
				rpn.push_back(buffs[i]);
			}
			/*1.对于运算符号，若栈空，入栈： 
			* 2.若当前运算优先级高于栈顶，入栈；
			* 3.若当前优先级低于或等于栈顶，则栈顶符号加入rpn，当前符号入栈
			* 4.最后将栈中剩余元素依次加入rpn 
			*/ 
			else
			{
				if(sym.empty())	//栈为空 
					sym.push(buffs[i]);
				else if(buffs[i]=='x' || buffs[i]=='/')	//只有四则运算符号，故* /运算等级最高，只判断是否相等 
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
				 
				else if(buffs[i]=='+' || buffs[i]=='-')	 //只有四则运算符号，故+ -运算等级最低，步骤3处理
				{
					rpn.push_back(sym.top());
					sym.pop();
					sym.push(buffs[i]);
				 } 
			 } 
		}
		//运算符号处理步骤4
		while(!sym.empty())
		{
			rpn.push_back(sym.top());
			sym.pop();
		} 
		
//debug
//cout << rpn << endl;
		
		//处理后缀表达式
		int num1=0, num2=0, res=0;
		for(int i=0;i<lenth;i++)
		{
			//遇到运算符号，弹出栈顶两个数字进行运算，并将结果压入栈中 
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
			//遇到数字直接入opr栈 
			else
			{
				opr.push(rpn[i] - '0');
			}
		}
		//判断24点
		if(res==24)
			cout <<"Yes" << endl;
		else
			cout << "No" << endl;
		
		//相关辅助栈和字符串清零
		//因本代码的辅助变量在for循环内初始化，故不用清零； 
			 
	}
	
	 
	return 0;
}
