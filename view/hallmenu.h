//============================================================================
// Name        : hallmenu.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int HallMenu();

int HallMenu()
{
    int choose;
    system("cls");
    printf("��������������������������������������\n");
    printf("��������������������������������������\n");
    printf("����         Ӱ������ϵͳ         ����\n");
    printf("��������������������������������������\n");
    printf("��������������������������������������\n");
    printf("����     [1]----���Ӱ����Ϣ      ����\n");
    printf("����     [2]----����Ӱ����Ϣ      ����\n");
    printf("����     [3]----����Ӱ����Ϣ      ����\n");
    printf("����     [0]----�������˵�        ����\n");
    printf("����                              ����\n");
    printf("����                              ����\n");
    printf("����                              ����\n");
    printf("����                              ����\n");
    printf("����                              ����\n");
    printf("��������������������������������������\n");
    printf("��������������������������������������\n");
    choose=Cursor(6,9,8,29,9,1);
    return choose;
}