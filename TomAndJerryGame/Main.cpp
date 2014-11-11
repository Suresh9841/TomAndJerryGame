#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<sstream>
#include<time.h>
#include<graphics.h>
#include<windows.h>
#include<MMSystem.h>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define SZ(a)  (int)a.size()
#define lookalike scanf("%*d")
#define all(a) (a).begin(),(a).end()
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

#define MAX 100
int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1};
int grid[MAX][MAX];

void make(int r,int c,int level);
void init();
void open_01(void);
void ran(int r,int c,int level);
void view(int r,int c,int level);
pair<int,int> make_a_move(int r1,int c1,int level);
int BFS(int r,int c,int level);
void fill_grid(int r,int c,int level);
int traverse(int r,int c,int level);
void open_02(void);
int random_p(int pre);

void make(int r,int c,int level)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(i==1 and j==1)
            {
                setfillstyle(9, 11);
                bar(j*42,i*42,j*42 + 30,i*42 +30);
            }
            else if(grid[i][j]==1)
            {
               setfillstyle(1,GREEN);
               bar(j*42,i*42,j*42 + 30,i*42 +30);
            }
            else if(grid[i][j]==0)
            {
                setfillstyle(9,RED);
                bar(j*42,i*42,j*42 + 30,i*42 +30);
            }
            else if(grid[i][j]==100)
            {
                setfillstyle(5, 11);
                bar(j*42,i*42,j*42 + 30,i*42 +30);
            }
            else if(grid[i][j]==-1)
            {
                setfillstyle(1, 4);
                bar(j*42,i*42,j*42 + 30,i*42 +30);
                continue;
            }
            else
            {
                grid[i][j]=100;
                make(r,c,level);
            }

            if(i==r and j==r)
            {
                setfillstyle(1,3);
                bar(j*42,i*42,j*42 + 30,i*42 +30);
            }
        }
    }
}

int main()
{
    initwindow(900,600,"Tom And Jery");
    open_01();
//    open_02();

    setbkcolor(GREEN);
    clearviewport();

    init();
    setviewport(1, 1, 580, 580, 1);

    bool id=1; int row=12;int cul=12; int level=1;
    int rannum=1;
    int rannum1=1;

    while(id)
    {
        setbkcolor(7);
        clearviewport();

        fill_grid(row,cul,level);
        ran(row,cul,level);
        view(row,cul,level);

        clearviewport();
        setcolor(WHITE);
        rectangle(0,0,580,580);

        make(row,cul,level);
        int res=traverse(row,cul,level);

        if(res)
        {
            sndPlaySound("sound_win_02.wav",SND_ASYNC);
            clearviewport();
            rannum1=random_p(rannum1);
            if(rannum1==1) readimagefile("win_01.bnp",0,0,580,580);
            else if(rannum1==2)readimagefile("win_02.bnp",0,0,580,580);
            else if(rannum1==3) readimagefile("win_03.bnp",0,0,580,580);
            else if(rannum1==4)readimagefile("win_04.bnp",0,0,580,580);
            else if(rannum1==5)readimagefile("win_05.bnp",0,0,580,580);
            else if(rannum1==6)readimagefile("win_06.bnp",0,0,580,580);
            else if(rannum1==7)readimagefile("win_07.bnp",0,0,580,580);
            else readimagefile("win_08.bnp",0,0,580,580);

            char a[200];
            setcolor(RED);
            sprintf(a,"Congratulation!! Your Level Uped.");
            outtextxy(80,250,a);
            level++;
            getch();
        }
        else
        {
            clearviewport();
            sndPlaySound("sound_loss_03.wav",SND_ASYNC);

            rannum=random_p(rannum);
            if(rannum==1) readimagefile("loss_01.bnp",0,0,580,580);
            else if(rannum==2)readimagefile("loss_02.bnp",0,0,580,580);
            else if(rannum==3) readimagefile("loss_03.bnp",0,0,580,580);
            else if(rannum==4)readimagefile("loss_04.bnp",0,0,580,580);
            else if(rannum==5)readimagefile("loss_05.bnp",0,0,580,580);
            else if(rannum==6)readimagefile("loss_06.bnp",0,0,580,580);
            else readimagefile("loss_08.bnp",0,0,580,580);

            setcolor(RED);
            char a[200];
            sprintf(a,"You Lose !! Try again to level up.");
            outtextxy(80,250,a);
            getch();
        }

        clearviewport();
        readimagefile("tm.bnp",0,0,580,580);
        setcolor(RED);
        char a[120];
        sprintf(a,"Your Current Level is: %d.",level);
        outtextxy(140,510,a);
        setcolor(2);
        outtextxy(75,540,"Press Any Key To Continu Or 'N' To Exit");
        char c=getch();
        if('n'==tolower(c))
        {
            clearviewport();
            sndPlaySound("goodbye.wav",SND_ASYNC);
            readimagefile("g_02.bnp",0,0,580,580);
            delay(4000);
            break;
        }
    }
    return 0;
}

