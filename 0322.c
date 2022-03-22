#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sinfo {
	char name[8];
	char gender;
	char city[8];
	char dept[16];
	float gpa;
	int height;
	int weight;
} sinfo;

int n;
int cnt = 0;
sinfo* slist;

int count_student(FILE* fp) {
	char str[256];
	int i = 0;
	while (fgets(str, 256, fp) != NULL)
		i++;
	return i;
}
void input_student(FILE* fp) {
	int i;

	for (i = 0;i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", slist[i].name, &slist[i].gender, slist[i].city, slist[i].dept,
			&slist[i].gpa, &slist[i].height, &slist[i].weight);

	}
}
void output_student() {
	int i;

	for (i = 0;i < n;i++)
		printf("%s %c %s %s %.2f %d %d\n", slist[i].name, slist[i].gender, slist[i].city, slist[i].dept,
			slist[i].gpa, slist[i].height, slist[i].weight);
}
void process_create();
void process_create() {
	printf("Create\n");
	FILE* fp1 = fopen("list.txt", "r+");

	n = count_student(fp1);
	rewind(fp1);

	slist = (sinfo*)calloc(n, sizeof(sinfo));

	input_student(fp1);

	fclose(fp1);
}
void process_load();
void process_load() {
	FILE* fp1 = fopen("list.txt", "r+");

	int i = 0, j = 0;
	char tname[8];
	char tgender;
	char tcity[8];
	char tdept[16];
	float tgpa;
	int theight, tweight;

	for (j = 0;j < (n - 2);j++) {
		for (i = 0;i < (n - 1);i++) {
			if (strcmp(slist[i].name, slist[i + 1].name) > 0) {

				strcpy(tname, slist[i + 1].name);
				strcpy(slist[i + 1].name, slist[i].name);
				strcpy(slist[i].name, tname);

				tgender = slist[i + 1].gender;
				slist[i + 1].gender = slist[i].gender;
				slist[i].gender = tgender;

				strcpy(tcity, slist[i + 1].city);
				strcpy(slist[i + 1].city, slist[i].city);
				strcpy(slist[i].city, tcity);

				strcpy(tdept, slist[i + 1].dept);
				strcpy(slist[i + 1].dept, slist[i].dept);
				strcpy(slist[i].dept, tdept);

				tgpa = slist[i + 1].gpa;
				slist[i + 1].gpa = slist[i].gpa;
				slist[i].gpa = tgpa;

				theight = slist[i + 1].height;
				slist[i + 1].height = slist[i].height;
				slist[i].height = theight;

				tweight = slist[i + 1].weight;
				slist[i + 1].weight = slist[i].weight;
				slist[i].weight = tweight;
			}
		}
	}
	output_student();
	fclose(fp1);
}
void process_print();
void process_print() {
	printf("Print\n");
	FILE* fp1 = fopen("list.txt", "r+");
	output_student();
	fclose(fp1);

}
void process_insert(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8);
void process_insert(char* tok2, char* tok3, char* tok4, char* tok5, char* tok6, char* tok7, char* tok8) {
	printf("Insert\n");
	//slist[n].name = tok2;
}
void process_delete(char* tok2);
void process_delete(char* tok2) {
	printf("Delete\n");
	int i = 0;
	for (i = 0;i < n;i++) {
		if (strcmp(tok2, slist[i].name) != 0)
			continue;
		else
		{
			printf("asdfasdf\n");

			strcpy(slist[i].name, "\0\0");
			slist[i].gender = "\0";
			strcpy(slist[i].city, "");
			strcpy(slist[i].dept, "");

			slist[i].gpa = '\0';
			slist[i].height = '\0';
			slist[i].weight = '\0';

			break;
		}
	}
}
void process_search(char* tok2);
void process_search(char* tok2) {
	printf("Search\n");

	int i = 0;
	for (i = 0;i < n;i++) {
		if (strcmp(tok2, slist[i].name) == 0)
			printf("%s %c %s %s %.2f %d %d\n", slist[i].name, slist[i].gender, slist[i].city, slist[i].dept,
				slist[i].gpa, slist[i].height, slist[i].weight);
	}
}

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
			process_load();
			printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			//process_print();
			//printf(" %s done ===================================================================\n\n", tok1);
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			//process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			//printf(" %s done ===================================================================\n\n", tok1);
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
	process_print();
	fclose(fp);
}
