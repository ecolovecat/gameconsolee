#include <iostream>
#include <windows.h >
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include<stdio.h>
#include<time.h>



using namespace std;
int exitt = 0;
///////////////////// FUNCTION  //////////////////////
void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y) 
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
} 

void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

/////////// END FUNCTION ///////////////





/////////////////////////////////// THIS IS SNAKE   ////////////////////////////////////////////////


#define consoleWidth 25
#define consoleHeight 25

enum Move { Up, Down, Left, Right };

struct coordinates
{
	int x, y;
};

struct Snake
{
	coordinates point[50];
	int n;
	Move input;
	int pt = 0;
	int mode;
	int speech2;
};

struct food
{
	coordinates td;
};

struct subtract
{
	coordinates td;
};

void Init(Snake &snake,food &food)
{
	snake.n = 1;
	snake.point[0].x = 0;
	snake.point[0].y = 0;
	snake.input = Down;
	food.td.x = 10;
	food.td.y = 10;
}




void Control(Snake &snake)
{
	//trang thai cua tung point
	for (int i = snake.n - 1; i > 0; i--)
		snake.point[i] = snake.point[i - 1];
	if (kbhit())
	{
		int key = _getch();
		//dieu khien cai dau snake
		if (key == 'a' || key == 'A' )
			snake.input = Left;
		else
			if (key == 'w' || key == 'W')
				snake.input = Up;
			else
				if (key == 'S' || key == 's')
					snake.input = Down;
				else
					if (key == 'd' || key == 'D')
						snake.input = Right;
	}
	if (snake.input == Up)
		snake.point[0].y--;
	else if (snake.input == Down)
		snake.point[0].y++;
	else if (snake.input == Left)
		snake.point[0].x--;
	else if (snake.input == Right)
		snake.point[0].x++;
}
//
void Render(Snake snake, food food, Snake mode)
{
	system("cls");
	TextColor(11);
	for(int i=0;i<consoleHeight;i++)
	{
		gotoxy(consoleWidth,i);
		putchar (179);
	}
	for(int i=0;i<consoleHeight + 1;i++)
	{
		gotoxy(i,consoleWidth - 1);
		putchar (95);
	}
	TextColor(11);
	gotoxy(food.td.x,food.td.y);
	putchar('*');
	TextColor(13);
	gotoxy (snake.point[0].x,snake.point[0].y);
	putchar('@');
	for (int i = 1; i < snake.n; i++)
	{
		gotoxy(snake.point[i].x, snake.point[i].y);
		putchar('O');
	}
}

