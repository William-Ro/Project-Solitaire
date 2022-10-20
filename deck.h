//
// Created by Administrador on 17/10/2022.
//

#ifndef PROJECTSOLITAIRE_DECK_H
#define PROJECTSOLITAIRE_DECK_H
#include <vector>
#include "card.h"
using namespace std;

class deck {

public:

    deck(){


        card* p1 = new card("1",char(06),"black");
        card* p2 = new card("2",char(06),"black");
        card* p3 = new card("3",char(06),"black");
        card* p4 = new card("4",char(06),"black");
        card* p5 = new card("5",char(06),"black");
        card* p6 = new card("6",char(06),"black");
        card* p7 = new card("7",char(06),"black");
        card* p8 = new card("8",char(06),"black");
        card* p9 = new card("9",char(06),"black");
        card* p10 = new card("10",char(06),"black");
        card* p11 = new card("11",char(06),"black");
        card* p12 = new card("12",char(06),"black");
        card* p13 = new card("13",char(06),"black");

        card* d1 = new card("1",char(04),"red");
        card* d2 = new card("2",char(04),"red");
        card* d3 = new card("3",char(04),"red");
        card* d4 = new card("4",char(04),"red");
        card* d5 = new card("5",char(04),"red");
        card* d6 = new card("6",char(04),"red");
        card* d7 = new card("7",char(04),"red");
        card* d8 = new card("8",char(04),"red");
        card* d9 = new card("9",char(04),"red");
        card* d10 = new card("10",char(04),"red");
        card* d11 = new card("11",char(04),"red");
        card* d12 = new card("12",char(04),"red");
        card* d13 = new card("13",char(04),"red");

        card* t1 = new card("1",char(05),"black");
        card* t2 = new card("2",char(05),"black");
        card* t3 = new card("3",char(05),"black");
        card* t4 = new card("4",char(05),"black");
        card* t5 = new card("5",char(05),"black");
        card* t6 = new card("6",char(05),"black");
        card* t7 = new card("7",char(05),"black");
        card* t8 = new card("8",char(05),"black");
        card* t9 = new card("9",char(05),"black");
        card* t10 = new card("10",char(05),"black");
        card* t11 = new card("11",char(05),"black");
        card* t12 = new card("12",char(05),"black");
        card* t13 = new card("13",char(05),"black");

        card* c1 = new card("1",char(03),"red");
        card* c2 = new card("2",char(03),"red");
        card* c3 = new card("3",char(03),"red");
        card* c4 = new card("4",char(03),"red");
        card* c5 = new card("5",char(03),"red");
        card* c6 = new card("6",char(03),"red");
        card* c7 = new card("7",char(03),"red");
        card* c8 = new card("8",char(03),"red");
        card* c9 = new card("9",char(03),"red");
        card* c10 = new card("10",char(03),"red");
        card* c11 = new card("11",char(03),"red");
        card* c12 = new card("12",char(03),"red");
        card* c13 = new card("13",char(03),"red");

        vector.push_back(p1);
        vector.push_back(p2);
        vector.push_back(p3);
        vector.push_back(p4);
        vector.push_back(p5);
        vector.push_back(p6);
        vector.push_back(p7);
        vector.push_back(p8);
        vector.push_back(p9);
        vector.push_back(p10);
        vector.push_back(p11);
        vector.push_back(p12);
        vector.push_back(p13);

        vector.push_back(d1);
        vector.push_back(d2);
        vector.push_back(d3);
        vector.push_back(d4);
        vector.push_back(d5);
        vector.push_back(d6);
        vector.push_back(d7);
        vector.push_back(d8);
        vector.push_back(d9);
        vector.push_back(d10);
        vector.push_back(d11);
        vector.push_back(d12);
        vector.push_back(d13);

        vector.push_back(t1);
        vector.push_back(t2);
        vector.push_back(t3);
        vector.push_back(t4);
        vector.push_back(t5);
        vector.push_back(t6);
        vector.push_back(t7);
        vector.push_back(t8);
        vector.push_back(t9);
        vector.push_back(t10);
        vector.push_back(t11);
        vector.push_back(t12);
        vector.push_back(t13);

        vector.push_back(c1);
        vector.push_back(c2);
        vector.push_back(c3);
        vector.push_back(c4);
        vector.push_back(c5);
        vector.push_back(c6);
        vector.push_back(c7);
        vector.push_back(c8);
        vector.push_back(c9);
        vector.push_back(c10);
        vector.push_back(c11);
        vector.push_back(c12);
        vector.push_back(c13);

    }
    string toStringDeck() const{

        stringstream s;
        for (auto i : vector) {

            s<<i->toStringCard()<<endl;

        }
        return s.str();

    }

    void shuffle()
    {

        srand(time(NULL));      // Esto sirve para que no se repita el mismo patron a la hora de abrir el programa
        int max = 52;
        for(int i=0; i<max-1; i++)
        {
            int randNum = rand() % 52;                   //Metodo general para revolver objetos
            std::swap(vector[i], vector[randNum]);
        }
    }

    vector<card*> vector;



};


#endif //PROJECTSOLITAIRE_DECK_H
