#include "Menu.h"

using namespace std;

void Menu::printError(int er) {
    if (er == -1)
        cout << "Bledne dane!" << endl;
    if (er == 1)
        cout << "Bledny wybor!" << endl;
}

void Menu::tspMenu() {
    int op = -1;
    int check = 0;
    int err = 0;

    Graph *data = new Graph();
    do {
        printError(err);
        err = 0;
        printf("\n\nProblem komiwojazera:\n"
                       "[1] Laduj Plik\n"
                       "[2] Generuj Dane\n"
                       "[3] Algorytm Przegladu Zupelnego\n"
                       "[4] Algorytm Podzialu i Ograniczen\n"
                       "[0] Zakoncz\n"
                       "Wybierz: ");
        check = scanf("%d", &op);
        if (check != 1) {
            err = -1;
            fflush(stdin);
            continue;
        }
        switch (op) {
            case 1:
                File::load(*data);
                data->print();
                break;
            case 2:
                err = tspGenerate(data);
                data->print();
                break;
            case 3:
                if (data->getPoints() == 0) {
                    printf("\nBrak grafu\n");
                    continue;
                }

                printf("Caly graf:\n");
                data->print();

                ATSP::BruteForce(data)->print();
                fflush(stdin);
                break;
            case 4:
                if (data->getPoints() == 0) {
                    printf("\nBrak grafu\n");
                    continue;
                }

                printf("Caly graf:\n");
                data->print();

                ATSP::BB(data)->print();
                fflush(stdin);
                break;
            default:
                err = 1;
                break;
        }
    } while (op != 0);
}

int Menu::tspGenerate(Graph *data) {
    int size;
    cout << "Podaj ilosc miast: ";
    int check = scanf("%d", &size);
    if (check != 1) {
        data->generate(0);
        return -1;
    }
    data->generate(size, true);
    return 0;
}