int Handle(Snake &snake,food &food, int &speech)
{
	snake.mode = rand() % 3 + 1;
	gotoxy(35, 5);
	printf("Your point: %d", snake.pt);
	gotoxy(35, 6);
	printf("Your mode is: %d", snake.mode);
	if(snake.point[0].x < 0|| snake.point[0].x >= consoleWidth||
	snake.point[0].y < 0 || snake.point[0].y >= consoleHeight)
	return -1;
	for(int i = 1; i < snake.n; i++)
		if(snake.point[0].x == snake.point[i].x && snake.point[0].y == snake.point[i].y)
		return -1;
	if(snake.mode == 1) {
	if(snake.point[0].x == food.td.x && snake.point[0].y == food.td.y)
	{
		for(int i = snake.n; i > 0; i--)
			snake.point[i] = snake.point[i-1];
		snake.n++;
		if (snake.input == Up)
		snake.point[0].y--;
	else if (snake.input == Down)
		snake.point[0].y++;
	else if (snake.input == Left)
		snake.point[0].x--;
	else if (snake.input == Right)
		snake.point[0].x++;
		
		food.td.x= rand() % consoleWidth;
		food.td.y= rand() % consoleHeight;
		if (food.td.x == consoleWidth && food.td.y == consoleHeight) {
			food.td.x= rand() % consoleWidth;
			food.td.y= rand() % consoleHeight;
		}
		if(speech > 30)
		speech -= 8;
		snake.pt++;
		snake.pt += 5;
		
		
	}
	}
	
	if(snake.mode == 2) {
	gotoxy(food.td.x,food.td.y);
	putchar('/');
	if(snake.point[0].x==food.td.x&&snake.point[0].y==food.td.y)
	{
		for(int i=snake.n;i>0;i--)
			snake.point[i]=snake.point[i-1];
		if (snake.n > 1) {
		snake.n /= 2;
	}
		if (snake.input == Up)
		snake.point[0].y--;
	else if (snake.input == Down)
		snake.point[0].y++;
	else if (snake.input == Left)
		snake.point[0].x--;
	else if (snake.input == Right)
		snake.point[0].x++;
		
		food.td.x= rand() % consoleWidth - 2;
		food.td.y= rand() % consoleHeight -2 ;
		if (food.td.x == consoleWidth && food.td.y == consoleHeight) {
			food.td.x= rand() % consoleWidth;
			food.td.y= rand() % consoleHeight;
		}
		if(speech > 30)
		speech -= 8;
		snake.pt++;
		snake.pt += 5;
		
		
	}
	}
	
	if(snake.mode == 3) {
		gotoxy(food.td.x,food.td.y);
		putchar('-');
	if(snake.point[0].x==food.td.x&&snake.point[0].y==food.td.y)
	{
		for(int i=snake.n;i>0;i--)
			snake.point[i]=snake.point[i-1];
		snake.n++;
		if (snake.input == Up)
		snake.point[0].y--;
	else if (snake.input == Down)
		snake.point[0].y++;
	else if (snake.input == Left)
		snake.point[0].x--;
	else if (snake.input == Right)
		snake.point[0].x++;
		
		food.td.x= rand() % consoleWidth - 2;
		food.td.y= rand() % consoleHeight -2 ;
		if (food.td.x == consoleWidth - 1 && food.td.y == consoleHeight - 1) {
			food.td.x= rand() % consoleWidth;
			food.td.y= rand() % consoleHeight;
		}
		if(speech > 30)
		speech -= 8;
		snake.pt++;
		snake.pt -= 10;
		if (snake.pt < 0) {
			snake.pt = 0;
		}
		
		
	}
	}
	
}



void snake() {
	system("cls");
	cout << "Choose your start speed: 1 ~ 5: " << " ";
	int speed ;
	cin >> speed;
	int speedd = 250 - speed * 40;
	system("cls");
	int flag;
	
	food food;
	Snake snake;
	Snake mode;
	Init(snake, food);
	while (true)
	{
		
		Render(snake, food, mode);
		gotoxy(35,2);
		printf("Di chuyen bang cach an a s d w");
		Control(snake);
		flag = Handle(snake, food,speedd);
		if(flag == -1) 
		{
			gotoxy(consoleWidth +1 , 10);
			printf("press enter to exit");
			while(_getch() != 13);
			break;
		}
		
		Sleep(speedd);
	}

}


//////////////////////////////////  END SNAKE    //////////////////////////////////////////////



///////////////////////////////////   THIS IS HANG MAN     ///////////////////////////////////////////////////


const string render[] ={
	"     ------------------   \n"
	"     |                    \n"
	"     |                    \n"
	"     |                    \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                     \n"
    "     |                     \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |                     \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |                |    \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |               /|    \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |               /|\\   \n"
	"     |                     \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |               /|\\   \n"
	"     |               /    \n"
	"   ------                  \n",
	"     ------------------    \n"
	"     |                |   \n"
	"     |                0   \n"
	"     |               /|\\   \n"
	"     |               / \\  \n"
	"   ------                  \n",
};

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

/////////     guesssss           /////////////

void update(string renderWord,int count, vector<char>wrong){
	cout << render[count];
	cout << "BAN DA DOAN SAI SO LAN LA : " << count << endl;
	cout << "CAC CHU BAN DA DOAN SAI: ";
	for (int i = 0; i < wrong.size(); i++) {
		cout << wrong[i] << " ";
	}
	cout << endl << endl;
	cout<<renderWord<<endl;
	
}

