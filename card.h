//
// Created by Administrador on 17/10/2022.
//

#ifndef PROJECTSOLITAIRE_CARD_H
#define PROJECTSOLITAIRE_CARD_H

#include <iostream>
#include <sstream>
#include <utility>
using namespace std;

class card {

public:

    card(string value,char sign, string color){

        this->value = std::move(value);

        this->sign = sign;

        this->color = std::move(color);

    }

    string toStringCard(){

        stringstream s;

        s << value << " ";

        s << sign << " ";

        s << color <<endl;

        return s.str();
    }

private:

    string value,color;
    char sign;



};


#endif //PROJECTSOLITAIRE_CARD_H
