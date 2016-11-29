#include<stdlib.h>
#include<stdbool.h>
typedef int datatype;

//using Link list to implament queue
struct LinkList
{
	datatype data;
	struct LinkList * next;
};

struct queue
{
	struct LinkList *front;
	struct LinkList *rear;
};

typedef struct queue Queue;

//initialize the queue
void init(Queue *q)
{
	q->front=q->rear=NULL;
}

//if the queue is Empty
bool Empty(Queue *q)
{
	if(q->front==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//push to the queue
void Push(Queue *q,datatype	data)
{
	struct LinkList * p=(struct LinkList *)malloc(sizeof(struct LinkList));
	p->data=data;
	p->next=NULL;
	if(q->rear==NULL)  //当只有一个元素时，指向同一节点
	{
		q->front=q->rear=p;
	}
	else              //当有多个元素时，改变队尾指针
	{
		q->rear->next=p;
		q->rear=p;
	}
}

//pop from the queue
void Pop(Queue *q)
{
	if(!Empty(q))
	{
		q->front=q->front->next;
	}
	else
	{
		printf("队空\n");
	}
}

//get the element of the queue
datatype Top(Queue *q)
{
	if(!Empty(q))
	{
		return q->front->data;
	}
	else
	{
		printf("队空\n");
	}
}

//destroy the queue
void Destroy(Queue *q)
{
	free(q->front);
	free(q->rear);
	q->front=NULL;
	q->rear=NULL;
}