#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct date                 //��ӳ
{
    int day;                        //��
    int month;                      //��
    int year;                       //��
    int openhour;                   //����ʱ
    int openmin;                    //������
    int closehour;                  //��Ļʱ
    int closemin;                   //��Ļ��
    int hallnum;                    //Ӱ��
    struct date *next;
}date;

typedef struct film                 //��Ӱ
{
    char filmname[22];              //Ƭ��
    double score;                   //����
    double length;                  //Ƭ��
    double fare;                    //Ʊ��
    struct date *premiere;          //��ӳ
    struct film *next;
}film;

typedef struct order
{
    int ordernum;                   //������
    int shit[2];                    //��λ
    char filmname[22];              //Ƭ��
    double score;                   //����
    double length;                  //Ƭ��
    double fare;                    //Ʊ��
    int day;                        //��
    int month;                      //��
    int year;                       //��
    int openhour;                   //����ʱ
    int openmin;                    //������
    int closehour;                  //��Ļʱ
    int closemin;                   //��Ļ��
    int hallnum;                    //Ӱ��
    struct order *next;
}order;

typedef struct user                 //�û�
{
    char id[15];                    //�˺�
    char password[15];              //����
    struct user *next;
    int power;                      //Ȩ��
}user;

#define FILMF "%s %lf %lf %lf\n"
#define TIMEF "%d %d %d %d %d %d %d %d\n"
#define ORDER "%d %d %d\n%s %lf %lf %lf\n%d %d %d %d %d %d %d\n"

int n=0,m=0,o=0;                    //��Ӱ�û���������
typedef  int (*ss)[14];             //��λ�ļ���������
int s[6][14];                       //��λ����
char ch;
int line;
int choose;

#include "view/position.h"               //��������
#include "view/cursor.h"
#include "user/newfile.h"
#include "film/filmsave.h"               //����ӰƬ��Ϣ
#include "film/filmread.h"               //��ȡӰƬ��Ϣ
#include "seat/seatsave.h"               //������λ��Ϣ
#include "seat/seatread.h"               //��ȡ��λ��Ϣ
#include "user/usersave.h"               //�����û���Ϣ
#include "user/userread.h"               //��ȡ�û���Ϣ
#include "order/ordersave.h"             //���涩����Ϣ
#include "order/orderread.h"             //��ȡ������Ϣ
#include "hall/hallread.h"               //��ȡӰ����Ϣ
#include "user/login.h"                  //��¼
#include "user/register.h"               //ע��
#include "user/forget.h"                 //��������
#include "user/setup.h"                  //��¼ϵͳ
#include "view/mainmenu.h"               //���˵�
#include "view/filmmenu.h"               //ӰƬ����˵�
#include "view/hallmenu.h"               //Ӱ������˵�
#include "view/ordermenu.h"              //��������˵�
#include "view/usermenu.h"               //�û�����˵�
#include "view/hallview.h"
#include "film/filmenter.h"              //¼��ӰƬ
#include "film/filmbrowse.h"             //���ӰƬ
#include "film/filmquery.h"              //����ӰƬ
#include "film/filmmodify.h"             //�޸�ӰƬ
#include "film/filmdelete.h"             //ɾ��ӰƬ
#include "film/filmsort.h"               //����ӰƬ
#include "order/order.h"                 //��Ʊ
#include "order/orderquery.h"            //��ѯ����
#include "order/ordercount.h"            //ͳ�ƶ���
#include "order/orderdelete.h"            //ɾ������
#include "user/userbrowse.h"             //����û�
#include "user/userquery.h"              //��ѯ�û�
#include "user/usermodify.h"             //�޸��û�
#include "user/userdelete.h"             //ɾ���û�
#include "user/usersort.h"               //�����û�

#endif
