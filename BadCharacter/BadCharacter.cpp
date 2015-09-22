#include <iostream>
using namespace std;

void preBmBc(char *x, int m, int bmBc[]);

void main(){
	int a[255];
	preBmBc("text", 4, a);
}

void preBmBc(char *x, int m, int bmBc[]){
	int i,k;
	for(i=0; i<255; ++i){
		bmBc[i]= -1;
	}
	for(i=0 ; i<m; ++i){
		bmBc[x[i]] = i;
		printf("bmBc[%d] = %c [%d]\n", bmBc[x[i]],x[i],x[i]);
	}
	cout << "\n";
	for(i=0 ; i<m; ++i){
		printf("bmBc[%d] = %c [%d]\n", bmBc[x[i]],x[i],x[i]);
	}
}