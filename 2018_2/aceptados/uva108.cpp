#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)==1){
		int maxsum = INT_MIN, sub;
		int sum[n][n];
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				scanf("%d",&sub);
				sum[i][j]=sub;
				if(j>0)
					sum[i][j]+=sum[i][j-1];
				if(i>0)
					sum[i][j]+=sum[i-1][j];
				if(i>0 && j>0)
					sum[i][j]-=sum[i-1][j-1];
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				sub = sum[i][j];
				if(sub>maxsum){
					maxsum=sub;
				}
				for (int k = 0; k < i; ++k){
					sub = sum[i][j] - sum[k][j];
					if(sub>maxsum){
						maxsum=sub;
					}
					for (int l = 0; l < j; ++l){
						sub = sum[i][j] - sum[k][j] - sum[i][l] + sum[k][l];
						if(sub>maxsum){
							maxsum=sub;
						}
					}
				}
				for (int k = 0; k < j; ++k){
					sub = sum[i][j] - sum[i][k];
					if(sub>maxsum){
						maxsum=sub;
					}
				}
			}
		}
		printf("%d\n",maxsum);
	}
	return 0;
}