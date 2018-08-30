#include <stdio.h>

int dig04[5], dig59[5];

bool digitos(int num, int * arr){
	int digit, i=0;
	arr[0] = -1;
	do{
		digit = num % 10;
		arr[i] = digit;
		num = num / 10;
		for(int j=0;j<i;j++){
			if(arr[i]==arr[j]){
				return false;
			}
		}
		i++;
	}while(i<5);
	return true;
}

bool if09(){
	int count;
	for(int i=0;i<10;i++){
		count = 0;
		for(int j=0;j<5;j++){
			if(dig04[j]==i)
				count++;
			if(dig59[j]==i)
				count++;
		}
		if(count!=1)
			return false;
	}
	return true;
}

int main(){
	int numerador, denominador, cuociente;
	bool solucion;
	scanf("%d",&cuociente);
	while(cuociente!=0){
		numerador = 1234;
		solucion = false;
		for(numerador;numerador<=98765;numerador++){
			if(numerador % cuociente == 0){
				denominador = numerador / cuociente;
				if(denominador>1000){//debe ser al menos mayor que 1000 para tener 5 digitos diferentes
					if(digitos(numerador, dig04) && digitos(denominador, dig59) && if09()){
						printf("%05d / %05d = %d\n", numerador, denominador, cuociente);
						solucion = true;
					}
				}
			}
		}
		if(!solucion)
			printf("There are no solutions for %d.\n", cuociente);
		scanf("%d",&cuociente);
		if(cuociente!=0)
			printf("\n");
	}
	
	return 0;
}