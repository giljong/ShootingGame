#include <stdio.h>
#include <conio.h>
#include<windows.h>

int y1 = 44;
int y2 = 45;
int y3 = 46;
int y4 = 47;
int cnt = 0;
int score = 0;
int x = 30;
int a = 0;
int i = 0;

struct bullet {
	int x = 35, y = 43, exist = 0;
}bullet[50];

struct enemy {
	int x = 10, y = 0, exist = 0;
}enemy[5];

void gotoxy(int x, int y);
void eb(int i);
void db(int i);
void ep();
void start();
void de(int i);
void ee(int i);
void ape();
void ecrash();
void pcrash();
void move();
void em();
void line();
void sco();

int main() {
	system("mode con cols=100 lines=55");
	start();
	ape();
	line();
	while (1) {
		move();
		sco();
		ape();
		em();
	}
}
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void eb(int i) {
	gotoxy(bullet[i].x - 1, bullet[i].y);
	printf("  ");
}

void db(int i) {
	gotoxy(bullet[i].x, bullet[i].y);
	printf("*");
}

void ep() {
	gotoxy(x, y1);
	printf("                ");
	gotoxy(x, y2);
	printf("                ");
	gotoxy(x, y3);
	printf("                ");
	gotoxy(x, y4);
	printf("                ");
}

void start() {
	gotoxy(25, 0);
	printf("민종이의 슈팅게임");
	gotoxy(x, y1);
	printf("   ▲    ");
	gotoxy(x, y2);
	printf(" ■■■    ");
	gotoxy(x, y3);
	printf(" ▲■▲   ");
	gotoxy(x, y4);
	printf(" ▼  ▼  ");
	gotoxy(x, y4 + 1);
	printf("게임을 하려면 아무키나 누르세요...");
	getch();
	gotoxy(x, y4 + 1);
	printf("                                                                      ");
	gotoxy(25, 0);
	printf("                     ");
}

void de(int i) {
	enemy[i].exist = 1;
	gotoxy(enemy[i].x, enemy[i].y);
	printf("▲  ▲");
	gotoxy(enemy[i].x, enemy[i].y+1);
	printf("■■■");
	gotoxy(enemy[i].x, enemy[i].y+2);
	printf("▼■▼");
	gotoxy(enemy[i].x, enemy[i].y+3);
	printf("  ▼");
}

void ee(int i) {
	gotoxy(enemy[i].x, enemy[i].y);
	printf("      ");
	gotoxy(enemy[i].x, enemy[i].y + 1);
	printf("      ");
	gotoxy(enemy[i].x, enemy[i].y + 2);
	printf("      ");
	gotoxy(enemy[i].x, enemy[i].y + 3);
	printf("      ");
}

void ape() {
	for (int i = 0; i < 5; i++) {
		if (enemy[i].exist == 1) {
			cnt++;
		}
	}
	if (cnt == 0) {
		for (int i = 0; i < 5; i++) {
			enemy[i].x += i * 10;
			de(i);
		}
	}
	cnt = 0;
}

void ecrash() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 50; j++) {
			if(bullet[j].exist == 1) {
				if ((enemy[i].x == bullet[j].x && enemy[i].y + 2 == bullet[j].y) ||  (enemy[i].x + 1 == bullet[j].x && enemy[i].y + 2 == bullet[j].y)) {
					enemy[i].exist = 0;
					ee(i);
					score += 10;
					enemy[i].x = 10;
				}
				if ((enemy[i].x + 2 == bullet[j].x && enemy[i].y+3 == bullet[j].y) || (enemy[i].x + 3 == bullet[j].x && enemy[i].y+3 == bullet[j].y)) {
					enemy[i].exist = 0;
					ee(i);
					score += 10;
					enemy[i].x = 10;
				}
				if ((enemy[i].x + 4 == bullet[j].x && enemy[i].y + 2 == bullet[j].y) || (enemy[i].x + 5 == bullet[j].x && enemy[i].y + 2 == bullet[j].y)) {
					enemy[i].exist = 0;
					ee(i);
					score += 10;
					enemy[i].x = 10;
				}
			}
		}
		///	ape();
	}
}

