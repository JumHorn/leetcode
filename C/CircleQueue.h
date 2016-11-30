#include<stdbool.h>
#define maxsize 10
typedef int datatype;

//定义队的结构体
struct queue
{
    datatype data[maxsize];
    int front;
    int rear;
};

typedef struct queue Queue;

//初始化队
void init(Queue *q)
{
    q->front=q->rear=0;
}

//判断是否为空
//这里有两种方法
//先实现牺牲一个存储空间的方法，即rear始终指向空
bool Empty(Queue *q)
{
    if(q->front==q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断是否满
bool full(Queue *q)
{
    if((q->rear+1)%maxsize==q->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//入队
void Push(Queue *q,datatype element)
{
    if(!full(q))
    {
        q->data[q->rear]=element;
        q->rear=(q->rear+1)%maxsize;
    }
    else
    {
        printf("队满！\n");
    }
}

//出队
void Pop(Queue *q)
{
    if(!Empty(q))
    {
        q->front=(q->front+1)%maxsize;
    }
    else
    {
        printf("队空\n");
    }
}

//取队顶元素
datatype Top(Queue *q)
{
    if(!Empty(q))
    {
        return q->data[q->front];
    }
    else
    {
        printf("队空\n");
    }
}