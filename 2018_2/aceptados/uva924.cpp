#include <bits/stdc++.h>

using namespace std;

struct amigo{
	int num;
	amigo *sig;
};

struct persona{
	bool rumor;
	amigo *lista;
};

int main(){
	int n, t, s, a ,b, bday, bsize;
	scanf("%d",&n);
	persona empleados[n];
	for (int i = 0; i < n; ++i)	{
		empleados[i].rumor=false;
		empleados[i].lista=NULL;
		scanf("%d",&a);
		for (int j = 0; j < a; j++){
			scanf("%d",&b);
			amigo *x = (amigo*)malloc(sizeof(amigo));
			x->num = b;
			x->sig = empleados[i].lista;
			empleados[i].lista = x;
		}

	}

	scanf("%d",&t);//leer nº de casos
	for (int i = 0; i < t; ++i)	{
		bday = 0;
		bsize = 0;
		scanf("%d",&s);
		empleados[s].rumor = true;
		stack<int> expand;
		expand.push(s);
		int day = 0, exsize;
		do{
			exsize = 0;
			day++;
			stack<int> tomorrow;
			while(!expand.empty()){
				amigo *pun = empleados[expand.top()].lista;
				while(pun!=NULL){
					if(!empleados[pun->num].rumor){
						empleados[pun->num].rumor=true;
						exsize++;
						tomorrow.push(pun->num);
					}
					pun = pun->sig;
				}
				expand.pop();
			}
			if(exsize > bsize){
				bsize = exsize;
				bday = day;
			}
			expand = tomorrow;
		}while(exsize > 0);
		
		if(bsize > 0)
			printf("%d %d\n", bsize, bday);
		else
			printf("0\n");

		for (int j = 0; j < n; ++j){
			empleados[j].rumor=false;
		}
	}

	return 0;
}