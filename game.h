//
// Created by Administrador on 20/10/2022.
//

#ifndef PROJECTSOLITAIRE_GAME_H
#define PROJECTSOLITAIRE_GAME_H

#include "playSpace.h"
#include "deck.h"

using namespace std;

class game {

public:

    deck d1;  //Creamos nuestro mazo

    game() : space(52), discard(52) {

        d1.shuffle();        //Revolvemos las 52 cartas que tenemos

        for (int i = 0; i < 7; i++) {
            playSpace stackCards = playSpace(20);     //Crea las 7 "pilas" con las que vamos a jugar
            table.push_back(stackCards);
        }
        for (int i = 0; i < 4; i++) {
            playSpace suitCard = playSpace(13);      //Crea la pila donde van los "A"
            signCards.push_back(suitCard);
        }


        dealCards(space);  //Repartimos las cartas en nuestro espacio de juego, en este caso lo mandamos por parametros


    }

    void dealCards(playSpace &aDeck) {               //Metodo para repartir las cartas


        aDeck.clear();
        for (int i = 0; i < 52; i++) {
            aDeck.pushValueCopy(d1.vec[i]);
        }


        for (int i = 0; i < 7; i++) {       //Acomodamos las cartas en columnas

            for (int j = 0; j < 7 - i; j++) {          //Este for va disminuyendo las cartas al repartir

                if (j == (7 - i) - 1) {
                    space.top().flip();        //Le doy vuelta a la ultima carta
                }

                table[j].push(space.top());
                space.pop();
            }
        }
    }

    void draw(int numToDeal) {
        int size = space.size;
        for (int i = 0; i < size; i++) {
            if (space.top().getFaceUp()) {
                space.top().flip();
                discard.push(space.top());
                space.pop();
            }
        }

        if (space.empty()) {
            for (int i = discard.size - 1; i >= 0; i--)
                space.push(discard[i]);

            discard.clear();
        }

        int index;
        for (int i = 0; i < numToDeal; i++) {
            index = space.size - i - 1;
            if (index >= 0) {
                space[index].flip();
            } else
                break;
        }
    }

    bool gameCompleted() {
        for (auto &suitCard: signCards) {
            if (suitCard.size >= 13)     //Cuando se llena la pila de "A" gana
                return true;
        }
        return false;
    }


