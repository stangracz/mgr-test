//te define moim zdaniem powinny być w innym pliku i definiowane przez preprocess w pythonie - wtedy jedna zmiana poiągnie kolejne
#define SINGLEFILE "../../data/single/list.tmp"
#define MAXNAMELEN 8
#define SINGLEFILES 3
#define PAIREDFILES 3
#define SINGLELIMIT 59
//te define moim zdaniem powinny być w innym pliku i definiowane przez preprocess w pythonie - wtedy jedna zmiana poiągnie kolejne, poza tym będziemy już mieć policzone długości serii

#include <stdio.h>
#include <stdlib.h>

int readstr() {
	FILE *fsinglep;
	char **sfiles;
	char ctmp;
	
	fsinglep = fopen(SINGLEFILE,"r");	
	if (fsinglep == NULL) return 1;	
	
	sfiles = malloc(SINGLEFILES * sizeof(char*));
	if (sfiles == NULL) return 1;	
	
	for (int i = 0; i < SINGLEFILES; i++){
		sfiles[i] = malloc(MAXNAMELEN * sizeof(char));
		if (sfiles[i] == NULL) return 1;	
		for (int j = 0; j < MAXNAMELEN; j++){
			ctmp = getc(fsinglep);
			if (ctmp != SINGLELIMIT){	
				sfiles[i][j] = ctmp;			
				printf("%c",sfiles[i][j]);
			} else {
				j = -1;			
			}
		}
		printf("\n");
	}
	fclose(fsinglep);

	for (int i = 0; i < SINGLEFILES; ++i) { 
		free(sfiles[i]);
	}	
	free(sfiles);
		
	return 0;
}

int main() {
	int a;
	a = readstr();
	return 0;
}
