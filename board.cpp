#include<iostream>
#include<vector>
#include<conio.h>
#include<time.h>
#include<synchapi.h>
#include<algorithm>
#include <windows.h>
#include<fstream>
using namespace std;
#define width 25
#define lenght 50

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void setConsoleColour(unsigned short colour)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    SetConsoleTextAttribute(hOut, colour);
}
void setcursor(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
char board[width][lenght];
vector<int> snake;
bool food_eaten=1;
int food_x,food_y,hsc;

void plane(){
	int i,j;
	for(i=0;i<width;i++){
		for(j=0;j<lenght;j++)
			board[i][j]=' ';
	}
	if(food_eaten){
		food_x=rand()%(width-1);
		food_y=rand()%(lenght-1);
		food_x++;
		food_y++;
		food_eaten=0;
	}
	board[food_x][food_y]='O';
}
void initialise_snake(){
	snake.clear();
	snake.push_back(0);
	snake.push_back(30);
	snake.push_back(1);
	snake.push_back(30);
	snake.push_back(2);
	snake.push_back(30);
}
void print_title(){	
	cout<<"                  YOUR SCORE: "<<"\n";
	for(int i=0;i<lenght+2;i++)
	cout<<"H";
	cout<<"\n";
	for(int i=0;i<width;i++){
		for(int j=0;j<lenght+2;j++)
			if(j==0)				cout<<"H";
			else if(j==lenght+1)	cout<<"H";
			else 					cout<<" ";	
		cout<<"\n";
	}
	
	for(int i=0;i<lenght+2;i++)
	cout<<"H";
}

void print_game(){
	int i,j;
	setcursor(31,0);
	cout<<snake.size()/2-3;
	for(i=0;i<width;i++){
		setcursor(1,2+i);
		for(j=0;j<lenght;j++)
			cout<<board[i][j];
		cout<<"\n";
	}
}

void move_snake(int move,char direction){
	int i,j;
	if(direction=='v'){
		snake.push_back(snake[snake.end()-2-snake.begin()]+move);
		snake.push_back(snake[snake.end()-2-snake.begin()]);
	}
	else{
		snake.push_back(snake[snake.end()-2-snake.begin()]);
		snake.push_back(snake[snake.end()-2-snake.begin()]+move);
	}
	snake.erase(snake.begin());
	snake.erase(snake.begin());
}

void snake_board(){
	int i,j;
	plane();
	bool set_head=1;
	for(i=0;i<snake.size();i=i+2){
		if(i==snake.size()-2)		{
			set_head=0;
			board[snake[i]][snake[i+1]]='O';
		}
		board[snake[i]][snake[i+1]]='+';
	}
}

void eat_food(){
	food_eaten=1;
	snake.insert(snake.begin(),snake[1]);
	snake.insert(snake.begin(),snake[1]);
}
int print_final_message(){
	system("cls");

	int a=snake.size()/2-3,k;
	if(a>hsc)
	hsc=a;
	cout<<"\n\n\n\n\n               GAME OVER\n";
	cout<<"               YOUR SCORE: "<<snake.size()/2-3<<endl;
	cout<<"               HIGH SCORE EVER: "<<hsc;
	cout<<endl<<endl<<endl;
	cout<<"               PRESS ANY KEY TO RESTART\n               esc to EXIT\n";
	a=getch();
	return a;
}
bool check_interbody_death(){
	int x,y,i;
	bool j=0;
	x=snake[snake.end()-snake.begin()-2];
	y=snake.back();
	for(i=0;i<snake.size()-2;i=i+2){
		if(x==snake[i] && y==snake[i+1]){
			j=1;
			break;
		}
	}
	return j;
}
void pause_menu(){
	setcursor(1,12);
	for(int i=0;i<20;i++) cout<<" ";
	cout<<"GAME PAUSED";
	setcursor(1,14);
	for(int i=0;i<15;i++) cout<<" ";
	cout<<"PRESS 'P' TO CONTINUE";	 
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int welcome_to();
	hidecursor();
	int sc=0,time=0;
	
	setConsoleColour(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	time=welcome_to();
	
	restartg:
		food_eaten=1;
		system("cls");
		print_title();
		plane();
		initialise_snake();
		int i1=80,i2=80;
		while(i1!=99){
			if(kbhit()){
				i1=getch();
				if(i1==72 && i2!=80 )				i2=i1,move_snake(-1,'v');
				else if(i1==80 && i2!=72)			i2=i1,move_snake(1,'v');
				else if(i1==75 && i2!=77)			i2=i1,move_snake(-1,'h');
				else if(i1==77 && i2!=75)			i2=i1,move_snake(1,'h');
				else if(i1==112)					{pause_menu();while(1){
					i1=getch();
					if(i1==112)
					break;
				}}
				else 								goto congo;
			}
			else{
				congo:
				if(i2==72 )							move_snake(-1,'v');
				else if(i2==80)						move_snake(1,'v');
				else if(i2==75)						move_snake(-1,'h');
				else if(i2==77)						move_snake(1,'h');
			}
			if(check_interbody_death())																												break;
			if(snake.back()>lenght-1 || snake.back()<0 || snake[snake.end()-snake.begin()-2]<0 || snake[snake.end()-snake.begin()-2]>width-1)		break;
			if(food_y==snake.back() && food_x==snake[snake.end()-2-snake.begin()])																	eat_food();
			snake_board();
			print_game();
			Sleep(time);
		}
		int result;
		result=print_final_message();	
		if(result!=27)
		goto restartg;
}
int welcome_to(){
	int a;
	bool t=1;
	cout<<"\n\n\n\n\n\n\n\n\n                         WELCOME TO MY SNAKE GAME\n\n";
	cout<<"                         Choose Difficulty!\n                         1. LOW\n                         2. MEDIUM\n                         3. HIGH\n\n";
	startagai:
	a=getch();
	if(a==49)		return 100;
	else if(a==50)	return 40;
	else if(a==51)	return 0;
	else	if(t)	t=0,cout<<"                         Enter 1 or 2 or 3 only\n";
	goto startagai;
	
}
