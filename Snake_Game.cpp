//Rakesh_Shritosh

#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail = 0;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int test = 0;
char ch, prevch;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;

}

void Draw()
{
	test++;
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int  i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j==0 || j == (width - 1))
			{
				cout << "#";
			}
			else if (j==x && i==y)
			{
				cout << "O";
			}
			else if (j==fruitX && i==fruitY)
			{
				cout << "F";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k]==j && tailY[k]==i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
				

			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score:" << score << endl;
	cout << "Test:" << test << endl;
}

void Input()
{
	if (_kbhit())
	{
		ch = _getch();
		if ((prevch=='a' && ch=='s') || (prevch == 's' && ch == 'a') || (prevch == 'w' && ch == 'd') || (prevch == 'd' && ch == 'w'))
		{
			ch = prevch;
		}
		switch (ch)
		{
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
		prevch = ch;
	}

}

void Logic()
{
	/*tailX[0] = x;
	tailY[0] = y;*/
	int prevX = tailX[0];
	int prevY = tailY[0];
	//int prevX, prevY;
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	
	for (int i = 1; i <= ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	/*for (int i = ntail; i > 0; i--)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}*/
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	/*if (x < 1 || x > width - 1 || y < 0 || y > height - 1)
	{
		gameOver = true;
	}*/
	if (x > width-2)
		x = 1;
	else if (x < 1)
		x = width - 2;

	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;

	for (int i = 1; i < ntail; i++)
	{
		if (x==tailX[i] && y==tailY[i])
		{
			gameOver = true;
		}
	}
	if (x==fruitX && y==fruitY)
	{
		score = +10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
	}

}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(500/ntail);
	}
	



	return 0;
}
