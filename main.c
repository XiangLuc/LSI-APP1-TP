#include <stdio.h>

#include "mastermind.h"

int main() {

    int comb[20][5];
    int secret[SIZE];
    int try = 20;

    random_comb(secret);

    for(int i = 0 ; i < try ; i++) {
        printf("Attempt %d:\n", i + 1);
        if(!read_comb(comb[i])) {
            printf("Combinaison invalide. Veuillez saisir %d chiffres (0-9).\n", SIZE);
            i--;
            continue;
        }

        int well = well_placed(secret, comb[i]);
        int wrong = at_wrong_place(secret, comb[i]);

        result(well, wrong);

        if(well == SIZE) {
            printf("Félicitation ! Vous avez trouvez la combinaison !\n");
            break;
        }

        if(i == try - 1) {
            printf("Vous avez perdu. La combinaison secrète était : ");
            display_comb(secret);
        }
    }
    
    return 0;
}