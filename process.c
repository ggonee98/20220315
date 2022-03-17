#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "sinfo.h"

int count_student(FILE* fp) {
	char str[256];
	int i = 0;
	while (fgets(str, 256, fp) != NULL)
		i++;
	return i;
}

void process_create() {
	printf("Create\n");
}
void process_load(char tok2) {
	/*
	int i = 0;
	Person* person01[44];

	FILE* fp = fopen("list.txt", "r+t");

	while (!feof(fp)) {
		person01[i] = (Person*)malloc(sizeof(Person));
		fscanf(fp, "%s %s %s %s %f %d %d", person01[i]->name, person01[i]->gender, person01[i]->region, person01[i]->depart,
			&person01[i]->grade, &person01[i]->height, &person01[i]->weight);
		//printf("%s %s %s %s %.2f %d %d\n", person01[i]->name, person01[i]->gender, person01[i]->region, person01[i]->depart,
		//	person01[i]->grade, person01[i]->height, person01[i]->weight);
		free(person01[i]);
		i++;
	}
	fclose(fp);
	*/
	printf("Load\n");
}

void process_print() {
	//printf("Print\n");
	int i;

	for (i = 0;i < n;i++)
		printf("%s %c %s %s %.2f %d %d\n", slist[i].name, slist[i].gender, slist[i].city, slist[i].dept,
			slist[i].gpa, slist[i].height, slist[i].weight);
}

void process_insert(char tok2, char tok3, char tok4, char tok5, char tok6, char tok7, char tok8) {
	printf("Insert\n");
}

void process_delete(char tok2) {
	printf("Delete\n");
}

void process_search(char tok2) {
	printf("Search\n");
}
