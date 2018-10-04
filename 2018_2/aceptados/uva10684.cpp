#include <bits/stdc++.h>

int main(){
	int n, in, m1, m2;
	scanf("%d", &n);
	while(n>0){
		m1=0; m2=0;
		for(int i=0; i<n; i++){
			scanf("%d",&in);
			if(m1>m2){
				m2=m1;
			}
			m1+=in;
			if(m1<0){
				m1=0;
			}
		}
		m2=std::max(m2,m1);
		if(m2>0)
			printf("The maximum winning streak is %d.\n", m2);
		else
			printf("Losing streak.\n");
		scanf("%d",&n);
	}
	return 0;
}