//============================================================================
// Name        : filmbrowse.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film                 //��Ӱ
{
    char filmname[22];              //Ƭ��
    double score;                   //����
    double length;                  //Ƭ��
    double fare;                    //Ʊ��
    struct date *premiere;          //��ӳ
    struct film *next;
}film;
*/

void FilmBrowse(film *p);

void FilmBrowse(film *p)
{
	film *q;						//ӰƬ�����ƶ��ڵ�ָ��
	date *t;						//��������ͷ���ָ��
	date *d;						//���������ƶ��ڵ�ָ��
	int i,j;						//ѭ������
	int len;						//Ƭ������
	int u=0;						//��������
	int choosefilm;					//ѡ��ӰƬ
	int choosedate;					//ѡ�񳡴�
	q=p;
	if(n!=0)
	{
		system("cls");
		printf("������������������������������������������������������������������������\n");
		printf("��           ���ӰƬ��Ϣ           ��\n");
		printf("������������������������������������������������������������������������\n");
		while(p!=NULL)
		{
			printf("��  %s",p->filmname);
			len=strlen(p->filmname);
			for(i = 0;i < 23-len;i++)
			{
				printf(" ");
			}
			printf("%3.1lf����  ��\n",p->score);
			printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",p->length,p->fare);
			printf("������������������������������������������������������������������������\n");
			p=p->next;
		}
		printf("��                                  ��\n");
		printf("������������������������������������������������������������������������\n");
		choosefilm=Cursor(4,3*n+1,2,34,0,3);
		//ѡ��Ŀ���Ӱ�������ͷ��������������Ӧλ��
		for(i=0;i<(choosefilm-4)/3;i++)
		{
			q=q->next;
		}
		system("cls");
		printf("������������������������������������������������������������������������\n");
		printf("��           ���ӰƬ��Ϣ           ��\n");
		printf("������������������������������������������������������������������������\n");
		printf("��  %s",q->filmname);
		len=strlen(q->filmname);
		for(i = 0;i < 23-len;i++)
		{
			printf(" ");
		}
		printf("%3.1lf����  ��\n",q->score);
		printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",q->length,q->fare);
		printf("������������������������������������������������������������������������\n");
		printf("��  %4d��%2d��%2d��                  ��\n",q->premiere->next->year,q->premiere->next->month,q->premiere->next->day);
		printf("������������������������������������������������������������������������\n");
		line=9;
		t=q->premiere->next;
		d=t;
		while(t!=NULL)
		{
			Position(1,line);
			printf("��  %2d:%2d-%2d:%2d               %2d��  ��\n",t->openhour,t->openmin,t->closehour,t->closemin,t->hallnum);
			printf("������������������������������������������������������������������������\n");
			t=t->next;
			line+=2;
			u++;
		}
		printf("��                                  ��\n");
		printf("������������������������������������������������������������������������\n");
		choosedate=Cursor(9,2*u+7,2,34,0,2);
		for(i=0;i<(choosedate-9)/2;i++)
		{
			d=d->next;
		}
		HallView(q,d);
	}
	else
	{
		system("cls");
		printf("������������������������������������������������������������������������\n");
		printf("�� [!]��ʾ:�޸�ӰƬ��¼,����������! ��\n");
		printf("������������������������������������������������������������������������\n");
	}
	getch();
	system("cls");
}
