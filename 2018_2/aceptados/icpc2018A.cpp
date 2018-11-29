#include <bits/stdc++.h>
using namespace std;

int main(){
    float a;
    scanf("%f", &a);
    int pzz=360, n, d, r;
    while(floorf(a)!=a){
        a*=10;
        pzz*=10;
    }
    n=pzz;
    d=(int)a;
    r=n%d;
    while(r!=0){
        n=d;
        d=r;
        r=n%d;
    }
    cout << (pzz/d) << endl;
    return 0;
}
