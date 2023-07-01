#include<stdio.h>

int memory[1000];

int f(int n){
	if(n<=1){
		return n;
	}
	
	if(memory[n]!=0){
		return memory[n];
	}
	return memory[n]=f(n-1)+f(n-2);
}

int countWays(int n){
	return f(n);
}

int main(){
	
	int n = 7;
	
	int ways = countWays(n);
	
	printf("The number of ways to reach %dth stair are: %d", n, ways);
	
	return 0;
}
