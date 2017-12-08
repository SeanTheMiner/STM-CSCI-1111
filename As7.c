/* Assignment 7
Sean Miner - miners@my.normandale.edu

This program interprets a file describing a 
"Karel the Robot" world. */

#include <stdio.h> 
#include <stdlib.h>

struct startEntry {
    int ar[6];
} ;

struct entry {
    int ar[7];
} ;

int countLines(FILE *fp);
void printStart(struct startEntry start);
void printNode(struct entry entry);


int main (int argc, char *argv[]) {

    FILE *fp;

    fp = fopen(argv[1], "r");

    int x = 0;
    int i, j;                             // i controls line number, j controls index on struct's array

    struct startEntry start;              // Create the start info struct.

    int lines = countLines(fp);
    struct entry entAr[lines-2];          // Create an array of entries, for all but the starting line

    char buffer[8];
    fgets(buffer, 8, fp);                 //Skip first line


    // Fill start struct
    for (i = 0; i < 6; i++) {
        fscanf(fp, "%d", &x);
        start.ar[i] = x;
        //printf("%d ", x);
    }

    printf("\n");
    printStart(start);

    for (j = 0; j < lines-3; j++) {
        for (i = 0; i < 7; i++) {
            fscanf(fp, "%d", &x);
            entAr[j].ar[i] = x;
            //printf("%d ", x);
        }
        //printf("\n");
    }

    for (i = 0; i < (sizeof(entAr)/sizeof(entAr[0]) -1); i++) 
        printNode(entAr[i]);

    fclose(fp);

    return 0;

} // End main()


int countLines(FILE *fp) {

    int ch;
    int lines = 1;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            lines++;
    }

    fseek(fp, 0, SEEK_SET);

    return lines;

} // End countLines()


void printStart(struct startEntry start) {

    int dir;

    printf("The screen's lower left corner is at street %d, avenue %d.\n", start.ar[0], start.ar[1]);
    printf("Karel is initially located at the corner of street %d, avenue %d.\n", start.ar[2], start.ar[3]);
    printf("She is facing ");

    dir = start.ar[4];

    switch (dir) {
        case 1 : 
            printf("North"); 
            break;
        case 2 : 
            printf("South");
            break;
        case 3 : 
            printf("East");
            break;
        case 4 : 
            printf("West");
            break;
    }

    printf(" and is carrying %d beepers.\n\n", start.ar[5]);

} // End printStart()


void printNode(struct entry entry) {

    int i;
    int walls = 0;

    enum dir {North, South, East, West} ;

    printf("At street %d, avenue %d, there are %d beepers, and", entry.ar[0], entry.ar[1], entry.ar[2]);

    for (i = 3; i < 7; i++) {
        if (entry.ar[i]) {
            walls++;
        }
    }

    switch (walls) {
        case 0 :
            printf(" all directions are clear.");
            break;
        case 1 :
            printf(" one wall lies to the ");
            break;
        default :
            printf(" walls lie to the ");
            break;
    }

    if (entry.ar[3]) {
        if (!entry.ar[4] && !entry.ar[5] && !entry.ar[6])
            printf("North.");
        else
            printf("North, ");
    }

    if (entry.ar[4]) {
        if (!entry.ar[5] && !entry.ar[6])
            printf("and South.");
        else   
            printf("South, ");
    }

    if (entry.ar[5]) {
        if (!entry.ar[6])
            printf("and East.");
        else
            printf("East, ");
    }

    if (entry.ar[6]) {
        if (!entry.ar[3] && !entry.ar[4] && !entry.ar[5])
            printf("West.");
        else   
            printf("and West.");
    }
    
    printf("\n");

} // End printNode