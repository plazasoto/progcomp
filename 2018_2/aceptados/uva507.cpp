#include <bits/stdc++.h>
using namespace std;

int main(){
	int b, s, nice, ii, jj;
	scanf("%d", &b);
	for(int r = 1; r <= b; ++r){
		scanf("%d", &s);
		int n[s];
		for(int i = 1; i < s; ++i){
			scanf("%d", &n[i]);
		}
		nice = -1;
		ii=0;
		jj=0;
		for(int i = 1; i < s; ++i){
			int aux = 0;
			for(int j = i; j < s; ++j){
				aux+=n[j];
				if(aux>nice){
					nice = aux;
					ii=i;
					jj=j+1;
				}
				else if(aux == nice && j+1-i>jj-ii){
					ii=i;
					jj=j+1;
				}
				
			}
		}
		if(nice>0)
			printf("The nicest part of route %d is between stops %d and %d\n", r, ii, jj);
		else
			printf("Route %d has no nice parts\n", r);
	}
	return 0;
}