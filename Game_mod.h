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
	
	
	printf("����� ����������!\n������� �������� ��������� �����:\n������ �����: ");
	scanf_s("%d", &minrand);
	printf("������� �����: ");
	scanf_s("%d", &maxrand);
	randamount = minrand + rand() % (maxrand - minrand + 1);

	printf("�������, �� ������� ������� �� ������ ����������� ������� �����: ");
	scanf_s("%d", &amountcount);
	
	printf("������ ���� ������:");
	do
	{
		scanf("%d", &bet);
		if (bet > Player_temp.balance)
		{
			err = 0;
			printf("���� ������ ������, ��� ���������� ����� �� ����� �����. �� ������ ������� ������ �� 0 �� %d �����.\n���������� ������ ������: ", Player_temp.balance);
		}
		else if (bet < 0)
		{
			err = 0;
			printf("���� ������ ������ 0. �� ������ ������� ������ �� 0 �� %d �����.\n���������� ������ ������: ", Player_temp.balance);
		}
		else err = 1;

	} while (err < 1);
	prize = (maxrand - minrand) / amountcount * bet;
	printf("� ������ �������� �� �������� - %d �����.\n", prize);

	printf("����������� ������� �����!\n");
	int i = 1;
	int x = 0;
	do
	{
		printf("������� �%d (�������� %d �������): ", i, amountcount);
		scanf_s("%d", &x);
		if (x == randamount)
		{
			printf("�� �������!\n��� ����: %d �����\n", prize);
			Player_temp.balance += prize;
			Player_temp.count_win_game++;
			return Player_temp;
		}
		else if ((x < randamount) && (amountcount != 0))
		{
			printf("���������� ����� ������ ��� ��, ��� �� �����.\n");
		}
		else if ((x > randamount) && (amountcount != 0))
		{
			printf("���������� ����� ������ ��� ��, ��� �� �����.\n");
		}
		i++;
		amountcount--;
		if (amountcount == 0)
		{
			printf("�� �� ������ ������� �� �������� ��������� �������.\n���������� �����: %d\n", randamount);
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

	printf("���� ������ �������.\n");
	printf("����� �� ������ ������� ���������� ������ �� ����� 100 ����� - 60 ����������.\n");
	printf("����� ���������� ����� �� ������ �������(�� ����� ����� %d �����):", Player_1.balance);
	do
	{
		scanf("%f", &depos);
		/*fflush(stdin);
		err = scanf("%f", &depos);
		if (err < 1)
		{
			printf("������������ ����, ��������� ����...\n");
			continue;
		}*/

		if (depos > Player_1.balance)
		{
			err = 0;
			printf("������� ������� ���������� ����� ��� ������, ��� ���� � ������.\n������� ������� ���������� �����.\n");
		}
		else if (depos < 0)
		{
			err = 0;
			printf("�������� ���������� ����� ������ ����.\n������� ���������� ����� �� 0 �� %d: ", Player_1.balance);
		}
		else
		{
			err = 1;
		}

	} while (err < 1);
	

	money = depos * 0.6;

	printf("����� ��������� %.0f �����, ���������������� � %.2f ����������.\n", depos, money);
	printf("������� ����� ������� ��� �����������...\n");
	getch();
	return (int)depos;
}