//
// Created by Administrador on 23/10/2022.
//

#ifndef PROJECTSOLITAIRE_PLAYSPACE_H
#define PROJECTSOLITAIRE_PLAYSPACE_H

#include "card.h"
#include <vector>

class playSpace {
public:

     explicit playSpace(int max) {            //El explicit fue una recomendacion del IDE

        cards.resize(max);         //Esto sirve para especificar el tamanno exacto del vector
        this->size = 0;
        this->max = max;

    }

    bool push(card &card) {
        if (size < max) {
            cards[size] = &card;           //Aca agrego las cartas al vector
            size++;
            return true;
        }
        return false;
    }

    bool pop() {
        if (size > 0) {
            cards[size - 1] = nullptr;      //Quita el de abajo
            size--;
            return true;
        }
        return false;
    }

    card &top() {

        if (size > 0) {
            return *cards[size - 1];         //Retorna el de abajo
        }

    }

    bool empty() const{
        if (size == 0)
            return true;                    //Metodo para comprobar si el vector tiene algo
        return false;
    }

    void clear() {
        for (int i = 0; i < size; i++)          //Metodo para limpiar
            cards[i] = nullptr;

        size = 0;
    }

    bool pushValueCopy(card cardAux) {

        if (size < max) {
            cards[size] = new card(cardAux);     //Hace una copia de la carta
            size++;
            return true;
        }
        return false;
    }

    bool removeAt(int index) {
        if (index >= 0 && index < max) {           //Quita un valor de un espacio en especifico
            cards[index] = nullptr;
            size--;
            return true;
        }
        return false;
    }

    static void move(playSpace &from, playSpace &to) {
        to.push(from.top());                             //Mueve de un lado a otro
        from.pop();
    }

    card &operator[](int index) {

        if (index >= 0 && index <= size) {           //Imprime una carta en especifico
            return *cards[index];
        }

    }


    int size;

private:

    vector<card *> cards; //Un vector de punteros de carta para meter las pilas de cartas del juego
    int max;


};


#endif //PROJECTSOLITAIRE_PLAYSPACE_H
