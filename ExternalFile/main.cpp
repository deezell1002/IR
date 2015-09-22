#include <iostream>
using namespace std;


main(){
	char szBuf[2048];
	int c, i;
	FILE *fp;

	if((fp = fopen("text.txt","rb")) == NULL){
		printf("Error : Can't open file.\n");
		return;
	}

	do{
		i = 0;
		while((i<2048) && ((c = getc(fp)) != EOF)){
			//printf("c = %c\n",c);
			szBuf[i] = c;
			printf("szBuf[%d] = %c\n",i,szBuf[i]);
			i++;
		}
	}while(c != EOF);
	fclose(fp);
	printf("\nTotal Message Size: %d bytes\nBye!\n",i);
}