/*

*Please dont steal my work and my name, (if you to use it contact me).
**I worked hard for this over a week.
*** You can support by following me on gethub.

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
int life;
int Score();
char key;
void load();
void printbanner();
int level();
int vite;
void spide_game();
void Move();
void Food();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void Finjeux();

struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int main()
{
    char name[20] ;

        system("COLOR 1A") ;

    char key;

    int L,i ;

    printbanner();

    getch();

    system("cls");

    load();

    length=2;

    head.x=7;

    head.y=8;

    head.direction=DOWN;

    vite=level;

    Boarder();

    Food();

    life=5;

    bend[0]=head;

    Move();

    level();

    return 0;

}

void Move()
{
    int a,i;

    do{

        Food();

        fflush(stdin);

        len=0;

        for(i=0;i<30;i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

            break;

        }

        spide_game(length);

        Boarder();

        if(head.direction==RIGHT)
        {
            Right();

        }
        else if(head.direction==LEFT)
        {
            Left();

        }
        else if(head.direction==DOWN)
        {
            Down();

    }
        else if(head.direction==UP)
        {
            Up();

        }
        Finjeux();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;

    COORD b;

    fflush(stdout);

    b.X = x;

    b.Y = y;

    a = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(a,b);
 }

void Boarder()
{

   system("cls");

   int i;

   char random = rand ( ) % 10;

      GotoXY(food.x,food.y);

       printf("%c",random);

   for(i=1;i<78;i++)
   {
       GotoXY(i,4);

           printf("-");

           GotoXY(i,5);

           printf("-");

           GotoXY(i,25);

           printf("-");

           GotoXY(i,26);

           printf("-");
   }
   for(i=4;i<27;i++)
   {

       GotoXY(0,i);

       printf("|");

       GotoXY(1,i);

       printf("|");

       GotoXY(78,i);

       printf("|");

       GotoXY(79,i);

       printf("|");
   }
       GotoXY(3,28);

       printf("           /^\\/^\\");

       printf("\n");

       GotoXY(3,29);

       printf("          _|__|  O|");

       printf("\n");

       GotoXY(3,30);

       printf(" \\/     /~     \\_/ \\");

       printf("\n");

       GotoXY(3,31);

       printf("  \\____|__________/  \\");

       printf("\n");

       GotoXY(3,32);

       printf("         \\_______      \\");

       printf("\n");

       GotoXY(3,33);

       printf("                 `\\     \\                 \\");

       printf("\n");

       GotoXY(3,34);

       printf("                   |     |                  \\");

       printf("\n");

       GotoXY(3,35);

       printf("                  /      /                    \\");

       printf("\n");

       GotoXY(3,36);

       printf("                 /     /                       \\\\");

       printf("\n");

       GotoXY(3,37);

       printf("               /      /                         \\ \\");

       printf("\n");

       GotoXY(3,38);

       printf("              /     /                            \\  \\");

       printf("\n");

       GotoXY(3,39);

       printf("            /     /             _----_            \\   \\");

       printf("\n");

       GotoXY(3,40);

       printf("           /     /           _-~      ~-_         |   |");

       printf("\n");

       GotoXY(3,41);

       printf("          (      (        _-~    _--_    ~-_     _/   |");

       printf("\n");

       GotoXY(3,42);

       printf("           \\      ~-____-~    _-~    ~-_    ~-_-~    /");

       printf("\n");

       GotoXY(3,43);

       printf("             ~-_           _-~          ~-_       _-~   - Gaith bechir -");

       printf("\n");

       GotoXY(3,44);

       printf("                ~--______-~                ~-___-~");

       printf("\n");


}

void load(){
    int i,j;
    char t[]="." ;

    gotoxy(30,24);

    printf("loading Game snake");


    gotoxy(30,25);

    for(i=1;i<=20;i++){

    for(j=0;j<=20000000;j++);{}

    gotoxy(47,24);

    printf(".");

    for(j=0;j<=20000000;j++);{}

    gotoxy(47,24);

    printf(" ");


    gotoxy(48,24);

    printf(".");

    for(j=0;j<=20000000;j++);{}

    gotoxy(48,24);

    printf(" ");

    gotoxy(49,24);

    printf(".");

    for(j=0;j<=20000000;j++);{}

    gotoxy(49,24);

    printf(" ");


    gotoxy(29+i,25);


    printf("%c",177);

    }

    getch();

}

 int Score()
{
   int score,i;

   for(i=5;i<26;i++){

   GotoXY(i,1) ;

   printf("-") ;
}
   GotoXY(15,2);

   printf("%c",179);

   score=length-2;

   printf("Score : %d",score);

   printf("%c",179);

   GotoXY(5,2);

   printf("%c",179);

   printf("life : %d",life);

   for(i=5;i<26;i++){

   GotoXY(i,3) ;

   printf("-") ;

}

   return score;

}

void spide_game(int vite)
{

   Score();

    long double i;

    int sp=vite;

    int c;

if (sp==1) {

    c==10;

}else if (sp==2){

    c==100;

}else if(sp==3){

    c==1000;

}else if (sp==4){

    c==10000;
}else{

    c==100000;
}

    for(i=0;i<=(100*c);i++){};

}
void Finjeux()

{

    int x,y ;

    int i,check=0;

    for(i=4;i<length;i++)
    {

        if(body[0].x==body[i].x&&body[0].y==body[i].y)

        {

            check++;

        }

        if(i==length||check!=0)

            break;

    }

    if(head.x<=1||head.x>=78||head.y<=5||head.y>=25||check!=0)

    {

        life--;

        if(life>=0)

        {

            x=rand()%77;

        if(x<=5)

            x=x+5;

        y=rand()%20;// for not mort>| border

        if(y<=6)

            y=y+6;

            head.x=x;

            head.y=y;

            bend_no=0;

            head.direction=DOWN;

            Move();

        }

        else

        {

          char t[]="0 LIVES LEFT !" ;

          char t2[]="Push any botton to quit the game !";

            system("cls");

int l=5;

for (int i=0;i<15;i++){

            GotoXY(l,15);

            printf("%c",t[i]) ;

for(int j=0;j<=30000000;j++)

{

}

l++ ;

}

printf("\n");

l=5;

for (int i=0;i<35;i++){

            GotoXY(l,16);

            printf("%c",t2[i]) ;

for(int j=0;j<=30000000;j++)

{

}

l++ ;

}

printf("\n");

            exit(0);

        }

    }

}

void Food()

{

    if(food.x==0)

    {

        food.x=rand()%76;

        if(food.x<7)

            food.x+=8 ;

        food.y=rand()%23;

        if(food.y<7)

            food.y+=8;

    }

    else if(head.x==food.x&&head.y==food.y)

    {

        length++;

        food.x=rand()%77;

        if(food.x<4)

            food.x+=5;

        food.y=rand()%24;

        if(food.y<6)

            food.y+=6;

    }

}

void Up()

{

   int i;

   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)

   {

       GotoXY(head.x,head.y+i);

       {

           if(len==0)

               printf("^");

           else

               printf("+");

       }

       body[len].x=head.x;

       body[len].y=head.y+i;

       len++;

   }

   Bend();

   if(!kbhit())

       head.y--;

}

void Down()

{

    int i;

    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)

    {

        GotoXY(head.x,head.y-i);

        {

            if(len==0)

                printf("v");

            else

                printf("+");

        }

        body[len].x=head.x;

        body[len].y=head.y-i;

        len++;

    }

    Bend();

    if(!kbhit())

        head.y++;

}

void Left()

{

    int i;

    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)

    {

        GotoXY((head.x+i),head.y);

       {

                if(len==0)

                    printf("<");

                else

                    printf("+");

        }

        body[len].x=head.x+i;

        body[len].y=head.y;

        len++;

    }

    Bend();

    if(!kbhit())

        head.x--;

}

void Right()

{

    int i;

    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)

    {

        body[len].x=head.x-i;

        body[len].y=head.y;

        GotoXY(body[len].x,body[len].y);

        {

            if(len==0)

                printf(">");

            else

                printf("+");

        }

        len++;

    }

    Bend();

    if(!kbhit())

        head.x++;

}

void Bend()

{

    int i,j,diff;

    for(i=bend_no;i>=0&&len<length;i--)

    {

            if(bend[i].x==bend[i-1].x)

            {

                diff=bend[i].y-bend[i-1].y;

                if(diff<0)

                    for(j=1;j<=(-diff);j++)

                    {

                        body[len].x=bend[i].x;

                        body[len].y=bend[i].y+j;

                        GotoXY(body[len].x,body[len].y);

                        printf("+");

                        len++;

                        if(len==length)

                            break;

                    }

                else if(diff>0)

                    for(j=1;j<=diff;j++)

                    {

                        body[len].x=bend[i].x;

                        body[len].y=bend[i].y-j;

                        GotoXY(body[len].x,body[len].y);

                        printf("+");

                        len++;

                        if(len==length)

                            break;

                    }

            }

        else if(bend[i].y==bend[i-1].y)

        {

            diff=bend[i].x-bend[i-1].x;

            if(diff<0)

                for(j=1;j<=(-diff)&&len<length;j++)

                {

                    body[len].x=bend[i].x+j;

                    body[len].y=bend[i].y;

                    GotoXY(body[len].x,body[len].y);

                        printf("+");

                   len++;

                   if(len==length)

                           break;

               }

           else if(diff>0)

               for(j=1;j<=diff&&len<length;j++)

               {

                   body[len].x=bend[i].x-j;

                   body[len].y=bend[i].y;

                   GotoXY(body[len].x,body[len].y);

                       printf("+");

                   len++;

                   if(len==length)

                       break;

               }

       }

   }

}


void printbanner(){

    GotoXY(5,1);

    printf("        ___");

    printf("\n");

GotoXY(5,2);

    printf("      ,~._,`.");

    printf("\n");
GotoXY(5,3);

    printf("     (-.___.-)");

    printf("\n");
GotoXY(5,4);

    printf("     (-.___.-)");

    printf("\n");
GotoXY(5,5);

    printf("     `-.___.-~                  ");

    printf("\n");
GotoXY(5,6);

    printf("      ((  @ @|              .            __");

    printf("\n");
GotoXY(5,7);

    printf("       \\   ` |         ,\\   |`.    @|   |  |      _.-._");

    printf("\n");
GotoXY(5,8);

    printf("      __`.`=-=mm===mm:: |   | |`.   |   |  |    ,~=` ~=`.");

    printf("\n");
GotoXY(5,9);

    printf("     (    `-~|:/  /:/  `/  @| | |   |, @| @|   /---)W(---\\");

    printf("\n");
GotoXY(5,10);

    printf("      \\ \\   / /  / /         @| |   ~         (----| |----) ,~");

    printf("\n");
GotoXY(5,11);

    printf("      |\\ \\ / /| / /            @|              \\---| |---/  |");

    printf("\n");
GotoXY(5,12);

    printf("      | \\ V /||/ /                              `.-| |-,~   |");

    printf("\n");
GotoXY(5,13);

    printf("      |  `-~ |V /                                 \\| |/    @~");

    printf("\n");
GotoXY(5,14);

    printf("      |    , |-~                                 __| |__");

    printf("\n");
GotoXY(5,15);

    printf("      |    .;: _,-.                         ,--~~..| |..~~--.");

    printf("\n");
GotoXY(5,16);

    printf("      ;;:::~ ~    )                        (`--::__|_|__::--~)");

    printf("\n");
GotoXY(5,17);

    printf("    ,-~      _,  /                          \\`--...___...--~/   ");

    printf("\n");
GotoXY(5,18);

    printf("   (    -:--~/  /                           /`--...___...--~\\");

    printf("\n");
GotoXY(5,19);

    printf("    ~-._  `~~._/                           /`---...___...---~\\");

    printf("\n");
GotoXY(5,20);

    printf("        ~-._   ~---.                      (`---....___....---~)");

    printf("\n");

GotoXY(5,21);

    printf("         .~ ~,._ ,~ )                     |`---....___....---~|");

    printf("\n");

GotoXY(5,22);

    printf("         /`._|  `|  |                     (`---....___....---~) ");

    printf("\n");

GotoXY(5,23);

    printf("        (   \\    |  /                      \\`---...___...---~/");

    printf("\n");

GotoXY(5,24);

    printf("         `.  `,  ^~~                        `:--...___...--;~");

    printf("\n");

GotoXY(5,25);

    printf("           `.,~             Gaith_bechir      `-._______.-~");

    printf("\n");

    GotoXY(20,30);

char t[]="Press any key to play game...";

for (int i=0;i<30;i++){

            printf("%c",t[i]) ;

for(int j=0;j<=20000000;j++)

{

}

}



GotoXY(5,35);

    printf("  ______ ____ _____  |  | __ ____    /  _____/_____    _____   ____  ");

    printf("\n");

GotoXY(5,36);

    printf(" /  ___//    \\\\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\ ");

    printf("\n");

GotoXY(5,37);

    printf(" \\___ \\|   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ ");

    printf("\n");

GotoXY(5,38);

    printf("/____  >___|  (____  /__|_ \\\\___  >  \\______  (____  /__|_|  /\\___  >");

    printf("\n");

GotoXY(5,39);

    printf("     \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/ ");

    printf("\n");

}

int level(){

    int x ;

char t[]="Chose Difficulty please  [1..5]  >";

   GotoXY(15,25);

x=2;

do{

int l=15;

   system("cls");

for (int i=0;i<35;i++){

            GotoXY(l,25);

            printf("%c",t[i]) ;

for(int j=0;j<=30000000;j++)

{

}

l++ ;

}

   GotoXY(50,25);

   scanf("%i",&x);

}while (x > 5 );

   system("cls");

return x;

}
