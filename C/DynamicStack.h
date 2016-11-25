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

Stack s;
//初始化栈
void init()
{
    s.data = (datatype *)malloc(sizeof(datatype)*maxsize);
    s.top=-1;
}

//判断栈是否为空
bool Empty()
{
    if(s.top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断栈是否已满了
void full()
{
    if(s.top==realsize-1)
    {
        realsize++;
        s.data=(datatype *)realloc(s.data,realsize);
    }
}

//入栈
void Push(datatype element)
{
    full();
    s.top++;
    s.data[s.top]=element;
}

//出栈
void Pop()
{
    if(!Empty())
    {
        s.top--;
    }
    else
    {
        printf("栈空\n");
    }
}

//取栈顶元素
datatype Top()
{
    if(!Empty())
    {
        return s.data[s.top];
    }
    else
    {
        printf("栈空\n");
    }
}

//销毁栈
void Destroy()
{
    s.top=-1;
    free(s.data);
}