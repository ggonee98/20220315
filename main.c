#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "sinfo.h"

void input_student(FILE* fp) {
	int i;

	for (i = 0;i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", slist[i].name, &slist[i].gender, slist[i].city, slist[i].dept,
			&slist[i].gpa, &slist[i].height, &slist[i].weight);

	}
}

/*
void output_student() {
	int i;

	for (i = 0;i < n;i++)
		printf("%s %c %s %s %.2f %d %d\n", slist[i].name, slist[i].gender, slist[i].city, slist[i].dept,
			slist[i].gpa, slist[i].height, slist[i].weight);
}
*/

/*
int main() {
	FILE* fp = fopen("list.txt", "r+");

	n = count_student(fp);
	rewind(fp);

	slist = (sinfo*)calloc(n, sizeof(sinfo));

	input_student(fp);

	output_student();

	fclose(fp);
	return 0;
}
*/

int main() {
	FILE* fp = fopen("input.txt", "r+t");
	char input[512];
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32], tok9[32];

	while (fgets(input, 512, fp) != NULL) {
		sscanf(input, "%s%s%s%s%s%s%s%s%s", tok1, tok2, tok3, tok4, tok5, tok6, tok7, tok8, tok9);
		if (strcmp(tok1, "CREATE") == 0) {
			process_create();
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "LOAD") == 0) {
			process_load(tok2);
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			process_print();
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "DELETE") == 0) {
			process_delete(tok2);
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "SEARCH") == 0) {
			process_search(tok2);
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else
			printf("%s is not a keyword.\n", tok1);
	}
}
