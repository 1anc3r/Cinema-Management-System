//============================================================================
// Name        : filmenter.h
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

film *FilmEnter();

film *FilmEnter()
{
	film *phead,*pend,*pnew;		//��Ӱ����ĳ�ʼ��
	date *qend,*qnew,*hallall;		//��������ĳ�ʼ��
	int u,i;						//��Ӱ������ѭ������
	int k1,k2;						//�Ƿ����¼���Ӱ(key1)�ͳ���(key2)�Ĺؼ�ֵ
	//Ӱ����λ�ĳ�ʼ��
	int s[6][14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//ʹ�õ�Ӱ�ĳ�����Ϣ����Ӱ����λ�ļ�
	char filename[19]="";			//Ӱ����λ�ļ���
	char stryear[5],strmonth[3],strday[3],stropenhour[3],stropenmin[3],strclosehour[3],strclosemin[3],strhallnum[3];
	char name,score,length,fare,year,month,day;
	//��Ӱ��Ϣ���ַ����ж϶�ȡֵ
	char tempname[22],tempscore[4],templength[4],tempfare[7],tempyear00[5],tempmonth00[3],tempday00[3];
	//��Ӱ��Ϣ�ַ��������ַ�����
	int tempyear=0,tempmonth=0,tempday=0,temphour=0,tempmin=0,temphallnum=0,tempopen,tempclose,hallopen,hallclose;
	//Ӱ��ʱ����Ϣ���ж��Ƿ��ͻ
	n=0;
	u=n;
	phead=(film*)malloc(sizeof(film));
	pend=phead;
	do
	{
		pnew=(film*)malloc(sizeof(film));
		pnew->score=0;
		pnew->length=0;
		pnew->fare=0;
		flag:
		system("cls");
		printf("��������������������������������������\n");
		printf("��                            ����  ��\n");
		printf("��  Ƭ����   ����               Ԫ  ��\n");
		printf("��������������������������������������\n");
		printf("��      ��  ��  ��                  ��\n");
		printf("��������������������������������������\n");
		printf("��                                  ��\n");
		printf("��������������������������������������\n");
    	/*********************Ƭ��*********************/
		flagoffilmname:
		Position(5,2);
		printf("                      ");
		Position(1,9);
		printf("��������������������������������������\n");
		printf("��        [!]��ʾ:����Ƭ��.[0<23]   ��\n");
		printf("��������������������������������������\n");
		Position(5,2);
		//scanf("%s",pnew->filmname);
		i=0;
		while((name=getch())!='\r')
		{
			if(name==0x1b)
			{
				Position(5,2);
				printf("                      ");
				goto flag;
			}
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
		strcpy(pnew->filmname,tempname);
		if(strlen(pnew->filmname)==0)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(5,2);
			printf("                      ");
			goto flagoffilmname;
		}
		/*********************����*********************/
		flagofscore:
		Position(28,2);
		printf("   ");
		Position(1,10);
		printf("��        [!]��ʾ:��������.[0<10]   ��\n");
		printf("��������������������������������������\n");
		Position(28,2);
		//scanf("%lf",&pnew->score);
		i=0;
		while((score=getch())!='\r')
		{
			if(score==0x1b)
			{
				Position(28,2);
				printf("   ");
				goto flagoffilmname;
			}
			if(i<3&&score!='\b')
			{
				tempscore[i++]=score;
				printf("%c",score);
			}
			if(i>0&&score=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==3)
			{
				continue;
			}
		}
		putchar('\n');
		tempscore[i]='\0';
		pnew->score=atof(tempscore);
		if(pnew->score<=0||pnew->score>9.999)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(28,2);
			printf("   ");
			goto flagofscore;
		}
		/*********************Ƭ��*********************/
		flagoflength:
		Position(11,3);
		printf("   ");
		Position(1,10);
		printf("��        [!]��ʾ:����Ƭ��.[0<1000] ��\n");
		printf("��������������������������������������\n");
		Position(11,3);
		//scanf("%lf",&pnew->length);
		i=0;
		while((length=getch())!='\r')
		{
			if(length==0x1b)
			{
				Position(11,3);
				printf("   ");
				goto flagofscore;
			}
			if(i<3&&length!='\b')
			{
				templength[i++]=length;
				printf("%c",length);
			}
			if(i>0&&length=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==3)
			{
				continue;
			}
		}
		putchar('\n');
		templength[i]='\0';
		pnew->length=atof(templength);
		if(pnew->length<=0||pnew->length>999.9)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(11,3);
			printf("   ");
			goto flagoflength;
		}
		/*********************Ʊ��*********************/
		flagoffare:
		Position(27,3);
		printf("      ");
		Position(1,10);
		printf("��        [!]��ʾ:����Ʊ��.[0<1000] ��\n");
		printf("��������������������������������������\n");
		Position(27,3);
		//scanf("%lf",&pnew->fare);
		i=0;
		while((fare=getch())!='\r')
		{
			if(fare==0x1b)
			{
				Position(27,3);
				printf("      ");
				goto flagoflength;
			}
			if(i<6&&fare!='\b')
			{
				tempfare[i++]=fare;
				printf("%c",fare);
			}
			if(i>0&&fare=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==6)
			{
				continue;
			}
		}
		putchar('\n');
		tempfare[i]='\0';
		pnew->fare=atof(tempfare);
		if(pnew->fare<=0||pnew->fare>999)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(27,3);
			printf("      ");
			goto flagoffare;
		}
		/*********************���*********************/
		flagofyear:
		Position(5,5);
		printf("    ");
		Position(1,10);
		printf("��        [!]��ʾ:�������.[0<10000]��\n");
		printf("��������������������������������������\n");
		Position(5,5);
		//scanf("%d",&tempyear);
		i=0;
		while((year=getch())!='\r')
		{
			if(year==0x1b)
			{
				Position(5,5);
				printf("    ");
				goto flagoffare;
			}
			if(i<4&&year!='\b')
			{
				tempyear00[i++]=year;
				printf("%c",year);
			}
			if(i>0&&year=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==4)
			{
				continue;
			}
		}
		putchar('\n');
		tempyear00[i]='\0';
		tempyear=atoi(tempyear00);
		if(tempyear<1||tempyear>9999)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(5,5);
			printf("    ");
			goto flagofyear;
		}
		/*********************�·�*********************/
		flagofmonth:
		Position(11,5);
		printf("  ");
		Position(1,10);
		printf("��        [!]��ʾ:�����·�.[1~12]   ��\n");
		printf("��������������������������������������\n");
		Position(11,5);
		//scanf("%d",&tempmonth);
		i=0;
		while((month=getch())!='\r')
		{
			if(month==0x1b)
			{
				Position(11,5);
				printf("  ");
				goto flagofyear;
			}
			if(i<2&&month!='\b')
			{
				tempmonth00[i++]=month;
				printf("%c",month);
			}
			if(i>0&&month=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==2)
			{
				continue;
			}
		}
		putchar('\n');
		tempmonth00[i]='\0';
		tempmonth=atoi(tempmonth00);
		if(tempmonth<1||tempmonth>12)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(11,5);
			printf("  ");
			goto flagofmonth;
		}
		/*********************����*********************/
		flagofday:
		Position(15,5);
		printf("  ");
		Position(1,10);
		printf("��        [!]��ʾ:��������.[1~30]   ��\n");
		printf("��������������������������������������\n");
		Position(15,5);
		//scanf("%d",&tempday);
		i=0;
		while((day=getch())!='\r')
		{
			if(day==0x1b)
			{
				Position(15,5);
				printf("  ");
				goto flagofmonth;
			}
			if(i<2&&day!='\b')
			{
				tempday00[i++]=day;
				printf("%c",day);
			}
			if(i>0&&day=='\b')
			{
				--i;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			if(i==2)
			{
				continue;
			}
		}
		putchar('\n');
		tempday00[i]='\0';
		tempday=atoi(tempday00);
		if(tempday<1||tempday>30)
		{
			Position(1,10);
			printf("��        [!]��ʾ:�����ʽ!         ��\n");
			printf("��������������������������������������\n");
			getch();
			Position(15,5);
			printf("  ");
			goto flagofday;
		}
		//¼���Ӱ(δ)���
		if(strlen(pnew->filmname)<1||pnew->score==0||pnew->length==0||pnew->fare==0||tempyear==0||tempmonth==0||tempday==0)
		{
			Position(1,10);
			printf("��        [!]��ʾ:δ���!           ��\n");
			printf("��������������������������������������\n");
			getch();
			goto flagofday;
		}
		//¼�볡��
		line=7;
		pnew->premiere=(date*)malloc(sizeof(date));
		qend=pnew->premiere;
		do
		{
			flagofdate:
			qnew=(date*)malloc(sizeof(date));
			Position(1,line);
			printf("��    :  -  :                   ��  ��\n");
			printf("��������������������������������������\n");
			printf("��                                  ��\n");
			printf("��������������������������������������\n");
			qnew->year=tempyear;
			qnew->month=tempmonth;
			qnew->day=tempday;
			Position(1,line+4);
			printf("��������������������������������������\n");
			printf("��        [!]��ʾ:���뿪Ļʱ.[0<24] ��\n");
			printf("��������������������������������������\n");
			Position(5,line);
			scanf("%d",&qnew->openhour);
			if(qnew->openhour<0||qnew->openhour>23)
			{
				Position(1,line+4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				Position(1,line);
				printf("��    :  -  :                   ��  ��\n");
				goto flagofdate;
			}
			Position(1,line+4);
			printf("��������������������������������������\n");
			printf("��        [!]��ʾ:���뿪Ļ��.[0<60] ��\n");
			printf("��������������������������������������\n");
			Position(8,line);
			scanf("%d",&qnew->openmin);
			if(qnew->openmin<0||qnew->openmin>59)
			{
				Position(1,line+4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				Position(1,line);
				printf("��    :  -  :                   ��  ��\n");
				goto flagofdate;
			}
			qnew->closemin=qnew->openmin+(int)pnew->length%60;
			qnew->closehour=qnew->openhour+(int)pnew->length/60;
			if(qnew->closemin>59)
			{
				qnew->closehour+=1;
				qnew->closemin-=60;
			}
			if(qnew->closehour>23)
			{
				Position(1,line+4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				Position(1,line);
				printf("��    :  -  :                   ��  ��\n");
				goto flagofdate;
			}
			Position(11,line);
			printf("%2d",qnew->closehour);
			Position(14,line);
			printf("%2d",qnew->closemin);
			Position(31,line);
			scanf("%d",&qnew->hallnum);
			Position(1,line+4);
			printf("��������������������������������������\n");
			printf("��        [!]��ʾ:����Ӱ����.[0<100]��\n");
			printf("��������������������������������������\n");
			//Ӱ���Ƿ�Ϊ��
			tempopen=qnew->openhour*100+qnew->openmin;
			tempclose=qnew->closehour*100+qnew->closemin;
			hallall=HallRead()->next;
			while(hallall!=NULL)
			{
				hallopen=hallall->openhour*100+hallall->openmin;
				hallclose=hallall->closehour*100+hallall->closemin;
				if((qnew->year==hallall->year&&qnew->month==hallall->month&&qnew->day==hallall->day&&qnew->hallnum==hallall->hallnum)&&((tempopen>hallopen||tempopen<hallclose)||(tempclose>hallopen||tempclose<hallclose)))
				{
					Position(1,line+4);
					printf("��������������������������������������\n");
					printf("��        [!]��ʾ:�����Ѵ���!       ��\n");
					printf("��������������������������������������\n");
					getch();
					Position(1,line);
					printf("��    :  -  :                   ��  ��\n");
					goto flagofdate;
				}
				hallall=hallall->next;
			}
			if(qnew->hallnum<1||qnew->hallnum>99)
			{
				Position(1,line+4);
				printf("��������������������������������������\n");
				printf("��        [!]��ʾ:�����ʽ!         ��\n");
				printf("��������������������������������������\n");
				getch();
				system("cls");
				goto flagofdate;
			}
			//���ճ��κ�Ӱ����Ϣ�����ļ�����ʼ����λ
			itoa(qnew->year,stryear,10);
			itoa(qnew->month,strmonth,10);
			itoa(qnew->day,strday,10);
			itoa(qnew->openhour,stropenhour,10);
			itoa(qnew->openmin,stropenmin,10);
			itoa(qnew->closehour,strclosehour,10);
			itoa(qnew->closemin,strclosemin,10);
			itoa(qnew->hallnum,strhallnum,10);
			strcat(filename,stryear);
			strcat(filename,strmonth);
			strcat(filename,strday);
			strcat(filename,stropenhour);
			strcat(filename,stropenmin);
			strcat(filename,strclosehour);
			strcat(filename,strclosemin);
			strcat(filename,strhallnum);
			strcat(filename,".txt");
			SeatSave(s,filename);
			strcpy(filename,"");
			qend->next=qnew;
			qend=qnew;
			line+=2;
			Position(1,line+2);
			printf("��������������������������������������\n");
			printf("��      �Ƿ����¼�볡����Ϣ?       ��\n");
			printf("��      �� ����      �� ����        ��\n");
			printf("��������������������������������������\n");
				//scanf("%d",&k2);
			k2=9;
			Position(k2,line+4);
			printf("��");
			while((ch=getch())!=0x0d)
			{
				while(ch==0x4b)
				{
					if(k2==9)
					{
						break;
					}
					else
					{
						Position(k2,line+4);
						printf("��");
						k2=9;
						Position(k2,line+4);
						printf("��");
						break;
					}
				}
				while(ch==0x4d)
				{
					if(k2==22)
					{
						break;
					}
					else
					{
						Position(k2,line+4);
						printf("��");
						k2=22;
						Position(k2,line+4);
						printf("��");
						break;
					}
				}
			}
		}while(k2==9);
		qend->next=NULL;
		pend->next=pnew;
		pend=pnew;
		Position(1,line+2);
		printf("��������������������������������������\n");
		printf("��      �Ƿ����¼��ӰƬ��Ϣ?       ��\n");
		printf("��      �� ����      �� ����        ��\n");
		printf("��������������������������������������\n");
		k1=9;
		Position(k1,line+4);
		printf("��");
		while((ch=getch())!=0x0d)
		{
			while(ch==0x4b)
			{
				if(k1==9)
				{
					break;
				}
				else
				{
					Position(k1,line+4);
					printf("��");
					k1=9;
					Position(k1,line+4);
					printf("��");
					break;
				}
			}
			while(ch==0x4d)
			{
				if(k1==22)
				{
					break;
				}
				else
				{
					Position(k1,line+4);
					printf("��");
					k1=22;
					Position(k1,line+4);
					printf("��");
					break;
				}
			}
		}
		u++;
	}while(k1==9);
	pend->next=NULL;
	n=u;
	system("cls");
	printf("��������������������������������������\n");
	printf("��    [!]��ʾ:¼��%3d��ӰƬ��Ϣ!    ��\n",u);
	printf("��        ������������˵�...       ��\n");
	printf("��������������������������������������\n");
	getch();
	system("cls");
	return phead;
}
