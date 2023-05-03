#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "Player.h"
#include "Menu.h"
#include "Game_mod.h"

int main()
{
	srand(time(NULL));			//Инициализация "настоющего" рандомайзера

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	//Добавление кириллицы в ввод/вывод

	int point_menu = 0;
	char c = 'n';

	Player Player_1;

	printf("Добро пожаловать!\nВведите своё имя: ");
	Player_1 = Create_Player();
	system("cls");

	while (1 > 0)
	{
		Menu(Player_1.name);
		while (point_menu < 4)
		{
			scanf("%d", &point_menu);

			switch (point_menu)
			{
			case 1:
				system("cls");
				while (1 > 0)
				{
					Player_1 = game(Player_1);
					printf("Хотите сыграть ещё раз? y/n\n");
					while (1 > 0)
					{
						scanf("%c", &c);
						scanf("%c", &c);
						switch (c)
						{
						case 'y':
							break;
						case 'n':
							break;
						default:
							printf("Введен неправильный символ, попробуйте ещё раз...\n");
							break;
						}
					if ((c == 'n') || (c == 'y')) break;
					}

					if (c == 'n')
					{
						system("cls");
						break;
					}
					else if (c == 'y')
					{	
						system("cls");
						continue;
					}
					
				}
				system("cls");
				break;
			case 2:
				system("cls");
				Menu_stat(Player_1.name);
				while (1 > 0)
				{
					int point_stat_menu;
					scanf("%d", &point_stat_menu);

					switch (point_stat_menu)
					{
					case 1:
						printf("Ваш баланс: %d монет.\n", Player_1.balance);
						break;
					case 2:
						printf("Количество выигранных вами игр: %d игр.\n", Player_1.count_win_game);
						break;
					case 3:
						printf("Количество проигранных вами игр: %d игр.\n", Player_1.count_lose_game);
						break;
					case 0:
						break;
					default:
						printf("Такого номера пункта нет в меню, попробуйте снова.\n");
						break;
					}
					if (point_stat_menu == 0) break;
				}
				system("cls");
				break;
			case 3:
				system("cls");

				Player_1.balance -= deposite(Player_1);
				
				system("cls");
				break;
			case 0:
				system("cls");
				break;
			default:
				printf("Такого номера пункта нет в меню, попробуйте снова.\n");
				break;
			}
			break;
		}
		if ((point_menu == 0) || (Player_1.balance <= 0)) break;

	}
	if (Player_1.balance <= 0) printf("У вас закончились монеты, программа будет завершена...\n");
	printf("До новых встреч!\nНажмите любую клавишу для продолжения...");

	getch();
	return 0;
}