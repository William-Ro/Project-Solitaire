//
// Created by Administrador on 26/10/2022.
//

#ifndef PROJECTSOLITAIRE_DECK_H
#define PROJECTSOLITAIRE_DECK_H

#include <ctime>
#include "card.h"
#include "playSpace.h"


// Se declaran los constantes para cada una de las posibilidades de cartas
const static char VALUE[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
const static char SUITS[] = {char(03),char(04),char(06),char(05)};

class deck{

public:

    deck(){

        srand(time(nullptr));      // Esto sirve para que no se repita el mismo patron a la hora de abrir el programa
        initialize();

    }

    void initialize() {
        int index = 0;                           //Metodo para crear cada una de las cartas y meterlas en un vector
        for (char i : SUITS) {                  //For each, recomendacion el IDE que estamos usando
            for (char j : VALUE) {
                vec[index] = card(j, i); //Metemos las cartas al vector
                index++;
            }
        }
    }
    void shuffle() {
        int max = 52;
        for (int i = 0; i < max - 1; i++) {
            int randNum = rand() % 52;                   //Metodo general para revolver objetos https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/
            std::swap(vec[i], vec[randNum]);
        }
    }


    card vec[52];    //Vector donde vamos a meter las cartas


};



#endif //PROJECTSOLITAIRE_DECK_H
