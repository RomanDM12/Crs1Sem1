#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char* Surname;
	int year;
	char*  Position;
	int Salary;
	char* Education;
}Worker;


int main () {
	srand(time(NULL));

	int workercnt = 5;
	Worker*  Person = NULL;
	Person = (Worker*)malloc(workercnt*sizeof(Worker));

	char* Surname[5] = {"Bibov", "Bobov", "Popaev", "Simpleev", "Kopov"};
	char* Position[5] = {"Trener", "Analitik", "Marketolog", "Gamer", "Bancir"};
	char* Education[5] = {"Higher", "Secondary", "General", "Undergraduate", "Doctor"};

	for (int i = 0; i < workercnt; i++) {
		Person[i].Surname = Surname[i];
		Person[i].year = rand()%100 + 1910;
		Person[i].Position = Position[i];
		Person[i].Salary = rand()%1000 + 500000;
		Person[i].Education = Education[i];
	}
	for (int i = 0; i < workercnt; i++) {
		printf("%d. Surname: %s; Year Burn: %d; Position: %s; Salary: %d; Education: %s\n", i + 1, Person[i].Surname, Person[i].year, Person[i].Position, Person[i].Salary, Person[i].Education);
	}
	printf("\n");


	int cnt = 0;
	for (int i = 0; i < workercnt; i++) {
		if(2021 - Person[i].year >= 60) {
			cnt ++;
		}
	}
	printf("Number: %d", cnt);
}
