#pragma once

typedef struct Player
{
	char* name;
	int capacity_name;
	int balance;
	int count_game;
	int count_win_game, count_lose_game;
} Player;

Player Create_Player()
{
	Player new_Player;
	new_Player.capacity_name = 0;
	int capacity = 1;
	int new_balance;
	new_Player.name = (char*)malloc(sizeof(char));

	char c = getchar();

	while (c != '\n')
	{
		new_Player.name[new_Player.capacity_name++] = c;

		if (new_Player.capacity_name >= capacity)
		{
			capacity *= 2;
			new_Player.name = (char*)realloc(new_Player.name, capacity * sizeof(char));
		}

		c = getchar();
	}

	new_Player.name[new_Player.capacity_name] = '\0';

	printf("¬ведите начальный баланс: ");
	scanf("%d", &new_balance);

	new_Player.balance = new_balance;
	new_Player.count_game = 0;
	new_Player.count_lose_game = 0;
	new_Player.count_win_game = 0;

	return new_Player;
}

/*
struct Player Create_Player();
#include "Player.c"
*/