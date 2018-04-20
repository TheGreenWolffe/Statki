#include <iostream>
#include "menu.cpp"
using namespace std;
bool koniec=false;
extern void menu();
int main()
{
    do{
        menu();
    }while(!koniec);

    return 0;
}
