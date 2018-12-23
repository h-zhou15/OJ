#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
	int data;
	int so;
	struct student *next;
}LinkList;

typedef struct Soi
{
	int si;
	int oi;
}LB;

LinkList *CreatList(int M,int *id)
{
	LinkList *head;
	
	LinkList *end = NULL;

	head = (LinkList*)malloc(sizeof(LinkList));
	
	end = head;
	head->next = NULL;

	for (int i = 0; i < M; i++)
	{
		LinkList *node = NULL;
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = *(id + i);

		end->next = node;				
		node->next = NULL;
		end = node;			   //使尾指针始终指向最后一个元素
	}
	return head;
}

void Insert_List(LinkList *head, int val)
{
	LinkList *p;
	p = head;
	
	for (p = p->next; p != NULL; p = p->next)
	{
		if (val < p->next->data || p->next == NULL)
		{
			LinkList *newnode = (LinkList*)malloc(sizeof(*newnode));
			newnode->data = val;
			newnode->next = p->next;
			p->next = newnode;
			break;
		}
	}
}

void DeleteList(LinkList *head, int val)
{
	LinkList *p;
	p = head;
	while (1)
	{
		if (p->next->data == val)
		{
			p->next = p->next->next;
			break;
		}
		else
		{
			p = p->next;
		}
	}

}

void  PrintList(LinkList *head)
{
	LinkList *p = head;

	for (p = p->next; p != NULL; p = p->next)
	{
		printf("%d\n", p->data);
	}
}



int main()
{
	int M;
	scanf_s("%d", &M);
	int *id = NULL;
	id = (int*)malloc(M * sizeof(*id));
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", id + i);
	}

	LinkList *LA = CreatList(M, id);
	//PrintList(LA);

	int N;
	scanf_s("%d", &N);
	LB *lb = (LB*)malloc(N * sizeof(*lb));
	
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d%d", &(lb[i].si), &(lb[i].oi));
		if (lb[i].oi)
		{
			Insert_List(LA, lb[i].si);
		}
		else
		{
			DeleteList(LA, lb[i].si);
		}
	}

	PrintList(LA);


	system("pause");
	return 0;
}