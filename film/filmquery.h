//============================================================================
// Name        : filmquery.h
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

film* FilmQuery(film *p);

film* FilmQuery(film *p)
{
	int i;							//����ѭ��
	int len;						//Ƭ������
	int choose;
	char name;
	char tempname[22];				//����Ƭ��
	int namelen;
	double tempscore;				//��������
	double templength;				//����Ƭ��
	double tempfare;				//����Ʊ��
	date *t;						//���νڵ�ָ��
	if(n!=0)
	{
		line=4;
		system("cls");
		printf("��������������������������������������\n");
		printf("��           ��ѯӰƬ��Ϣ           ��\n");
		printf("��������������������������������������\n");
		printf("��           [1]-----Ƭ��           ��\n");
		printf("��           [2]-----����           ��\n");
		printf("��           [3]-----Ƭ��           ��\n");
		printf("��           [4]-----Ʊ��           ��\n");
		printf("��           [0]-----ȡ��           ��\n");
		printf("��������������������������������������\n");
		choose=Cursor(4,8,12,26,8,1);
		system("cls");
		switch(choose)
		{
			case 4 :
			printf("��������������������������������������\n");
			printf("��  Ƭ��:                           ��\n");
			printf("��������������������������������������\n");
			Position(10,2);
			i=0;
			while((name=getch())!='\r')
			{
				if(i<22&&name!='\b')
				{
					tempname[i++]=name;
					printf("%c",name);
				}
				if(i>0&&name=='\b')
				{
					--i;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				if(i==22)
				{
					continue;
				}
			}
			putchar('\n');
			tempname[i]='\0';
			namelen=strlen(tempname);
			while(p!=NULL&&memcmp(tempname,p->filmname,namelen))
			{
				p=p->next;
			}
			if(!memcmp(tempname,p->filmname,namelen))
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             ӰƬ��Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf����  ��\n",p->score);
				printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",p->length,p->fare);
				printf("��������������������������������������\n");
				printf("��  %4d��%2d��%2d��                  ��\n",p->premiere->next->year,p->premiere->next->month,p->premiere->next->day);
				printf("��������������������������������������\n");
				line=12;
				t=p->premiere->next;
				while(t!=NULL)
				{
					Position(1,line);
					printf("��  %2d:%2d-%2d:%2d                     ��\n",t->openhour,t->openmin,t->closehour,t->closemin);
					printf("��������������������������������������\n");
					t=t->next;
					line+=2;
				}
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
				printf("�� [!]��ʾ:�޸�ӰƬ��¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 5 :
			printf("��������������������������������������\n");
			printf("��  ����:                           ��\n");
			printf("��������������������������������������\n");
			Position(10,2);
			scanf("%lf", &tempscore);
			while(p!=NULL&&p->score!=tempscore)
			{
				p=p->next;
			}
			if(p->score==tempscore)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             ӰƬ��Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf����  ��\n",p->score);
				printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",p->length,p->fare);
				printf("��������������������������������������\n");
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
				printf("�� [!]��ʾ:�޸�ӰƬ��¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 6 :
			printf("��������������������������������������\n");
			printf("��  Ƭ��:                           ��\n");
			printf("��������������������������������������\n");
			Position(10,2);
			scanf("%lf", &templength);
			while(p!=NULL&&p->length!=templength)
			{
				p=p->next;
			}
			if(p->length==templength)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             ӰƬ��Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf����  ��\n",p->score);
				printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",p->length,p->fare);
				printf("��������������������������������������\n");
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
				printf("�� [!]��ʾ:�޸�ӰƬ��¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 7 :
			printf("��������������������������������������\n");
			printf("��  Ʊ��:                           ��\n");
			printf("��������������������������������������\n");
			Position(10,2);
			scanf("%lf", &tempfare);
			while(p!=NULL&&p->fare!=tempfare)
			{
				p=p->next;
			}
			if(p->fare==tempfare)
			{
				Position(1,4);
				printf("��������������������������������������\n");
				printf("��             ӰƬ��Ϣ             ��\n");
				printf("��������������������������������������\n");
				printf("��  %s",p->filmname);
				len=strlen(p->filmname);
				for(i = 0;i < 23-len;i++)
				{
					printf(" ");
				}
				printf("%3.1lf����  ��\n",p->score);
				printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",p->length,p->fare);
				printf("��������������������������������������\n");
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
				printf("�� [!]��ʾ:�޸�ӰƬ��¼,����������! ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				return NULL;
			}
			break;
			case 8 :
			goto flag;
			break;
		}
	}
	else
	{
		system("cls");
		printf("��������������������������������������\n");
		printf("��  [!]��ʾ:��ӰƬ����,����������!  ��\n");
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
