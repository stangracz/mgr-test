#include <stdio.h>

int readstr() {
	FILE* fp;
	fp = fopen ("temp.tmp", "w+");
   	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
   	fclose(fp);   
   	
	return 0;
}

int main() {
	int a = readstr();
	printf("Hello World \n");
	return 0;
}
