#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t=0, s1, s2, s3;
	scanf("%d",&n);
	int trees[n];
	for (int i = 0; i < n; ++i){
		scanf("%d",&trees[i]);
		t+=trees[i];
	}
	t/=2;
	int ii, j, k;
	for(int i = 0; i < n; ++i){
		s1=trees[i];
		ii=i;
		j=(i+1)%n;
		while(s1 < t){//si s1 > t, se deja de acumular y se pasa a reiniciar s1 con el siguiente arbol
			s2=trees[j];
			while(s1 + s2 < t){//s1 + s2 deben ser exactamente t para continuar con la comprobacion de la otra mitad del rectangulo
				j=(j+1)%n;
				s2+=trees[j];
			}
			if(s1 + s2 == t){//ver si s3 == s1
				k=(j+1)%n;
				s3=trees[k];
				while(s3 < s1){
					k=(k+1)%n;
					s3+=trees[k];
				}
				if(s3 == s1){//seguir sumando hasta s3 == t
					do{
						k=(k+1)%n;
						s3+=trees[k];
					}while(s3 < t);
					if(s3 == t && (k+1)%n == i){//correcto
						cout << "Y" << endl;
						return 0;
					}
				}
			}
			ii=(ii+1)%n;
			s1+=trees[ii];
		}

	}
	cout << "N" << endl;
	return 0;
}
