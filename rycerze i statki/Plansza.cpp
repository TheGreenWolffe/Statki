//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////		VV	File with everything we need ! VV
///////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

#include "Zasoby.h"

char AreaPl[12][12], AreaPlS[12][12];
char AreaPlE[12][12], AreaPlES[12][12];
char AreaSi[12][12], AreaSiS[12][12];

bool CanBePlaced(char Area[12][12],int x,int y,int side)
{
	if (Area[x][y + 1] == ' ' && Area[x][y - 1] == ' ' && Area[x + 1][y] == ' ' && Area[x + 1][y + 1] == ' ' && Area[x + 1][y - 1] == ' '  && Area[x - 1][y + 1] == ' ' && Area[x - 1][y - 1] == ' ' && Area[x - 1][y] == ' ')
	{
	switch (side)
	{
	case 0:
		//Area[x - 1][y] and Area[x][y]
		if (Area[x - 2][y + 1] == ' ' && Area[x - 2][y - 1] == ' ' && Area[x - 2][y] == ' ') return true;
		break;
	case 1:
		//Area[x + 1][y] and Area[x][y]
		if ( Area[x + 2][y + 1] == ' ' && Area[x + 2][y - 1] == ' ' && Area[x + 2][y] == ' ') return true;
		break;
	case 2:
		//Area[x][y - 1] and Area[x][y]
		if ( Area[x - 1][y - 2] == ' ' && Area[x + 1][y - 2] == ' ' && Area[x][y - 2] == ' ') return true;
		break;
	case 3:
		//Area[x][y + 1] and Area[x][y]
		if (Area[x - 1][y + 2] == ' ' && Area[x + 1][y + 2] == ' ' && Area[x][y + 2] == ' ') return true;
		break;
	default:
		std::cout << "jakiœ niespodziewany error w sprawdzaniu terenu(brak mozliwosci wykrycia jednostek)" << std::endl;
		return false;
		break;
	}
	}
	else return false;

}

bool CanBePlaced(char Area[][12], int x, int y)
{
	if (Area[x - 1][y] == ' ' && Area[x + 1][y] == ' ' && Area[x][y - 1] == ' ' && Area[x][y + 1] == ' ' && Area[x - 1][y + 1] == ' ' && Area[x + 1][y + 1] == ' ' && Area[x + 1][y - 1] == ' ' && Area[x - 1][y - 1] == ' ')
	return true;
	else return false;
}

