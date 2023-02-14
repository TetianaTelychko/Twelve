#include <iostream>
#include "Twelve.h"

string interface = "\x1B[95m─────────────────────────⊰⊱─────────────────────────\x1B[0m\n";
string clear = "\033[2J\033[1;1H";

void game(Twelve &twelve1, Twelve &twelve2){
    cout << clear;
    cout << interface;
    twelve1.show();
    cout << clear;
    int j;
    for(int i = 0; i < 12; ++i){
        cout << '[' << i << ']' << " введи значення : ";
        cin >> j;
        twelve2.getVector().push_back(j);
    }

    cout << "Введіть 1, щоб відредагувати вектор (або будь-яке інше щоб продовжити) : ";
    int user;
    cin >> user;
    if(user == 1){
        cout << "Введіть індекс : ";
        int index;
        cin >> index;
        twelve2.editVector(index);
        cout << "Введіть 1, щоб відредагувати ще одне значення : ";
        cin >> user;
    }
    cout << clear << interface << "Результат = " << Twelve::getCommon(twelve1, twelve2);
}
int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    Twelve twelve1{12};
    cout << interface;
    cout << "Ціль гри: запам'ятати якомога більше чисел за 20 секунд.\n"
            "Щоб розпочати гру, введіть 1 : ";
    int user;
    cin >> user;
    Twelve twelve2;
    if(user == 1){
        game(twelve1, twelve2);
    }

    return 0;
}
