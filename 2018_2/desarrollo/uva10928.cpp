#include <stdio.h>

int main(){
	int n, p;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &p);
		int vecinos[p]={0};
		int j=0, enl;
		while(j<p){
			vecinos[j]+=scanf("%d", &enl);
			enl=getchar();
			if(enl=='\n' || enl==EOF)
				j++;
		}
		for(int qwe=0; qwe<p; qwe++){
			printf("%d\n", vecinos[qwe]);
		}
	}
	return 0;
}