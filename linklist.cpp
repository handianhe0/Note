//链表实例
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Node
{
    int a;
    struct Node *next;
}node;    //结点定义

//创建链表
struct Node *Create(unsigned int Size)
{
    struct Node *pHead=NULL;  //头结点
    struct Node *pOne=NULL;   
    struct Node *pPrevOne=NULL;
    pOne=(struct Node*)malloc(sizeof(struct Node));  //为结点分配空间
    pOne->next=NULL;
    pPrevOne=pHead=pOne;
    //结点指针域指向下一个结点地址
    for(int i=0;i<Size;i++)
    {
        pPrevOne=pOne;
        pOne=(struct Node*)malloc(sizeof(struct Node));
        pPrevOne->next=pOne;
        pOne->next=NULL;
    }
    return pHead;
}

void RemoveAll(struct Node *list)
{
    node *pPrevOne=NULL,*pOne=NULL;
    pOne=list;
    while(pOne->next!=NULL)
    {
        pPrevOne=pOne;
        pOne=pOne->next;
        free(pPrevOne);
    }
}

int main(int argc,char*argv[])
{
    Node *linklistpHead,*iter;
    int size;
    cout<<"请输入链表长度：";
    cin>>size;
    cout<<"请依次输入链表的值：";
    linklistpHead=Create(size);
    iter=linklistpHead;
    for(int i=0;i<size;i++)
    {
        cin>>iter->a;
        iter=iter->next;
    }
    cout<<"链表中的元素值为:";
    iter=linklistpHead;
    for(int i=0;i<size;i++)
    {
        cout<<iter->a<<setw(5);
        iter=iter->next;
    }
    RemoveAll(linklistpHead);
    return 0;
}