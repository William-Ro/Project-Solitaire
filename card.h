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

    card *up;
    card *down;

    card(char value, char sign): up(nullptr),down(nullptr) {

        this->value = value;

        this->sign = sign;

        this->isFaceUp = false;



    }
    card(){

    }

    string toStringCard() {

        stringstream s;

        s << value << " ";

        s << sign << " ";

        return s.str();
    }

    void flip() {
        isFaceUp = !isFaceUp;        //Esto es para las cartas que tenemos ocultas, cuando queremos darles vuelta
    }

    bool getFaceUp() const {

        return isFaceUp;
    }

    char getSign() const {

        return sign;             //Devuelve el simbolo
    }

    char getValue() const {

        return value;
    }

    int getValueCourtCards() {

        if (value == 'A') {
            return 1;
        } else if (value == 'T') {
            return 10;
        } else if (value == 'J') {
            return 11;
        } else if (value == 'Q') {
            return 12;
        } else if (value == 'K') {
            return 13;
        }
        else
        {
            char c[] = {value, '\0'};
            return atoi(c);
        }

    };


    friend std::ostream &operator<<(std::ostream &os, card &c);

private:

    char value;
    char sign;
    bool isFaceUp;


};

std::ostream &operator<<(ostream &os, card &c) {

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(c.sign == char(05) || c.sign == char(06))
        SetConsoleTextAttribute(handle, BLUE);
    else
        SetConsoleTextAttribute(handle,RED);

    os<< c.sign << c.value;
    SetConsoleTextAttribute(handle,WHITE);

    return os;
}


#endif //PROJECTSOLITAIRE_CARD_H
