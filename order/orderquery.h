//============================================================================
// Name        : orderquery.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

order* OrderQuery(order *p);

order* OrderQuery(order *p)
{
	int k,i;
	int len;
	int num;
	int line;
	int choose;
	char tempnum[8];
	char strnum[8];
	order *q;
	q=p->next;
	if(o!=0)
	{
		line=5;
		system("cls");
		printf("��������������������������������������\n");
		printf("��           ��ѯ������Ϣ           ��\n");
		printf("��������������������������������������\n");
		printf("��                                  ��\n");
		printf("��           [1]-----������         ��\n");
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
			printf("��  ������:                         ��\n");
			printf("��������������������������������������\n");
			Position(12,2);
			scanf("%s",tempnum);
			num=strlen(tempnum);
			while(q!=NULL&&itoa(q->ordernum,strnum,10)&&memcmp(tempnum,strnum,num))
			{
				p=p->next;
				q=p->next;
			}
			if(!memcmp(tempnum,strnum,num))
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             ������Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��������������������������������������\n");
				printf("��  ������                 %7d  ��\n",q->ordernum);
				printf("��������������������������������������\n");
				printf("��  Ƭ��:");
				len=strlen(q->filmname);
				for(i = 0;i < 25-len;i++)
				{
					printf(" ");
				}
				printf("%s  ��\n",q->filmname);
				printf("��������������������������������������\n");
				printf("��  Ƭ����                 %3.lf����  ��\n",q->length);
				printf("��������������������������������������\n");
				printf("��  ����:           %4d��%2d��%2d��  ��\n",q->year,q->month,q->day);
				printf("��������������������������������������\n");
				printf("��  ����:              %2d:%2d-%2d:%2d  ��\n",q->openhour,q->openmin,q->closehour,q->closemin);
				printf("��������������������������������������\n");
				printf("��  Ժ��:                     %2d��  ��\n",q->hallnum);
				printf("��������������������������������������\n");
				printf("��  ��λ:                 %2d��%2d��  ��\n",q->shit[0],q->shit[1]);
				printf("��������������������������������������\n");
				printf("��  С��:                 %6.2lfԪ  ��\n",q->fare);
				printf("��������������������������������������\n");
				printf("��                                  ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return q;
			}
			else
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("�� [!]��ʾ:�޸ö�����¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 7 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��  [!]��ʾ:�޶�������,����������!  ��\n");
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
