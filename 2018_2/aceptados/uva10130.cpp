#include <stdio.h>
#include <algorithm>
int main(){
	int caso, objetos, grupo;
	scanf("%d",&caso);
	for(int i=1; i <= caso; i++){//cada caso
		int total = 0;
		scanf("%d",&objetos);
		int precios[objetos], pesos[objetos];
		for(int j=0; j<objetos; j++){
			scanf("%d",&precios[j]);
			scanf("%d",&pesos[j]);
		}
		scanf("%d",&grupo);
		int pesoMaximo[grupo];
		for(int j=0; j < grupo; j++){
			scanf("%d",&pesoMaximo[j]);
		}//fin entrada

		//basado en el problema de la mochila
		for(int per=0; per<grupo; per++){//donde cada persona es una mochila

			int parcial[objetos+1][pesoMaximo[per]+1];
			for (int j=0; j <= pesoMaximo[per]; j++){
				parcial[0][j] = 0;
			}

			for (int k=1; k <= objetos; k++){
				for (int j=0; j <= pesoMaximo[per]; j++){
					if(pesos[k-1]<= j){
						parcial[k][j] = std::max(precios[k-1] + parcial[k-1][j - pesos[k-1]] , parcial[k-1][j]);
					}
					else
						parcial[k][j] = parcial[k-1][j] ;
				}
			}

			total = total + parcial[objetos][pesoMaximo[per]];
		}

		printf("%d\n", total);
	}

	return 0;
}