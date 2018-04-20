#include <iostream>
#include <windows.h>
using namespace std;

extern bool koniec;
void tutorial()
{
    int wybor;
    cout<<"1.Tutorial"<<endl<<"2.Pojedynek"<<endl<<"3.wroc";
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
    break;

case 2:
    system("cls");
    break;
default:
    break;
}
}

void pojedynek()
{
    int wybor;
    cout<<"1.Easy"<<endl<<"2.Normal"<<endl;
    cin>>wybor;
switch( wybor)
{
case 1:
    system("cls");
    break;

case 2:
    system("cls");
    break;
default:
    break;
}
}

void start()
{
    int wybor;
    cout<<"1.Tutorial"<<endl<<"2.Pojedynek"<<endl;
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
