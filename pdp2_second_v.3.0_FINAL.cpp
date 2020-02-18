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
	
	//initializing variables and scanning them
	int n, k, out, current_sum, start;
	scanf("%d %d",&n, &k);
	
	//scanning the first day's value and put it at the 0th index so it doesn't get miscomputed
	scanf("%d",&data[0]);
	//setting the current sum to be the first value of the array
	current_sum = data[0];
	
	//scanning all of the other days and putting them in the array
	for(int i = 1; i < n; i++) scanf(" %d",&data[i]);
	
	//for every value of the array
	for(int i = 1; i < n; i++)
	{
		//while the current sum exceeds the max money variable (stated 'K' in the problem), remove the starting elements until the current sum is less than the max avaliable money
		while(current_sum > k && start < i - 1)
		{
			current_sum -= data[start];
			//increment the starting point
			start++;
		}
		
		//if the current sum is equal to the max money variable ('k') AND the duration (i-1 - start) is bigger than the biggest duration. The biggest duration becomes the current duration
		if(current_sum == k && i-1 - start > out)
			out = i - start;
		
		//if n is grater than i then we add the the i-th element to the current sum
		if (i < n)
        	current_sum += data[i]; 
	}
	//we print the output and end the program!
	printf("%d\n",out);
	return 0;
}