bool isInclude(vector<char>word,char guess){
	for(int i=0; i < word.size(); i++){
		if(word[i] == guess) return true;
	}
	return false;
}

void updateWord(string &renderWord,char doanchu,vector<char>word){
	for(int i=0;i<renderWord.length();i++){
		if(word[i] == doanchu) renderWord[i] = doanchu; 
	}
}

void game(vector<char>word);
void gotoxy(int x, int y);
void game(vector<char>word) {
	int lives = 7;
	int dem=0;
	string renderWord(word.size(),'~');
	char doanchu;
	vector<char>wrong;
	string word2="";
	word2.resize(word.size());
	for (int i = 0; i < word.size(); i++) {
		word2[i] = word[i];
	}
	do{
		update(renderWord,dem,wrong);
		cin>>doanchu;
		system("cls");
		if(isInclude(word,doanchu)){
			updateWord(renderWord,doanchu,word);
	}
		else {
			dem++;
			wrong.push_back(doanchu);
			
		}
	}
	while(dem < lives && word2 != renderWord);
	update(renderWord,dem,wrong);
	if(dem < lives){
		system("cls");
		cout<<"                      YOU WIN"<<endl;
		
		cout<<"                      Dap An LA: "<<renderWord<<endl;
		
		
	}
	else{
		system("cls");
		cout<<"                               GAME OVER                         "<<endl;
		cout<<"                               THE ANSWER IS: ";
		for (int i = 0; i < word.size(); i++) {
			cout << word[i];
		}
		cout << endl;
		cout<<"                               YOU DIED"<<endl;
		cout<<render[lives];
	}
	system("pause");
}

////////      end guess            //////////

void mode();
void runWord();
void start() {
	cout << "|--------------------------------|" << endl;
	cout << "|                                |" << endl;
	cout << "|      ";
	SetColor(5,6);
	cout << "WELCOME TO HANG MAN";
	SetColor(0,12);
	cout << "       |" << endl;
	cout << "|                                |" << endl;
	cout << "|--------------------------------|" << endl;
	cout << endl;
	SetColor(0,14);
	
	cout << endl;
	mode();
	
}

//              number player         //

void solo() {
	vector<char>word;
	char letter;
	int live = 7;
	int flag = 1;
	cout << "Nhap vao tu ban muon doi phuong doan, nhan ENTER de ket thuc:  ";
	while (flag != 0) {
		letter = getch();
		switch (letter) {
			case '\r':
				flag = 0;
				break;
			case '\b':
				cout << "\b" << " " << "\b\b";
				word.pop_back();
				flag = 1;
				break;
			default:
				cout << "*";
				word.push_back(letter);
				flag = 1;
				break;
		}
	}
	system("cls");
	game(word);
	
}

const string listWord[] = {"angle","ant","apple","arch","arm","army","baby","bag","ball","band","basin","basket","bath","bed","bee","bell","berry","bird","blade","board""boat","bone","book","boot","bottle","box","boy","brain","brake","branch","brick","bridge","brush","bucket","bulb","button","cake","camera","card","cart","carriage","cat","chain","cheese","chest","chin","church","circle","clock","cloud","coat","collar","comb","cord","cow","cup","curtain","cushion","dog","door","drain","drawer","dress","drop","ear","egg","engine","eye","face","farm","feather","finger","fish","flag","floor","fly","foot","fork","fowl","frame","garden","girl","glove","goat","gun","hair","hammer","hand","hat","head","heart","hook","horn","horse","hospital","house","island","jewel","kettle","key","knee","knife","knot","leaf","leg","library","line","lip","lock","map","match","monkey","moon","mouth","muscle","nail","neck","needle","nerve","net","nose","nut","office","orange","oven","parcel","pen","pencil","picture","pig","pin","pipe","plane","plate","plow","pocket","pot","potato","prison","pump","rail","rat","receipt","ring","rod","roof","root","sail","school","scissors","screw","seed","sheep","shelf","ship","shirt","shoe","skin","skirt","snake","sock","spade","sponge","spoon","spring","square","stamp","star","station","stem","stick","stocking","stomach","store","street","sun","table","tail","thread","throat","thumb","ticket","toe","tongue","tooth","town","train","tray","tree","trousers","umbrella","wall","watch","wheel","whip","whistle","window","wing","wire","worm"};
const int numwords = sizeof(listWord)/sizeof(string);
string Word(){
	int k=rand()%numwords;
	return listWord[k];
}

