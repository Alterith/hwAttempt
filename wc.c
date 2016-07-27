#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void wc ( FILE *infile, char *inname);

int totalW = 0;
int totalB = 0;
int totalL = 0;

int main (int argc, char *argv[]) {

	//printf("%s is the name of the file maybe", argv[1]);
	int i;
	for(i=1;i<argc;i++){
		char* name = argv[i];
		FILE* file = fopen(name,"r");
		wc(file, name);		
		fclose(file);
	}

	if(argc>2){
		printf("%5d",totalL);
		printf("%5d",totalW);
		printf("%7d",totalB);
		printf("%10s\n","total");

	}

	return 0;
}

void wc( FILE *infile, char *inname) {
	//printf("%s: ", inname);
	//required data values	 
	int lCount = 0;
	int bCount = 0;
	int wCount = 0;
	
	FILE* f = infile;
	char sChar;
	bool wStart = false;
	while((sChar=fgetc(f))!=EOF)
	{
		bCount = bCount+1;
		if(sChar == '\n'){
			lCount = lCount+1;		
		}
		
		if (isspace(sChar)){  // isspace() checks for whitespace characters '  ', '\t', '\n','\r, so no need to write like this (isspace(n) || n == '\n')
   			wStart=false; //outside of word.     
		}else if(wStart==false){
    			wCount++;
    			wStart=true; //inside of word.
 		}
	}
	totalL = totalL+lCount;
	totalW = totalW+wCount;
	totalB = totalB+bCount;
	printf("%5d",lCount);
	printf("%5d",wCount);
	printf("%7d",bCount);
	printf("%10s\n",inname);
	
}





