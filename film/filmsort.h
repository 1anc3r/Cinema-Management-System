//============================================================================
// Name        : filmsort.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

/*
typedef struct film//��Ӱ
{
    char filmname[40];//��Ӱ�� %s
    double score;//���� %3.2lf
    int length;//Ƭ�� %d
    double fare;//Ʊ�� %6.2lf
    struct date *premiere;//��ӳ
}film;
*/

film *FilmSort(film *p);

film *FilmSort(film *p)
{
    int choose;
    film *post,*card,*temp,*i,*j;
    if(n!=0)
    {
        line=4;
        system("cls");
        printf("������������������������������������������������������������������������\n");
        printf("��           ����ӰƬ��Ϣ           ��\n");
        printf("������������������������������������������������������������������������\n");
        printf("��           [1]-----Ƭ��           ��\n");
        printf("��           [2]-----����           ��\n");
        printf("��           [3]-----Ƭ��           ��\n");
        printf("��           [4]-----Ʊ��           ��\n");
        printf("��           [0]-----ȡ��           ��\n");
        printf("������������������������������������������������������������������������\n");
        choose=Cursor(4,8,11,25,8,1);
        system("cls");
        post=(film*)malloc(sizeof(film));
        post->next=p;
        card=post;
        while(card->next->next!=NULL)
        {
            for(i=card,j=card->next;j->next!=NULL;j=j->next)
            {
                switch(line)
                {
                    case 4 :
                    if((j->next->filmname[0])<(i->next->filmname[0])) i=j;
                    break;
                    case 5 :
                    if((j->next->score)<(i->next->score)) i=j;
                    break;
                    case 6 :
                    if((j->next->length)<(i->next->length)) i=j;
                    break;
                    case 7 :
                    if((j->next->fare)<(i->next->fare)) i=j;
                    break;
                    case 8 :
                    goto flag;
                }
            }
            if(i!=j)
            {
                temp=i->next;
                i->next=temp->next;
                temp->next=card->next;
                card->next=temp;
            }
            card=card->next;
        }
        p=post->next;
        free(post);
        return p;
    }
    else
    {
        printf("������������������������������������������������������������������������\n");
        printf("��  [!]��ʾ:��ӰƬ����,����������!  ��\n");
        printf("������������������������������������������������������������������������\n");
    }
    getch();
    system("cls");
    flag:
    return p;
}
