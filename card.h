//
// Created by Administrador on 17/10/2022.
//

#ifndef PROJECTSOLITAIRE_CARD_H
#define PROJECTSOLITAIRE_CARD_H

#include <iostream>
#include <sstream>
#include<windows.h>


const static int BLUE = 9;         //Colores para las cartas
const static int RED = 12;
const static int WHITE = 15;

using namespace std;
class card {

public:

    card(char value, char sign): up(nullptr),down(nullptr) {

        this->value = value;

        this->sign = sign;

        this->isFaceUp = false;

    }
    card(){  //Este contructor se va usar luego para inicializar el mazo

    }



    void flip() {
        isFaceUp = !isFaceUp;        //Esto es para las cartas que tenemos ocultas, cuando queremos darles vuelta
    }

    bool getFaceUp() const {

        return isFaceUp;                //Obtiene el estado de la carta
    }

    char getSign() const {

        return sign;             //Devuelve el simbolo de la carta
    }

    char getValue() const {

        return value;            //Devuelve el valor de la carta
    }

    int getValueCourtCards() {

        if (value == 'A') {
            return 1;
        } else if (value == 'T') {
            return 10;                  //Esto se utiliza porque el valor de las cartas es un char y ocupamos el int
        } else if (value == 'J') {      // de cuanto vale esa carta
            return 11;
        } else if (value == 'Q') {
            return 12;
        } else if (value == 'K') {
            return 13;
        }
        else
        {
            char c[] = {value, '\0'};        //Esto convierte el char a int
            return atoi(c);
        }

    };


    friend std::ostream &operator<<(std::ostream &os, card &c);  //Se utiliza operadores para mostrar las cartas
    card *up;
    card *down;

private:

    char value;  //Variable del valor que tiene cada carta

    char sign;   //Este es el simbolo que tiene cada carta

    bool isFaceUp;  //Para ver de que lado esta la carta


};

std::ostream &operator<<(ostream &os, card &c) {

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(c.sign == char(05) || c.sign == char(06))
        SetConsoleTextAttribute(handle, BLUE);
    else
        SetConsoleTextAttribute(handle,RED);         //Metodo para cambiar de color
                                                                                // los simbolos en consola
    os<< c.sign << c.value;
    SetConsoleTextAttribute(handle,WHITE);

    return os;
}


#endif //PROJECTSOLITAIRE_CARD_H
