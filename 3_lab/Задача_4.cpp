#include <iostream>
#include <ctime>
using namespace std;
void main()
{

    int random_number_comp;
    int random_number_user;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    do {
        srand(time(NULL));
        random_number_comp = rand() % 3 + 1;
        random_number_user = 0;
        char random[3][8] = { "Камень", "Ножницы", "Бумага" };
        cout << "Введите Камень - 1,Ножницы - 2 или Бумага - 3" << endl;
        cin >> random_number_user;
        cout << "Вы ввели - " << random[random_number_user - 1] << endl << " Ввел компьютер - " << random[random_number_comp - 1] << endl;
        if (random_number_comp == random_number_user) cout << "Ничья" << endl;
        else if (random_number_comp == 1 && random_number_user == 3
            || random_number_comp == 2 && random_number_user == 1
            || random_number_comp == 3 && random_number_user == 2) cout << "Вы выиграли" << endl;
        else cout << "Вы проиграли" << endl;


    } while (random_number_comp == random_number_user);
    system("pause");


}