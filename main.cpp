#include <iostream>
#include <fstream>
#include "game.h"


void HandleMove(game &game);

void HandleMoveToAnswer(game &game);


using namespace std;

int main() {

    string name;
    int cont = 0;
    game Game = game();
    Game.printAllDetails();
    bool running = true;

    cout<<"Type your name: "; cin>>name;

    ofstream archivo ("solitaire.txt");

    archivo << name<< " ";



    do {
        char option = ' ';
        cout << endl << endl;
        cout << "1. Move";
        cout << "\n2. Move to answers";
        cout << "\n3. Draw";
        cout << "\n0. Exit";
        cout << "\nEnter option:";
        cin >> option;

        /* 48 - 55 ascii code is 0 - 7 */

        if (Game.gameCompleted()) {
            system("CLS");
            cout << "\n\n\n\t\t\t CONGRATULATIONS YOU WON :) !!!\n\n";
            cont++;
            stringstream ss;
            ss<< cont;
            string str = ss.str();        //Convertimos de int a string para guardar en archivos
            archivo << str <<endl;

            archivo.close();
            system("pause");
            cin.get();
            running = false;
        } else {
            switch ((int) option) {
                case 48:
                    running = false;
                    break;
                case 49:
                    HandleMove(Game);
                    break;
                case 50:
                    HandleMoveToAnswer(Game);
                    break;
                case 51:
                    Game.draw(1);
                    break;
                default:
                    cout << "\nInvalid Option";
                    cin.ignore(80, '\n');
                    break;
            }
            system("CLS");
            Game.printAllDetails();
        }

    } while (running);



    return 0;

}

void HandleMove(game &game) {
    char from = '0', to = '0';
    cout << endl << endl;
    cout << "From (7 for deck):";
    cin >> from;
    cout << "To: ";
    cin >> to;

    if ((int) from >= 48) {
        if ((int) from <= 55 &&
            ((int) from >= 48 && (int) to <= 54)) {
            game.makeMoveRowToRow((int) from - 48, (int) to - 48);
        } else {
            cout << "Invalid input";
            cin.get();
            cin.get();
        }
    } else {
        cout << "Invalid input";
        cin.get();
        cin.get();
    }

}

void HandleMoveToAnswer(game &game) {
    char from = 0;
    cout << endl << endl;
    cout << "From: ";
    cin >> from;

    if ((int) from >= 48 && (int) from <= 55)
        game.makeSuitMove((int) from - 48);

    else {
        cout << "Invalid input";
        cin.get();
        cin.get();
    }

}



