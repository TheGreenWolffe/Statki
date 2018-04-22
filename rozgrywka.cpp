#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>


using namespace std;


extern void wypDwieplan(char plansza[10][10],char plan[10][10]);
extern char planSI[10][10],planPLS[10][10];
extern char planSIs[10][10],planPL[10][10];
extern char planPLE[10][10],planPLEs[10][10];
extern void wypplan(char plansza[10][10]);
extern void wpiplan(char plasz[10][10]);
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
    wypDwieplan(planPLS,planSIs);
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
        wypDwieplan(planPLS,planSIs);;
        cout << "Podaj kordynacje strzalu (po kazdym parametrze enter): " << endl;
        cin >> x;
        cin >> y;

        strzaly++;
    }
    while(statki!=0);

    cout << endl;
    cout << "Mapa wroga" << endl;
    wypDwieplan(planPLS,planSIs);
    do
    {
        system("cls");
        cout << "Informacje o wrogu: ";
        strzalSI(xSI,ySI,statkiSI);
        cout << endl;
        cout << "Mapa wroga" << endl;
        wypDwieplan(planPLS,planSIs);
        cout << "Kordynacje podane przez komputer: "<< xSI << ySI << endl;
        x=rand()%10;
        y=rand()%10;

        strzalySI++;
    }
    while(statkiSI!=0);
}

void strzalpvp(int x,int y,int &statki)
{
    if(planPL[x-1][y-65]=='V')
    {
        cout<<"Trafiony zatopiony!!"<<endl;
        planPLS[x-1][y-65]='X';
        statki--;
    }
    else if(planPL[x-1][y-65]=='Y')
    {
        cout<<"Trafiony "<<endl;
        planPLS[x-1][y-65]='X';
        statki--;
        if((planPL[x-1][y-64]=='Y' or planPL[x-1][y-66]=='Y' or planPL[x][y-65]=='Y' or planPL[x-2][y-65]=='Y') and (planPLS[x-1][y-64]=='X' or planPLS[x-1][y-66]=='X' or planPLS[x][y-65]=='X' or planPLS[x-2][y-65]=='X'))
        {
            cout<<"zatopiony!!"<<endl;
        }
    }
    else
    {
        planPLS[x-1][y-65]='O';
        cout<<"Pudlo"<<endl;
    }

}


void strzalpvp2(int x,int y,int &statki)
{
    if(planPLE[x-1][y-65]=='V')
    {
        cout<<"Trafiony zatopiony!!"<<endl;
        planPLEs[x-1][y-65]='X';
        statki--;
    }
    else if(planPLE[x-1][y-65]=='Y')
    {
        cout<<"Trafiony "<<endl;
        planPLEs[x-1][y-65]='X';
        statki--;
        if((planPLE[x-1][y-64]=='Y' or planPLE[x-1][y-66]=='Y' or planPLE[x][y-65]=='Y' or planPLE[x-2][y-65]=='Y') and (planPLEs[x-1][y-64]=='X' or planPLEs[x-1][y-66]=='X' or planPLEs[x][y-65]=='X' or planPLEs[x-2][y-65]=='X'))
        {
            cout<<"zatopiony!!"<<endl;
        }
    }
    else
    {
        planPLEs[x-1][y-65]='O';
        cout<<"Pudlo"<<endl;
    }

}

void PVP()
{
    string player,player2;
    int statki=20,statki2=20,x,y,strzaly,strzaly2;
    cout<<"Podaj nick pierwszego gracza:"<<endl;
    cin>>player;
    system("cls");
    cout<<"Podaj nick drogiego gracza:"<<endl;
    cin>>player2;
    system("cls");
    cout<<"Wybiera gracz "<<player<<endl;
    wpiplan(planPL);
    cout<<"wybiera gracz "<<player2<<endl;
    wpiplan(planPLE);


    cout << "Informacje o poprzednim strzale przeciwnika: " << "Brak" << endl;
    cout << "Mapa strzalow"<<endl;
    wypDwieplan(planPLS,planPLEs);
    cout << "Tura gracza "<<player<<endl;
    cout << "Podaj kordynacje strzalu (po kazdym parametrze  enter): " << endl;
    cin >> x;
    cin >> y;
    system("cls");
    cout << "Informacje o poprzednim strzale przeciwnika: ";
    strzalpvp2(x,y,statki);
    cout << "Mapa strzalow:"<<endl<<player<<"                              "<<player2;
    wypDwieplan(planPLS,planPLEs);
    cout << "Tura gracza "<<player2<<endl;
    cout << "Podaj kordynacje strzalu (po kazdym parametrze  enter): " << endl;
    cin >> x;
    cin >> y;
    do
    {
    cout << "Informacje o poprzednim strzale przeciwnika: ";

    strzalpvp2(x,y,statki);

    cout << "Mapa strzalow"<<endl;

    wypDwieplan(planPLS,planPLEs);

    cout << "Tura gracza "<<player<<endl;

    cout << "Podaj kordynacje strzalu (po kazdym parametrze  enter): " << endl;

    cin >> x;
    cin >> y;
    system("cls");
    cout << "Informacje o poprzednim strzale przeciwnika: ";

    strzalpvp2(x,y,statki);

    cout << "Mapa strzalow:"<<endl<<player<<"                              "<<player2;

    wypDwieplan(planPLS,planPLEs);

    cout << "Tura gracza "<<player2<<endl;

    cout << "Podaj kordynacje strzalu (po kazdym parametrze  enter): " << endl;

    cin >> x;

    cin >> y;
    strzaly+=2;
    if(statki==0 and statki2==0)
    {
        cout<<"REMIS"<<endl<<"oddane strzaly ogolnie to :"<<strzaly<<endl;
    }

    else if(statki==0)
    {
        cout<<"wygrywa gracz "<<player<<endl<<"oddane strzaly ogolnie to :"<<strzaly<<endl;
    }

    else
    {
        cout<<"wygrywa gracz "<<player2<<endl<<"oddane strzaly ogolnie to :"<<strzaly<<endl;
    }

    }
    while(statki!=0 and statki2!=0);

}


