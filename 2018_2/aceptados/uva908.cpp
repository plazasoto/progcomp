#include <bits/stdc++.h>

using namespace std;

bool alltrue(bool *b, int n){
	for(int i=0;i<n;i++){
		if(!b[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int N;//nodos
	bool loop=false;
	while(scanf("%d",&N)!=EOF){
		if(loop)printf("\n");
		int ci = 0, cf = 0;
		bool incluir[N]={false};

		int arcos[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				arcos[i][j]=INT_MAX;
			}
		}

		int T[N-1][3];//lineas usadas en solucion actual
		for(int i=0; i<N-1; i++){
			scanf("%d%d%d",&T[i][0],&T[i][1],&T[i][2]);
			ci+=T[i][2]; //el costo total inicial
			
			if(arcos[T[i][0]-1][T[i][1]-1]>T[i][2]){
				arcos[T[i][0]-1][T[i][1]-1]=T[i][2];
				arcos[T[i][1]-1][T[i][0]-1]=T[i][2];
			}
		}

		int K;
		scanf("%d",&K);
		int B[K][3];//lineas nuevas
		for(int i=0; i<K; i++){
			scanf("%d%d%d",&B[i][0],&B[i][1],&B[i][2]);

			if(arcos[B[i][0]-1][B[i][1]-1]>B[i][2]){
				arcos[B[i][0]-1][B[i][1]-1]=B[i][2];
				arcos[B[i][1]-1][B[i][0]-1]=B[i][2];
			}
		}

		int M;
		scanf("%d",&M);
		int C[M][3];//lineas anteriormente disponibles
		for(int i=0; i<M; i++){
			scanf("%d%d%d",&C[i][0],&C[i][1],&C[i][2]);

			if(arcos[C[i][0]-1][C[i][1]-1]>C[i][2]){
				arcos[C[i][0]-1][C[i][1]-1]=C[i][2];
				arcos[C[i][1]-1][C[i][0]-1]=C[i][2];
			}
		}
		


		incluir[0]=true;
		while(!alltrue(incluir,N)){
			int minim=INT_MAX, vecMin;
			for(int i=0;i<N;i++){
				if(incluir[i]){
					for(int j=0;j<N;j++){
						if(i!=j && !incluir[j] && arcos[i][j] < minim){
							minim=arcos[i][j];
							vecMin=j;
						}
					}
				}
			}
			cf+=minim;
			incluir[vecMin]=true;
		}

		printf("%d\n%d\n", ci, cf);
		loop=true;
	}
	return 0;
}