#include <stdio.h>
#include <string.h>

typedef struct Person {
	char* name;
	char* surname;
	char* gender;
} pers;

void readfile(char **file);

void funktion(pers* p, int *length, int *j, char *i, int *k, char **file);

int main()
{
    char* file;
    int length;
    int j;
    char i;
    int k;
    readfile(&file);
    pers p;
	funktion(&p, &length, &j, &i, &k, &file);
	
	
	//Ausgabe aller gender
	/*for (int l = 0; l < k; l++) {
        printf("Gender von Person %d = %c\n", l + 1, p.gender[l]);
    }*/
    
	return 0;
}

void readfile(char **file) {
    *file = "alexander;steiner;m\nmax;musterman;m\nmelanie;quintus;w\nhelene;fische;w\nolaf;scholz;m\n\0";
}

void funktion(pers* p, int *length, int *j, char *i, int *k, char **file) {
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
}
