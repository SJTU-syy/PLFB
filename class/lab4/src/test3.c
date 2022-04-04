#include<stdio.h>
#include<stdlib.h>
#define FILE_NAME "../genbank1.gb"

int main() {
	FILE *fp; fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("Failed to open %s\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	return 0;
}