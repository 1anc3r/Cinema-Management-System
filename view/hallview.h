void HallView(film *f,date *d);

void HallView(film *f,date *d)
{
	int len;
	int i,j;
	int (*seat)[14];						//��λ��ά����
	char filename[19]="";					//�����ļ���
	char stryear[5],strmonth[3],strday[3],stropenhour[3],stropenmin[3],strclosehour[3],strclosemin[3],strhallnum[3];
	HANDLE hOut;							//����̨��������
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ���,�ı���ɫ
	system("cls");
	printf("��������������������������������������\n");
	printf("��           ���Ӱ����Ϣ           ��\n");
	printf("��������������������������������������\n");
	printf("��  %s",f->filmname);
	len=strlen(f->filmname);
	for(i = 0;i < 23-len;i++)
	{
		printf(" ");
	}
	printf("%3.1lf����  ��\n",f->score);
	printf("��  Ƭ����%3.lf����         %6.2lfԪ  ��\n",f->length,f->fare);
	printf("��������������������������������������\n");
	printf("��  %4d��%2d��%2d��                  ��\n",d->year,d->month,d->day);
	printf("��������������������������������������\n");
	printf("��  %2d:%2d-%2d:%2d               %2d��  ��\n",d->openhour,d->openmin,d->closehour,d->closemin,d->hallnum);
	printf("��������������������������������������\n");
	printf("������ѡ  ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	printf("����ѡ  ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf("������            ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
	printf("��\n��������������������������������������\n");
	printf("��    ��������������������������������\n");
	printf("��    ��          ��Ļ            ����\n");
	printf("��    ��������������������������������\n");
	printf("��                                  ��\n");
	printf("���� ��                             ��\n");
	printf("����1������������������������������ ��\n");
	printf("����2������������������������������ ��\n");
	printf("����3������������������������������ ��\n");
	printf("����4������������������������������ ��\n");
	printf("����5������������������������������ ��\n");
	printf("����6������������������������������ ��\n");
	printf("���� ��                             ��\n");
	printf("��                                  ��\n");
	printf("��������������������������������������\n");
	itoa(d->year,stryear,10);
	itoa(d->month,strmonth,10);
	itoa(d->day,strday,10);
	itoa(d->openhour,stropenhour,10);
	itoa(d->openmin,stropenmin,10);
	itoa(d->closehour,strclosehour,10);
	itoa(d->closemin,strclosemin,10);
	itoa(d->hallnum,strhallnum,10);
	strcat(filename,stryear);
	strcat(filename,strmonth);
	strcat(filename,strday);
	strcat(filename,stropenhour);
	strcat(filename,stropenmin);
	strcat(filename,strclosehour);
	strcat(filename,strclosemin);
	strcat(filename,strhallnum);
	strcat(filename,".txt");
	seat=SeatRead(s,filename);
	for(i=0;i<6;i++)
	{
		for(j=0;j<14;j++)
		{
			if(seat[i][j]==0)
			{
				Position(j*2+8,i+18);
				printf("��");
			}
			if(seat[i][j]==1)
			{
				Position(j*2+8,i+18);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
				printf("��");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
			if(seat[i][j]==2)
			{
				Position(j*2+8,i+18);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
				printf("��");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
		}
	}
}
