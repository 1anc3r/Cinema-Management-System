//============================================================================
// Name        : filmdelete.h
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

void FilmDelete(film *p);

void FilmDelete(film *p)
{
    int i;                          //ѭ������
    int len;                        //Ƭ������
    int choose;
    film *o,*q;                     //ӰƬ��ɾ���ڵ㼰��ǰһ�ڵ�
    q=p->next;
    o=FilmQuery(p);
    if(o!=NULL)
    {
        line=5;
        system("cls");
        printf("������������������������������������������������������������������������\n");
        printf("��           ɾ��ӰƬ��Ϣ           ��\n");
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
            while(q->next!=NULL&&(strcmp(o->filmname,q->filmname)!=0))
            {
                p=p->next;
                q=p->next;
            }
            if(strcmp(o->filmname,q->filmname)==0)
            {
                p->next=q->next;
                free(q);
                n--;
            }
            break;
            case 7 :
            break;
        }
        system("cls");
    }
    else
    {
        printf("������������������������������������������������������������������������\n");
        printf("�� [!]��ʾ:�޸�ӰƬ����,����������! ��\n");
        printf("������������������������������������������������������������������������\n");
        getch();
        system("cls");
    }
    system("cls");
    printf("������������������������������������������������������������������������\n");
    printf("��       [!]��ʾ:ɾ�����!          ��\n");
	printf("��        ������������˵�...       ��\n");
    printf("������������������������������������������������������������������������\n");
    getch();
    system("cls");
}
