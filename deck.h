//
// Created by Administrador on 26/10/2022.
//

#ifndef PROJECTSOLITAIRE_DECK_H
#define PROJECTSOLITAIRE_DECK_H

#include <ctime>
#include "card.h"
#include "playSpace.h"

const static char VALUE[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
const static char SUITS[] = {char(03),char(04),char(06),char(05)};

class deck{

public:

    deck(){

        srand(time(nullptr));      // Esto sirve para que no se repita el mismo patron a la hora de abrir el programa
        initialize();

    }

    void initialize() {
        int index = 0;        //Llenar el mazo
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                vec[index] = card(VALUE[j], SUITS[i]);
                index++;
            }
        }
    }
    string toStringDeck() const {

        stringstream s;
        for (auto i: vec) {
            s << i.toStringCard() << endl;
        }
        return s.str();

    }
    void shuffle() {
        int max = 52;
        for (int i = 0; i < max - 1; i++) {
            int randNum = rand() % 52;                   //Metodo general para revolver objetos
            std::swap(vec[i], vec[randNum]);
        }
    }
    void initializeVector(playSpace &aDeck) {
        int max = 52;
        aDeck.clear();
        for (int i = 0; i < max; i++)
            aDeck.pushValueCopy(vec[i]);
    }

private:
    card vec[52];


};



#endif //PROJECTSOLITAIRE_DECK_H