void AI() {
	vector<char>word;
	string word2 = Word();
	for (int i = 0; i < word2.length(); i++) {
		word.push_back(word2[i]);
	}
	system("cls");
	game(word);
	
	
}


////////////////////           end number    ////////////////////



void load()
{
	SetColor(0,2);
	char a = 219;
	gotoxy(56, 14);
	cout << "Loading..."<< endl;
	gotoxy(50,16);
	for(int i = 1; i <= 20; i++)
	{
		for(int j = 0; j <= 25000000; j++);
		cout << a;
	}
	Sleep(1000);
}


void mode();

void intro() {
	
	int intro;
	char letter;
	for (intro = 1; intro < 8; intro++) {
		switch (intro) {
				case 1:
					letter = 'H';
					break;
				case 2:
					letter = 'A';
					break;
				case 3:
					letter = 'N';
					break;
				case 4:
					letter = 'G';
					break;
				case 5:
					letter = 'M';
					break;
				case 6:
					letter = 'A';
					break;
				case 7:
					letter = 'N';
					break;
		}
		
		for (int y = 1; y < 15; ++y) {
			gotoxy(55 + intro, y);
//               Set color             //
		switch (intro) {
				case 1:
					SetColor(0,9);
					cout << letter;
					break;
				case 2:
					SetColor(0,6);
					cout << letter;
					break;
				case 3:
					SetColor(0,3);
					cout << letter;
					break;
				case 4:
					SetColor(0,12);
					cout << letter;
					break;
				case 5:
					SetColor(0,13);
					cout << letter;
					break;
				case 6:
					SetColor(0,5);
					cout << letter;
					break;
				case 7:
					SetColor(0,12);
					cout << letter;
					break;
		}

//                                     //
			Sleep(10);
			if (y < 14)
				{
					cout << "\b\b" << "  ";
				}
			}
		}
		
		
		Sleep(300);
		system("cls");
		int dem = 1;
		while (dem != 0) {
			runWord();
			

			Sleep(500);
			dem--;
			system("cls");
			start();
			mode();
		}
		
		}

void mode();

void instruction() {
	system("cls");
	cout << "Hangman is a paper and pencil guessing game for two or more players.";
	cout << endl << "One player thinks of a word, phrase or sentence and the other(s)";
	cout << endl << "tries to guess it by suggesting letters within a certain number of guesses.";
	cout << endl << endl;
	cout << "press E to exit:  ";
	
	int flag = 1;
	while (flag != 0) {
		char input;
		cin >> input;
		if (input == 'e' || input == 'E') {
			system("cls");
			start();
			flag = 0;
		}
	}
}






void runWord() {
	char tempa[1000] = "powered by Tran Phuong Duy - 19020268         ";
	char tempb[1000], tempc[1000];
	strcpy(tempb, tempa);
	strcat(tempa, tempb);
	int dem = 50;
	for (int i = 0; i < strlen(tempa); i++) {
		strncpy(tempc, tempa + i, 10);
		tempc[15] = 0;
		Sleep(90);
		gotoxy(50,12);
		cout << tempc;
		if (i == strlen(tempb)) {
			i = 0;
		}
		if (dem == 1) {
			
		}
		dem--;
		if(dem == 0){
			system("cls");
			load();
			cout << endl << endl << endl << endl << endl << endl << endl;
			break;
		}
	}
}


void hangman() {
	intro();
	system("cls");
	start();
	fflush(stdin);
	mode();
	//solo(word);
}


////////////////////////////////////////      END OF HANG MAN         ///////////////////////////////////////////////

