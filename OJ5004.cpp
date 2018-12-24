#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NUMBER
{
	int data;
	struct NUMBER *next;
}LinkList;

LinkList *CreatList(int M, char *id);
void Insert_List(LinkList *head, int val);
void DeleteList(LinkList *head, int val);
void Addtion(LinkList *head1, LinkList *head2);
void PrintList(LinkList *head);
void ReverseStr(char *str);

int main()
{
	char s1[101];
	char s2[101];
	gets_s(s1);
	gets_s(s2);
	ReverseStr(s1);
	ReverseStr(s2);

	LinkList *h1 = CreatList(strlen(s1), s1);
	LinkList *h2 = CreatList(strlen(s2), s2);

	Addtion(h1, h2);


	system("pause");
	return 0;
}

LinkList *CreatList(int M,char *id)
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
		node->data = *(id + i) - '0';

		//链表的顺序应该是从个位到最高位
		//数字的插入应该是先高后低
		
		end->next = node;
		node->next = NULL;
		end = node;			   //使尾指针始终指向最后一个元素
		
	}

//	PrintList(head);
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

int SizeofList(LinkList *head)
{
	int val = 0;
	LinkList *p = head;
	while (p->next != NULL)
	{
		val++;
		p = p->next;
	}
	return val;
}

void Addtion(LinkList *head1, LinkList *head2)
{
	LinkList *str1 = (LinkList*)malloc(sizeof(LinkList));
	LinkList *str2 = (LinkList*)malloc(sizeof(LinkList));
	
	if (SizeofList(head1) != SizeofList(head2))
	{
		bool first = 0;
		if (SizeofList(head1) > SizeofList(head2))
		{
			//str1表示长度较大的那位
			str1 = head1->next;
			str2 = head2->next;
			first = true;
		}
		else
		{
			str1 = head2->next;
			str2 = head1->next;
			first = false;
		}

		bool flag = 0;

		for (; str2 != NULL;)
		{
			int val = str1->data + str2->data + flag;
			if (val >= 10)
			{
				flag = true;		   //表示十进位
				str1->data = val % 10;
			}
			else
			{
				flag = false;
				str1->data = val % 10;
			}
			str1 = str1->next;
			str2 = str2->next;
			if (str2 == NULL)
			{
				str1->data = str1->data + flag;
			}

		}
		
		if (first)
			PrintList(head1);
		else
			PrintList(head2);
		return;
	}
	else
	{
		str1 = head1->next;
		str2 = head2->next;

		bool flag = 0;

		for (; str2 != NULL;)
		{
			int val = str1->data + str2->data + flag;
			if (val >= 10)
			{
				flag = true;
				str1->data = val % 10;
			}
			else
			{
				flag = false;
				str1->data = val % 10;
			}
			str1 = str1->next;
			str2 = str2->next;
			if (str1 == NULL && str2 == NULL)
			{
				if (flag)
				{
					LinkList *node = (LinkList*)malloc(sizeof(LinkList));
					node->data = flag;
					node = str1->next;
					node->next = NULL;
				}
			}
		}
		PrintList(head1);
		return;
	}

	
}

void  PrintList(LinkList *head)
{
	LinkList *p = head->next;

	char str[101] = { '\0' };

//	printf("\n");

	for (int i=0; p != NULL; p = p->next,i++)
	{
//		printf("%d", p->data);
		str[i] = (char)(p->data);
	}
//	printf("\nresult\n");
	for (int i = 0; i < strlen(str); i++)
	{
		printf("%d", str[strlen(str) - 1 - i]);
	}
}

void ReverseStr(char *str)
{
	char Nstr[100] = { '\0' };

	for (int i = 0; i < strlen(str); i++)
	{
		Nstr[i] = str[i];
	}

	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = Nstr[strlen(str) - 1 - i];
	}
	return;
}
