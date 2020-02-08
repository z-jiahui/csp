#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, max, min, buff1, buff2, midn, flag = 0;
	float midf;
	cin >> n;
	for(int i=1; i<n+1; i++)
	{
		cin >> buff1;
		if(i==1)
			max = buff1;
		if(i==n)
			min = buff1;
		
		if(2*(n/2) == n){	//n为偶数 
			if(i == n/2)
				buff2 = buff1;
			if(i == n/2+1)
				if((buff1 + buff2)%2==0)	//中位数为偶数 
					midn = (buff1 + buff2) / 2;
				else
				{
					midf = ((float)buff1 + (float)buff2) / 2;
					flag = 1;
				}
		}
		else{				//n为奇数 
			if(i == (n+1)/2 )
				midn = buff1;
		}
		
	}
	
	if(max < min)
		swap(max, min);
	
	if(flag == 0)
		cout << max << ' ' << midn << ' ' << min;
	else
		printf("%d %.1f %d", max, midf, min);
	
	return 0;
	
 } 
