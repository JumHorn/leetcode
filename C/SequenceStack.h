#include<stdbool.h>
#define maxsize 10
typedef int datatype;

//Sequence Stack 实现顺序栈，使用数组来实现
struct stack
{
    datatype data[maxsize];
    int top;
};

typedef struct stack Stack;
//创建栈

Stack s;
//初始化栈
void init()
{
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
bool full()
{
    if(s.top==maxsize-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//入栈
void Push(datatype element)
{
    if(!full())
    {
        s.top++;
        s.data[s.top]=element;
    }
    else
    {
        printf("栈满\n");
    }
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
}