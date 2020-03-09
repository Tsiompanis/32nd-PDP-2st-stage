/* USER: 32pdpu17  
LANG: C++  
TASK: longsumk*/ 
//ΑΓΝΟΗΣΕ ΤΑ 300 ΑΧΡΗΣΤΑ INCLUDES
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
	
	//variable initialization
	int n, k, help, current_sum;
	int out = 0;
	int pointer1 = 0;
	int pointer2 = 0;
	
	//scanning n and k
	scanf("%d %d",&n, &k);

	//making the array with the sums
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&help);
		data[i] = data[i-1] + help;
	}
	
	//while the second pointer is smaller than n:
	while(pointer2 < n)
	{
		//find the sum of the current sub-array
		current_sum = data[pointer2 + 1] - data[pointer1];
		
		//if the sum from the current sub-array is equal to k we update the "out" variable which stores the length of the longest sub-array with sum -k-
		if(current_sum == k)
		{
			if(pointer2 - pointer1 + 1 > out)
				out = pointer2 - pointer1 + 1;
			
			//increment the second pointer
			pointer2++;
		}
		
		//BUT if the current_sum is less than k then go ahead and increment the second pointer
		else if(current_sum < k)
			pointer2++;
		
		//else (the current_sum is bigger than k) increment the first pointer. And also if the first and second pointers are the same then increment the second one!
		else
		{
			pointer1++;
			if(pointer1 == pointer2)
				pointer2++;
		}
	}
	
	//print the solutiom and exit the program!
	printf("%d\n",out);
	return 0;
}
