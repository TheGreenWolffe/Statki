#include <iostream>
#include <windows.h>
using namespace std;

extern bool koniec;
void pojedynek();
void start();
void menu();


void PvS()
{
    int wybor;
    cout<<"1.Easy"<<endl<<"2.Normal"<<endl<<"3.Hard"<<endl<<"4.Wroc";
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
    break;
case 4:
    system("cls");
    pojedynek();
    break;
default:
    break;
}
}
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

void start()
{
    int wybor;
    cout<<"1.Tutorial"<<endl<<"2.Pojedynek"<<endl<<"3.Wroc"<<endl;
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
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
