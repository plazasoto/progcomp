#include <stdio.h>
#include <stack>
#include <math.h> 
using namespace std;
int main(){
	stack<unsigned long long int> pila;
	unsigned long long int n;

	while(scanf("%llu",&n)!=EOF){
		pila.push(n);
	}

	while(!pila.empty()){
		printf("%.4f\n" ,sqrt((double)pila.top()));
		pila.pop();
	}
	return 0;
}