/* USER: 32pdpu17  
LANG: C++  
TASK: longsumk*/  
#include <stdio.h>        
#include <cstdio>        
#include <algorithm>        
#include <iostream>      
#include <array>  
#include <vector>  
#include <bits/stdc++.h>  
 
using namespace std;  
int data[1000005];

int main()
{
	//initializing freopen functions  
    freopen("longsumk.in","r",stdin);        
    freopen("longsumk.out","w",stdout);      
	
	
	int n, k, help, out, temp, current, prev, out_for_now, now;
	scanf("%d %d",&n, &k);
	
	
	//SCAN THE FIRST DAY'S VALUE
	scanf("%d",&data[0]);
	if(data[0]<=out) out_for_now++;
	
	
	for(int i = 1; i < n; i++)
	{
		scanf(" %d",&now);
		if(data[i-1] + now <= k)
		{
			data[i] = data[i-1] + now;
			out_for_now++;
		}
		
		if(data[i-1] + now > k)
		{
			data[i] = now;
			if(data[i-1] == k && out_for_now > out)
			{
				out = out_for_now;
			}
			if(data[i] > k) out_for_now = 0;
			if(data[i] <= k) out_for_now = 1;
		}
		
	}
	

	
	
	printf("%d\n",out);
	return 0;
}
