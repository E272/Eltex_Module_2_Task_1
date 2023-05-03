#pragma once
#include "Player.h"

Player game(Player Player_temp)
{
	int minrand, maxrand;
	int randamount;
	int amountcount;
	int prize;
	int bet;
	int err = 1;

	minrand = 1;
	maxrand = 10;
	amountcount = 3;
	
	
	printf("Добро пожаловать!\nВведите диапазон генерации числа:\nНижний порог: ");
	scanf_s("%d", &minrand);
	printf("Верхний порог: ");
	scanf_s("%d", &maxrand);
	randamount = minrand + rand() % (maxrand - minrand + 1);

	printf("Укажите, за сколько попыток вы хотите попробовать угадать число: ");
	scanf_s("%d", &amountcount);
	
	printf("Какова ваша ставка:");
	do
	{
		scanf("%d", &bet);
		if (bet > Player_temp.balance)
		{
			err = 0;
			printf("Ваша ставка больше, чем количество монет на вашем счету. Вы можете сделать ставку от 0 до %d монет.\nПредложите другую ставку: ", Player_temp.balance);
		}
		else if (bet < 0)
		{
			err = 0;
			printf("Ваша ставка меньше 0. Вы можете сделать ставку от 0 до %d монет.\nПредложите другую ставку: ", Player_temp.balance);
		}
		else err = 1;

	} while (err < 1);
	prize = (maxrand - minrand) / amountcount * bet;
	printf("В случае выигрыша вы получите - %d монет.\n", prize);

	printf("Попытайтесь угадать число!\n");
	int i = 1;
	int x = 0;
	do
	{
		printf("Попытка №%d (осталось %d попыток): ", i, amountcount);
		scanf_s("%d", &x);
		if (x == randamount)
		{
			printf("Вы угадали!\nВаш приз: %d монет\n", prize);
			Player_temp.balance += prize;
			Player_temp.count_win_game++;
			return Player_temp;
		}
		else if ((x < randamount) && (amountcount != 0))
		{
			printf("Загаданное число больше чем то, что вы ввели.\n");
		}
		else if ((x > randamount) && (amountcount != 0))
		{
			printf("Загаданное число меньше чем то, что вы ввели.\n");
		}
		i++;
		amountcount--;
		if (amountcount == 0)
		{
			printf("Вы не смогли угадать за заданное колчество попыток.\nЗагаданное число: %d\n", randamount);
			Player_temp.balance -= bet;
			Player_temp.count_lose_game++;
			return Player_temp;
		}

	} while (amountcount > 0);
	return Player_temp;
}

int deposite(Player Player_1)
{	
	float money, depos = 0.0;
	int err = 1;

	printf("Меню вывода средств.\n");
	printf("Здесь вы можете вывести выигранные монеты по курсу 100 монет - 60 деревянных.\n");
	printf("Какое количество монет вы хотите вывести(на вашем счету %d монет):", Player_1.balance);
	do
	{
		scanf("%f", &depos);
		/*fflush(stdin);
		err = scanf("%f", &depos);
		if (err < 1)
		{
			printf("Некорректный ввод, повторите ввод...\n");
			continue;
		}*/

		if (depos > Player_1.balance)
		{
			err = 0;
			printf("Введено большее количество монет для вывода, чем есть у игрока.\nВведите меньшее количество монет.\n");
		}
		else if (depos < 0)
		{
			err = 0;
			printf("Введеное количество монет меньше нуля.\nВведите количество монет от 0 до %d: ", Player_1.balance);
		}
		else
		{
			err = 1;
		}

	} while (err < 1);
	

	money = depos * 0.6;

	printf("Будет выведенно %.0f монет, конвертированных в %.2f деревянных.\n", depos, money);
	printf("Нажмите любую клавишу для продолжения...\n");
	getch();
	return (int)depos;
}