void pcrash() {
	for (int i = 0; i<5;i++) {
		if(enemy[i].exist == 1) {
			if((enemy[i].x + 2 == x&&enemy[i].y+3 == y2)||(enemy[i].x + 3 == x&&enemy[i].y+3 == y2)) {
				system("cls");
				gotoxy(42,25);
				printf("당신의 점수는 %d점입니다.",score);
				gotoxy(60,50);
				printf("이런게임에서도 죽으시는 당신은 도덕책...");
				getch();
				exit(1);
			}
			if((enemy[i].x + 2 == x + 2&&enemy[i].y+3 == y1)||(enemy[i].x + 2 == x + 3&&enemy[i].y+3 == y1)) {
				system("cls");
				gotoxy(42,25);
				printf("당신의 점수는 %d점입니다.",score);
				gotoxy(60,50);
				printf("이런게임에서도 죽으시는 당신은 도덕책...");
				getch();
				exit(1);
			}
			if((enemy[i].x + 3 == x + 3&&enemy[i].y+3 == y1)||(enemy[i].x + 3 == x + 2&&enemy[i].y+3 == y1)) {
				system("cls");
				gotoxy(42,25);
				printf("당신의 점수는 %d점입니다.",score);
				gotoxy(60,50);
				printf("이런게임에서도 죽으시는 당신은 도덕책...");
				getch();
				exit(1);
			}
			if((enemy[i].x + 5 == x&&enemy[i].y+3 == y1)||(enemy[i].x == x + 5&&enemy[i].y+3 == y1)) {
				system("cls");
				gotoxy(42,25);
				printf("당신의 점수는 %d점입니다.",score);
				gotoxy(60,50);
				printf("이런게임에서도 죽으시는 당신은 도덕책...");
				getch();
				exit(1);
			}
			if((enemy[i].x + 2 == x+4 && enemy[i].y+3 == y2)||(enemy[i].x + 3 == x+5&&enemy[i].y+3 == y2)) {
				system("cls");
				gotoxy(42,25);
				printf("당신의 점수는 %d점입니다.",score);
				gotoxy(60,50);
				printf("이런게임에서도 죽으시는 당신은 도덕책...");
				getch();
				exit(1);
			}
		}
	}
}

void move() {
	while (!a) {
		ecrash();
		pcrash();
		if (GetAsyncKeyState(VK_LEFT) && x > 1) {
			x--;
			for (int i = 0; i < 50; i++) {
				if (bullet[i].y == y1 - 1)
									bullet[i].x--;
			}
			gotoxy(x, y1);
			printf("  ▲   ");
			gotoxy(x, y2);
			printf("■■■   ");
			gotoxy(x, y3);
			printf("▲■▲   ");
			gotoxy(x, y4);
			printf("▼  ▼   ");
			gotoxy(x + 8, y1);
			printf("      ");
			gotoxy(x + 8, y2);
			printf("      ");
			gotoxy(x + 8, y3);
			printf("       ");
			gotoxy(x + 8, y4);
			printf("       ");
			a = 1;
		}
		if (GetAsyncKeyState(VK_RIGHT) && x < 60) {
			x += 1;
			for (int i = 0; i < 50; i++) {
				if (bullet[i].y == y1 - 1)
									bullet[i].x++;
			}
			gotoxy(x, y1);
			printf("  ▲   ");
			gotoxy(x, y2);
			printf("■■■   ");
			gotoxy(x, y3);
			printf("▲■▲   ");
			gotoxy(x, y4);
			printf("▼  ▼   ");
			gotoxy(x - 1, y2);
			printf(" ");
			gotoxy(x - 1, y3);
			printf(" ");
			gotoxy(x - 1, y4);
			printf(" ");
			a = 1;
		}
		if (GetAsyncKeyState(VK_SPACE) < 0) {
			int j;
			for (j = 0; bullet[j].y != y1 - 1; j++);
			bullet[j].exist = 1;
			bullet[j].x = x + 4;
			bullet[j].y = 42;
		}
		for (int i = 0; i < 50; i++) {
			if (bullet[i].y != 43) {
				eb(i);
				bullet[i].y--;
				db(i);
				if (bullet[i].y == 1) {
					eb(i);
					bullet[i].y = 43;
					bullet[i].x = x + 4;
					continue;
				}
			}
		}
		Sleep(40);
		a = 1;
	}
	a = 0;
}

void em() {
	for (int i = 0;i<5;i++) {
		if(enemy[i].y>=44) {
			ee(i);
			enemy[i].exist = 0;
			enemy[i].x = 10;
			enemy[i].y = 0;
		} else {
			ee(i);
			enemy[i].y++;
			de(i);
		}
	}
}

void line() {
	for (int i = 0; i<55;i++) {
		gotoxy(67,i);
		printf("|");
	}
}

void sco() {
	gotoxy(78,22);
	printf("score: %d",score);
	gotoxy(75,12);
	printf("좌로 이동:    ←");
	gotoxy(77,10);
	printf("  <조작법>");
	gotoxy(75,13);
	printf("우로 이동:    →");
	gotoxy(75,14);
	printf("총알 발사: 스페이스바");
	gotoxy(76,25);
	printf("자리가 남는다");
	gotoxy(73,30);
	printf("비어있어서 찝찝하다");
	gotoxy(73,35);
	printf("조금만 더 채워야겠다");
	gotoxy(73,40);
	printf("한 줄만 더 채워야겠다");
	gotoxy(73,45);
	printf("마지막으로 한 줄만 더..");
	gotoxy(70,50);
	printf("이제 진짜 마지막으로 한 줄..");
}