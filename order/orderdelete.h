//============================================================================
// Name        : orderdelete.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void OrderDelete(order *p);

void OrderDelete(order *p)
{
    int i;                          //ѭ������
    int len;                        //Ƭ������
    int choose;
    int (*seat)[14];                        //��λ��ά����
    char filename[23]="";                   //�����ļ���
    char stryear[5],strmonth[3],strday[3],stropenhour[3],stropenmin[3],strclosehour[3],strclosemin[3],strhallnum[3];
    order *o,*q;                     //ӰƬ��ɾ���ڵ㼰��ǰһ�ڵ�
    q=p->next;
    o=OrderQuery(p);
    if(o!=NULL)
    {
        line=5;
        system("cls");
        printf("������������������������������������������������������������������������\n");
        printf("��               ��Ʊ               ��\n");
        printf("������������������������������������������������������������������������\n");
        printf("��                                  ��\n");
        printf("��           [1]-----ȷ��           ��\n");
        printf("��                                  ��\n");
        printf("��           [0]-----ȡ��           ��\n");
        printf("��                                  ��\n");
        printf("������������������������������������������������������������������������\n");
        choose=Cursor(5,7,11,25,7,2);
        system("cls");
        switch(choose)
        {
            case 5 :
                while(q->next!=NULL&&q->ordernum!=o->ordernum)
                {
                    p=p->next;
                    q=p->next;
                }
                itoa(q->year,stryear,10);
                itoa(q->month,strmonth,10);
                itoa(q->day,strday,10);
                itoa(q->openhour,stropenhour,10);
                itoa(q->openmin,stropenmin,10);
                itoa(q->closehour,strclosehour,10);
                itoa(q->closemin,strclosemin,10);
                itoa(q->hallnum,strhallnum,10);
                strcat(filename,stryear);
                strcat(filename,strmonth);
                strcat(filename,strday);
                strcat(filename,stropenhour);
                strcat(filename,stropenmin);
                strcat(filename,strclosehour);
                strcat(filename,strclosemin);
                strcat(filename,strhallnum);
                strcat(filename,".txt");
                printf("%s\n", filename);
                getch();
                seat=SeatRead(s,filename);
                seat[q->shit[1]][q->shit[0]]=0;
                printf("2\n");
                getch();
                SeatSave(seat,filename);
                p->next=q->next;
                free(q);
                o--;
            break;
            case 7 :
            break;
        }
        system("cls");
    }
    else
    {
        printf("������������������������������������������������������������������������\n");
        printf("�� [!]��ʾ:�޸ö�������,����������! ��\n");
        printf("������������������������������������������������������������������������\n");
        getch();
        system("cls");
    }
    system("cls");
    printf("������������������������������������������������������������������������\n");
    printf("��       [!]��ʾ:ɾ�����!          ��\n");
    printf("��       ������������˵�...        ��\n");
    printf("������������������������������������������������������������������������\n");
    getch();
    system("cls");
}
