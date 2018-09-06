#include <stdio.h>

int rotar(int o, char a){
	int t=o;
	if(a=='R')
		t++;
	if(a=='L')
		t--;
	if(t<0)
		t=3;
	if(t>3)
		t=0;
	return t;
}

char nesw(int o){
	switch (o){
		case 0:
		return 'N';
		case 1:
		return 'E';
		case 2:
		return 'S';
		case 3:
		return 'W';
		default:
		return '?';
	}
}

int main(){
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){//casos
		if(i!=0)
			printf("\n");
		int rows, columns;
		scanf("%d%d", &rows, &columns);

		int maze[rows][columns], aux;//leer laberinto
		for(int j=0; j<rows; j++){
			for(int k=0; k<columns; k++){
				do{
					aux=getchar();
				}while(aux=='\n');
				maze[j][k]=aux;
			}
		}

		int r0, c0, o0=0; //posicion y orientacion
		//0=N, 1=E, 2=S, 3=W
		scanf("%d%d", &r0, &c0);
		r0--;c0--;
		char comm;
		scanf("%c", &comm);
		while(comm!='Q'){
			if(comm=='R' || comm=='L')
				o0=rotar(o0,comm);
			else if(comm=='F'){
				if(o0==0 && maze[r0-1][c0]!='*')
					r0=r0-1;
				else if(o0==1 && maze[r0][c0+1]!='*')
					c0=c0+1;
				else if(o0==2 && maze[r0+1][c0]!='*')
					r0=r0+1;
				else if(o0==3 && maze[r0][c0-1]!='*')
					c0=c0-1;
			}
			scanf("%c", &comm);
		}
		char oc = nesw(o0);
		r0++;c0++;
		printf("%d %d %c\n", r0, c0, oc);
			
	}
	return 0;
}