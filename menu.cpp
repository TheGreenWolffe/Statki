#include <iostream>
#include <windows.h>

#include "rozgrywka.cpp"
using namespace std;

extern char planSI[10][10];
extern void wypplan(char plansza[10][10]);



extern bool koniec;
void pojedynek();
void start();
void menu();

//wybor pojedynku gracz vs gracz/komp
void pojedynek()
{
    int wybor;
    cout<<"1.Player vs Player"<<endl<<"2.Player vs SI"<<endl<<"3.Wroc"<<endl;
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
    break;

case 2:
    system("cls");
    break;
case 3:
    system("cls");
    start();
    break;
default:
    break;
}
}


//wybor typu rozgrywki
void start()
{
    int wybor;
    cout<<"1.Tutorial"<<endl<<"2.Pojedynek"<<endl<<"3.Wroc"<<endl;
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
    tutorial();
    break;

case 2:
    system("cls");
    pojedynek();
    break;
case 3:
    system("cls");
    menu();
    break;
default:
    break;
}
}


//menu glowne
void menu(){
    int wybor;
    cout<<"1.Start"<<endl<<"2.Exit"<<endl;
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
    start();
    break;

case 2:
    koniec=true;
    break;
default:
    break;
}

}
