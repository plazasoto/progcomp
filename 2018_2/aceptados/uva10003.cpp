#include <bits/stdc++.h>
using namespace std;

int tabla[51][51];


int corte(int inicio, int fin, vector<int> *v, int i1, int i2){
	if(tabla[i1][i2]!=-1)
		return tabla[i1][i2];
	if(i1==i2){
		tabla[i1][i2]=0;
		return 0;
	}
	int x=INT_MAX;

	for (int ia = i1; ia!=i2; ++ia){
		x=min(x, 	corte(v->at(ia), 	fin, 		v, 	ia + 1, 	i2)
				+ 	corte(inicio, 		v->at(ia), 	v, 	i1, 		ia));
	}

	tabla[i1][i2] = fin - inicio + x;
	return fin - inicio + x;
}

int main(){
	int l,n,a, r;
	scanf("%d",&l);
	while(l!=0){
		scanf("%d",&n);
		vector<int> c;
		for(int i=0; i<n; i++){
			scanf("%d",&a);
			c.push_back(a);
		}
		memset(tabla, -1, sizeof(tabla));
		r=corte(0, l, &c, 0, n);

		printf("The minimum cutting is %d.\n", r);
		scanf("%d",&l);
	}
	return 0;
}