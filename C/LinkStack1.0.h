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

// Stack *s;
//初始化栈
Stack* init(Stack *s)
{
    s=NULL;
    return s;
}

//判断栈是否为空
bool Empty(Stack *s)
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
Stack* Push(Stack *s,datatype element)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data=element;
    p->next=s;
    s=p;             //这里指针只是副本，无法修改原来的指针，要么使用二级指针，要么返回这个指针
    return s;
}

//出栈
Stack* Pop(Stack *s)
{
    if(!Empty(s))
    {
        s=s->next;
    }
    else
    {
        printf("栈空\n");
    }
    return s;
}

//取栈顶元素
datatype Top(Stack *s)
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
Stack* Destroy(Stack *s)
{
    free(s);//因该销毁每一个元素
    s=NULL;
    return s;
    // free(s.data); //容易导致失败
}