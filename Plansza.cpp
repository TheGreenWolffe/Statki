#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

using namespace std;

char planSI[10][10],planPLS[10][10];
char planSIs[10][10],planPL[10][10];
char planPLE[10][10],planPLEs[10][10];
void genplan();

void genplan()
{

    srand(time(NULL));
    int x,y,z;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            planSI[i][j]=' ';
            planPLS[i][j]=' ';
        }

    }

    for(int i = 0; i < 5; i++)
    {
        x=rand()%10;
        y=rand()%10;
        z=rand()%4;
        if(planSI[x][y]!='Y')
        {
            planSI[x][y]='Y';
            if(z==0)
            {
                planSI[x][y-1]='Y';
            }
            else if(z==1)
            {
                planSI[x][y+1]='Y';
            }
            else if(z==2)
            {
                planSI[x-1][y]='Y';
            }
            else if(z==3)
            {
                planSI[x+1][y]='Y';
            }
        }
        else
        {
            i--;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        x=rand()%10;
        y=rand()%10;
        if(planSI[x][y]!='V' or planSI[x][y]=='Y')
        {
            planSI[x][y]='V';
        }
        else
        {
            i--;
        }

    }



}




void wpiplan(char plasz[10][10])
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        plasz[i][j]=' ';

    char x=' ';
    char y=' ';
    char strona=' ';
    for(int i = 0; i<5; i++)
    {
        cout<<"Postaw swoj dwu masztowiec !! (masz juz "<<i<<"/5 dwu masztowcow)"<<endl;
        wypplan(plasz);
        x=getch();
        cout<<"*"<<endl;
        y=getch();
        cout<<"*"<<endl;
        if(plasz[x-49][y-65]!='Y')
        {

            plasz[x-49][y-65]='Y';
            cout<<"W ktora strone ustawic dziob?"<<endl<<"G - Gora"<<endl<<"P - Prawo"<<endl<<"L - Lewo"<<"D - Dol"<<endl;
            cin>>strona;
            if(strona=='G')
            {
                if(plasz[x-50][y-65]==' ')
                    plasz[x-50][y-65]='Y';
                                        else
                    {
                        cout<<"Tutaj masz juz jakis statek!"<<endl;
                        plasz[x-49][y-65]=' ';
                        i--;
                    }
            }
            else if(strona=='L')
            {
                if(plasz[x-49][y-66]==' ')
                    plasz[x-49][y-66]='Y';
                                        else
                    {
                        cout<<"Tutaj masz juz jakis statek!"<<endl;
                        plasz[x-49][y-65]=' ';
                        i--;
                    }
            }
            else if(strona=='P')
            {
                if(plasz[x-49][y-64]==' ')
                    plasz[x-49][y-64]='Y';
                                        else
                                        {
                        cout<<"Tutaj masz juz jakis statek!"<<endl;
                        plasz[x-49][y-65]=' ';
                        i--;
                                        }

            }
            else if(strona=='D')
            {
                if(plasz[x-48][y-65]==' ')
                    plasz[x-48][y-65]='Y';
                    else
                    {
                        cout<<"Tutaj masz juz jakis statek!"<<endl;
                        plasz[x-49][y-65]=' ';
                        i--;
                    }

            }
            else
            {
                cout<<"musisz wpisac odpowiedni znak!"<<endl;
                plasz[x-49][y-65]=' ';
                i--;
            }

        }
        else
        {
            cout<<"Tutaj juz masz postawiony statek!"<<endl;
            i--;
        }

    }
    cout<<"Pora na jedno masztowce!"<<endl;
    for(int i = 0; i<10;i++)
    {
        cout<<"Postaw swoj jedno masztowiec !! (masz juz "<<i<<"/10 jedno masztowcow)"<<endl;
        wypplan(plasz);
        x=getch();
        cout<<"*"<<endl;
        y=getch();
        cout<<"*"<<endl;
        if(plasz[x-49][y-65]==' ')
        {
            plasz[x-49][y-65]='V';
        }
        else
            {
                cout<<"Tam masz juz jakis statek!"<<endl;
                i--;
            }
    }
}


void wypplan(char plansza[10][10])
{
    cout<<"  |A|B|C|D|E|F|G|H|I|J|"<<endl;
    cout<<"--+-+-+-+-+-+-+-+-+-+-+"<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<i+1;
        if(i+1<10)
        {
            cout<<" ";
        }
        for(int j = 0; j < 10; j++)
        {
            cout<<"|"<<plansza[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"+---------------------+"<<endl;

}


void wypDwieplan(char plansza[10][10],char plan[10][10])
{
    cout<<"  |A|B|C|D|E|F|G|H|I|J|            |A|B|C|D|E|F|G|H|I|J|"<<endl;
    cout<<"--+-+-+-+-+-+-+-+-+-+-+          --+-+-+-+-+-+-+-+-+-+-+"<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<i+1;
        if(i+1<10)
        {
            cout<<" ";
        }
        for(int j = 0; j < 10; j++)
        {
            cout<<"|"<<plansza[i][j];
        }
        cout<<"|          "<<i+1;
        if(i+1<10)
        {
            cout<<" ";
        }
        for(int j = 0; j < 10; j++)
        {
            cout<<"|"<<plan[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<"+---------------------+          +---------------------+"<<endl;

}
