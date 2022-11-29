#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_end(struct node *);
int main()
{
	int option;
	do
	{
		printf("\n\n *****MAIN MENU*****");
	    printf("\n 1: Create list");
	    printf("\n 2: Display the list");
	    printf("\n 3: Add a node at the beginning");
	    printf("\n 4: Delete a node from the end");
	    printf("\n 5: EXIT");
	    printf("\n\n Enter your option: ");
	    scanf("%d", &option);
	    switch(option)
	    {
	    	case 1: start=create_cll(start);
	                printf("\n CIRCULER LINKED LIST CREATED");
					break;    	
			case 2: start=display(start);
			        break;
			case 3: start=insert_beg(start);
			        break;
			case 4: start=delete_end(start);
			        break;
		}
	}
	while(option !=9);
	return 0;
}
struct node *create_cll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next !=start)
			          ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;           
			
		}
		printf("\n Enter the data: ");
		scanf("%d", &num);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next !=start)\
	{
		printf("\t %d", ptr->data);
		ptr=ptr->next;
	}
	printf("\t %d", ptr->data);
		return start;
	}
	struct node *insert_beg(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n enter the data: ");
	scanf("%d", &num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next !=start)
	        ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=start;
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next !=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
