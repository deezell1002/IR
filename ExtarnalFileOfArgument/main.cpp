#include <iostream>
using namespace std;

main(int argc, char *argv[]){
	char szBuf[2048];
	char fname[25];
	int c, i;
	FILE *fp;

	switch(argc){
		case 1:
			break;
		case 2:
			strcpy(fname,argv[1]);
			break;
		default:
			printf("usage: testFile[filename]\n");
			return 0;
	}

	if((fp = fopen(fname,"rb")) == NULL){
		printf("Error : Can't open file.\n");
		return 0;
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