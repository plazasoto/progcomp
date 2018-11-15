//tomado de http://codealltheproblems.blogspot.com/2015/06/uva-674-coin-change.html
// UVa 674 - Coin Change

#include <iostream>
#include <string.h>
using namespace std;

#define datatype unsigned long long int

int coin[5] = { 1, 5, 10, 25, 50 };//tipos de moneda. Se usan para generar las posibles combinaciones.

int main() {

	datatype T[7490];//Tabla con las cantidades de posibles combinaciones de monedas para todas las posibles cantidades de dinero (hasta 7489 centavos).
	memset(T, 0, sizeof(T));//Inicializa la talba en 0 para todos los valores.
	T[0] = 1;//Caso base: 1 posible combinacion para 0 centavos.
	//A continuacion se llena la tabla para todos los casos posibles.
	for (int i = 0; i < 5; i++) {//i indica uno de los 5 tipos de moneda.
		for (int j = coin[i]; j <= 7489; j++) {//j es una cantidad de dinero, comenzando por el valor de moneda i hasta el maximo posible 7489.
			T[j] += T[j - coin[i]];//En cada iteracion, la cantidad de combinaciones para j centavos aumenta en la cantidad ya conocida para para el caso anterior j menos el valor de la moneda i.
		}//La cantidad total de combinaciones de monedas posibles para j centavos es la suma de los casos posibles para j menos cada una de las 5 monedas.
	}//Esto funciona gracias al caso base, pues en los primeros casos en que un valor de moneda se resta a si mismo se llega al caso 0, lo que representa la posiblidad de usar una sola moneda para esa cantidad.
	
	int n;
	while (cin >> n) {//Lee n.
		cout << T[n] << endl;//Para cada n, imprime el valor guardado en la tabla.
	}

	return 0;
}
