// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//define WIDTH


#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <conio.h>
#include <string>


#define LENGTH 30
#define WIDTH 20

using namespace std;

int  Xfruit, Yfruit;
int Score;


inline void gotoxy(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


typedef struct struct_snake {

	int x;
	int y;
	int tai_length;
	int tab_snake_x[50];
	int tab_snake_y[50];
	char direction;

};


void map() {
	
	for (size_t i = 0; i < LENGTH; i++)
	{
		cout << "*";
	}
	cout << endl;


	for (size_t i = 0; i < WIDTH; i++)
	{
		cout << "*";
		for (size_t k = 0; k < LENGTH-1; k++)
		{
			cout << " ";

		}
		cout << "*" << endl;
	}

	for (size_t i = 0; i < LENGTH; i++)
	{
		cout << "*";
	}

}

void display_fruit(struct_snake &snake) {

	bool repeat;

/*	if (Score % 10 == 0 && Score > 10) {
		Score += 10;
		Xfruit = (rand() % LENGTH-1) - 1;
		Yfruit = (rand() % WIDTH - 1) - 1;
		gotoxy(Xfruit, Yfruit);
		cout << 'X';
	}
	else {*/
	Score++;


	do
	{ 

		repeat = false;
		srand(time(NULL));
		Xfruit = (rand() % (LENGTH +1) -1 );
		Yfruit = (rand() % (WIDTH + 1) -1) ;

		for (int i = 0; i <= snake.tai_length; i++)
		{
			if (Xfruit == snake.tab_snake_x[i] || Yfruit == snake.tab_snake_y[i])
			{
				repeat = true;
			}
		}
		
		
	} while (repeat || (Xfruit==0) || (Xfruit==LENGTH) || (Yfruit==0 ) || (Yfruit==WIDTH) );


	

	if (Score % 10 == 0 && Score > 9) {

		gotoxy(Xfruit, Yfruit);
		cout << 'X';
		Score+= 10;

	}
	else {
		gotoxy(Xfruit, Yfruit);
		cout << 'O';
		Score ++;
	}
	
}



void Direcion(struct_snake &snake , char last_key ) {

	char current_key;

	if (_kbhit())
	{
		current_key = _getch();

		if (current_key =='q' && last_key!='d')
			snake.direction = 'q';
			
		else if (current_key == 's' && last_key != 'z')
			snake.direction = 's';
			
		else if (current_key == 'd' && last_key != 'q')
			snake.direction = 'd';

		else if (current_key == 'z' && last_key != 's')
			snake.direction = 'z';

	}
	
}


void Move(struct_snake &snake ) {
	
		switch (snake.direction) {

		case 'q':
			snake.x--;
			break;

		case 'd':
			snake.x++;
			break;

		case 'z':
			snake.y--;
			break;

		case 's':
			snake.y++;
			break;

		}
	
}


void initiate(struct_snake& snake) {
	
	Score = 0;
	snake.x = 10;
	snake.y = 10;
	snake.tai_length = 2;
	snake.tab_snake_x[0] = snake.x;
	snake.tab_snake_y[0] = snake.y;
	gotoxy(snake.tab_snake_x[0], snake.tab_snake_y[0]);
	cout << "*";
	Xfruit = 5;
	Yfruit = 5;
	gotoxy(Xfruit , Yfruit);
	cout << 'O';

}



int main()
{


	bool Game_Over(true);
	int X_tete, Y_tete;
	struct_snake snake;
	map();
	initiate(snake);
	

	while (Game_Over) {
		


		Direcion(snake, snake.direction);
		Move(snake);

		for (int i = snake.tai_length-1; i > 0; i--)
		{

			snake.tab_snake_x[i] = snake.tab_snake_x[i-1];
			snake.tab_snake_y[i] = snake.tab_snake_y[i-1];

			snake.tab_snake_x[0] = snake.x;
			snake.tab_snake_y[0] = snake.y;

			if ((snake.tab_snake_x[0] == snake.tab_snake_x[i]) && (snake.tab_snake_y[0] == snake.tab_snake_y[i]) && i>2) {
				Game_Over = false;
			}

		}

		if (snake.tab_snake_x[0] >= LENGTH || snake.tab_snake_x[0] <= 0 || snake.tab_snake_y[0] <= 0 || snake.tab_snake_y[0] >= WIDTH)
		{
			Game_Over = false;
		}
		
		

		gotoxy(snake.tab_snake_x[0], snake.tab_snake_y[0]);
		cout << "*";

		Sleep(200);

		gotoxy(snake.tab_snake_x[snake.tai_length - 1], snake.tab_snake_y[snake.tai_length - 1]);
		cout << " ";

					

		if (Xfruit == snake.tab_snake_x[0] && Yfruit == snake.tab_snake_y[0])
		{

			display_fruit(snake);
			snake.tai_length++;

		}
					
		
	}


	cout << "your score is " << Score;

}


