//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////		VV	File with everything we need ! VV
///////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

#include "Zasoby.h"

bool strzal(int x, int y, char Area[][12])
{
	if (Area[x][y] != ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TutorialR()
{
	int x, y;
	std::cout << "Witaj w tutorialu Trybu Statki !";
	std::chrono::seconds wait(5);
	std::this_thread::sleep_for(wait);
	system("cls");
	std::cout << "Tutaj nauczymy cie podstaw.";
	std::this_thread::sleep_for(wait);
	system("cls");
	std::cout << "Tak wiec nie tracmy czasu i zaczynajmy !";
	std::this_thread::sleep_for(wait);
	system("cls");
	std::cout << "W grze istenieja dwa rodzaje jednostek:" << std::endl << "jedno-masztowiec(jest ich 4) , dwu-masztowiec(jest ich 3) , trzy-masztowiec(jest ich 2) oraz cztero--masztowiec(jest tylko 1).";
	std::this_thread::sleep_for(wait);
	system("cls");
	std::cout << "jedno-masztowiec - zajmuja 1 kratke na mapie " << <<std::endl "dwu-masztowiec - zajmuja 2 kratki na mapie" << std::endl <<"trzy-masztowiec - zajmuja 3 kratki na mapie "<<std::endl<<"cztero-masztowiec - zajmuje 4 kratki na mapie" << std::endl;
	std::this_thread::sleep_for(wait);
	system("cls");
	std::cout << "Twoim pierwszym zadaniem bedzie strzal w jednostke wroga!" << std::endl << "Podaj jakies kordy(1 - 10, A - J)";
	std::this_thread::sleep_for(wait);
	GenPlan(AreaSi);
	std::cout << "Twoje oodane strzaly:" << std::endl;
	Draw(AreaPlS, AreaSi);
	bool good;
	do {
		good = true;
		std::cin >> x;
		if (std::cin.fail() || x >= 11 || x<1)
		{
			std::cin.clear();
			std::cin.ignore();
			good = false;
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
	} while (std::cin.fail() || !good);
	strzal(x, y, AreaSi);
}