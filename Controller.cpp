#include "Controller.h"
void Controller::Start()//��ʼ����
{
    SetWindowSize(34+2, 44+2);//���ô��ڴ�С
    SetColor(2);//���ÿ�ʼ������ɫ
//    StartInterface *start = new StartInterface();//��̬����һ��StartInterface��start
//    start->Action();//��ʼ����
//    delete start;//�ͷ��ڴ�ռ�
    Map m;
    m.Surface();
    /*���ùر�λ�ã��������ʾ��ȴ�������������*/
    Print(Point(31,12),(string)"��������ۿ��˹����ϰ����ı���(����AI��)",2);
    Print(Point(32,12),(string)"Press any key to start... ",2);
    SetCursorPosition(33, 12);
    SetColor(0);
    system("pause");
    system("cls");
}
void Controller::Game()//��Ϸһ��ѭ��
{//��ʼ����

    Start();//�˳���Ϸ��δд
    Map *m=new Map(34,0);
    m->PrintInitmap();
    delete m;
    Sleep(1000);
    Aiqyan();
    while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
    {

        int sel=Select();
        if(sel==1)//�˵�����Ϸѡ��
        {
            int tflag,dflag;//ѡ�����Ϸģʽ����Ϸ�Ѷ�
            tflag=TimeMune();//0Ϊ��ʱ��
            dflag=Difficulty();//1Ϊ����
            while(true)
            {
                SetData(tflag,dflag);
                DrawGame();//������Ϸ����
                int tmp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
                if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
                {
                    system("cls");
                    continue;
                }
                else if (tmp == 2) //����ֵΪ2ʱ�������˵�
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
        /*��ʼ������ѡ��*/
    SetColor(2);
    SetCursorPosition(25, 35);
    std::cout << "�Ͻ�����" ;
    SetCursorPosition(26, 35);
    std::cout << "���¼�ѡ�� �س���ȷ��";
    SetCursorPosition(27, 37);
    std::cout<<"�⻹����ô?" ;

    SetCursorPosition(19, 36);
    SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
    std::cout << "Game Start" ;

    SetCursorPosition(21, 36);
    SetColor(3);
    std::cout << "Ranking" ;

    SetCursorPosition(23, 36);
    SetColor(3);
    std::cout << "Exit" ;

    score = 0;//�����ÿ�Ϊ��Ϸ��׼��
        /*���·����ѡ��ģ��*/
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while((ch=getch()))
    {
        switch(ch)//��������
        {
            case 72:////UP�Ϸ����
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

    return key;//��
}
int Controller::Difficulty()//1���� 2��ͨ 3��
{
    SetColor(3);
    SetCursorPosition(19, 36);
    cout<<"��ѡ���Ѷȣ�";

    SetBackColor();
    SetCursorPosition(21, 36);
    cout<<"����  ";

    SetColor(3);
    SetCursorPosition(23, 36);
    cout<<"��ͨ  ";

    SetColor(3);
    SetCursorPosition(25, 36);
    cout<<"��";
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while((ch=getch()))
    {
        switch(ch)//��������
        {
            case 72:////UP�Ϸ����
                if(key>1)
                {
                    if(key==2)
                    {
                        SetCursorPosition(21, 36);
                        SetBackColor();
                        std::cout<<"����  ";

                        SetCursorPosition(23, 36);
                        SetColor(3);
                        std::cout<<"��ͨ  ";

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"��  ";
                    }
                    else if(key==3)
                    {
                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout<<"����  ";

                        SetCursorPosition(23, 36);
                        SetBackColor();
                        std::cout<<"��ͨ  ";

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"��  ";
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
                        std::cout<<"����   ";

                        SetCursorPosition(23, 36);
                        SetBackColor();
                        std::cout << "��ͨ  " ;

                        SetCursorPosition(25, 36);
                        SetColor(3);
                        std::cout<<"��  ";
                    }
                    else if(key==2)
                    {
                        SetCursorPosition(21, 36);
                        SetColor(3);
                        std::cout<<"����  ";
                        SetColor(3);
                        SetCursorPosition(23, 36);
                        std::cout<<"��ͨ  ";

                        SetCursorPosition(25, 36);
                        SetBackColor();
                        std::cout<<"��  ";
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
int Controller::TimeMune()//0Ϊ��ʱ�� 1Ϊ��ʱ��
{
    SetColor(3);
    SetCursorPosition(19, 36);
    cout<<"��ѡ��ģʽ��";

    SetBackColor();
    SetCursorPosition(21, 36);
    cout<<"��ʱ��";

    SetColor(3);
    SetCursorPosition(23, 36);
    cout<<"��ʱ��";
    int ch;//��¼����ֵ
    int flag=0;
    int tchoice = 1;//��¼ѡ�����ʼѡ���һ��
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
                std::cout<<"��ʱ��";
                SetColor(3);
                SetCursorPosition(23, 36);
                std::cout<<"��ʱ��";
            }
            break;
        case 80:
            if(tchoice<2)
            {
                tchoice++;
                SetCursorPosition(21, 36);
                SetColor(3);
                std::cout<<"��ʱ��";
                SetColor(3);
                SetBackColor();
                SetCursorPosition(23, 36);
                std::cout<<"��ʱ��";
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
void Controller::DrawGame(int bias)//������Ϸ����
{
    system("cls");//����
    /*���Ƶ�ͼ*/
    SetColor(3);
    Map *init_map = new Map(wide+2,bias);
    init_map->PrintInitmap();
    delete init_map;

    /*���Ʋ����*/
    SetColor(3);
    SetCursorPosition(2, 37);
    std::cout << "Link Game" ;
    SetCursorPosition(3, 37);
    std::cout << "������" ;
    SetCursorPosition(6, 36);
    std::cout << "�Ѷȣ�" ;
    SetCursorPosition(6,39 );
    switch (key)
    {
    case 1:
        std::cout << "����" ;
        break;
    case 2:
        std::cout << "��ͨ" ;
        break;
    case 3:
        std::cout << "��" ;
        break;
    default:
        break;
    }
    Print(Point(7,36),"ʱ��:",3);
    if(Mtime)
    {
        Print(Point(8,36),"�÷֣�",3);
        SetCursorPosition(8,38);
        printf("%4d",score);
    }
    SetCursorPosition(14, 37);
    std::cout << " ������ƶ�" ;
    SetCursorPosition(15, 37);
    std::cout << " ESC����ͣ" ;
    SetCursorPosition(16, 37);
    std::cout << " r�������ͼ" ;
    SetCursorPosition(17, 37);
    std::cout << " g���˼�����ʾ" ;
    SetCursorPosition(18, 37);
    std::cout << " ���Դ����ָ�����" ;
}
void Controller::RankMune()
{
    system("cls");//����

    /*���Ƶ�ͼ*/
    SetColor(3);
    Map *init_map = new Map(34,0);
    init_map->PrintInitmap();
    delete init_map;
    SetColor(3);
    SetCursorPosition(2, 35);
    std::cout<<"��ʱ��:";
    SetCursorPosition(16, 35);
    std::cout<<"��ʱ��:";
    SetBackColor();
    SetCursorPosition(3, 39);
    std::cout<<"����";
    SetColor(3);
    SetCursorPosition(7, 39);
    std::cout<<"��ͨ";
    SetCursorPosition(11,39);
    std::cout<<"��";
    SetCursorPosition(17, 39);
    std::cout<<"����";
    SetCursorPosition(21, 39);
    std::cout<<"��ͨ";
    SetCursorPosition(25, 39);
    std::cout<<"��";
    SetCursorPosition(29, 39);
    std::cout<<"�˳�";
    key = 0;//��¼ѡ�����ʼѡ���һ��
    char ch;
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while((ch=getch()))
    {
        int xarr[]={3,7,11,17,21,25,29};
        string *sarr=new string[7];
        sarr[0]="����";
        sarr[1]="��ͨ";
        sarr[2]="��";
        sarr[3]="����";
        sarr[4]="��ͨ";
        sarr[5]="��";
        sarr[6]="�˳�";
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
    int pauseflag=0;//��ͣ��ʾ �����ж��ǽ�����Ϸ���� ������Ϸ
    double delenum=0;
    int gameflag=0;//������Ϊ����ֵ��ʾ��Ϸ�����¿�ʼ1 ���Ƿ������˵�2
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
    if(!Mtime)//����ʱ�亯��
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
        case 75://��
            if(ycur>2)
            {
                ycur--;
                SetCursorPosition(xcur,ycur);
           }
           break;
         case 77://��
            if(ycur<wide+1)
            {
                ycur++;
                SetCursorPosition(xcur,ycur);
           }
           break;
         case 13:
            if(changed==0)
            {
                int xtemp=xcur-1,ytemp=ycur-1,ctemp;//�˴���xyֵΪ1����ϵ�µ�
                if(!lin->GetEle(xtemp,ytemp,&ctemp))
                {
                    p1.ChangePosition(xtemp+1,ytemp+1);//��ԭΪ2����ϵ�µ�
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
                    int xtemp=xcur-1,ytemp=ycur-1,ctemp;//Ϊ1ֵ����ϵ�µ�
                    if(!lin->GetEle(xtemp,ytemp,&ctemp))
                    {
                        p2.ChangePosition(xtemp+1,ytemp+1);//2ֵ����ϵ�µ�
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
                            std::cout<<"�и�ɵ�ӻ��ܵ��";
                            SetCursorPosition(33,35);
                            std::cout<<"�����Ƿ���";
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
            pauseflag=PauseMenu();//��Pause����3ʱ�������˵� 2ʱ���¿�ʼ 1ʱ�������Ϸ
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
        if(delenum==elenum||ptime<=0)//��ɾ�������ɲ���������ͬ����Ϸ������
        {
            system("cls");//����
            SetColor(3);
            SetCursorPosition(34,42);
            std::cout<<delenum<<"="<<elenum<<"  "<<ptime;
            gameflag=GameOver();//��GameOver�д����������
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
int Controller::PauseMenu()//1Ϊ������Ϸ ��ͣ�˵�//2Ϊ���¿�ʼ //3Ϊ�������˵�
{
    /*���Ʋ˵�*/
    SetColor(11);
    SetCursorPosition(19,37);
    std::cout << "�˵���" ;
    Sleep(100);
    SetCursorPosition(21, 38);
    SetBackColor();
    std::cout << "������Ϸ" ;
    Sleep(100);
    SetCursorPosition(23, 38);
    SetColor(11);
    std::cout << "���¿�ʼ" ;
    Sleep(100);
    SetCursorPosition(25,38);
    std::cout << "�������˵�" ;
    SetCursorPosition(0, 0);

    /*ѡ�񲿷�*/
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
                    std::cout << "������Ϸ" ;
                    SetCursorPosition(23, 38);
                    SetColor(11);
                    std::cout << "���¿�ʼ" ;

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(23, 38);
                    SetBackColor();
                    std::cout << "���¿�ʼ" ;
                    SetCursorPosition(25, 38);
                    SetColor(11);
                    std::cout << "�������˵�" ;

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
                    std::cout << "���¿�ʼ" ;
                    SetCursorPosition(21, 38);
                    SetColor(11);
                    std::cout << "������Ϸ" ;

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(25, 38);
                    SetBackColor();
                    std::cout << "�������˵�" ;
                    SetCursorPosition(23, 38);
                    SetColor(11);
                    std::cout << "���¿�ʼ" ;

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

    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
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
        cout<<"�˼�û����´ΰ�";
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
        cout<<"|���ã�����񣻿������������ |\n";//16
        SetCursorPosition(17,12);
        cout<<"|    ������                   |\n";//17
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
        cout<<"�Ѵ��� ��ȥ�鿴";
        SetCursorPosition(34,12);
        system("Pause");
        system("cls");
        return 2;
    }
}

void Controller::SetData(int tf,int df)
{
    score=0;
    if(tf==0)//��ʱ��
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
