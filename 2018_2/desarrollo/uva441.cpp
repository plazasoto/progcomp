#include <stdio.h>

//int q;

int maxG(int i, int k){
	return k-6+i;
}

void eek(int k, int* g, int i){
	if(g[i]<maxG(i,k))
		g[i]++;
	else{//if(g[i]>maxG(i,k)){
		if(g[i]!=g[i-1]+1)
			g[i]=g[i-1]+2;
		eek(k,g,i-1);	////f
	}
	
}

int main(){
	int k;//>6
	scanf("%d",&k);
	while(1){
		int s[k],i=0,game[]={0,1,2,3,4,5};
		while(i<k){
			scanf("%d",&s[i]);
			i++;
		}
		//
		//q=0;
		printf("%d %d %d %d %d %d\n",s[game[0]],s[game[1]],s[game[2]],s[game[3]],s[game[4]],s[game[5]]);
		//printf("%d %d %d %d %d %d\n",game[0],game[1],game[2],game[3],game[4],game[5]);
		while(game[0]!=k-6){
			eek(k,game,5);
			printf("%d %d %d %d %d %d\n",s[game[0]],s[game[1]],s[game[2]],s[game[3]],s[game[4]],s[game[5]]);
		//	printf("%d %d %d %d %d %d\n",game[0],game[1],game[2],game[3],game[4],game[5]);
		}	
		
		scanf("%d",&k);
		if(k==0)break;
		printf("\n");
	}
	return 0;
}