//============================================================================
// Name        : userdelete.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void UserDelete(user *p);

void UserDelete(user *p)
{
    int i;
    int len;
    int choose;
    user *o,*q;
    o=UserQuery(p);
    if(o!=NULL)
    {
        line=5;
        system("cls");
        printf("������������������������������������������������������������������������\n");
        printf("��           ɾ���û���Ϣ           ��\n");
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
            while(q->next!=NULL&&(strcmp(o->id,q->id)!=0)&&(strcmp(o->password,q->password)!=0))
            {
                p=p->next;
                q=p->next;
            }
            if((strcmp(o->id,q->id)==0)&&(strcmp(o->password,q->password)==0))
            {
                p->next=q->next;
                free(q);
                m--;
            }
            if(q->next->power==3)
            {
                break;
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
        printf("�� [!]��ʾ:�޸��û�����,����������! ��\n");
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
