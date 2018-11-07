#include <bits/stdc++.h>
int ne[20000][20000]={0};

int main(){
	int n, q, d, m, set=1, count;
	scanf("%d%d", &n, &q);
	while(n!=0 && q!=0){
		printf("SET %d:\n", set);
		++set;
		int N[n];
		for (int i = 0; i < n; ++i){
			scanf("%d", &N[i]);
		}
		for (int i = 1; i <= q; ++i){
			count=0;
			scanf("%d%d", &d, &m);
			
			printf("QUERY %d: %d\n", i, count);
		}

		scanf("%d%d", &n, &q);
	}
	return 0;
}