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
#include <unordered_map>  

using namespace std;  
vector<int> data;

int find(vector<int> data, int n, int k)
{
	//initialize some helping variables for the current sum and the max sum
	int current_sum = 0;
	int max_length = 0;
	//intialize unordered map to store the ending index
	unordered_map<int, int> map;
	
	for(int i = 0; i < n; i++)
	{
		//add the current day's value to the sum
		current_sum += data[i];
		
		//put the current sum with its index in the hash table!
		map[current_sum] = i;
		
		//for when sub-array starts from index zero
		if(current_sum == k) 
			max_length = i + 1;
		
		//check if (current sum) - k is in the hash table
		if(map.find(current_sum - k) != map.end())
		{
			//update the max length if the current length is bigger than the max length
			if(max_length < (i - map[current_sum-k]))
				max_length = i - map[current_sum-k];
		}	
	}
	return max_length;
}

int main()
{
	//initializing freopen functions  
	freopen("longsumk1.in","r",stdin);        
    freopen("longsumk.out","w",stdout);      
	
	//initializing variables and scanning them
	int n, k, help;
	scanf("%d %d",&n, &k);
	
	//scanning all of the other days and putting them in the array
	for(int i = 0; i < n; i++)
	{
		scanf(" %d",&help);
		data.push_back(help);
	}
	
	//we print the output coming from the "find" function and end the program!
	printf("%d\n",find(data, n, k));
	return 0;
}
