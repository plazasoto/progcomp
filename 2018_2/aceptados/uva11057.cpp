#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m=-1;

	while(scanf("%d",&n) != EOF){
		int books[n], i, j;
		for(i=0; i<n; i++){
			scanf("%d",&books[i]);
		}
		scanf("%d",&m);
		//fin de entrada

		int book1, book2, dif=1000001;
		for(i=0; i<n-1; i++){
			int koob = m - books[i];//precio de libro j para que con i sumen m
			for(j=i+1; j<n; j++){
				if(books[j]==koob && abs(books[i]-books[j])<dif){
					book1 = books[i]<books[j]?books[i]:books[j];
					book2 = books[i]<books[j]?books[j]:books[i];
					dif = abs(books[i]-books[j]);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",book1,book2);
	}

	return 0;
}