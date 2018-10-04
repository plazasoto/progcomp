#include <bits/stdc++.h>

std::vector<int> dp(51,0);
int fib(int n){
	if(n<=1) return 1;
	if(dp[n]!=0) return dp[n];
	dp[n]=fib(n-1)+fib(n-2);
	return dp[n];
}

int main(){
	int n, f1, f2, a;
	scanf("%d", &n);
	while(n>0){/*
		f1=1; f2=1;
		for(int i=1; i<n; i++){
			a=f2;
			f2+=f1;
			f1=a;
		}*/
		printf("%d\n", fib(n)); //f2);
		scanf("%d",&n);
	}
	return 0;
}