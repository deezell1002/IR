#include <iostream>
#include <string>
using namespace std;

void preQsBc(char *x, int m, int qsBc[]);
void QS(char *x, int m,char *y, int n);
void search(char text[],int n , char pat[],int m);

main(int argc, char *argv[]){
	char szBuf[2048], fname[25], pat[10], method[2];
	char c;
	string txt;
	int i;
	FILE *fp;

	switch(argc){
		case 1:
			break;
		case 4:
			strcpy(method,argv[3]);
		case 3:
			strcpy(pat,argv[2]);
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
		
		/*หาขนาดของ text*/
		while((i<2048) && ((c = getc(fp)) != EOF)){
			szBuf[i] = c;
			txt = txt + c;
			printf("szBuf[%d] = %c\n",i,szBuf[i]);
			i++;
		}
	
		//cout <<"text :"<< text <<"\n";	
	}while(c != EOF);
	fclose(fp);
	printf("Pattern %s \n",pat);
	printf("Method %s \n",method);
	if(strcmp(method,"a") == 0){
		QS(pat,strlen(pat),szBuf,i);		
	}else if(strcmp(method,"b") == 0){
		search(szBuf,i,pat,strlen(pat));
	}else
		printf("Good Bye!\n");
}

/*Quick Search*/
void QS(char *x, int m,char *y, int n){
	int j, qsBc[256];

	preQsBc(x,m,qsBc);

	j = 0;
	
	while(j <=n-m){
		if(memcmp(x,y+j,m) == 0) printf("Found at %d\n", j);
		//printf("Befor add j = %d qsBc[%c] = %d\n",j,y[j+m],qsBc[y[j+m]]);
		j += qsBc[y[j+m]];
		//printf("After add j = %d \n",j);
	}
}

void preQsBc(char *x, int m, int qsBc[]){
	int i;

	for(i=0; i<256; ++i){
		qsBc[i]=m+1;
	}
	for(i=0; i<m;++i){
		qsBc[x[i]] = m-i;
	}
}
/*End quick Search*/

/*Brutefource*/
void search(char text[],int n , char pat[],int m){
	int i , j , k ,lim , count=0,count2=0;

	//printf("text = %s\n",text);
	//printf("pat = %s\n",pat);
	lim = n-m+1;

	for(i = 0 ; i <= lim-1 ; i++)
	{
		k = i ;		
		for (j = 0 ; j <= m-1 && text[k] == pat[j] ; j++)
		{
			k++;
			count2++;
		}
		if(j > m-1 )
		{
			printf ("Found at %d \n",(i));
			count++;

		}		
	}
	count2--;
	printf("count of condition = %d\n",count);
	printf("count of tab = %d\n",count2);
}