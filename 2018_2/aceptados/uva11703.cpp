#include <bits/stdc++.h>
using namespace std;
vector<int> t(1000000,-1);
int xi(int i){
	if(i==0)
		return t[0];
	int i1,i2,i3;
	i1=floor(i-sqrt(i));
	if(t[i1]==-1)
		t[i1]=xi(i1);

	i2=floor(log(i));
	if(t[i2]==-1)
		t[i2]=xi(i2);

	i3=floor(i*pow(sin(i),2));
	if(t[i3]==-1)
		t[i3]=xi(i3);

	return (t[i1] + t[i2] + t[i3])%1000000;
}

int main(){
	int n;
	t[0]=1;
	scanf("%d",&n);
	while(n>=0){
		cout << xi(n) << endl;
		scanf("%d",&n);
	}
	return 0;
}