//tomado de http://codealltheproblems.blogspot.com/2015/08/uva-10616-divisible-group-sums.html
// UVa 10616 - Divisible Group Sums

#include <iostream>
#include <string.h>
using namespace std;

#define datatype signed long int

int main() {
	int n, q, cases = 0;//cases corresponde al número de set mostrado en la salida.
	cin >> n >> q;//n y q son las variables definidas en el enunciado: cantidad de números y cantidad de consultas (query).
	while (n || q) {
		cases++;
		datatype a[201];//almacena los n números de la lista.
		cout << "SET " << cases << ":" << endl;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int qq = 1; qq <= q; qq++) {//se procesa las q consultas.
			int d, m;//d: divisor. m: cantidad de numeros a sumar.
			cin >> d >> m;
			int now = 0, b4 = 1;
			unsigned long long int T[2][11][20];//Tabla de memorización. El primer índice indica si se trata del caso actual (durante el proceso) o del anterior.
			//El segundo indica cuántos números de los m (hasta 10) se han sumado. El tercero es el módulo de la suma hasta esa cantidad de números sumados.
			//El valor almacenado en la tabla corresponde a la cantidad de grupos que cumplen las condiciones pedidas.
			memset(T, 0, sizeof(T));//Inicializa la tabla en 0 grupos para todos los casos.
			T[now][0][0] = 1;//Caso base: se considera que hay un solo conjunto posible para m=0.
			for (int i = 0; i < n; i++) {
				now = b4;//now y b4 tienen valores 1 o 0 distintos entre ellos. Aquí now toma el valor de b4
				b4 = (b4 + 1) % 2;//y b4 cambia su valor de 1 a 0 o de 0 a 1 según corresponda.
				for (int j = 0; j <= m; j++)
					for (int k = 0; k < d; k++)
						T[now][j][k] = T[b4][j][k];//iguala valores actuales de la tabla a los anteriores.

				for (int j = 0; j < m; j++) {
					for (int k = 0; k < d; k++) {
						if (T[b4][j][k] != 0) {//si el caso anterior con j y k tiene conjuntos posibles
							int kk = (k + (a[i] % d) + d) % d;//kk es el resto de la suma que daba resto k más el número a[i], 
							//luego, se suma la cantidad de conjuntos contemplados al sumar j números que da resto k al total
							//de conjuntos para un números más (j+1) y que da resto kk.
							T[now][j + 1][kk] += T[b4][j][k];//Así se construye cada caso en base al anterior hasta llegar a
															//sumar m números, siendo la solución cuando da resto 0. 
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