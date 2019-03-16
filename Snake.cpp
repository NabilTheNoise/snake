#include <iostream>
#include "conio.h"
#include <random>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

static char board[20][20];
int check();

int gameover(int score) {
	system("cls");
	cout << "\n\n\t\tGame Over!";
	cout << "\n\n\t\tYour score is: " << score;
	cout << "\n\n\t\tRestrat? (Y/N) ";
	char x = _getch();
	if (x == 'y' || x == 'Y') {
		return 1;
	}
	if (x == 'n' || x == 'N') {
		system("cls");
		cout << "\n\n\t\tThanks for Playing the game!\n\t\tGoodbye!\n\t\t(press enter to quit)...";
		cin.get();
		exit(1);
	}

}
void checkforfruit(int m, int n) {
	if (check() == 0) {
		int p1, p2;
		p1 = 1 + (rand() % 18);
		p2 = 1 + (rand() % 18);
		if (board[p1][p2] != '*') {
			board[p1][p2] = 'F';
		}
		board[m][n] = '*';
	}
	else
	{
		board[m][n] = '*';
	}
}
int check() {
	int checkxy = 0;
	for (int i = 1; i<19; i++) {
		for (int j = 1; j<19; j++) {
			if (board[i][j] == 'F' || board[i][j] == 'f') {
				checkxy = 1;
			}
		}
	}
	return checkxy;
}
void box() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 19 || j == 0 || j == 19) {
				board[i][j] = '#';
			}
			else {
				board[i][j] = ' ';
			}
		}
	}

}
void printbox() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
int main() {
	while (true) {
		system("color 0a");
		int move = 0;
		char s[2000]{ 0 };
		//Prevent the array from overloading!!!
		/*for (int i = 0; i < 10000; i++) {
		s[i]={ 0 };
		}*/

		int l = 0;
		int m = 1, n = 1;
		int p = -1, q = -1;
		int x = -1, y = -1;
		int ex = 0, ey = 0;
		int gover = 0;
		int score = 0;
		srand(time(0));
		int sx[400]{ 0 };
		int sy[400]{ 0 };
		box();
		cout << "Welcome To The Snake Classic Game!\n\n";
		cout << "Move with\n'w' (up)\t's' (down)\n'a' (left)\t'd' (right)\n\n";
		cout << "Game Rules Are:\n1.Do not hit the walls\n2.Do not hit the snake head to its body\n";
		cout << "Press 'Enter' to start the game!";
		cin.get();

		while (gover == 0) {



			system("cls");
			checkforfruit(m, n);
			printbox();
			//board[x][y] = '*';
			cout << "your score is:" << score << endl;
			cout << "Moves:" << move << endl;




			s[move] = _getch();
			//cout << endl << s[move];

			switch (s[move]) {
			case 'w':
				if (board[m - 1][n] == 'F' || board[m - 1][n] == 'f') {
					score++;
					y = m;
					x = n;
				}
				if (m - 1 == 0) {
					gover = 1;
					gameover(score);
					break;
					/*
					board[1][n] = ' ';
					m = 19;
					p = m;
					q = n;*/
				}
				if (board[m - 1][n] == '*') {
					gameover(score);
					gover++;
					break;
				}
				if (m - 1 != 0) {
					p = m;
					q = n;
					m--;
				}
				break;


			case 's':
				if (board[m + 1][n] == 'F' || board[m + 1][n] == 'f') {
					score++;
					y = m;
					x = n;
				}
				if (m + 1 == 19) {
					gover = 1;
					gameover(score);
					break;
					/*board[18][n] = ' ';
					m = 0;
					p = m;
					q = n;*/
				}
				if (board[m + 1][n] == '*') {
					gameover(score);
					gover++;
					break;
				}
				if (m + 1 != 19) {
					p = m;
					q = n;
					m++;
				}
				break;


			case 'a':
				if (board[m][n - 1] == 'F' || board[m][n - 1] == 'f') {
					score++;
					y = m;
					x = n;
				}
				if (n - 1 == 0) {
					gover = 1;
					gameover(score);
					break;
					/*
					board[m][1] = ' ';
					n = 19;
					p = m;
					q = n;*/
				}
				if (board[m][n - 1] == '*') {
					gameover(score);
					gover++;
					break;
				}
				if (n - 1 != 0) {
					p = m;
					q = n;
					n--;
				}
				break;


			case 'd':
				if (board[m][n + 1] == 'F' || board[m][n + 1] == 'f') {
					score++;
					y = m;
					x = n;
				}
				if (n + 1 == 19) {
					gover = 1;
					gameover(score);
					break;
					/*
					board[m][18] = ' ';
					n = 0;
					p = m;
					q = n;*/
				}
				if (board[m][n + 1] == '*') {
					gameover(score);
					gover++;
					break;
				}
				if (n + 1 != 19) {
					p = m;
					q = n;
					n++;
				}
				break;
			}
			ey = p;
			ex = q;
			for (int i = move - 1; i >= move - (score + 1); i--) {
				switch (s[i]) {
				case 'w':
					ey++;
					break;
				case 's':
					if (p == 18) {
						ey = 1;
					}
					else
						ey--;
					break;

				case 'a':
					ex++;
					break;

				case 'd':
					ex--;
					break;
				}
			}
			board[ey][ex] = ' ';
			move++;
		}
		system("pause");
		system("cls");
		continue;
	}
}