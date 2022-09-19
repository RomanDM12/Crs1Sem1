#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int cnt;
	int price;
	char*  nameProduct;
	char* izgotov;
	char* date;
}Item;

int main() {
	srand(time(NULL));

	int itemcnt = 5;
	Item* Shop = NULL;
	Shop = (Item*)malloc(itemcnt*sizeof(Item));

	char* Products[5] = {"eggs", "moloko", "meat", "carrot", "cheese"};
	char* Countries[5] = {"Russia", "Spain", "Italy", "Germany", "China"};
	char* Dates[5] = {"02.08.2020", "03.09.2021", "04.10.2022", "05.11.2023", "06.12.2024"};

	for (int i = 0; i < itemcnt; i++) {
		Shop[i].nameProduct = Products[i];
		Shop[i].cnt = rand() % 10;
		Shop[i].price = rand() % 1000+100;
		Shop[i].izgotov = Countries[i];
		Shop[i].date = Dates[i];
	}

	for (int i = 0; i < itemcnt; i++) {
		printf("%d name: %s; cnt: %d; price: %d; izgotov: %s; date: %s\n", i + 1, Shop[i].nameProduct, Shop[i].cnt, Shop[i].price, Shop[i].izgotov, Shop[i].date);
	}
	printf("\n");

	int cnt = 0;
	for (int i = 0; i < itemcnt; i++) {
		if (Shop[i].cnt>=5){
			printf("%d name: %s; cnt: %d; price: %d; izgotov: %s; date: %s\n", i + 1, Shop[i].nameProduct, Shop[i].cnt, Shop[i].price, Shop[i].izgotov, Shop[i].date);
		}
	}
}
