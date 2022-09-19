#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	char start[20];
	char end[20];
	int len;
}Marshrut;

void inputMarshrut(Marshrut *marshrut) {
	for (int i = 0; i < 10; i++) {
    	marshrut[i].number=0;
    	for(int j=0; j<20; j++){
    	marshrut[i].start[j]='0';
    	marshrut[i].end[j]='0';
    	}

    	marshrut[i].len=0;
    	}

    for (int i = 0; i < 10; i++) {

	printf("%d) Number (int) : ",i+1);
    	scanf("%d",&marshrut[i].number);

    	if(marshrut[i].number==-1){
    		marshrut[i].number=0;
    		break;
    	}


    	printf("%d) Start (string) : ",i+1);
    	scanf(" %[^\n]%*c",marshrut[i].start );


    	printf("%d) End (string) : ",i+1);
    	scanf(" %[^\n]%*c",marshrut[i].end );


    	printf("%d) Len of Marshrut (int) : ",i+1);
    	scanf("%d",&marshrut[i].len );

	printf("\n");
	}
	printf("\n------------------\n");
}

void MaxDlinaMarshrut(Marshrut *marshrut) {
	int maxlen = 0;
	for (int i =0; i < 10; i++) {
		if(marshrut[i].len > maxlen) {
			maxlen = marshrut[i].len;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (marshrut[i].len == maxlen) {
			printf("\n-------------\n Max len: ");
			printf("%d. Number of Marshrut: %d | Start: %s | End: %s | Len of Marshrut: %d\n", i + 1, marshrut[i].number, marshrut[i].start, marshrut[i].end, marshrut[i].len);
			printf("\n ------------- \n");
		}
	}

}

void VosrastMarshrutov(Marshrut *marshrut) {
	Marshrut buf;

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			if (marshrut[i].number > 0) {
				if (marshrut[i].number > marshrut[i+1].number) {
					buf = marshrut[i];
					marshrut[i] = marshrut[i+1];
					marshrut[i+1] = buf;
				}
			}
		}
	}


}

void MarshrutFindStation(Marshrut *marshrut) {
	printf("Совпадения станций: ");

	char str[20];
	scanf("%c", &str);
	printf("Найдено: ");

	int j = 0;
	for (int i =0; i < 10; i++) {
		if (strcmp(marshrut[i].start, str) == 0) {
			printf("%d. Number: %d | Start: %s | End: %s | Len of Marshrut: %d\n", j + 1, marshrut[i].number, marshrut[i].start, marshrut[i].end, marshrut[i].len);
			j++;
		}
		if (strcmp (marshrut[i].end, str) == 0) {
			printf("%d. Number: %d | Start: %s | End: %s | Len of Marshrut: %d\n", j + 1, marshrut[i].number, marshrut[i].start, marshrut[i].end, marshrut[i].len);
			j++;
		}
	}

	printf("\n-----------\n");
}

int main () {

	Marshrut* marshrut = NULL;
	marshrut = (Marshrut*)malloc(sizeof(Marshrut) * 10);

	inputMarshrut(marshrut);

	MaxDlinaMarshrut(marshrut);

	VosrastMarshrutov(marshrut);

	MarshrutFindStation(marshrut);

	return 0;

}

