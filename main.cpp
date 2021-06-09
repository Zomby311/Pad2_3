#include <iostream>

#include "Liste.h"

using namespace std;

int main() {


//    Item<int> *item1 = new Item<int>(1);
//    Item<int> *item2 = new Item<int>(2);
//    Item<int> *item3 = new Item<int>(3);
//    Item<int> *item4 = new Item<int>(4);
//    Item<int> *item5 = new Item<int>(5);
//    Item<int> *item6 = new Item<int>(6);
//    Item<int> *item7 = new Item<int>(7);
//    Item<int> *item8 = new Item<int>(8);
//    Item<int> *item9 = new Item<int>(9);
//    Item<int> *item10 = new Item<int>(10);
//
//    Liste<int> liste = Liste<int>();
//
//
//
//    liste.ins(item3);
//    liste.ins(item5);
//    liste.ins(item4);
//    liste.ins(item1);
//    liste.ins(item8);
//    liste.ins(item6);
//    liste.ins(item10);
//    liste.ins(item9);
//    liste.ins(item7);
//    liste.ins(item2);


    Item<string > *item1 = new Item<string>("a");
    Item<string > *item2 = new Item<string>("b");
    Item<string > *item3 = new Item<string>("c");
    Item<string > *item4 = new Item<string>("d");
    Item<string > *item5 = new Item<string>("e");

    Liste<string> liste = Liste<string>();

    liste.ins(item1);
    liste.ins(item2);
    liste.ins(item4);
    liste.ins(item3);



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
//                liste.ins(new Item<int>(eingabe));
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
