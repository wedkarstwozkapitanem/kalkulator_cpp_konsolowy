#include <iostream>
#include <locale.h>
#include <limits>
#include <math.h>

using std::cin;
using std::cout;
using std::cerr;

void wyrownaj(int rozmiar,std::string znak = " ") {
    for (int i = 0; i <= 10 - rozmiar; i++) cout << znak;
}


void drukuj_menu(bool start=false) {
    cout << " ---------------\n| Menu główne   |\n ---------------\n";
    std::string opcje[] = { "Dodawania","Odejmowanie","Mnożenie","Dzielenie","Zamknij" };
    for (int i = 0; i < sizeof(opcje) / sizeof(opcje[0]); i++) { cout << "| " << (i + 1) << ". " << opcje[i]; wyrownaj(opcje[i].length()); cout << "|" << '\n'; };
    cout << " --------------- \n \n";
    if (start) {
  
        cout << " "; wyrownaj(-11, "*"); cout << '\n';
        cout << " * Tutaj bedzie wynik * \n";
        cout << " ";  wyrownaj(-11, "*"); cout << '\n';
    }
}



int main()
{
    setlocale(LC_CTYPE, "Polish"); //jak nie odpowiednie kodowanie to polskie znaki sie wysypią

    int opcja=0;

    drukuj_menu(true);

    cout << '\n';
    while (opcja != 5) {
        double x = 0, y = 0;
        do {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(), '\n');
                system("cls"); // moze powodowac blod
                drukuj_menu();
                cout << "Nie prawidłowa liczba! \nWprowadz jeszcze raz ";
                cout << " liczbe 1 ";
                cin >> x;
                cout << " liczbe 2 ";
                cin >> y;
            }
            else {
                cout << " Podaj 1 liczbe: ";
                cin >> x;
                cout << " Podaj 2 liczbe: ";
                cin >> y;
            }
        } while (cin.fail());

        std::cout << "Wybierz numer opcji z menu ";
        while (!(std::cin >> opcja)) {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << "Błedna opcja jeszcze raz \n";
            cin >> opcja;
        }
        system("cls"); // działa tylko na win api
        drukuj_menu();
        cout << " "; wyrownaj(-25, "*"); cout << '\n' << "  ";
        switch (opcja) {
        case 1:
            cout << "Suma liczb " << x << " + " << y << " wynosi: " << (x + y);
            break;
        case 2:
            cout << "Różnica liczb " << x << " - " << y << " wynosi: " << (x - y);
            break;
        case 3:
            cout << "Iloczyn liczb " << x << " * " << y << " wynosi: " << (x * y);
            break;
        case 4:
            if (!y) cerr << "Nie można dzielić przez 0!";
            else
                cout << "Iloraz liczb " << x << " / " << y << " wynosi: " << (x / y);
            break;
        case 5:
            cout << "Zamykanie kalkulatora! \n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return 0;
            //exit(0);
            break;
        default:
            cout << "Nie prawidłowa opcja! ";
        }
        cout << "  \n "; wyrownaj(-25, "*"); cout << "\n \n";
    }

    return 0;
}