    void printSuitDetails() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "\n------------------------------------------------------------\n";
        for (int j = 0; j < signCards.size(); j++) {
            switch (j) {
                case 0:
                    SetConsoleTextAttribute(handle,RED);
                    cout << char(03) << " :";
                    break;
                case 1:
                    SetConsoleTextAttribute(handle,RED);
                    cout << char(04) << " :";
                    break;
                case 2:
                    SetConsoleTextAttribute(handle, BLUE);
                    cout << char(06) << " :";
                    break;
                case 3:
                    SetConsoleTextAttribute(handle, BLUE);
                    cout << char(05) << " :";
                    break;
            }

            for (int i = 0; i < signCards[j].size; i++) {
                if (&signCards[j][i] != nullptr)
                    cout << signCards[j][i] << " ";
                else
                    break;
            }
            cout << endl;
        }
        SetConsoleTextAttribute(handle,WHITE);
        cout << endl;
    }

    void printDeckDetails() {

        cout <<" "<< char(176)<<"  ";
        for (unsigned int i = 0; i < space.size; i++) {
            if (space[i].getFaceUp()) {
                cout << space[i] << " ";
            }

        }
        cout << "\n------------------------------------------------------------\n";
    }

    void printAllDetails() {

        printSuitDetails();

        cout << "| 6 | \t | 5 | \t | 4 | \t | 3 | \t | 2 | \t | 1 | \t | 0 |\n";
        cout<<endl;
        //Cannot be unsigned as number is always greater than or equal to 0 --
        int colMax = table.size();
        int rowMax = 0;
        for (int i = 0; i < colMax; i++) {
            if (table[i].size > rowMax) {
                rowMax = table[i].size;
            }
        }

        for (int i = 0; i < rowMax; i++) {
            for (int j = colMax - 1; j >= 0; j--) {
                if (i >= table[j].size) {
                    cout << " \t ";
                    continue;
                }

                if (table[j][i].getFaceUp()) {
                    cout << "  " << table[j][i] << " \t ";
                } else
                    cout << "  " << (char) 176 << " \t ";
            }
            cout << endl;
        }
        cout << endl << endl;

        printDeckDetails();

    }

    bool validSuitMove(int from) {
        card *fromCard;
        if (from == 7) {
            if (!space.empty()) {
                if (!space.top().getFaceUp()) {
                    return false;
                } else {
                    fromCard = &space.top();
                }
            } else {
                return false;
            }
        } else {
            if (!table[from].empty())
                fromCard = &table[from].top();
            else
                return false;
        }


        char suit = fromCard->getSign();
        int moveIndex = 0;
        switch (suit) {
            case char(03):
                moveIndex = 0;
                break;
            case char(04):
                moveIndex = 1;
                break;
            case char(06):
                moveIndex = 2;
                break;
            case char(05):
                moveIndex = 3;
                break;
        }

        if (fromCard->getValueCourtCards() ==
            signCards[moveIndex].size + 1) {
            if (signCards[moveIndex].size != 0) {
                if (fromCard->up != nullptr)
                    fromCard->up->down = nullptr;
                fromCard->up = &signCards[moveIndex].top();     //Este metodo utiliza up y down para navegar entre las columnas
                signCards[moveIndex].top().down = fromCard;
                fromCard->down = nullptr;

            }
            if (from != 7) {
                playSpace::move(table[from], signCards[moveIndex]);
                if (!table[from].empty()) {
                    if (!table[from].top().getFaceUp())
                        table[from].top().flip();
                }
            } else {
                signCards[moveIndex].push(space.top());
                space.pop();
            }
        }


        return false;
    }

    void makeSuitMove(int from) {
        validSuitMove(from);/* validSuit move also makes move */
    }

    void makeMoveBetweenRows(int from, int to) {
        if (validMove(from, to)) {
            if (!table[to].empty())
                table[to].top().down = &table[from].top();

            if (table[from].top().getValue() != 'K')
                table[from].top().up = &table[to].top();

            playSpace::move(table[from], table[to]);

            if (!table[from].empty())
                if (!table[from].top().getFaceUp())
                    table[from].top().flip();
        }

    }

    bool validMove(int from, int to) {

        //start move and end move the same
        if (from == to && from != 7)
            return false;

        card *toCard;
        card *fromCard;

        if (from == 7) {
            if (!space.empty()) {
                if (!space.top().getFaceUp()) {
                    return false;
                } else {
                    fromCard = &space.top();
                }
            } else {
                return false;
            }
        } else {
            //if no card in moving from row not valid
            if (!table[from].empty())
                fromCard = &table[from].top();
            else
                return false;
        }

        if (!table[to].empty())
            toCard = &table[to].top();

        //move king to empty space
        if (table[to].empty()) {
            if (fromCard->getValue() == 'K') //Esto como dice el autor nos sirve para que el K se pueda mover libremente en los espacios vacios
                return true;
            else
                return false;
        } else if (fromCard->getValueCourtCards() == toCard->getValueCourtCards() - 1) {
            int toColor = 0, fromColor = 0;
            if (toCard->getSign() == char(03) || toCard->getSign() == char(04))
                toColor = 0;
            else
                toColor = 1;
            if (fromCard->getSign() == char(03) || fromCard->getSign() == char(04))
                fromColor = 0;
            else
                fromColor = 1;

            if (fromColor == toColor)
                return false;
            else
                return true;
        }
        return false;
    }

    void makeMoveDeckToRow(int to) {
        if (validMove(7, to)) {
            if (!table[to].empty())
                table[to].top().down = &space.top();
            if (space.top().getValue() != 'K')
                space.top().up = &table[to].top();

            table[to].push(space.top());
            space.pop();


        }
    }

    bool validRowToRowMove(card *fromCard, int to) {
        card *toCard;

        if (!table[to].empty())
            toCard = &table[to].top();

        //move king to empty space
        if (table[to].empty()) {
            if (fromCard->getValue() == 'K')
                return true;
            else
                return false;
        } else if (fromCard->getValueCourtCards() == toCard->getValueCourtCards() - 1) {
            int toColor = 0, fromColor = 0;
            if (toCard->getSign() == char(03) || toCard->getSign() == char(04))
                toColor = 0;
            else
                toColor = 1;
            if (fromCard->getSign() == char(03) || fromCard->getSign() == char(04))
                fromColor = 0;
            else
                fromColor = 1;

            if (fromColor == toColor)
                return false;
            else
                return true;
        }
        return false;

    }

    void makeMoveRowToRow(int from, int to) {
        if (from == 7) {
            makeMoveDeckToRow(to);
            return;
        } else if (table[from].size == 0)
            return;

        card *fromCard;
        fromCard = &table[from].top();

        if (fromCard->up == nullptr)
            makeMoveBetweenRows(from, to);
        else {
            int pos = table[from].size - 1;
            bool checkParent = true;
            bool found = false;
            while (checkParent && !found) {
                if (validRowToRowMove(fromCard, to))
                    found = true;
                else if (fromCard->up == nullptr)
                    checkParent = false;
                else {
                    fromCard = fromCard->up;
                    pos--;
                }

            }

            if (found) {
                bool hasChildren = true;
                if (fromCard->up != nullptr)
                    fromCard->up->down = nullptr;

                while (hasChildren) {

                    if (!table[to].empty()) {
                        fromCard->up = &table[to].top();
                        table[to].top().down = fromCard;
                    }
                    table[to].push(*fromCard);

                    table[from].removeAt(pos);
                    fromCard = fromCard->down;


                    pos++;
                    if (fromCard == nullptr)
                        hasChildren = false;
                }

            }

            if (!table[from].empty())
                if (!table[from].top().getFaceUp())
                    table[from].top().flip();
        }
    }


private:

    playSpace space;   //Espacio de juego global

    playSpace discard; //Espacio donde se descartan cartas

    vector<playSpace> table;        //En este vector van metidas las 7 pilas con las que vamos a jugar

    vector<playSpace> signCards;     //Aca va metida la pila de los "A"


};

#endif //PROJECTSOLITAIRE_GAME_H
