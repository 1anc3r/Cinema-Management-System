//============================================================================
// Name        : usermodify.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void UserModify(user *p);

void UserModify(user *p)
{
	int i;
	int len;
	int choose;
	user *q;
	q=UserQuery(p);
	if(q!=NULL)
	{
		line=4;
		system("cls");
		printf("��������������������������������������\n");
		printf("��           �޸��û���Ϣ           ��\n");
		printf("��������������������������������������\n");
		printf("��           [1]-----�˺�           ��\n");
		printf("��                                  ��\n");
		printf("��           [3]-----����           ��\n");
		printf("��                                  ��\n");
		printf("��           [0]-----ȡ��           ��\n");
		printf("��������������������������������������\n");
		choose=Cursor(4,8,12,26,8,2);
		system("cls");
		switch(choose)
		{
			case 4 :
			Position(1,1);
			printf("��������������������������������������\n");
			printf("��  ���˺�:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%s",&q->id);
			break;
			case 6 :
			Position(1,1);
			printf("��������������������������������������\n");
			printf("��  ������:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%s",&q->password);
			break;
			case 8 :
			goto flag;
			break;
		}
		Position(1,4);
		printf("��������������������������������������\n");
		printf("��             �û���Ϣ             ��\n");
		printf("��������������������������������������\n");
		printf("��%d %s %s",q->power,q->id,q->password);
		for(i=0;i<31-strlen(q->id)-strlen(q->password);i++)
		{
			printf(" ");
		}
		printf("��\n��������������������������������������\n");
		printf("��                                  ��\n");
		printf("��������������������������������������\n");
		getch();
		system("cls");
	}
	else
	{
		system("cls");
		printf("��������������������������������������\n");
        printf("��  [!]��ʾ:���û�����,����������!  ��\n");
        printf("��������������������������������������\n");
		getch();
		system("cls");
	}
	flag:
	system("cls");
	printf("��������������������������������������\n");
	printf("��       [!]��ʾ:�޸����!          ��\n");
	printf("��       ������������˵�...        ��\n");
	printf("��������������������������������������\n");
	getch();
	system("cls");
}
