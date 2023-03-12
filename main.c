#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

void creatlist(list *l,int c)
{
    while(c--)
    {
        scanf("%d",&(l->data));
        if(c!=0)
        {
            l->next=(list *)malloc(sizeof(list));
            l=l->next;
        }
        else
        {
            l->next=NULL;
        }
    }
}

void insertlist(list *l,int num,int loc)
{
    list *new=(list *)malloc(sizeof(list));
    new->data=num;
    if(loc==1)
    {
        new->next=l;
    }
    else
    {
        while(--loc-1)
        {
            l=l->next;
        }

        new->next=l->next;
        l->next=new;
    }
}
void  dellist(list *l,int num)
{
    list *q=l,*p=l->next;
    while(p)
    {
        if(p->data==num)
        {
            q->next=p->next;
            free(p);
            break;
        }
        q=q->next;
        p=p->next;
    }

}
int lenlist(list *l)
{
    int count=0;
    while(l)
    {
        count++;
        l=l->next;
    }
    return count;
}
void findlist(list *l,int num)
{
    int yes=0;
    while(l)
    {
        if(l->data==num)
            yes=1;
        l=l->next;
    }
    if(yes)
    {
        printf("˳���la���в���Ԫ��%d\n",num);
    }
    else
    {
        printf("˳���la��û�в���Ԫ��%d\n",num);
    }

}
void find(list *l,int loc)
{

    while(loc--)
    {
        if(loc==0)
            printf("Ҫ��ȡ�ĵ�5��Ԫ��Ϊ%d\n",l->data);
        l=l->next;
    }
}
void print(list *l)
{
    while(l->next)
    {
        printf("%d ",l->data);
        l=l->next;
    }
    printf("%d\n",l->data);
}

int main()
{
    list *head=(list *)malloc(sizeof(list));
    int c,num,loc;
    scanf("%d",&c);
    creatlist(head,c);
    printf("˳���la:");
    print(head);
    scanf("%d%d",&num,&loc);
    insertlist(head,num,loc);
    printf("�������Ԫ�غ��˳���la:");
    print(head);
    printf("ɾ��Ԫ�ص�ֵΪ%d\n",num);
    dellist(head,num);
    printf("ɾ��Ԫ�غ��la:",num);
    print(head);
    printf("˳���ĳ���:%d\n",lenlist(head));
    scanf("%d",&num);
    findlist(head,num);
    scanf("%d",&loc);
    find(head,loc);
    printf("˳���la�Ѿ����\n˳���la�ĳ���Ϊ0\n˳���la������\n");
}

