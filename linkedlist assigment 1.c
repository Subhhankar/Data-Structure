#include<stdio.h>
#include<malloc.h>
struct node
{
	int  data;
	int key;
	struct node *next;

};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
int main()
{ 
         int option;
         do
         {
         	printf("\n\n *****MAIN MENU*****");
         	printf("\n 1: create a list");
         	printf("\n 2: Display the list");
         	printf("\n 3: Add a node at the beginning");
         	printf("\n 4: Add a node at the end ");
         	printf("\n 5:  Add a node before a given node");
            printf("\n 6: Add a node after a given node");
            scanf("%d", &option);
            switch(option)
            {
            	case 1:  start=create_ll(start);
                         printf("\n LINKED LIST CREATED");
						break;
				case 2:  start=display(start);
				         break;
				case 3:  start=insert_beg(start);
						 break;
				case 4: start=insert_end(start);
						break;
				case 5: start=insert_before(start);
						break;
				case 6: start=insert_after(start);
						break;
						
						     		         		
			}
            
		 }
		 while(option !=7);
		 return 0;
}
struct node *create_ll(struct node *start)
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
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			        ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;        
		}
		printf("\n Enter the data : ");
		scanf("%d", &num);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr !=NULL)
	{
		printf("\t %d", ptr->data);
		ptr=ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num ;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next !=NULL)
            ptr=ptr->next;
	ptr->next=new_node;
	return start;			
}
 struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value before which the data has to be inserted: ");
	scanf("%d", &val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data !=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted: ");
	scanf("%d", &val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data !=val)	
{
           preptr=ptr;
           ptr=ptr->next;
}
preptr->next=new_node;
new_node->next=ptr;
return start;
}


