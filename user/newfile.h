//============================================================================
// Name        : newfile.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void NewFile();

void NewFile()
{
	if(fopen("data/infofilm.txt","at+")==NULL)
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��       [!]��ʾ:�ļ���ʧ��!      ��\n");
		printf("��������������������������������������\n");
		getch();
		exit(0);
	}
	if(fopen("data/infoorder.txt","at+")==NULL)
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��       [!]��ʾ:�ļ���ʧ��!      ��\n");
		printf("��������������������������������������\n");
		getch();
		exit(0);
	}
	if(fopen("data/infouser.txt","at+")==NULL)
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��       [!]��ʾ:�ļ���ʧ��!      ��\n");
		printf("��������������������������������������\n");
		getch();
		exit(0);
	}
}
