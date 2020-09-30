#include<stdio.h>
#include<stdlib.h>

typedef struct node *Node;

struct node
{
int data;
Node link;
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

void insert(Node *n, int data)
{
    Node temp;
    temp = getNode();
    temp->data = data;
    temp->link = NULL;
    (*n)->link = temp;
}

void display(Node n)
{
    Node temp;
    temp = n;
    temp = temp->link;
    while(temp!=NULL)
    {printf("%d \t",temp->data);
    temp = temp->link;
    }
}

Node deleteFront(Node n)
{
Node temp;
temp = n;
temp = temp->link;
n->link = temp->link;
free(temp);
return n;
}

void main()
{
Node root,last;
root=getNode();
last = root;
insert(&root,10);
insert(&root,20);
insert(&root,30);
insert(&root,40);
insert(&root,50);
insert(&root,60);
display(last);
}