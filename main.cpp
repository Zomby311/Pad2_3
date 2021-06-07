#include <iostream>

#include "Liste.h"

using namespace std;

int main() {

    Item<int> *moin1 = new Item<int>(1);
    Item<int> *moin2 = new Item<int>(2);
    Item<int> *moin3 = new Item<int>(3);
    Item<int> *moin4 = new Item<int>(4);
    Item<int> *moin5 = new Item<int>(5);

    Liste<int> liste = Liste<int>();

    liste.ins(moin1);
    liste.ins(moin2);
    liste.ins(moin3);
    liste.ins(moin4);
    liste.ins(moin5);


    liste.reset();
    liste.adv();
    liste.adv();
    liste.ins(new Item<int>(10));


    liste.print();




    int input;
    bool run = true;

    while (run) {
        cout << "Bitte waehlen sie eine Option." << endl;
        cout << "0 - Beenden" << endl;
        cout << "1 - Aktuelle Element" << endl;
        cout << "2 - Check ob Liste leer ist." << endl;
        cout << "3 - Check ob Zeiger am Ende ist." << endl;
        cout << "4 - Zeiger vorruecken." << endl;
        cout << "5 - Zeiger auf Anfang setzten" << endl;
        cout << "6 - Item hinzufuegen." << endl;
        cout << "7 - Element am Zeiger loeschen." << endl;
        cout << "8 - Liste ausgeben" << endl;
        cin >> input;

        switch (input) {
            case 0:
                run = false;
                break;
            case 1:
                liste.get()->print();
                break;
            case 2:
                if (liste.empty()) {
                    cout << "Liste ist leer." << endl;
                } else {
                    cout << "Liste ist nicht leer." << endl;
                }
                break;
            case 3:
                if (liste.end()) {
                    cout << "Zeiger ist am Ende" << endl;
                } else {
                    cout << "Zeiger ist nicht am Ende" << endl;
                }
                break;
            case 4:
                liste.adv();
                cout << "Zeiger wurde um eine Stelle nach vorne gerueckt." << endl;
                break;
            case 5:
                liste.reset();
                cout << "Zeiger ist wieder am Anfang." << endl;
                break;
            case 6:
                int eingabe;
                cout << "Bitte eine Info eingeben." << endl;
                cin >> eingabe;
                liste.ins(new Item<int>(eingabe));
                break;
            case 7:
                cout << "Element am Zeiger wurde geloescht" << endl;
                liste.del();
                break;
            case 8:
                liste.print();
                break;
            default:
                cout << "Falsche Eingabe." << endl;
        }
    }
    return 0;
}
