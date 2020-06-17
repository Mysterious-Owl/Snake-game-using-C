#include<iostream>
#include<vector>
#include<conio.h>
#include<time.h>
#include<synchapi.h>
#include<algorithm>
#include <windows.h>
using namespace std;
namespace consoleforeground
{
  enum {
    BLACK             = 0,
    DARKBLUE          = FOREGROUND_BLUE,
    DARKGREEN         = FOREGROUND_GREEN,
    DARKCYAN          = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED           = FOREGROUND_RED,
    DARKMAGENTA       = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW        = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY          = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY              = FOREGROUND_INTENSITY,
    BLUE              = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN             = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN              = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED               = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA           = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW            = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE             = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
  };
}
namespace consolebackground
{
  enum {
    BLACK             = 0,
    DARKBLUE          = BACKGROUND_BLUE,
    DARKGREEN         = BACKGROUND_GREEN,
    DARKCYAN          = BACKGROUND_GREEN | BACKGROUND_BLUE,
    DARKRED           = BACKGROUND_RED,
    DARKMAGENTA       = BACKGROUND_RED | BACKGROUND_BLUE,
    DARKYELLOW        = BACKGROUND_RED | BACKGROUND_GREEN,
    DARKGRAY          = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    GRAY              = BACKGROUND_INTENSITY,
    BLUE              = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    GREEN             = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    CYAN              = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    RED               = BACKGROUND_INTENSITY | BACKGROUND_RED,
    MAGENTA           = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    YELLOW            = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    WHITE             = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
  };
}

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
int food_x,food_y,hsc,time1=0;;

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
	setConsoleColour(consoleforeground::BLUE);
	cout<<"                   YOUR SCORE:                ";
	if(time1==0)		cout<<"HIGH";
	else if(time1==40)	cout<<"MEDIUM";
	else if(time1==100)	cout<<"LOW";
	cout<<"\n";
	setConsoleColour(consolebackground::CYAN);
	for(int i=0;i<lenght+2;i++)
	cout<<" ";
	cout<<"\n";
	for(int i=0;i<width;i++){
		for(int j=0;j<lenght+2;j++)
			if(j==0)				cout<<" ";
			else if(j==lenght+1)	cout<<" ";
			else 					cout<<" ";	
		cout<<"\n";
	}
	for(int i=0;i<lenght+2;i++)
	cout<<" ";
}

void print_game(){
	int i,j;
	setcursor(31,0);
	setConsoleColour(consoleforeground::BLUE);
	cout<<snake.size()/2-3;
	for(i=0;i<width;i++){
		setcursor(1,2+i);
		for(j=0;j<lenght;j++){
			setConsoleColour(consolebackground::BLACK);
			if(i==snake[snake.end()-snake.begin()-2] && j==snake.back())		setConsoleColour(consolebackground::WHITE);
			else if(board[i][j]=='+')		setConsoleColour(consolebackground::RED);	
			else if(board[i][j]=='O')		setConsoleColour(consolebackground::GREEN);
			cout<<" ";
		}
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
	setConsoleColour(consoleforeground::DARKYELLOW);
	int a=snake.size()/2-3,k;
	if(a>hsc)
	hsc=a;
	cout<<"\n\n\n\n\n                  GAME OVER\n";
	cout<<"                  YOUR SCORE: "<<snake.size()/2-3<<endl;
	cout<<"                  HIGH SCORE EVER: "<<hsc;
	cout<<endl<<endl<<endl;
	cout<<"                  PRESS ANY KEY TO RESTART\n                  esc to EXIT\n";
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
	setcursor(1,11);
	setConsoleColour(consolebackground::WHITE);
	for(int i=0;i<50;i++) cout<<" ";
	setcursor(1,12);
	
	for(int i=0;i<20;i++) cout<<" ";
	cout<<"GAME PAUSED";
	for(int i=0;i<19;i++) cout<<" ";
	setcursor(1,13);
	for(int i=0;i<50;i++) cout<<" ";
	setcursor(1,14);
	for(int i=0;i<15;i++) cout<<" ";
	cout<<"PRESS 'P' TO CONTINUE";
	for(int i=0;i<14;i++) cout<<" ";
	setcursor(1,15);
	for(int i=0;i<50;i++) cout<<" ";	 
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int welcome_to();
	hidecursor();
	int sc=0;
	time1=welcome_to();
	
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
				else if(i1==112){
					pause_menu();
					while(1){
						i1=getch();
						if(i1==112)
						break;
					}
				}					
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
			Sleep(time1);
		}
		int result;
		result=print_final_message();	
		if(result!=27)
		goto restartg;
}
int welcome_to(){
	int a;
	bool t=1;
	setConsoleColour(consoleforeground::YELLOW);
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