void GenPlan(char Area[][12])
{
	//Reset Area
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Area[i][j]=' ';
		}
	}
	//Add Knights on horse
	srand(time(NULL));
	int knight = 0;
	do
	{
		int x = rand() % 10 + 1, y = rand() % 10 + 1, side = rand() % 4;
		if (Area[x][y] == ' ')
		{
			switch (side)
			{
			case 0:
				if (Area[x - 1][y] == ' ' && x - 1 != 0 && CanBePlaced(Area,x,y,side))
				{
					Area[x - 1][y] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				break;
			case 1:
				if (Area[x + 1][y] == ' ' && x + 1 != 11 && CanBePlaced(Area, x, y, side))
				{
					Area[x + 1][y] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				break;
			case 2:
				if (Area[x][y - 1] == ' ' && y - 1 != 0 && CanBePlaced(Area, x, y, side))
				{
					Area[x][y - 1] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				break;
			case 3:
				if (Area[x][y + 1] == ' ' && y + 1 != 0 && CanBePlaced(Area, x, y, side))
				{
					Area[x][y + 1]= 'H';
					Area[x][y] = 'H';
					knight++;
				}
				break;
			default:
				break;
			}
		}
	} while (knight < 5);
	//Add Knights
	knight = 0;
	srand(time(NULL));
	do
	{
		int x = rand() % 10 + 1, y = rand() % 10 + 1;
		if (Area[x][y] == ' ' && CanBePlaced(Area,x,y))
		{
			Area[x][y] = 'K';
			knight++;
		}
	} while (knight <10);
}

void Draw(char Area[][12])
{
	HANDLE znak;
	znak = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(znak, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  |A|B|C|D|E|F|G|H|I|J|" << std::endl;
	std::cout << "--+-+-+-+-+-+-+-+-+-+-+" << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		std::cout << i;
		if (i < 10)
		{
			std::cout << " ";
		}
		for (int j = 1; j <= 10; j++)
		{
			
			std::cout << "|";
			if(Area[i][j]=='H')
			SetConsoleTextAttribute(znak, BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			else if (Area[i][j] == 'K')
				SetConsoleTextAttribute(znak, BACKGROUND_RED | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(znak, BACKGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << " ";
			SetConsoleTextAttribute(znak, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		std::cout << "|" << std::endl;
	}
}

void Draw(char Area[][12],char AreaE[][12])
{
	HANDLE znak;
	znak = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(znak, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  |A|B|C|D|E|F|G|H|I|J|            |A|B|C|D|E|F|G|H|I|J|" << std::endl;
	std::cout << "--+-+-+-+-+-+-+-+-+-+-+          --+-+-+-+-+-+-+-+-+-+-+" << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			std::cout << "|";
			if (Area[i][j] == 'H')
				SetConsoleTextAttribute(znak, BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			else if (Area[i][j] == 'K')
				SetConsoleTextAttribute(znak, BACKGROUND_RED | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(znak, BACKGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << " ";
			SetConsoleTextAttribute(znak, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
			std::cout << "|";
			std::cout << "          ";
			
		for (int j = 0; j <= 10; j++)
		{
			std::cout << "|";
			if (AreaE[i][j] == 'H')
				SetConsoleTextAttribute(znak, BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			else if (AreaE[i][j] == 'K')
				SetConsoleTextAttribute(znak, BACKGROUND_RED | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(znak, BACKGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << " ";
			SetConsoleTextAttribute(znak, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		}
		std::cout << "|" << std::endl;
	}
}

void PlaceKnight(char Area[][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Area[i][j] = ' ';
		}
	}
	int x;
	char y;
	int knight = 0;
	char side=' ';
	bool good=false;
	do {
		std::cout << "Podaj kordynacje gdzie ma stac ta kawaleria ( " << knight << " /5):" << std::endl;

		//VV Are thouse inputs correct ? VV
		do {
			good = false;
			std::cin >> x;
			if (std::cin.fail() || x>=11 || x<1)
			{	
				std::cin.clear();
				std::cin.ignore();
				good = true;
				std::cout << "Podaj poprawna kordynacje ";

			}
			std::cin >> y;
		if (y >= 'a' && y >= 'A' || y <= 'z' && y <= 'Z')
		{
			if (y >= 97 and y <= 122)
			{
				y -= 32;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Podaj poprawna kordynacje ";
		}
		} while (std::cin.fail() || good);
		//End of checking
	
		if (Area[x][y-64] == ' ')
		{
			std::cout << "W ktora strone ma byc ustawiona kawaleria"<<std::endl;
			do
			{
				std::cin >> side;
				if (side == 'D' || side == 'G' || side == 'L' || side == 'P' || side == 'd' || side == 'g' || side == 'l' || side == 'p')
				{
					if (side == 'd' || side == 'g' || side =='l' || side =='p')
					{
					side -= 32;
					}
				}
				else
				{
					std::cin.clear();
					std::cin.ignore();
				}
			}while (std::cin.fail());
			y -= 64;
			switch (side)
			{
			case 'G':
				if (Area[x - 1][y] == ' ' && x - 1 != 0 && CanBePlaced(Area, x, y, side-71))
				{
					Area[x - 1][y] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				break;
			case 'D':
				if (Area[x + 1][y] == ' ' && x + 1 != 11 && CanBePlaced(Area, x, y, side-67))
				{
					Area[x + 1][y] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				else
				{
					std::cout << "Nie mozesz tam postawic kawaleri" << std::endl;
				}
				break;
			case 'L':
				if (Area[x][y - 1] == ' ' && y - 1 != 0 && CanBePlaced(Area, x, y, side-74))
				{
					Area[x][y - 1] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				else
				{
					std::cout << "Nie mozesz tam postawic kawaleri" << std::endl;
				}
				break;
			case 'P':
				if (Area[x][y + 1] == ' ' && y + 1 != 11 && CanBePlaced(Area, x, y, side-77))
				{
					Area[x][y + 1] = 'H';
					Area[x][y] = 'H';
					knight++;
				}
				else
				{
					std::cout << "Nie mozesz tam postawic kawaleri" << std::endl;
				}
				break;
			default:
				std::cout << "heh cos sie nie udalo ;/"<<std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Nie mozesz tam postawic kawaleri" << std::endl;
		}
		system("cls");
	Draw(Area);
	} while (knight < 5);


}