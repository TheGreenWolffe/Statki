#include <iostream>

//linkowane pliki
#include "menu.cpp"
#include "Plansza.cpp"


using namespace std;

bool koniec=false;
extern char planSI[10][10];
extern void genplan();
extern void wypplan(char plansza[10][10]);
extern void menu();
extern void wpiplan(char plasz[10][10]);
int main()
{
    do{
        genplan();
        menu();
    }while(!koniec);

    return 0;
}
