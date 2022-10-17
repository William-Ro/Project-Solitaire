//
// Created by Administrador on 17/10/2022.
//

#ifndef PROJECTSOLITAIRE_DECK_H
#define PROJECTSOLITAIRE_DECK_H

#include <queue>
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

        queue.push(p1);
        queue.push(p2);
        queue.push(p3);
        queue.push(p4);
        queue.push(p5);
        queue.push(p6);
        queue.push(p7);
        queue.push(p8);
        queue.push(p9);
        queue.push(p10);
        queue.push(p11);
        queue.push(p12);
        queue.push(p13);

        queue.push(d1);
        queue.push(d2);
        queue.push(d3);
        queue.push(d4);
        queue.push(d5);
        queue.push(d6);
        queue.push(d7);
        queue.push(d8);
        queue.push(d9);
        queue.push(d10);
        queue.push(d11);
        queue.push(d12);
        queue.push(d13);

        queue.push(t1);
        queue.push(t2);
        queue.push(t3);
        queue.push(t4);
        queue.push(t5);
        queue.push(t6);
        queue.push(t7);
        queue.push(t8);
        queue.push(t9);
        queue.push(t10);
        queue.push(t11);
        queue.push(t12);
        queue.push(t13);

        queue.push(c1);
        queue.push(c2);
        queue.push(c3);
        queue.push(c4);
        queue.push(c5);
        queue.push(c6);
        queue.push(c7);
        queue.push(c8);
        queue.push(c9);
        queue.push(c10);
        queue.push(c11);
        queue.push(c12);
        queue.push(c13);

    }
    string toStringDeck(){

        stringstream s;

        ::queue<card*> queueAux = queue;

        while (!queueAux.empty()){

            s<<queueAux.front()->toStringCard();
            queueAux.pop();
        }


        return s.str();

    }

    queue<card*> queue;



};


#endif //PROJECTSOLITAIRE_DECK_H
