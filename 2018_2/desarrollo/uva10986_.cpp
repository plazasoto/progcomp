#include <bits/stdc++.h>
using namespace std;

struct nodoL{
	int costoA, id;
	bool v;
	vector<pair<int, int> > list;
};

class comparar{
public:
	bool operator()(nodoL n1, nodoL n2){
		return n1.costoA > n2.costoA;
	}
};

typedef priority_queue<nodoL,vector<nodoL>,comparar > qp;

int main(){
	int N, n, m, s, t, w, s1, s2, dd;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){//casos
		scanf("%d%d%d%d",&n,&m,&s,&t);

		nodoL na;

		vector<nodoL> servers;
		for(int k=0;k<n;k++){
			
			na.v=false;
			na.costoA = INT_MAX;
			na.id = k;
			servers.push_back(na);
		}


		for(int j=0; j<m; j++){//conecciones
			scanf("%d%d%d",&s1,&s2,&w);//server-server-latency	
			servers[s1].list.push_back(make_pair(s2,w));
			servers[s2].list.push_back(make_pair(s1,w));
		}

		qp front;
		servers[s].costoA = 0;
		front.push(servers[s]);
		nodoL aux;
		pair<int, int> paux;

		do{
			aux=front.top();
			front.pop();

			servers[aux.id].v=true;

			int l = aux.list.size();
			for(int p=0; p<l; p++){
				paux = aux.list[p];
				if(!servers[paux.first].v){
					dd = aux.costoA + paux.second;
					if(servers[paux.first].costoA > dd){
						servers[paux.first].costoA = dd;
					}
					front.push(servers[paux.first]);
				}
			}
		}while(!front.empty() && aux.id != t);


		if(servers[t].costoA < INT_MAX)
			printf("Case #%d: %d\n", i, servers[t].costoA);
		else
			printf("Case #%d: unreachable\n", i);
	}
	return 0;
}