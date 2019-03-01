//============================================================================
// Name        : ordercount.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void OrderCount(film *fp,order *op);

void OrderCount(film *fp,order *op)
{
	double sum;
	order *oq;
	oq=op->next;
	film *q;						//ӰƬ�����ƶ��ڵ�ָ��
	date *t;						//��������ͷ���ָ��
	date *d;						//���������ƶ��ڵ�ָ��
	int i,j;						//ѭ������
	int len;						//Ƭ������
	int u=0;						//��������
	int choosefilm;					//ѡ��ӰƬ
	int choosedate;					//ѡ�񳡴�
	q=fp;
	system("cls");
	printf("������������������������������������������������������������������������\n");
	printf("��           ͳ��Ʊ����Ϣ           ��\n");
	printf("������������������������������������������������������������������������\n");
	while(fp!=NULL)
	{
		printf("��  %s",fp->filmname);
		len=strlen(fp->filmname);
		for(i = 0;i < 23-len;i++)
		{
			printf(" ");
		}
		printf("%3.1lf����  ��\n",fp->score);
		printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",fp->length,fp->fare);
		printf("������������������������������������������������������������������������\n");
		fp=fp->next;
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
	printf("��           ͳ��Ʊ����Ϣ           ��\n");
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
	if(o!=0)
	{
		sum=0.0;
		while(oq!=NULL)
		{
			if(oq->hallnum==d->hallnum)
			{
				sum+=oq->fare;
			}
			oq=oq->next;
		}
		printf("\n������������������������������������������������������������������������\n");
		printf("��  �ϼ�:                 %6.2lfԪ  ��\n",sum);
		printf("������������������������������������������������������������������������\n");
	}
	else
	{
		Position(1,14);
		printf("������������������������������������������������������������������������\n");
		printf("��  [!]��ʾ:�޶�����¼,����������!  ��\n");
		printf("������������������������������������������������������������������������\n");
	}
	getch();
	system("cls");
}
