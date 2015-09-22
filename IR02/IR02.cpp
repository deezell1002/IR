#include <iostream>
using namespace std;

void search(char text[], int n, char pat[], int m);

main(){
	search("ababa", 5, "ba", 2);
}

void search(char text[], int n, char pat[], int m){
	int i, j, k, lim, count=-1,ship=0;

	printf("text = %s\n", text);
	printf("pat = %s\n", pat);
	lim = n-m+1;

	for(i=0 ; i<= lim-1 ; i++){
		k = i;
		count++;
		for(j=0 ; j<=m-1 && text[k] == pat[j] ; j++ ){
			k++;
		}
		if(j>m-1){
			printf("Found at %d \n",(i));
		}
	}
	printf("Shift = %d\n",j);
	printf("Compare = %d\n",count);
}