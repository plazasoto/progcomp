//Código conseguido de https://github.com/esbanarango/Competitive-Programming/blob/master/UVa/10986%20-%20Sending%20email.cpp
/*
  10986 - Sending email
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        SSSP on Weighted Graph, I used 'Competitive Programming 2' Dijkstra implementation.

*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;   //Un par de enteros. Se usa tanto en la lista de adyacencia como en la cola de prioridad del algoritmo de Dijkstra.
typedef vector <ii> vii;    //Usado para la lista de adyacencia del grafo, donde cada entero del par representa
                            //el número de un nodo y la latencia de la conexión con él.
typedef vector <int> vi;    //Usado para guardar las distancias a cada nodo para el algoritmo de Dijkstra.
#define INF 1000000000      //Se usa como valor inicial de las distancias a cada nodo.


void dijkstra(int s, vi *dist, vector<vii> *graph){ //Implementación del algoritmo de Dijkstra con cola de prioridad.
    priority_queue< ii, vector<ii>, greater<ii> > pq;   //Cola de prioridad de pares <int,int>, donde el primer elemento es la distancia
                                                        //al nodo indicado por el segundo elemento. Se especifica el comparador greater<ii> 
                                                        //para dar prioridad a los valores menores en vez de los mayores.
    pq.push(ii(0, s));      //La cola comienza con distancia 0 al nodo inicial.
    while (!pq.empty()) {   //El bucle termina cuando la cola de prioridad queda vacía, lo que ocurre cuando se ha visitado y
                            //determinado la distancia mínima de todo nodo alcanzable desde el inicial s.
        ii front = pq.top(); //front: par distancia-nodo del nodo a evaluar en cada iteración del ciclo while.
        pq.pop();            //Se elimina front de la cola para que en la siguiente iteración se tome otro nodo.
        int d = front.first, u = front.second;//d: distancia.   u: nodo.
        if (d == dist->at(u))   //Si la distancia d coincide con la del nodo u en el vector de distancias,
                                //significa que el nodo no ha sido visitado, por lo que se procede a evaluar
                                //las distancias hacia cada vecino del nodo u.
            for (int j = 0; j < (int)graph->at(u).size(); j++) {//Para cada elemento en la lista de vecinos del nodo u.
                ii v = graph->at(u)[j];                       // all outgoing edges from u
                                                                //v: una arista de u con otro nodo (un nodo y su latencia con u).
                if (dist->at(u) + v.second < dist->at(v.first)) {   //Si la distancia actual hasta el nodo del par v es mayor que
                                                                    //la suma de la latencia en v y la distancia hasta u
                    dist->at(v.first) = dist->at(u) + v.second;                 // relax operation
                                                                    //esa suma pasa a ser la distancia actual hasta en nodo indicado por v,
                    pq.push(ii(dist->at(v.first), v.first));        //y se agrega a la cola el par de esa distancia y ese nodo.
                }
            } 
    }
}

int main(){
    int N,cases=1;scanf("%d",&N);   //N: cantidad de casos.
                                    //cases: numera los casos cuando se imprime la salida.
    while(N--){
        int n,m,s,t;    //n: cantidad de nodos.     m: cantidad de conexiones.
                        //s: nodo inicial.          t: nodo final.

        scanf("%d %d %d %d",&n,&m,&s,&t);
        vector<vii> graph (n,vii());    //Grafo implementado como vector de vectores (lista de adyacencia).
        int u,v,w;
        for (int i = 0; i < m; ++i)     //Se lee las m conexiones entre nodos u y v con latencia (distancia) w.
        {   
            scanf("%d %d %d", &u, &v, &w);
            //"connected by a bidirectional cable"
            graph[u].push_back(ii(v, w)); //Crea conexión desde u hacia v
            graph[v].push_back(ii(u, w)); //Crea conexión desde v hacia u
        }
        vi dist(n, INF);    //Crea el vector de distancias inicializadas en 1000000000 (infinito para efectos del algoritmo).
        dist[s] = 0;        //Cambia la distancia del nodo inicial a 0.
        dijkstra(s,&dist,&graph);   //Ejecuta el algoritmo de Dijkstra.
        if(dist[t]!=INF){   //Si la distancia es distinta de infinito, el nodo final es alcanzable y se imprime su distancia.
            printf("Case #%d: %d\n",cases++,dist[t]);
        }else{              //Si la distancia no cambió de infinito, significa que el nodo t no es alcanzable.
            printf("Case #%d: unreachable\n",cases++);
        }
        
    }


 return 0;   

}