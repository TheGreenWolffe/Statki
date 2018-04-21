#include <iostream>
#include <cstdlib>


using namespace std;



extern char planPLS[10][10];
extern char planSI[10][10];
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


void tutorial()
{

    int statki=10,x,strzaly=0;
    char y;
    cout<<"informacje o poprzednim strzale:"<<"Brak"<<endl;
    cout<<"Mapa strzalow"<<endl;
    wypplan(planPLS);
    cout<<"Podaj kordynacje strzalu (po kazdym parametrze w przedziale <1,10>  enter):"<<endl;
    cin>>x;
    cin>>y;
    do
    {
        system("cls");
        cout<<"informacje o poprzednim strzale:";
        strzal(x,y,statki);
        cout<<endl;
        cout<<"Mapa strzalow"<<endl;
        wypplan(planPLS);
        cout<<"Podaj kordynacje strzalu (po kazdym parametrze enter):"<<endl;
        cin>>x;
        cin>>y;

        strzaly++;
    }
    while(statki!=0);

}


