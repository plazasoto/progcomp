#include <bits/stdc++.h>
using namespace std;

int t[21][201];

void gasto(vector<vector<int> > pre, int mon, int co){
	for(int b=0; b<pre[co].size(); ++b){
		if(mon-pre[co][b]>=0 && t[co][mon-pre[co][b]]!=1){
			t[co][mon-pre[co][b]]=1;
			if(co+1<pre.size())
				gasto(pre, mon-pre[co][b], co+1);
		}
	}
}

int main(){
	int n, m, c, k, p;
	vector<vector<int> > precios;
	scanf("%d", &n);
	for(int caso=0; caso < n; ++caso){
		precios.clear();
		scanf("%d%d", &m, &c);
		memset(t, 0, sizeof(t));
		for(int g=0; g < c; ++g){
			scanf("%d", &k);
			vector<int> temp;
			for(int i = 0; i < k; ++i){
				scanf("%d", &p);
				temp.push_back(p);
			}
			precios.push_back(temp);
		}
		gasto(precios,m,0);
		bool sol = false;
		int r;
		for(int x=0; x<m; ++x){
			if(t[c-1][x]==1){
				sol=true;
				r=m-x;
				cout << r << endl;
				break;
			}
		}
		if(!sol)
		cout << "no solution" << endl;
	}
	return 0;
}