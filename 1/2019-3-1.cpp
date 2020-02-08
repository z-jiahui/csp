#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, max, min, mid, buff1, buff2;
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
				mid = (buff1 + buff2) / 2;
		}
		else{				//n为奇数 
			if(i == (n+1)/2 )
				mid = buff1;
		}
		
	}
	
	if(max < min)
		swap(max, min);
	
	cout << max << ' ' << mid << ' ' << min;
	
	return 0;
	
 } 
