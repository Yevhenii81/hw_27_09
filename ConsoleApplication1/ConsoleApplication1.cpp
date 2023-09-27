// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime> // time
#include <Windows.h> // окрашивание, работа с координатами
#include <conio.h> // configurate input output
#include "Yevhenii.h"

int main()
{
    system("title Maze");

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// функция, которая скрывает курсор
	hideCursor(false, 100);

    srand(time(0));

    const int width = 60; //ширина лабиринта
    const int height = 20; //высота лабиринта 
    int maze[height][width] = {}; // заготовка

    // Функция, которая инициализирует лабиринт
    initializeMaze(maze, width, height);

    // Функция, которая рисует лабиринт
    printMaze(maze, width, height);

    COORD position;
    position.X = 0;
    position.Y = 2;
    SetCursor(0, 2, PINK, "\x01");

	int coins = 0;
	int hp = 100, enemyDamage = 25, medicineRestore = 25;
	while (true) {
		int code = _getch();
		if (code == 224)
		{
			code = _getch();
		}

		//cout << code << "\n";

		SetConsoleCursorPosition(h, position);
		cout << " ";
		
		if (code == RIGTH && maze[position.Y][position.X + 1] != WALL)
		{
			position.X++;
		}
		else if (code == LEFT && maze[position.Y][position.X - 1] != WALL)
		{
			position.X--;
		}
		else if (code == DOWN && maze[position.Y + 1][position.X] != WALL)
		{
			position.Y++;
		}
		else if (code == UP && maze[position.Y - 1][position.X] != WALL)
		{
			position.Y--;
		}

		SetConsoleCursorPosition(h, position);
		SetConsoleTextAttribute(h, PINK);
		cout << (char)1;

		///////////////////////////////////

		if (position.X == width - 1 && position.Y == heigth - 3)
		{
			MessageBoxA(0, "найден выход из лабиринта!", "ПОБЕДА!", MB_OK);
			break;
		}

		if (maze[position.Y][position.X] == COIN)
		{
			coins++;
			maze[position.Y][position.X] = HALL;
			COORD coins_info;
			coins_info.X = width + 2;
			coins_info.Y = 1;
			SetConsoleCursorPosition(h, coins_info);
			SetConsoleTextAttribute(h, YELLOW);
			cout << "COIN: " << coins;
		}

		if (maze[position.Y][position.X] == ENEMY)
		{
			hp -= enemyDamage;
			maze[position.Y][position.X] = HALL;
			COORD hp_info;
			hp_info.X = width + 1;
			hp_info.Y = 2;
			SetConsoleCursorPosition(h, hp_info);
			SetConsoleTextAttribute(h, RED);
			cout << " HP: " << hp << " %";


			if (hp <= 0)
			{
				MessageBoxA(0, "Вас атаковали враги! Игра окончена!", "ПОРАЖЕНИЕ!", MB_OK);
				break;
			}
		}

		if (maze[position.Y][position.X] == MEDICINE)
		{
			if (hp < 100)
			{
				hp += medicineRestore;
				if (hp > 100)
				{
					hp = 100;
				}
				maze[position.Y][position.X] = HALL;
				COORD hp_info;
				hp_info.X = width + 1;
				hp_info.Y = 2;
				SetConsoleCursorPosition(h, hp_info);
				SetConsoleTextAttribute(h, RED);
				cout << " HP: " << hp << " %";
			}
		}

	}

	system("cls");
	cout << "YOU WIN!!!\n\n";


	Sleep(INFINITE);
   
}


	// коридоры - 0
	// стены - 1
	// монетки - 2
	// враги - 3


// Было 222, стало - 210






















// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
