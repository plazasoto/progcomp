#include <stdio.h>
#include <stack>

void poppo(std::stack<int> &s, int num){//vaciar stack e ingresar un valor
	while(!s.empty()){
		s.pop();
	}
	s.push(num);
}

void printStack(std::stack<int> s){
	printf("%d", s.top()+1);
	s.pop();
	while(!s.empty()){
		printf(" %d", s.top()+1);
		s.pop();
	}
	printf("\n");
}

int main(){
	int n, p;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &p);
		int vecinos[p]={0};
		int j=0, enl;
		while(j<p){
			vecinos[j]+=scanf("%d", &enl);
			enl=getchar();
			if(enl=='\n' || enl==EOF)
				j++;
		}

		std::stack<int> smin;
		smin.push(p-1);
		for(int j=p-2; j>=0; j--){
			if(vecinos[j] == vecinos[smin.top()]){
				smin.push(j);
			}
			else if(vecinos[j] < vecinos[smin.top()]){
				poppo(smin, j);
			}
		}

		printStack(smin);
	}
	return 0;
}