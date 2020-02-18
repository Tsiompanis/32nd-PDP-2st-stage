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
//    freopen("longsumk.in","r",stdin);        
//    freopen("longsumk.out","w",stdout);      
	
	
	int n, k, help, out, temp;
	scanf("%d %d",&n, &k);
	
	scanf("%d",&data[0]);
	if(data[0] == k)
	{
		out = 1;
	}
	
	for(int i = 1; i < n; i++)
	{
		scanf(" %d",&help);
		help += data[i-1];
		data[i] = help;
		if(help == k)
		{
			out = 1;
		}
	}
	
	
	for(int i = 0; i < n; i++)
	{
		temp = i+1;
		if(data[i] == k && temp > out)
		{
			out = i+1;
		}
	}
	

	for(int i = 1; i < n; i++)
	{
		if(i == n-1) break;
		
		for(int j = i+1; j < n; j++)
		{
			if(data[j] - data[i-1] == k && j-i > out)
			{
				out = j-i+1;
			}
		}
		
	}
	
	
	
	
	
	printf("%d\n",out);
	return 0;
}
