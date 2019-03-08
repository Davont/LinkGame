#include "Controller.h"
void Controller::Start()//开始界面
{
    SetWindowSize(34+2, 44+2);//设置窗口大小
    SetColor(2);//设置开始动画颜色
//    StartInterface *start = new StartInterface();//动态分配一个StartInterface类start
//    start->Action();//开始动画
//    delete start;//释放内存空间
    Map m;
    m.Surface();
    /*设置关标位置，并输出提示语，等待任意键输入结束*/
    Print(Point(31,12),(string)"接下来请观看人工智障爱酱的表演(就是AI啦)",2);
    Print(Point(32,12),(string)"Press any key to start... ",2);
    SetCursorPosition(33, 12);
    SetColor(0);
    system("pause");
    system("cls");
}
void Controller::Game()//游戏一级循环
{//开始界面

    Start();//退出游戏还未写
    Map *m=new Map(34,0);
    m->PrintInitmap();
    delete m;
    Sleep(1000);
    Aiqyan();
    while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
    {

        int sel=Select();
        if(sel==1)//菜单的游戏选项
        {
            int tflag,dflag;//选择的游戏模式和游戏难度
            tflag=TimeMune();//0为无时限
            dflag=Difficulty();//1为困难
            while(true)
            {
                SetData(tflag,dflag);
                DrawGame();//绘制游戏界面
                int tmp = PlayGame();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
                if (tmp == 1) //返回值为1时重新开始游戏
                {
                    system("cls");
                    continue;
                }
                else if (tmp == 2) //返回值为2时返回主菜单
                {
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        else if(sel==2)
        {
            RankMune();
        }
        else if(sel==3)
        {
            system("cls");
            SetCursorPosition(33, 12);
            return ;
        }
    }
}
int Controller::Select()
{
        /*初始化界面选项*/
    SetColor(2);
    SetCursorPosition(25, 35);
    std::cout << "赶紧操作" ;
    SetCursorPosition(26, 35);
    std::cout << "上下键选择 回车键确认";
    SetCursorPosition(27, 37);
    std::cout<<"这还不会么?" ;

    SetCursorPosition(19, 36);
    SetBackColor();//第一个选项设置背景色以表示当前选中
    std::cout << "Game Start" ;

    SetCursorPosition(21, 36);
    SetColor(3);
    std::cout << "Ranking" ;

    SetCursorPosition(23, 36);
    SetColor(3);
    std::cout << "Exit" ;

    score = 0;//分数置空为游戏做准备
        /*上下方向键选择模块*/
    int ch;//记录键入值
    key = 1;//记录选中项，初始选择第一个
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while((ch=getch()))
    {
        switch(ch)//检测输入键
        {
            case 72:////UP上方向键
                if(key>1)
                {
                    if(key==2)
                    {
                        SetCursorPosition(19, 36);
                        SetBackColor();
                        std::cout << "Game Start" ;

                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout << "Ranking" ;

                        SetCursorPosition(23, 36);
                        SetColor(3);
                        std::cout << "Exit" ;
                    }
                    else if(key==3)
                    {
                        SetCursorPosition(19, 36);
                        SetColor(3);
                        std::cout << "Game Start" ;

                        SetCursorPosition(21, 36);
                        SetBackColor();
                        std::cout << "Ranking" ;

                        SetCursorPosition(23, 36);
                        SetColor(3);
                        std::cout << "Exit" ;
                    }
                    key--;
                }
                break;
            case 80://Down
                if(key<3)
                {
                    if(key==1)
                    {
                        SetCursorPosition(19, 36);
                        SetColor(3);
                        std::cout << "Game Start" ;

                        SetCursorPosition(21, 36);
                        SetBackColor();
                        std::cout << "Ranking" ;

                        SetCursorPosition(23, 36);
                        SetColor(3);
                        std::cout << "Exit" ;
                    }
                    else if(key==2)
                    {
                        SetCursorPosition(19, 36);
                        SetColor(3);
                        std::cout << "Game Start" ;
                        SetColor(3);
                        SetCursorPosition(21, 36);
                        std::cout << "Ranking" ;

                        SetCursorPosition(23, 36);
                        SetBackColor();
                        std::cout << "Exit" ;
                        SetColor(3);
                    }
                    key++;
                }
                break;
            case 13:
                flag=true;
                break;
            default:
                break;
        }
        if(flag)
        {
            SetCursorPosition(0, 31);
            break;
        }
    }
    SetCursorPosition(23, 36);
    std::cout << "             " ;
    SetCursorPosition(21, 36);
    std::cout << "              " ;
    SetCursorPosition(19, 36);
    std::cout << "             " ;
    SetCursorPosition(25, 35);
    std::cout << "            " ;
    SetCursorPosition(26, 35);
    std::cout << "                    " ;
    SetCursorPosition(27, 35);
    std::cout << "                " ;
    SetCursorPosition(0, 31);

    return key;//留
}
int Controller::Difficulty()//1困难 2普通 3简单
{
    SetColor(3);
    SetCursorPosition(19, 36);
    cout<<"请选择难度：";

    SetBackColor();
    SetCursorPosition(21, 36);
    cout<<"困难  ";

    SetColor(3);
    SetCursorPosition(23, 36);
    cout<<"普通  ";

    SetColor(3);
    SetCursorPosition(25, 36);
    cout<<"简单";
    int ch;//记录键入值
    key = 1;//记录选中项，初始选择第一个
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while((ch=getch()))
    {
        switch(ch)//检测输入键
        {
            case 72:////UP上方向键
                if(key>1)
                {
                    if(key==2)
                    {
                        SetCursorPosition(21, 36);
                        SetBackColor();
                        std::cout<<"困难  ";

                        SetCursorPosition(23, 36);
                        SetColor(3);
                        std::cout<<"普通  ";

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"简单  ";
                    }
                    else if(key==3)
                    {
                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout<<"困难  ";

                        SetCursorPosition(23, 36);
                        SetBackColor();
                        std::cout<<"普通  ";

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"简单  ";
                    }

                    key--;
                }
                break;
            case 80://Down
                if(key<3)
                {
                    if(key==1)
                    {
                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout<<"困难   ";

                        SetCursorPosition(23, 36);
                        SetBackColor();
                        std::cout << "普通  " ;

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"简单  ";
                    }
                    else if(key==2)
                    {
                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout<<"困难  ";
                        SetColor(3);
                        SetCursorPosition(23, 36);
                        std::cout<<"普通  ";

                        SetCursorPosition(25, 36);
                        SetBackColor();
                        std::cout<<"简单  ";
                        SetColor(3);
                    }
                    key++;
                }
                break;
            case 13:
                flag=true;
                break;
            default:
                break;
        }
        if(flag)
            break;
    }
    return key;
}
int Controller::TimeMune()//0为无时限 1为有时限
{
    SetColor(3);
    SetCursorPosition(19, 36);
    cout<<"请选择模式：";

    SetBackColor();
    SetCursorPosition(21, 36);
    cout<<"无时限";

    SetColor(3);
    SetCursorPosition(23, 36);
    cout<<"有时限";
    int ch;//记录键入值
    int flag=0;
    int tchoice = 1;//记录选中项，初始选择第一个
    while((ch=getch()))
    {
        switch(ch)
        {
        case 72:
            if(tchoice>1)
            {
                tchoice--;
                SetCursorPosition(21, 36);
                SetBackColor();
                std::cout<<"无时限";
                SetColor(3);
                SetCursorPosition(23, 36);
                std::cout<<"有时限";
            }
            break;
        case 80:
            if(tchoice<2)
            {
                tchoice++;
                SetCursorPosition(21, 36);
                SetColor(3);
                std::cout<<"无时限";
                SetColor(3);
                SetBackColor();
                SetCursorPosition(23, 36);
                std::cout<<"有时限";
            }
            break;
        case 13:
            flag=1;
            break;
        default:
            break;
        }
        if(flag)
            break;
    }
    Print(Point(21,36),"      ",0);
    Print(Point(23,36),"      ",0);
    return tchoice-1;
}
void Controller::DrawGame(int bias)//绘制游戏界面
{
    system("cls");//清屏
    /*绘制地图*/
    SetColor(3);
    Map *init_map = new Map(wide+2,bias);
    init_map->PrintInitmap();
    delete init_map;

    /*绘制侧边栏*/
    SetColor(3);
    SetCursorPosition(2, 37);
    std::cout << "Link Game" ;
    SetCursorPosition(3, 37);
    std::cout << "连连看" ;
    SetCursorPosition(6, 36);
    std::cout << "难度：" ;
    SetCursorPosition(6,39 );
    switch (key)
    {
    case 1:
        std::cout << "困难" ;
        break;
    case 2:
        std::cout << "普通" ;
        break;
    case 3:
        std::cout << "简单" ;
        break;
    default:
        break;
    }
    Print(Point(7,36),"时间:",3);
    if(Mtime)
    {
        Print(Point(8,36),"得分：",3);
        SetCursorPosition(8,38);
        printf("%4d",score);
    }
    SetCursorPosition(14, 37);
    std::cout << " 方向键移动" ;
    SetCursorPosition(15, 37);
    std::cout << " ESC键暂停" ;
    SetCursorPosition(16, 37);
    std::cout << " r键重随地图" ;
    SetCursorPosition(17, 37);
    std::cout << " g键菜鸡用提示" ;
    SetCursorPosition(18, 37);
    std::cout << " （自带新手福利）" ;
}
void Controller::RankMune()
{
    system("cls");//清屏

    /*绘制地图*/
    SetColor(3);
    Map *init_map = new Map(34,0);
    init_map->PrintInitmap();
    delete init_map;
    SetColor(3);
    SetCursorPosition(2, 35);
    std::cout<<"无时限:";
    SetCursorPosition(16, 35);
    std::cout<<"有时限:";
    SetBackColor();
    SetCursorPosition(3, 39);
    std::cout<<"困难";
    SetColor(3);
    SetCursorPosition(7, 39);
    std::cout<<"普通";
    SetCursorPosition(11,39);
    std::cout<<"简单";
    SetCursorPosition(17, 39);
    std::cout<<"困难";
    SetCursorPosition(21, 39);
    std::cout<<"普通";
    SetCursorPosition(25, 39);
    std::cout<<"简单";
    SetCursorPosition(29, 39);
    std::cout<<"退出";
    key = 0;//记录选中项，初始选择第一个
    char ch;
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while((ch=getch()))
    {
        int xarr[]={3,7,11,17,21,25,29};
        string *sarr=new string[7];
        sarr[0]="困难";
        sarr[1]="普通";
        sarr[2]="简单";
        sarr[3]="困难";
        sarr[4]="普通";
        sarr[5]="简单";
        sarr[6]="退出";
        switch(ch)
        {
            case 72:
                    if(key>0)
                    {
                        SetColor(3);
                        for(int i=0;i<7;i++)
                        {
                            if(i==key-1)
                                Print(Point(xarr[i],39),sarr[i],0);
                            else
                                Print(Point(xarr[i],39),sarr[i],3);
                        }
                        key--;
                        break;
                    }
                    break;
            case 80:
                    if(key<6)
                    {
                        SetColor(3);
                        for(int i=0;i<7;i++)
                        {
                            if(i==key+1) SetBackColor();
                            SetCursorPosition(xarr[i], 39);
                            std::cout<<sarr[i];
                            SetColor(3);
                        }
                        key++;
                        break;
                    }
                    break;
            case 13:
            for(int i=0;i<6;i++)
            Print(Point(5*i+6, 5),"                               ",3);
                if(key==6)
                {
                    flag=true;
                }
                else
                {

                    ShowRank(key);
                }
                break;
            default:
                break;
        }
        delete []sarr;
        if(flag==true&&key==6)
        {
            Print(Point(2, 35),"             ",3);
            Print(Point(16, 35),"             ",3);
            for(int i=0;i<7;i++)
                Print(Point(xarr[i],39),"             ",3);
            break;
        }
    }
}
void Controller::Print(Point cursor,string s,int color)
{
    SetCursorPosition(cursor.GetX(),cursor.GetY());
    if(color==0)
        SetBackColor();
    else
        SetColor(color);

    std::cout<<s;
    SetColor(2);
}
void Controller::UpdateScore(const int& ns)
{
    score+=ns;
}
int Controller::PlayGame()
{
    int pauseflag=0;//暂停标示 用于判断是结束游戏还是 继续游戏
    double delenum=0;
    int gameflag=0;//用来作为返回值标示游戏是重新开始1 还是返回主菜单2
    LinkGame *lin=new LinkGame(wide,wide,elenum,15);
    Map *m=new Map(lin,0);
    m->PrintInitmap(0);
    delete m;
    double tdelete;
    char ch=0;
    int changed=0;
    Point p1,p2;
    int xcur=2,ycur=2;
    Clocker *timer;
    if(!Mtime)//创建时间函数
    {
        timer= new Counter;
    }
    else
    {
        timer=new CounterDown(Mtime);
    }
    while(true)
    {
        SetCursorPosition(xcur,ycur);
        while(!kbhit())
        {
            Sleep(100);
            SetColor(2);
            ptime=timer->Getnow();
            if(!ch) tdelete=ptime;
            CursurOff();
            SetCursorPosition(7,39);
            printf("%4.2lf",ptime);//
            CursurOn();
            SetCursorPosition(xcur,ycur);
        }
        ch=getch();
//        SetCursorPosition(34,42);
//        std::cout<<"("<<xcur<<","<<ycur<<") ";
//        SetCursorPosition(xcur,ycur);
        switch(ch)
        {
        case 'g':
            {
            Hinting(xcur,ycur,2,lin);
            }
            break;
        case 72:
           if(xcur>2)
           {
                xcur--;
                SetCursorPosition(xcur,ycur);
           }
           break;
        case 80:
            if(xcur<wide+1)
            {
                xcur++;
                SetCursorPosition(xcur,ycur);
           }
            break;
        case 75://左
            if(ycur>2)
            {
                ycur--;
                SetCursorPosition(xcur,ycur);
           }
           break;
         case 77://右
            if(ycur<wide+1)
            {
                ycur++;
                SetCursorPosition(xcur,ycur);
           }
           break;
         case 13:
            if(changed==0)
            {
                int xtemp=xcur-1,ytemp=ycur-1,ctemp;//此处的xy值为1坐标系下的
                if(!lin->GetEle(xtemp,ytemp,&ctemp))
                {
                    p1.ChangePosition(xtemp+1,ytemp+1);//还原为2坐标系下的
                    p1.ChangeColor(ctemp);
                    changed++;
                    SetColor(p1.GetC());
                    p1.PrintCircular();
                    SetCursorPosition(xcur,ycur);
                }
                else break;
            }
            else if(changed==1)
            {
                if(xcur==p1.GetX()&&ycur==p1.GetY())
                {
                    SetColor(p1.GetC());
                    p1.Print();
                    SetCursorPosition(xcur,ycur);
                    changed--;
                }
                else
                {
                    int xtemp=xcur-1,ytemp=ycur-1,ctemp;//为1值坐标系下的
                    if(!lin->GetEle(xtemp,ytemp,&ctemp))
                    {
                        p2.ChangePosition(xtemp+1,ytemp+1);//2值坐标系下的
                        p2.ChangeColor(ctemp);
                        changed++;

                        SetColor(p2.GetC());
                        p2.PrintCircular();
                        SetCursorPosition(xcur,ycur);
                        if(!lin->Judge(p1.GetX()-1,p1.GetY()-1,p2.GetX()-1,p2.GetY()-1))
                        {
                            if(lin->Delete( p1.GetX()-1,p1.GetY()-1,p2.GetX()-1,p2.GetY()-1 ))
                            {
                                SetColor(3);
                                SetCursorPosition(10,38);
                                std::cout<<"ERROR";
                                system("pause");
                            }
                            else
                            {
                                delenum++;
                                changed=0;
                                score++;
                                p1.Print(0);
                                p2.Print(0);
                                tdelete=timer->Getnow();
                                if(Mtime)
                                {
                                    SetColor(3);
                                    SetCursorPosition(8,38);
                                    printf("%4d",score);
                                }
                                SetCursorPosition(xcur,ycur);
                            }
                        }
                        else
                        {
                            changed=0;
                            SetColor(2);
                            SetCursorPosition(32,35);
                            std::cout<<"有个傻子还能点错";
                            SetCursorPosition(33,35);
                            std::cout<<"我真是服气";
                            Sleep(1000);
                            SetColor(3);
                            SetCursorPosition(32,35);
                            std::cout<<"                  ";
                            SetCursorPosition(33,35);
                            std::cout<<"                  ";
                            SetColor(p1.GetC());
                            p1.Print();
                            SetColor(p2.GetC());
                            p2.Print();
                            SetCursorPosition(xcur,ycur);
                        }
                    }
                    else
                        break;
                }
            }
            break;
         case 27:
            pauseflag=PauseMenu();//当Pause返回3时返回主菜单 2时重新开始 1时则继续游戏
            if(pauseflag==3)
            {
                system("cls");
                Map *k=new Map(34,0);
                k->PrintInitmap();
                delete k;
                gameflag=2;
            }
            else if(pauseflag==2)
            {
                system("cls");
                gameflag=1;
            }
            else if(pauseflag==1)
            {
                ;
            }
            break;
         case 'r':
            {
                do{
                lin->ReStar();
                }while(!lin->Judge_If_Restar());
                Map*m=new Map(lin,0);
                m->PrintInitmap();
                delete m;
            }
            break;
         default:
            break;
        }
        if(delenum==elenum||ptime<=0)//若删除个数可产生个数相同则游戏结束；
        {
            system("cls");//清屏
            SetColor(3);
            SetCursorPosition(34,42);
            std::cout<<delenum<<"="<<elenum<<"  "<<ptime;
            gameflag=GameOver();//在GameOver中处理进不进榜
        }
        if(gameflag)
        {
            break;
        }
        if(!lin->Judge_If_Restar())
        {
            lin->ReStar();
            Map*m=new Map(lin,0);
            m->PrintInitmap();
            delete m;
        }

        //SetCursorPosition(34,35);
       // std::cout<<"("<<ptime<<"\t,"<<tdelete<<"\t) ";
        //SetCursorPosition(xcur,ycur);
        if(Mtime&&tdelete-ptime>10&&ptime>0)
        {
            tdelete=timer->Getnow();
            Hinting(xcur,ycur,2,lin);
        }
        else if(Mtime==0&&ptime-tdelete>10)
        {
            tdelete=timer->Getnow();
            Hinting(xcur,ycur,2,lin);
        }
    }
    if(timer)
    {
//        delete timer;
    }
    return gameflag;
}
int Controller::PauseMenu()//1为继续游戏 暂停菜单//2为重新开始 //3为返回主菜单
{
    /*绘制菜单*/
    SetColor(11);
    SetCursorPosition(19,37);
    std::cout << "菜单：" ;
    Sleep(100);
    SetCursorPosition(21, 38);
    SetBackColor();
    std::cout << "继续游戏" ;
    Sleep(100);
    SetCursorPosition(23, 38);
    SetColor(11);
    std::cout << "重新开始" ;
    Sleep(100);
    SetCursorPosition(25,38);
    std::cout << "返回主菜单" ;
    SetCursorPosition(0, 0);

    /*选择部分*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(21, 38);
                    SetBackColor();
                    std::cout << "继续游戏" ;
                    SetCursorPosition(23, 38);
                    SetColor(11);
                    std::cout << "重新开始" ;

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(23, 38);
                    SetBackColor();
                    std::cout << "重新开始" ;
                    SetCursorPosition(25, 38);
                    SetColor(11);
                    std::cout << "返回主菜单" ;

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(23, 38);
                    SetBackColor();
                    std::cout << "重新开始" ;
                    SetCursorPosition(21, 38);
                    SetColor(11);
                    std::cout << "继续游戏" ;

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(25, 38);
                    SetBackColor();
                    std::cout << "返回主菜单" ;
                    SetCursorPosition(23, 38);
                    SetColor(11);
                    std::cout << "重新开始" ;

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }

    if (tmp_key == 1) //选择继续游戏，则将菜单擦除
    {
        SetCursorPosition(32, 19);
        std::cout << "         " ;
        SetCursorPosition(34, 21);
        std::cout << "          ";
        SetCursorPosition(34, 23);
        std::cout << "         ";
        SetCursorPosition(34, 25);
        std::cout << "          ";
    }
    return tmp_key;
}
int Controller::GameOver(){

    Ranking ran(rank_type);
    Player pla;
    pla.name="unnamed";
    pla.score=score;
    if(Mtime==0)
    {
        pla.time=ptime;
    }
    else{
        pla.time=Mtime-ptime;
    }
    int num=ran.Judge(pla);
    if(num>=5)
    {
        SetColor(2);
        SetCursorPosition(15,12);
        cout<<"菜鸡没入榜，下次吧";
        SetCursorPosition(34,12);
        system("Pause");
        system("cls");
        return 2;
    }
    else{
        SetColor(2);
        SetCursorPosition(15,12);
        cout<<"|-----------------------------|\n";//15
        SetCursorPosition(16,12);
        cout<<"|您好，已入榜；快输入你的名字 |\n";//16
        SetCursorPosition(17,12);
        cout<<"|    姓名：                   |\n";//17
        SetCursorPosition(18,12);
        cout<<"|                             |\n";
        SetCursorPosition(19,12);
        cout<<"|-----------------------------|\n";
        SetColor(3);
        CursurOn();
        SetCursorPosition(17,12+8);
        string na;
        cin>>na;
        pla.name=na;
        pla.number=num+1;
        ran.Add(pla,num);
        SetCursorPosition(18,12);
        cout<<"已存入 快去查看";
        SetCursorPosition(34,12);
        system("Pause");
        system("cls");
        return 2;
    }
}

void Controller::SetData(int tf,int df)
{
    score=0;
    if(tf==0)//无时限
    {
        Mtime=0;
        ptime=999;
        switch(df)
        {
        case 1:
            rank_type=0;//
            elenum=512;
            wide=32;
            break;
        case 2:
            rank_type=1;
            elenum=72;
            wide=12;
            break;
        case 3:
            rank_type=2;
            elenum=18;
            wide=6;
            break;

        }
    }
    else
    {
        ptime=-1;
        switch(df)
        {
        case 1:
            rank_type=3;
            Mtime=2000;
            elenum=512;
            wide=32;
            break;
        case 2:
            rank_type=4;
            Mtime=120;
            elenum=72;
            wide=12;
            break;
        case 3:
            rank_type=5;
            Mtime=60;
            elenum=18;
            wide=6;
            break;
        }
    }
}
void Controller::ShowRank(int rank_num)
{
    Ranking ran(rank_num);
    Player *arr;
    int num=0;
    arr=ran.GetAll(num);
    SetColor(3);
    for(int i=0;i<num;i++)
    {
        SetCursorPosition(5*i+6, 5);
        SetColor(3);
        cout<<"No."<<arr[i].number<<'\t'<<arr[i].name<<'\t'<<arr[i].score<<'\t'<<arr[i].time;
    }
    SetCursorPosition(34, 10);
}
void Controller::Hinting(int xcur,int ycur,int bias,LinkGame *lin)
{
    Point p1,p2;
    lin->Supporter(p1,p2);
    p1.ChangeBias(bias);
    p2.ChangeBias(bias);
    p1.PrintCircular();
    p2.PrintCircular();
    SetCursorPosition(xcur,ycur);
    Sleep(200);
    p1.Clear();
    p2.Clear();
    SetCursorPosition(xcur,ycur);
    Sleep(200);
    p1.PrintCircular();
    p2.PrintCircular();
    SetCursorPosition(xcur,ycur);
    Sleep(200);
    p1.Clear();
    p2.Clear();
    SetCursorPosition(xcur,ycur);
    Sleep(200);
    p1.Print();
    p2.Print();
    SetCursorPosition(xcur,ycur);
}
void Controller::Aiqyan()
{
    double elenum=512;
    int wide=32;
    LinkGame *lin=new LinkGame(wide,wide,elenum,20);
    Map *m=new Map(lin,0);
    m->PrintInitmap(0);
    Point p1,p2;
    while(elenum--)
    {
        if(!lin->Supporter(p1,p2))
        {
            lin->Delete( p1.GetX()+1,p1.GetY()+1,p2.GetX()+1,p2.GetY()+1);
            p1.ChangeBias(2);
            p2.ChangeBias(2);
            p1.Clear();
            Sleep(10);
            p2.Clear();
        }
        if(!lin->Judge_If_Restar())
        {
            lin->ReStar();
            Map*m=new Map(lin,0);
            m->PrintInitmap();
            delete m;
        }
    }
}
