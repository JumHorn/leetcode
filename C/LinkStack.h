#include<stdbool.h>
#include<stdlib.h>
// #define maxsize 10
typedef int datatype;

//Link Stack 实现顺序栈，使用链表来实现

// struct LinkList
// {
//     datatype data;
//     struct LinkList *next;
// };

struct stack
{
    datatype data;
    struct stack *next;
};

typedef struct stack Stack;
//创建栈
Stack *s;
//初始化栈
void init()
{
    s=NULL;
}

//判断栈是否为空
bool Empty()
{
    if(s==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断栈是否已满了
// void full(Stack *s)
// {
//     if(s->top==realsize-1)
//     {
//         realsize++;
//         s->data=(datatype *)realloc(s->data,realsize);
//     }
// }

//入栈
void Push(datatype element)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data=element;
    p->next=s;
    s=p;             
}

//出栈
void Pop()
{
    if(!Empty(s))
    {
        s=s->next;
    }
    else
    {
        printf("栈空\n");
    }
}

//取栈顶元素
datatype Top()
{
    if(!Empty(s))
    {
        return s->data;
    }
    else
    {
        printf("栈空\n");
    }
}

//销毁栈
void Destroy()
{
    free(s);//因该销毁每一个元素
    s=NULL;
    // free(s.data); //容易导致失败
}