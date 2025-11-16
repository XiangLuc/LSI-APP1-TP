#ifndef MASTERMIND_H
#define MASTERMIND_H

#define SIZE 5

void display_comb(int comb[]);
int read_comb(int comb[]);
void random_comb(int array[]);
int well_placed(int comb[], int propos[]);
int at_wrong_place(int comb[], int propos[]);
void result(int x, int y);

#endif