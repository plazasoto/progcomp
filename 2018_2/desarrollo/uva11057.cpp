#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
//#include <string>

//respuesta incorrecta. Probablemente error al leer input
int main(){
	int n, m=-1;
	//std::string name;
	while(scanf("%d",&n) != EOF){
		if(m!=-1)
			printf("\n");
		int books[n], i, j;
		for(i=0; i<n; i++){
			scanf("%d",&books[i]);
		}
		
	//	std::getline(std::cin,name);

		scanf("%d",&m);

	//	std::getline(std::cin,name);
		//fin de entrada
		int book1, book2, dif=1000001;
		for(i=0; i<n-1; i++){
			int koob = m - books[i];//precio de libro j para que con i sumen m
			for(j=i+1; j<n; j++){
				if(books[j]==koob && abs(books[i]-books[j])<dif){
					book1 = books[i];
					book2 = books[j];
					dif = abs(books[i]-books[j]);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n",book2,book1);
	}

	return 0;
}