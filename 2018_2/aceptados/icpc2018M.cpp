#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, p=0, c=0, a;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
		scanf("%d",&a);
		if(a>p){
			++c;
		}
		p=a;
	}
	printf("%d\n", c);
	return 0;
}