void open_01(void)
{
    srand(time(0));
    sndPlaySound("TM1.wav",SND_ASYNC);

    clearviewport();
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(GREEN);
    setcolor(BLACK);
    clearviewport();

    int i,j;
    char s1[]="SUST ";
    char s2[]="CSE ";
    char s3[]="2010 ";

    char str3[]="Nakul Chandra Saha";
    char str4[]="Md.Afjal Hossain";
    char str1[]="Tom";
    char str2[]="&";
    char str33[]="Jerry";


    /// SUST CSE 2010
    outtextxy(100,100,s1);
    delay(600);
    setcolor(RED);
    delay(600);
    outtextxy(350,100,s2);
    setcolor(BLACK);
    delay(900);
    outtextxy(550,100,s3);

    /// Tom & jerry
    delay(800);
    setcolor(BLACK);
    outtextxy(300,200,str1);
    delay(700);
    setcolor(WHITE);
    outtextxy(360,250,str2);
    delay(900);
    setcolor(YELLOW);
    outtextxy(400,300,str33);
    delay(700);
    settextstyle(11,HORIZ_DIR,4);

    /// Created..
    setcolor(5);
    outtextxy(30,500,"Created by :__________________");
    setcolor(BLACK);
    outtextxy(75,525,str3); /// Nakul
    setcolor(WHITE);
    settextstyle(4,HORIZ_DIR,2);
    outtextxy(100,540,str2); /// &
    settextstyle(11,HORIZ_DIR,4);
    setcolor(YELLOW);
    outtextxy(40,560,str4); /// afjal
    setcolor(RED);

    delay(900);
    settextstyle(11,HORIZ_DIR,4);
    outtextxy(400,550,"Press any key to continue");

    getch();
    return;
}

void init()
{
    settextstyle(8,HORIZ_DIR,1);

    //For player icon
    setbkcolor(GREEN);
    setfillstyle(9,11);
    bar(600, 50, 630, 80);
    setcolor(YELLOW);
    rectangle(600,50,630,80);

    setcolor(WHITE);
    outtextxy(632,52,": Your start Position");
    setbkcolor(GREEN);

    //For wall icon
    setfillstyle(9, RED);
    bar(600,95,630,125);
    setcolor(RED);

//    setbkcolor(RED);
    rectangle(600, 95, 630, 125);
    setcolor(WHITE);
    outtextxy(632, 92, ": An Obstacle !!");

    // UP
    outtextxy(597, 170, "For");
    setcolor(RED);
    line(650, 170, 650, 185);
    line(650, 170, 644, 178);
    line(650, 170, 654, 178);
    setcolor(WHITE);
    outtextxy(680, 170, "Press 'W'");

//    //DOWN
    outtextxy(597, 200, "For");
    setcolor(RED);
    line(650, 200, 650, 215);
    line(650, 215, 644, 208);
    line(650, 215, 654, 208);
    setcolor(WHITE);
    outtextxy(680, 200, "Press 'S'");

//    //LEFT
    outtextxy(597, 230, "For");
    setcolor(RED);
    line(642, 240, 657, 240);
    line(642, 240, 650, 237);
    line(642, 240, 650, 243);
    setcolor(WHITE);
    outtextxy(680, 230, "Press 'A'");
//
//    //RIGHT
    outtextxy(597, 260, "For");
    setcolor(RED);
    line(640, 270, 655, 270);
    line(655, 270, 652, 264);
    line(655, 270, 652, 276);
    setcolor(WHITE);
    outtextxy(680, 260, "Press 'D'");

    /// End
    setfillstyle(1,3);
    bar(600, 300, 630,330);
    setcolor(YELLOW);
    rectangle(600, 300, 630,330);
    setcolor(WHITE);
    outtextxy(640,310,": Your End Position");
}

void view(int r,int c,int level)
{
    cout<<"The Gid is::"<<endl<<endl;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            printf("%5d",grid[i][j]);
        }
        puts("");
    }
    cout<<endl;
    return;
}


