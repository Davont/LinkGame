#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Clock.h"
#include "Point.h"
#include <string>
#include "LinkGame.h"
#include "Map.h"
#include "Point.h"
#include "Tools.h"
#include "stdio.h"
#include<time.h>
#include<conio.h>
#include<windows.h>
#include "Clock.h"
#include"RanKing.h"
using namespace std;
class Controller
{
public:
    Controller() : key(1),ptime(0),Mtime(0),score(0),wide(0) {}
    void Start();
    int Select();

    void RankMune();
    void ShowRank(int rank_num);

    int Difficulty();
    int TimeMune();

    void RewritePtime();
    void RewriteMtime();

    void DrawGame(int bias=0);
    void DrawMap(int bias=0);
    int PlayGame();

    void UpdateScore(const int&);
    void RewriteScore();

    void Print(Point cursor,string s,int color=3);

    void UpdateTime(const double&);

    int PauseMenu();
    void Game();
    int GameOver();
    void Hinting(int xcur,int ycur,int bias,LinkGame *lin);
    void SetData(int tf,int df);
    void Aiqyan();
private:
    int key;
    double ptime;
    double Mtime;
    int score;
    int elenum;
    int wide;
    int rank_type;
};
#endif // CONTROLLER_H
