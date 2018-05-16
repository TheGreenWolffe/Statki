//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////
///////////////		VV	File with everything we need ! VV
///////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

#include "Zasoby.h"


void Statki()
{
	int choice;
	std::cout << "STATKI" << std::endl;
	std::cout << "Wybierz Tryb:" << std::endl;
	std::cout << "1.Tutorial" << std::endl << "2.Gracz vs Komputer" << std::endl << "3.Gracz vs Gracz"<<std::endl;
	
	do {
		std::cin >> choice;
		if (std::cin.fail() || choice >= 11 || choice<1)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Dokonaj odpowiedniego wyboru (1/2/3)!" << std::endl;

		}
	} while (std::cin.fail());

	switch (choice)
	{
	case 1:
		system("cls");
		TutorialS();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		std::cout << "Podales zly wybor !" << std::endl;
	}
}

void Rycerze()
{
	int choice;
	std::cout << "RYCERZE" << std::endl;
	std::cout << "Wybierz Tryb:" << std::endl;
	std::cout << "1.Tutorial" << std::endl << "2.Gracz vs Komputer" << std::endl << "3.Gracz vs Gracz" << std::endl;

	do {
		std::cin >> choice;
		if (std::cin.fail() || choice >= 11 || choice<1)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Dokonaj odpowiedniego wyboru (1/2/3)!"<<std::endl;

		}
	} while (std::cin.fail());

	switch (choice)
	{
	case 1:
		system("cls");
		TutorialR();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		std::cout << "Podales zly wybor !" << std::endl;
	}
}

void StartMenu()
{
	char choice;
	std::cout << "W co zagramy ,w Statki(s) a moze w Rycerzy(r)?" << std::endl;
	std::cout << "Jezeli chcesz zobaczyc autrow tej gry wpisz 'a'" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 'S':
	case 's':
		system("cls");
		Statki();
		break;
	case 'r':
	case 'R':
		system("cls");
		Rycerze();
		break;
	case 'a':
		system("cls");
		std::cout << "Autorzy:" << std::endl;
		std::cout << "Jacek Stachecki" << std::endl;
		std::cout << "Adam Heinrich" << std::endl << std::endl;
		break;
	default:
		system("cls");
		std::cout << "Musisz dokonac odpowiedniego wyboru!" << std::endl;
	}
}