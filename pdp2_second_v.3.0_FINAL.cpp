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
	
	
	int n, k, help, out, temp, current, prev, out_for_now, now, start;
	scanf("%d %d",&n, &k);
	
	
	//SCAN THE FIRST DAY'S VALUE
	scanf("%d",&data[0]);
	current = data[0];
	
	
	for(int i = 1; i < n; i++) scanf(" %d",&data[i]);
	
	for(int i = 1; i < n; i++)
	{
		while(current > k && start < i - 1)
		{
			current -= data[start];
			start++;
		}
		
		if(current == k && i - 1 - start > out)
			out = i - start;
		
		if (i < n)
        	current = current + data[i]; 
	}
	

	
	
	printf("%d\n",out);
	return 0;
}
