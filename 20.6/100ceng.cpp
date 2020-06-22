#include<stdio.h>
#include<graphics.h>//��������
#define MAX_BOARD 15
#define WIN_WIDTH 640 
#define WIN_HIGHT 800
#define MAX_SPACE 60
struct board{
	int x;//������
	int y;//������
	int length;//����
	DWORD color;//��ɫ
}board[15];
struct Ball {
	int x;
	double y;
	double vx, vy;
	int r;
	int score;
	DWORD color;
}ball;
void gameInit() {
	srand(GetDoubleClickTime());
	for (int i = 0; i < MAX_BOARD; i++){
		board[i].length = rand() % 100 + 50;
		board[i].x = rand() % (WIN_WIDTH-board[i].length);
		if (i==0)
			board[i].y = rand() %200+200;
		else 
			board[i].y = board[i-1].y + MAX_SPACE;
		board[i].color =RGB(rand()%256, rand() % 256, rand() % 256);
	}
	//��ʼ������
	ball.r = 10;
	ball.x = board[0].x + rand() % board[0].length;
	ball.y = board[0].y-ball.r;
	ball.score = 0;
	ball.color = board[0].color;
	ball.vx = 5;
	ball.vy = 0.6;
}
void gameDraw() {
	cleardevice();
	for (int i = 0; i < MAX_BOARD; i++) {
		setfillcolor(board[i].color);
		solidrectangle(board[i].x, board[i].y, board[i].x + board[i].length, board[i].y + 5);
	}
	setfillcolor(ball.color);
	solidcircle(ball.x, ball.y, ball.r);
	char tempscore[30] = "";
	sprintf_s(tempscore, "����:%d", ball.score);
	outtextxy(10, 10, tempscore);
}
void boardMove() {
	for (int i = 0; i < MAX_BOARD; i++) {
		board[i].y -= 1;
		if (board[i].y<0){//���Խ��
			board[i].y = MAX_BOARD * MAX_SPACE;
			board[i].length = rand() % 100 + 50;
			board[i].x = rand() % (WIN_WIDTH - board[i].length);
			board[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);
		}
	}
}
void ballMove(int speed) {
	//��ȡ���̰���
	if (GetAsyncKeyState(VK_LEFT))
		ball.x -= speed;
	if (GetAsyncKeyState(VK_RIGHT)) 
		ball.x += speed;
	for (int i = 0; i < MAX_BOARD; i++){
		if (ball.x>board[i].x
			&&ball.x<board[i].x+ board[i].length
			&&ball.y>=board[i].y-ball.r
			&&ball.y<board[i].y){
			ball.y = board[i].y - ball.r;
			break;
		}
		else{
			ball.y +=ball.vy;
		}
	}
}
int main() {
	initgraph(WIN_WIDTH, WIN_HIGHT);
	gameInit();
	BeginBatchDraw();//��ʼ�����ͼ
	while (true){
		gameDraw();
		FlushBatchDraw();
		boardMove();
		ballMove(15);
		Sleep(60);
	}
	EndBatchDraw();
	getchar();
	return 0;
}