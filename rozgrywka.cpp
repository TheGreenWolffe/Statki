#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>


using namespace std;



extern char planPLS[10][10];
extern char planSI[10][10],planSIs[10][10],planPL[10][10];
extern void wypplan(char plansza[10][10]);
void strzal(int x,int y,int &statki)
{
    if(planSI[x-1][y-65]=='V')
    {
        cout<<"Trafiony zatopiony!!"<<endl;
        planPLS[x-1][y-65]='X';
        statki--;
    }
    else
    {
        planPLS[x-1][y-65]='O';
        cout<<"Pudlo!!"<<endl;
    }

}

void strzalSI(int xSI,int ySI,int &statkiSI)
{
    if(planPLS[xSI-1][ySI-65]=='V')
    {
        cout<<"Trafiony zatopiony!!"<<endl;
        planSIs[xSI-1][ySI-65]='X';
        statkiSI--;
    }
    else
    {
        planSIs[xSI-1][ySI-65]='O';
        cout<<"Pudlo!!"<<endl;
    }

}

void tutorial()
{

    int statki=15,x,strzaly=0;
    char y;
    cout << "Informacje o poprzednim strzale: " << "Brak" << endl;
    cout << "Mapa strzalow"<<endl;
    wypplan(planPLS);
    cout << "Podaj kordynacje strzalu (po kazdym parametrze w przedziale <1,duze A-J>  enter): " << endl;
    cin >> x;
    cin >> y;
    do
    {
        system("cls");
        cout << "Informacje o poprzednim strzale: ";
        strzal(x,y,statki);
        cout << endl;
        cout << "Mapa strzalow" << endl;
        wypplan(planPLS);
        cout << "Podaj kordynacje strzalu (po kazdym parametrze enter): " << endl;
        cin >> x;
        cin >> y;

        strzaly++;
    }
    while(statki!=0);

}

void PVSI()
{
    srand(time(NULL));
     int statki=15,x,strzaly=0,statkiSI=15,xSI,strzalySI=0;
    char y,ySI;
    cout << "Informacje o poprzednim strzale: " << "Brak" << endl;
    cout << "Mapa strzalow" << endl;
    wypplan(planPLS);
    cout << "Podaj kordynacje strzalu (po kazdym parametrze w przedziale <1,duze A-J>  enter): " << endl;
    cin >> x;
    cin >> y;
    do
    {
        system("cls");
        cout << "Informacje o poprzednim strzale: ";
        strzal(x,y,statki);
        cout << endl;
        cout << "Mapa strzalow" << endl;
        wypplan(planPLS);
        cout << "Podaj kordynacje strzalu (po kazdym parametrze enter): " << endl;
        cin >> x;
        cin >> y;

        strzaly++;
    }
    while(statki!=0);

    cout << endl;
    cout << "Mapa wroga" << endl;
    wypplan(planSIs);
    do
    {
        system("cls");
        cout << "Informacje o wrogu: ";
        strzalSI(xSI,ySI,statkiSI);
        cout << endl;
        cout << "Mapa wroga" << endl;
        wypplan(planSIs);
        cout << "Kordynacje podane przez komputer: "<< xSI << ySI << endl;
        x=rand()%10;
        y=rand()%10;

        strzalySI++;
    }
    while(statkiSI!=0);
}



