//============================================================================
// Name        : setup.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

int Setup();

int Setup()
{
    int bar=0,i,j,m=1,n=1,u=1;
    char tempid[20],tempass[20];
    user *p;
    while(bar<=95)
    {
        bar+=5;
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        printf("����   ��ӭʹ��ӰԺ��Ϣ����ϵͳ   ����\n");
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        printf("����                              ����\n");
        printf("����                              ����\n");
        printf("����            %4d%c             ����\n",bar,37);
        printf("����                              ����\n");
        printf("����                              ����\n");
        printf("����                              ����\n");
        printf("����");
        for(i=0;i<bar/3-3;i++)
        {
            printf(">");
        }
        for(j=0;j<30-i;j++)
        {
            printf(" ");
        }
        printf("����\n");
        printf("����                              ����\n");
        printf("����                              ����\n");
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        Sleep(50);
        system("cls");
    }
    while(1)
    {
        flag:
        line=8;
        system("cls");
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        printf("����   ��ӭʹ��ӰԺ��Ϣ����ϵͳ   ����\n");
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        printf("����                              ����\n");
        printf("����   ������������������������   ����\n");
        printf("����   �� [1]----��¼        ��   ����\n");
        printf("����   �� [2]----ע��        ��   ����\n");
        printf("����   �� [3]----��������    ��   ����\n");
        printf("����   �� [4]----ע��        ��   ����\n");
        printf("����   �� [0]----�˳�        ��   ����\n");
        printf("����   ������������������������   ����\n");
        printf("����                              ����\n");
        printf("��������������������������������������\n");
        printf("��������������������������������������\n");
        Position(10,line);
        printf(">");
        while((ch=getch())!=0x0d)
        {
            while(ch==0x48)
            {
                if(line==8)
                {
                    break;
                }
                else
                {
                    Position(10,line);
                    printf(" ");
                    line--;
                    Position(10,line);
                    printf(">");
                    break;
                }
            }
            while(ch==0x50)
            {
                if(line==12)
                {
                    break;
                }
                else
                {
                    Position(10,line);
                    printf(" ");
                    line++;
                    Position(10,line);
                    printf(">");
                    break;
                }
            }
        }
        switch(line)
        {
            case 8 :
            m=Login();
            if(m>0)
            {
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��             ��¼�ɹ�!            ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
                goto menu;
            }else{
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��             ��¼ʧ��!            ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
                goto flag;
            }
            case 9 :
            n=Register();
            if(n)
            {
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��             ע��ɹ�!            ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
            }else{
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��             ע��ʧ��!            ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
            }
            goto flag;
            case 10 :
            u=Forget();
            if(u){
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��           �޸�����ɹ�!          ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
            }else{
                Position(1,9);
                printf("���ة������������������������������ة�\n");
                printf("��           �޸�����ʧ��!          ��\n");
                printf("���Щ������������������������������Щ�\n");
                Sleep(200);
            }
            goto flag;
            case 11 :
                return 0;
            case 12 :
            system("cls");
            printf("���Щ���������������������������������\n");
            printf("���੤��������������������������������\n");
            printf("����   ��лʹ��ӰԺ��Ϣ����ϵͳ!  ����\n");
            printf("�������������������������������������\n");
            printf("�����������������������������������ة�\n");
            Sleep(200);
            exit(0);
        }

    }
    menu:
    system("cls");
    return m;
}
