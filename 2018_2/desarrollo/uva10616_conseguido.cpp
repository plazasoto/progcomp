//tomado de http://codealltheproblems.blogspot.com/2015/08/uva-10616-divisible-group-sums.html
// UVa 10616 - Divisible Group Sums

#include <iostream>
#include <string.h>
using namespace std;

#define datatype signed long int

int main() {
	int n, q, cases = 0;//cases corresponde al numero de set mostrado en la salida.
	cin >> n >> q;//n y q son las variables definidas en el enunciado: cantidad de numeros y cantidad de consultas (query).
	while (n || q) {
		cases++;
		datatype a[201];//almacena los n numeros de la lista.
		cout << "SET " << cases << ":" << endl;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int qq = 1; qq <= q; qq++) {//se procesa las q consultas.
			int d, m;//d: divisor. m: cantidad de numeros a sumar.
			cin >> d >> m;
			int now = 0, b4 = 1;
			unsigned long long int T[2][11][20];//tabla de memorización. La primera dimensión indica si se trata del caso actual (durante el proceso) o del anterior.
			// La segunda indica cuantos números de los m (hasta 10) faltan por sumar. La tercera es el módulo de la suma hasta ese momento.
			memset(T, 0, sizeof(T));
			T[now][0][0] = 1;//
			for (int i = 0; i < n; i++) {
				now = b4;//now y b4 tienen valores 1 o 0 distintos entre ellos. Aquí now toma el valor de b4
				b4 = (b4 + 1) % 2;//y b4 cambia su valor de 1 a 0 o de 0 a 1 según corresponda.
				for (int j = 0; j <= m; j++)
					for (int k = 0; k < d; k++)
						T[now][j][k] = T[b4][j][k];//iguala valores actuales de la tabla a los anteriores.

				for (int j = 0; j < m; j++) {
					for (int k = 0; k < d; k++) {
						if (T[b4][j][k] != 0) {
							int kk = (k + (a[i] % d) + d) % d;
							T[now][j + 1][kk] += T[b4][j][k];
						}
					}
				}
			}
			cout << "QUERY " << qq << ": " << T[now][m][0] << endl;
		}

		cin >> n >> q;
	}
	return 0;
}
