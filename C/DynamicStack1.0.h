#include<stdbool.h>
#include<stdlib.h>
#define maxsize 10
typedef int datatype;

//Sequence Stack 实现顺序栈，使用数组来实现
struct stack
{
    datatype *data;
    int top;
};

typedef struct stack Stack;
//创建栈

int realsize=maxsize;

// Stack s;
//初始化栈
void init(Stack *s)
{
    s->data = (datatype *)malloc(sizeof(datatype)*maxsize);
    s->top=-1;
}

//判断栈是否为空
bool Empty(Stack *s)
{
    if(s->top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断栈是否已满了
void full(Stack *s)
{
    if(s->top==realsize-1)
    {
        realsize++;
        s->data=(datatype *)realloc(s->data,realsize);
    }
}

//入栈
void Push(Stack *s,datatype element)
{
    full(s);
    s->top++;
    s->data[s->top]=element;
}

//出栈
void Pop(Stack *s)
{
    if(!Empty(s))
    {
        s->top--;
    }
    else
    {
        printf("栈空\n");
    }
}

//取栈顶元素
datatype Top(Stack *s)
{
    if(!Empty(s))
    {
        return s->data[s->top];
    }
    else
    {
        printf("栈空\n");
    }
}

//销毁栈
void Destroy(Stack *s)
{
    s->top=-1;
    // free(s.data); //容易导致失败
}