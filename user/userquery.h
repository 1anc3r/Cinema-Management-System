//============================================================================
// Name        : userquery.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

user *UserQuery(user *p);

user *UserQuery(user *p)
{
	int i;
	int choose;
	char tempid[15],tempasswd[15];
	if(m!=0)
	{
		line=5;
		system("cls");
		printf("��������������������������������������\n");
		printf("��           ��ѯ�û���Ϣ           ��\n");
		printf("��������������������������������������\n");
		printf("��                                  ��\n");
		printf("��           [1]-----�˺�           ��\n");
		printf("��                                  ��\n");
		printf("��           [0]-----ȡ��           ��\n");
		printf("��                                  ��\n");
		printf("��������������������������������������\n");
		choose=Cursor(5,7,12,26,7,2);
        system("cls");
        switch(choose)
		{
			case 5 :
			printf("��������������������������������������\n");
			printf("��  �˺�:                           ��\n");
			printf("��������������������������������������\n");
			Position(10,2);
			scanf("%s",&tempid);
			while(p->next!=NULL&&(strcmp(tempid,p->id)!=0))
			{
				p=p->next;
			}
			if(strcmp(tempid,p->id)==0)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             �û���Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��%d %s %s",p->power,p->id,p->password);
				for(i=0;i<31-strlen(p->id)-strlen(p->password);i++)
				{
					printf(" ");
				}
				printf("��\n��������������������������������������\n");
				printf("��                                  ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return p;
			}
			else
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("�� [!]��ʾ:�޸��û���¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 6 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��  [!]��ʾ:���û�����,����������!  ��\n");
		printf("��������������������������������������\n");
		getch();
		system("cls");
		return NULL;
	}
	flag:
	system("cls");
	printf("��������������������������������������\n");
	printf("��       [!]��ʾ:��ѯ���!          ��\n");
	printf("��       ������������˵�...        ��\n");
	printf("��������������������������������������\n");
	getch();
	system("cls");
	return NULL;
}
