#include<stdio.h>
#include<stdlib.h>

typedef struct node *Node;

struct node
{
int data;
Node lLink;
Node rLink;
};


Node getNode()
{
    Node temp;
    temp = (Node)malloc(sizeof(struct node));
    return temp;
} 

int isEmpty(Node n)
{
    return (n==NULL?1:0);
}

Node insertEnd(Node n, int data)
{
    Node new,temp;
    new = getNode();
    new->data = data;
    new->link = NULL;
    if(n == NULL)
       n = new;
    else{
    temp = n;
    while(temp->link !=NULL)
          temp = temp->link;
    temp->link = new;
    }   
    return n; 
}

void display(Node n)
{
    Node temp = n;
    while(temp!=NULL)
    {printf("Previous Address = %p \t",temp->lLink);
        printf("Address = %p \t",temp);
    printf("Data = %d \t",temp->data);
    printf("Next Address = %p \t",temp->rLink);
    printf("\n");
    temp = temp->rLink;
    }
    printf("\n");
}

Node deleteBack(Node n)
{
Node temp = n;
temp = temp->link;
n = temp;
return n;
}

Node deleteFront(Node n)
{
Node temp,prev;
temp = n;
for(;temp->link != NULL; temp = temp->link)
{prev = temp;}
prev->link = NULL;
free(temp);
return n;
}

Node deleteSpecific(Node n, int p)
{
Node temp,prev;
temp = n;
for(int i=0; i<p-1;i++,temp = temp->link)
{prev = temp;}
prev->link = temp->link;
free(temp);
return n;
}

void main()
{
int pos;
Node root = NULL;
root = insertEnd(root,10);
root = insertEnd(root,20);
root = insertEnd(root,30);
root = insertEnd(root,40);
root = insertEnd(root,50);
display(root);
root = insertEnd(root,60);
root = deleteFront(root);
root = insertEnd(root,70);
display(root);
root = insertEnd(root,80);
root = deleteBack(root);
root = insertEnd(root,90);
display(root);
root = deleteSpecific(root,2);
display(root);
root = deleteSpecific(root,3);
display(root);
}