#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void wc ( FILE *infile, char *inname);

int main (int argc, char *argv[]) {

	//printf("%s is the name of the file maybe", argv[1]);
	int i;
	for(i=1;i<argc;i++){
		char* name = argv[i];
		FILE* file = fopen(name,"r");
		wc(file, name);		
		fclose(file);
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
	char pChar = ' ';
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
	printf("%d",lCount);
	printf("\t%d",wCount);
	printf("\t%d",bCount);
	printf("\t%s\n",inname);
	
}





