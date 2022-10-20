#include <iostream>
#include "deck.h"

int main() {


    deck d1;

    d1.shuffle();

    cout<<d1.toStringDeck();


    system("pause");



    return 0;
}