int test_cor(int x,int y,int r,int c)
{
    int col[MAX][MAX];mem(col,0);int dis[MAX][MAX];mem(dis,0);
    int i,j,k,u,v;queue<int>Q;
    Q.push(1);Q.push(1);
    col[1][1]=1;
    dis[1][1]=0;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        int v=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            int tu=u+rrr[i];
            int tv=v+ccc[i];
            if(tu>=1 and tu<=r and tv>=1 and tv<=c and !col[tu][tv] and grid[tu][tv])
            {
                Q.push(tu);
                Q.push(tv);
                col[tu][tv]=1;
                dis[tu][tv]=dis[u][v]+1;
            }
        }
    }
    return dis[r][c];
}


void ran(int r,int c,int level)
{
    srand(time(0));
    int up=r*3+(level*3);
    if(up>125) up=125;
    while(up)
    {
        int r1=rand()%r+1;
        int c1=rand()%c+1;
        grid[r1][c1]=0;
        int id=test_cor(r1,c1,r,c);
        if(id==0)grid[r1][c1]=1;
        else up--;
    }
}

void fill_grid(int r,int c,int level)
{
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            grid[i][j]=1;
        }
    }
    return;
}

int BFS(int r,int c,int level)
{
    int col[MAX][MAX];mem(col,0);int dis[MAX][MAX];mem(dis,0);
    int i,j,k,u,v;queue<int>Q;
    Q.push(1);Q.push(1);
    col[1][1]=1;
    dis[1][1]=0;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        int v=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            int tu=u+rrr[i];
            int tv=v+ccc[i];
            if(tu>=1 and tu<=r and tv>=1 and tv<=c and !col[tu][tv] and grid[tu][tv])
            {
                Q.push(tu);
                Q.push(tv);
                col[tu][tv]=1;
                dis[tu][tv]=dis[u][v]+1;
            }
        }
    }
    return dis[r][c];
}

pair<int,int> make_a_move(int r1,int c1,int level)
{
    char c;pair<int,int >p;string s;
    while(1)
    {
        c=getch();
        if('w'==tolower(c)) return mp(r1-1,c1);
        else if('s'==tolower(c)) return mp(r1+1,c1);
        else if('a'==tolower(c)) return mp(r1,c1-1);
        else if('d'==tolower(c)) return mp(r1,c1+1);
    }
}

void open_02(void)
{
    readimagefile("loss_01.bnp",0,0,900,600);
    setcolor(YELLOW);
    char a[]="Tom and jerry";
    setbkcolor(YELLOW);
    outtextxy(100,200,a);
    getch();
}

int random_p(int pre)
{
    srand(time(0));
    int p=-1;
    while(1)
    {
        p=rand()%9;
        if(p!=pre and p) return p;
    }
}

int traverse(int r,int c,int level)
{
    sndPlaySound("TM2.wav",SND_ASYNC);
    sndPlaySound("TM1.wav",SND_ASYNC);

    int shortest_path=BFS(r,c,level);
    int require_path=shortest_path+(11-level);
    if(require_path<shortest_path) require_path=shortest_path;
    char arr[200];
    char le[200];

    settextstyle(6,HORIZ_DIR,2);
    setcolor(RED);
    sprintf(le,"Level: %2d",level);
    outtextxy(2,2,le);
    sprintf(arr,"Remaning Move Is: %d",require_path);
    outtextxy(130,2,arr);

    int cposx=1;int cposy=1;
    grid[1][1]=100;

    while(!(cposx==r and cposy==c) and require_path!=0)
    {
        pair<int,int> p=make_a_move(cposx,cposy,level);
        int tu=p.fs;int tv=p.sc;
        if(tu>=1 and tu<=r and tv>=1 and tv<=c and grid[tu][tv])
        {
            if(tu==r and tv==c)
            {
                setfillstyle(1, 4);
                bar(tv*42,tu*42,tv*42 + 30,tu*42 +30);
                cposx=tu;cposy=tv;
                continue;
            }

            require_path--;
            bool fl=1;

            if(grid[tu][tv]==100)
            {
                setfillstyle(4,5);
                bar(tv*42,tu*42,tv*42 + 30,tu*42 +30);
                fl=0;
            }
            cposx=tu;cposy=tv;
            grid[tu][tv]=100;
            if(fl)make(r,c,level);

            sprintf(arr,"Remaining Move Is: %2d",require_path);
            sprintf(le,"Level: %2d",level);
            outtextxy(2,2,le);
            outtextxy(130,2,arr);
        }
        view(r,c,level);
    }
    if(require_path>=0 and cposx==r and cposy==c) return 1;
    else return 0;
}

