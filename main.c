#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
	char* name;
	char* surname;
	char* gender;
} pers;

void readfile(char** newBuffer);

int main()
{
    char *Data;
    readfile(&Data);
    printf("%s", Data);
	
    printf("\n");
	return 0;
}

void readfile(char** newBuffer) {
    FILE *fptr;
    int fsize;
    fptr = fopen("personen.csv", "r");

    if (NULL == fptr) {printf("ERRROR, could not Open file!\n"); return;}

    fseek(fptr, 0, SEEK_END);
    fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char* buffer = calloc(fsize, sizeof(char));    

    int c;
    int i = 0;
    while ((c = fgetc(fptr)) != EOF) {
        buffer[i] = c;
        i++;
    }
    fclose(fptr);

    i = 0;
    c = buffer[i];
    while (c != '\n')
    {
        i++;
        c = buffer[i];
    }

    *newBuffer = (char *)malloc((fsize - i + 1) * sizeof(char));
    
    if (*newBuffer == NULL) {
            printf("ERROR, could not allocate Memory!.\n");
            return;
    }
    strcpy(*newBuffer, buffer + i + 1);
    
    printf("%s", *newBuffer);

    free(buffer);
    free(*newBuffer);
}

/*void funktion(pers* p, int *length, int *j, char *i, int *k, char **file) {
    *length = 0;
    *j = 0;
    *i = *file[*length];
    *k = 0;
    
    while(*i != '\0') {
        if (*i == '\n') {
            p->gender[*k] = *file[*length-1];
            printf("%c", p->gender[*k]);
            (*k)++;        
        }
        printf("%c", *i);
        (*length)++;
        *i = *file[*length];
    }
}*/
