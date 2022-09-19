#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char* Surname;
	_Bool Married;
	_Bool Kid;
}Person;

int main () {
	srand(time(NULL));

	int peoplecnt = 25;
	Person* people = NULL;

	people = (Person*)malloc(peoplecnt*sizeof(Person));

	char*  surnames[25] = {"dfjk", "sdf", "dgsf", "dghdh", "sdfgsfg", "wtrer", "dgdhfd", "dfgdg", "wethyr", "ergbd", "ergyt", "sdfrth", "fdhdh", "ehy", "ukyjjr", "rrnlr","gfdgg", "yhtydg", "htltgg", "ergker", "thpsf", "ergpe", "gpnlkr", "ptrmn", "eglfg",};

	for (int i = 0; i < peoplecnt; i++) {
		people[i].Surname = surnames[i];
		people[i].Married = rand() % 2;
		people[i].Kid = rand() % 2;
	}

	for (int i = 0; i < peoplecnt; i++) {
		printf("%d. Surname: %s; Married:  %d;  Kid:  %d\n", i + 1, people[i].Surname, people[i].Married, people[i].Kid);
	}

	printf("\n");

	int cnt = 0;
	for (int i = 0; i < peoplecnt; i++) {
		if (people[i].Married == 1 && people[i].Kid == 1) {
			printf("%d. Surname: %s; Married:  %d;  Kid:  %d\n", i + 1, people[i].Surname, people[i].Married, people[i].Kid);
			cnt++;
		}
	}
	printf("Number: %d", cnt);
}

