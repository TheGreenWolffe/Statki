#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

char planSI[10][10],planPLS[10][10],planSIs[10][10],planPL[10][10];
void genplan();

void genplan()
{

    srand(time(NULL));
    int x,y;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            planSI[i][j]=' ';
            planPLS[i][j]=' ';
        }

    }


    for(int i = 0; i < 10; i++)
    {
        x=rand()%10;
        y=rand()%10;
        if(planSI[x][y]!='V')
        {
            planSI[x][y]='V';
        }
        else
        {
            i--;
        }

    }

}


void wypplan(char plansza[10][10]){
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
