#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define pathfile "Desktop/task45.bin"

typedef struct {
	unsigned char surname[19];
	unsigned short numGroup;
	unsigned short Grade;
	unsigned short prize;

}Person;



Person* readfile(char* path) {
	Person* out = NULL;
	FILE* fin = fopen(path, "rb");
	if (fin == NULL) {
		perror("ERROR");
		return out;
	}
	struct stat st;
	stat(path, &st);
	out = (Person*)malloc(st.st_size);

	unsigned long int  cnt = st.st_size / sizeof(Person);
	fread(out, sizeof(Person), cnt, fin);
	fclose(fin);

	return out;
}

void savefile(char* path, Person* person, int cnt) {
	FILE* fin = fopen(path, "wb");
	if (fin == NULL) {
		perror("ERROR");
		return;
	}
	fwrite(person, sizeof(Person), cnt, fin);
	fclose(fin);
}

void print(Person person) {
	printf("Surnema: %s; Number of group: %d; Grade: %d; Scholarship: %d\n", person.surname, person.numGroup, person.Grade, person.prize);
}

int main () {
	int personcnt = 100;
	Person* from_disk = readfile(pathfile);

	for (int i = 0; i < personcnt; i++) {
		if (from_disk[i].Grade >= 50) {
			from_disk[i].prize = from_disk[i].prize * 1.3;
		}
	}

	for (int i = 0; i < personcnt; i++) {
		print(from_disk[i]);
	}

	savefile(pathfile, from_disk, personcnt);

	return 0;
}
