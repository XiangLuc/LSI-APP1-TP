#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mastermind.h"

void display_comb(int comb[]) {
    for(int i = 0 ; i < SIZE ; i++) {
        if(i > 0) {
            printf(" - ");
        }
        printf("%d", comb[i]);
    }
    printf("\n");
}

int read_comb(int comb[]) {
    char buffer[100];

    printf("Veuillez saisir votre combinaison : ");
    scanf("%s", buffer);

    if(strlen(buffer) != SIZE) {
        return 0;
    }

    for(int i = 0 ; i < SIZE ; i++) {
        if(buffer[i] < '0' || buffer[i] > '9') {
            return 0;
        }

        int val = (int) buffer[i] - '0';

        if(val < 0 || val > 9) {
            return 0;
        }
        comb[i] = val;
    }

    return 1;
}

void random_comb(int array[]) {
    for(int i = 0 ; i < SIZE ; i++) {
        array[i] = (rand() % 9) + 1;
    }
}

int well_placed(int comb[], int propos[]) {
    int count = 0;
    for(int i = 0 ; i < SIZE ; i++) {
        if(comb[i] == propos[i]) {
            count++;
        }
    }
    return count;
}

int at_wrong_place(int comb[], int propos[]) {
    int count = 0;

    for(int i = 0; i < SIZE; i++) {

        if (comb[i] == propos[i])
            continue;

        for(int j = 0; j < SIZE; j++) {
            if (j != i && comb[i] == propos[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}


void result(int x, int y) {
    printf("Bien placé : %d, Mauvaise position : %d\n", x, y);
}