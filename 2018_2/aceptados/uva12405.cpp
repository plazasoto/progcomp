#include <stdio.h>

int main(){
	int n,m;

	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&m);
		char campo[m];
		scanf("%s",campo);
		
		int cobertura[m]={0};
		int sc = 0, j = 1;
		while(j<m){
			if(campo[j-1]=='.'){
				sc++;
				cobertura[j-1]=1;
				cobertura[j]=1;
				cobertura[j+1]=1;
				j+=3;
			}
			else{
				j++;
			}
		}
		if(cobertura[m-1]==0 && campo[m-1]=='.')
			sc++;
		printf("Case %d: %d\n", i, sc);
	}

	return 0;
}