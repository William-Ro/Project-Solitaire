#include <iostream>
#include "card.h"

int main() {

    card* c1 = new card("8",char(05),"black");

    cout<<c1->toStringCard();


    return 0;
}
