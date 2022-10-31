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
            playSpace tableCard = playSpace(20);
            playSpaceCards.push_back(tableCard);
        }
        for (int i = 0; i < 4; i++) {
            playSpace suitCard = playSpace(13);
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

            for (int j = 0; j < 7 - i; j++) {

                if (j == (7 - i) - 1) {
                    space.top().flip();        //Le doy vuelta a la ultima carta
                }

                playSpaceCards[j].push(space.top());
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

        int index = 0;
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
            if (suitCard.size < 13)
                return false;
        }
        return true;
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
        int colMax = playSpaceCards.size();
        int rowMax = 0;
        for (int i = 0; i < colMax; i++) {
            if (playSpaceCards[i].size > rowMax) {
                rowMax = playSpaceCards[i].size;
            }
        }

        for (int i = 0; i < rowMax; i++) {
            for (int j = colMax - 1; j >= 0; j--) {
                if (i >= playSpaceCards[j].size) {
                    cout << " \t ";
                    continue;
                }

                if (playSpaceCards[j][i].getFaceUp()) {
                    cout << "  " << playSpaceCards[j][i] << " \t ";
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
            if (!playSpaceCards[from].empty())
                fromCard = &playSpaceCards[from].top();
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
                playSpace::move(playSpaceCards[from], signCards[moveIndex]);
                if (!playSpaceCards[from].empty()) {
                    if (!playSpaceCards[from].top().getFaceUp())
                        playSpaceCards[from].top().flip();
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
            if (!playSpaceCards[to].empty())
                playSpaceCards[to].top().down = &playSpaceCards[from].top();

            if (playSpaceCards[from].top().getValue() != 'K')
                playSpaceCards[from].top().up = &playSpaceCards[to].top();

            playSpace::move(playSpaceCards[from], playSpaceCards[to]);

            if (!playSpaceCards[from].empty())
                if (!playSpaceCards[from].top().getFaceUp())
                    playSpaceCards[from].top().flip();
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
            if (!playSpaceCards[from].empty())
                fromCard = &playSpaceCards[from].top();
            else
                return false;
        }

        if (!playSpaceCards[to].empty())
            toCard = &playSpaceCards[to].top();

        //move king to empty space
        if (playSpaceCards[to].empty()) {
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
            if (!playSpaceCards[to].empty())
                playSpaceCards[to].top().down = &space.top();
            if (space.top().getValue() != 'K')
                space.top().up = &playSpaceCards[to].top();

            playSpaceCards[to].push(space.top());
            space.pop();


        }
    }

    bool validRowToRowMove(card *fromCard, int to) {
        card *toCard;

        if (!playSpaceCards[to].empty())
            toCard = &playSpaceCards[to].top();

        //move king to empty space
        if (playSpaceCards[to].empty()) {
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
        } else if (playSpaceCards[from].size == 0)
            return;

        card *fromCard;
        fromCard = &playSpaceCards[from].top();

        if (fromCard->up == nullptr)
            makeMoveBetweenRows(from, to);
        else {
            int pos = playSpaceCards[from].size - 1;
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

                    if (!playSpaceCards[to].empty()) {
                        fromCard->up = &playSpaceCards[to].top();
                        playSpaceCards[to].top().down = fromCard;
                    }
                    playSpaceCards[to].push(*fromCard);

                    playSpaceCards[from].removeAt(pos);
                    fromCard = fromCard->down;


                    pos++;
                    if (fromCard == nullptr)
                        hasChildren = false;
                }

            }

            if (!playSpaceCards[from].empty())
                if (!playSpaceCards[from].top().getFaceUp())
                    playSpaceCards[from].top().flip();
        }
    }


private:

    playSpace space;   //Espacio de juego global
    playSpace discard;

    vector<playSpace> playSpaceCards;

    vector<playSpace> signCards;


};

#endif //PROJECTSOLITAIRE_GAME_H