///////////     CHOSE      ///////////////
void choose() {
	int Set2[] = {7,7};
	int counter2 = 1;
	char key2;
	for (int i = 0;;) {
		key2 = _getch();
		gotoxy(10,5);
		color(Set2[0]);
		cout << "Snake";
		
		gotoxy(10,6);
		color(Set2[1]);
		cout << "Hangman";
		
		
		if (key2 == 72 && counter2 == 2) counter2--;
		if (key2 == 80 && counter2 == 1)counter2++;
		if (key2 == '\r') {
			if (counter2 == 1) {
				system("cls");
				snake();
			}
			if (counter2 == 2) {
				system("cls");
				hangman();
			}
		}
		Set2[0] = 7;
		Set2[1] = 7;
		Set2[2] = 7;
		if(counter2 == 1) {
			Set2[0] = 12;
		}
		
		if(counter2 == 2) {
			Set2[1] = 12;
		}
		
	
		
	}
}



/////////////  END ///////////////

int main () {
	choose();
}

void mode() {
	int Set[] = {7,7,7};
	int counter = 1;
	char key;
	for (int i = 0;;) {
		key = _getch();
		gotoxy(10,6);
		color(Set[0]);
		cout << "1: One player";
		
		gotoxy(10,7);
		color(Set[1]);
		cout << "2: Two players";
		
		gotoxy(10,8);
		
		color(Set[2]);
		cout << "3: Exit";
		
		if (key == 72 && (counter >= 2 && counter <= 3)) counter--;
		if (key == 80 && (counter >= 1 && counter <= 2))counter++;
		if (counter == 1) {
			gotoxy(30,8);
			cout << "1 is selected";
		}
		
		if (counter == 2) {
			gotoxy(30,8);
			cout << "2 is selected";
		}
		
		if (counter == 3) {
			gotoxy(30,8);
			cout << "3 is selected";
		}
		if (key == '\r') {
			if (counter == 1) {
				
				system("cls");
			AI();
			
			int Set2[] = {7,7};
	int counter2 = 1;
	char key2;
	for (int i = 0;;) {
		key2 = _getch();
		gotoxy(10,5);
		color(Set2[0]);
		cout << "Play again";
		
		gotoxy(10,6);
		color(Set2[1]);
		cout << "Exit";
		
		
		if (key2 == 72 && counter2 == 2) counter2--;
		if (key2 == 80 && counter2 == 1)counter2++;
		if (key2 == '\r') {
			if (counter2 == 1) {
				system("cls");
				AI();
			}
			if (counter2 == 2) {
				system("cls");
				start();
				mode();
			}
		}
		Set2[0] = 7;
		Set2[1] = 7;
		Set2[2] = 7;
		if(counter2 == 1) {
			Set2[0] = 12;
		}
		
		if(counter2 == 2) {
			Set2[1] = 12;
		}
		
	
		
	}
			}
			if (counter == 2) {
				system("cls");
			solo();
			
			int Set3[] = {7,7};
	int counter3 = 1;
	char key3;
	for (int i = 0;;) {
		key3 = _getch();
		gotoxy(10,5);
		color(Set3[0]);
		cout << "Play again";
		
		gotoxy(10,6);
		color(Set3[1]);
		cout << "Exit";
		
		
		if (key3 == 72 && counter3 == 2) counter3--;
		if (key3 == 80 && counter3 == 1)counter3++;
		if (key3 == '\r') {
			if (counter3 == 1) {
				system("cls");
				solo();
			}
			if (counter3 == 2) {
				system("cls");
				start();
				mode();
			}
		}
		Set3[0] = 7;
		Set3[1] = 7;
		Set3[2] = 7;
		if(counter3 == 1) {
			Set3[0] = 12;
		}
		
		if(counter3 == 2) {
			Set3[1] = 12;
		}
	}
			}
			if (counter == 3) {
				exit(0);
			}
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		if(counter == 1) {
			Set[0] = 12;
		}
		
		if(counter == 2) {
			Set[1] = 12;
		}
		
		if(counter == 3) {
			Set[2] = 12;
		}
		
		
	}
}
