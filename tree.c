#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *create(int x,struct node *L,struct node *R)
{
struct node *t1;
t1=(struct node*)malloc(sizeof(struct node));
t1->data=x;
t1->left=L;
t1->right=R;
return t1;
}
struct node *insert(int x,struct node *T)
{
if(T==NULL)
return create(x,NULL,NULL);
else if(x<T->data)
T->left=insert(x,T->left);
else
T->right=insert(x,T->right);
return T;
}
void main()
{
struct node *root=NULL;
root=insert(52,root);
root=insert(38,root);
root=insert (40,root);
root=insert(100,root);
root=insert(99,root);
root=insert(5,root);
}

    







