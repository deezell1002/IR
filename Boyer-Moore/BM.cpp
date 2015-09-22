#include <iostream>
using namespace std;

void preBmBc(char *x, int m, int bmBc[]);
void BM(char *x, int m, char *y,int n);
void suffixes(char *x, int m, int *suff);
void preBmGs(char *x, int m, int bmGs[]);
int MAX(int a, int b);
void main(){

	BM("AANAANA",7,"ANMANDMANVANANDMANDMAN",22);
	//int a[8];
	///suffixes("ANPANMAN", 8, a);
	//preBmGs("ANPANMAN", 8, a);
	
}

void preBmBc(char *x, int m, int bmBc[]){
	int i;
	cout << "\nPreProcessing\n";
	for(i=0; i<255; ++i){
		//bmBc[i]= -1;
		bmBc[i]= m;

	}
	for(i=0 ; i<m; ++i){
		bmBc[x[i]] = i;
		//printf("bmBc[%d] = %c [%d]\n", bmBc[x[i]],x[i],x[i]);
	}
	cout << "\n";
	for(i=0 ; i<m; ++i){
		//printf("bmBc[%d] = %c [%d]\n", bmBc[x[i]],x[i],x[i]);
	}

}

void BM(char *x, int m, char *y,int n){
	int i, j, bmBc[255],bmGs[23];
	
	/*Preprocessing*/
	preBmGs(x,m,bmGs);
	printf("\n");
	preBmBc(x,m,bmBc);

	/*Searching*/
	j=0;
	while(j <= n-m){
		for(i=m-1; i>=0 && x[i] == y[i+j] ; --i);
		if(i < 0){
			printf("Found at %d \n",j);
			//exit(0);
			j +=bmGs[0];
		}else{
			//printf("bmBc[%c] = %d m = %d\n",y[i+j],bmBc[y[i+j]],m);
			//printf("j = %d\n",j);
			j += MAX(bmGs[i],bmBc[y[i+j]]-m+1+i);
			//printf("j = %d\n",j);
		}
	}
}

void suffixes(char *x, int m, int *suff){
	int f, g, i;

	suff[m-1] = m;
	g = m -1;
	for(i = m - 2 ; i >= 0 ; --i){
		if(i > g && suff[i + m - 1 - f] < i - g)
				suff[i] = suff[i + m - 1 - f];
		else{
			if(i < g)
				g = i;
			f = i;
			while(g >= 0 && x[g] == x[g + m -1 -f])
				--g;
			suff[i] = f - g;
		}
	}
	for(i = 0 ; i < m ; i++)
		printf("suff[%d,%c] = %d\n",i,x[i],suff[i]);

}
void preBmGs(char *x, int m, int bmGs[]){
	int i,j,suff[255];
	
	suffixes(x, m, suff);

	for(i=0;i<m;++i)
		bmGs[i] = m;
	j=0;
	for(i = m -1; i>= -1; --i)
		if(i == -1 || suff[i] == i + 1)
			for(;j < m - 1 -i; ++j)
				if(bmGs[j] == m)
					bmGs[j] = m-1-i;

	for(i = 0; i <= m - 2; ++i)
		bmGs[m-1-suff[i]] = m - 1 -i;
	for(i=0;i<m;++i)
		printf("bmGs[%d] = %d\n",i,bmGs[i]);
} 
int MAX(int a, int b){
	if(a>b) return a;
	else return b;
}