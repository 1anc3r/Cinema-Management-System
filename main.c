//============================================================================
// Name        : main.c
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

#include "func.h"

int main(void)
{
    //���˵��ķ���ֵ
    int mainkey,filmkey,hallkey,orderkey,userkey;
    int power;                      //Ȩ��
    film *filmpoint;                //ӰƬͷ�ڵ�ָ��
    order *orderpoint;              //����ͷ�ڵ�ָ��
    user *userpoint;                //�û�ͷ�ڵ�ָ��
    HWND hwnd = FindWindow("ConsoleWindowClass", NULL);     //��ȡ����
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };             //���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    system("title Cinema Management System");    //���ڱ���
    MessageBox(hwnd, TEXT(
        "                   �����������������                   \n"
        "                   ENTER����һ��                    \n"
        "                   SPACE��ȷ��/ȡ��(��λ)           \n"
        "                   ESC����һ��                      \n"
        "                                                    \n"
        "                            Cinema Management System\n"
        "                                            �D�DMade By Lancer\n"
        ), TEXT("��ӭʹ��ӰԺ����ϵͳ"), MB_OK);
    NewFile();                      //��û���ļ��򴴽��ļ�
    filmpoint=FilmRead();           //��ӰƬ�ļ��ж�ȡ��Ϣ
    orderpoint=OrderRead();         //�Ӷ����ļ��ж�ȡ��Ϣ
    userpoint=UserRead();           //���û��ļ��ж�ȡ��Ϣ
    flag:
    power=Setup();                  //��¼ϵͳ����ȡȨ��
    if(power==0)
    {
        goto flag;
    }
    while(1)
    {
        mainmenu:
        mainkey=MainMenu();
        system("cls");
        while(mainkey==6)           //ӰƬ��Ϣ����ϵͳ
        {
            if(power==2||power==3)  //��������͹���ԱȨ��
            {
                filmkey=FilmMenu();
                switch(filmkey)
                {
                    case 6 :
                    filmpoint=FilmEnter();          //¼��ӰƬ��Ϣ
                    break;
                    case 7 :
                    FilmBrowse(filmpoint->next);    //���ӰƬ��Ϣ
                    break;
                    case 8 :
                    FilmQuery(filmpoint);           //��ѯӰƬ��Ϣ
                    break;
                    case 9 :
                    FilmModify(filmpoint);          //�޸�ӰƬ��Ϣ
                    break;
                    case 10 :
                    FilmDelete(filmpoint);          //ɾ��ӰƬ��Ϣ
                    break;
                    case 11 :
                    filmpoint=FilmSort(filmpoint);  //����ӰƬ��Ϣ
                    FilmBrowse(filmpoint->next);    //����ʾ
                    break;
                    case 12 :
                    FilmSave(filmpoint);            //����ӰƬ��Ϣ
                    break;
                    case 13 :
                    filmpoint=FilmRead();           //��ȡӰƬ��Ϣ
                    break;
                    case 14 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("��������������������������������������\n");
                printf("��             û��Ȩ��!            ��\n");
                printf("��������������������������������������\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==7)           //Ӱ������ϵͳ
        {
            if(power==2||power==3)  //��������͹���ԱȨ��
            {
                hallkey=HallMenu();
                switch(hallkey)
                {
                    case 6 :
                    FilmBrowse(filmpoint->next);    //���Ӱ����Ϣ
                    break;
                    case 7 :
                    FilmSave(filmpoint);            //��ȡӰ����Ϣ
                    break;
                    case 8 :
                    filmpoint=FilmRead();           //��ȡӰ����Ϣ
                    break;
                    case 9 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("��������������������������������������\n");
                printf("��             û��Ȩ��!            ��\n");
                printf("��������������������������������������\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==8)           //��������ϵͳ
        {
            orderkey=OrderMenu();
            switch(orderkey)
            {
                case 6 :
                Order();                            //��Ʊ
                break;
                case 7 :
                // OrderDelete(orderpoint);            //ɾ��������Ϣ
                // OrderSave(orderpoint);              //���涩����Ϣ
                break;
                case 8 :
                OrderQuery(orderpoint);             //��ѯ������Ϣ
                break;
                case 9 :
                OrderCount(filmpoint->next,orderpoint);             //ͳ�ƶ�����Ϣ
                break;
                case 10 :
                OrderSave(orderpoint);              //���涩����Ϣ
                break;
                case 11 :
                orderpoint=OrderRead();             //��ȡ������Ϣ
                break;
                case 12 :
                goto mainmenu;
                break;
            }
        }
        while(mainkey==9)           //�û�����ϵͳ
        {
            if(power==3)            //���������ԱȨ��
            {

                userkey=UserMenu();
                switch(userkey)
                {
                    case 6 :
                    Register();                     //ע���û�
                    break;
                    case 7 :
                    UserBrowse(userpoint->next);    //����û���Ϣ
                    break;
                    case 8 :
                    UserQuery(userpoint);           //��ѯ�û���Ϣ
                    break;
                    case 9 :
                    UserModify(userpoint);          //�޸��û���Ϣ
                    break;
                    case 10 :
                    UserDelete(userpoint);          //ɾ���û���Ϣ
                    break;
                    case 11 :
                    userpoint=UserSort(userpoint);  //�����û���Ϣ
                    UserBrowse(userpoint->next);    //����ʾ
                    break;
                    case 12 :
                    UserSave(userpoint);            //�����û���Ϣ
                    break;
                    case 13 :
                    userpoint=UserRead();           //��ȡ�û���Ϣ
                    break;
                    case 14 :
                    goto mainmenu;
                }
            }
            else
            {
                system("cls");
                printf("��������������������������������������\n");
                printf("��             û��Ȩ��!            ��\n");
                printf("��������������������������������������\n");
                Sleep(200);
                goto mainmenu;
            }
        }
        while(mainkey==10)
        {
            goto flag;
        }
        while(mainkey==11)
        {
            system("cls");
            printf("���Щ���������������������������������\n");
            printf("���੤��������������������������������\n");
            printf("����   ��лʹ��ӰԺ��Ϣ����ϵͳ!  ����\n");
            printf("�������������������������������������\n");
            printf("�����������������������������������ة�\n");
            exit(0);
        }
    }
    getch();
    return 0;
}
