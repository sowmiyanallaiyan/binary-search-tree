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
struct node *delete1(struct node *T,int x)
{
    if(T==NULL)
    return NULL;
    if(x<T->data)
    T->left=delete1(T->left,x);
    else if(x>T->data)
    T->right=delete1(T->right,x);
    else
    {
        if((T->left==NULL)&&(T->right==NULL))
        return NULL;
         if((T->left==NULL)&&(T->right!=NULL))
        return (T->right);
         if((T->left!=NULL)&&(T->right==NULL))
        return (T->left);
        else
        {
            struct node *q;
            q=T->right;
            while(q->left!=NULL)
            {
                q=q->left;
                T->data=q->data;
                T->right=delete1(T->right,q->data);
            }
        }
    }
    return T;
}
void inorder(struct node *t1)
{
if(t1==NULL)
return;
else
{
inorder(t1->left);
printf("\t%d",t1->data);
inorder(t1->right);
}
}
void preorder(struct node *t1)
{
if(t1==NULL)
return;
else
{
printf("\t%d",t1->data);
preorder(t1->left);
preorder(t1->right);
}
}
void postorder(struct node *t1)
{
if(t1==NULL)
return;
else
{
postorder(t1->left);
postorder(t1->right);
printf("\t%d",t1->data);
}
}
int findmin(struct node *T)
{
    if(T==NULL)
    return -1;
    while(T->left!=NULL)
    T=T->left;
    return(T->data);
}
int findmax(struct node *T)
{
    if(T==NULL)
    return -1;
    while(T->right!=NULL)
    
        T=T->right;
        return (T->data);
}
int search(struct node *T,int x)
{
    if( T==NULL)
    return -1;
    else if(T->data==x)
    printf("\nThe given number is found");
    else if(x<T->data)
    return (search(T->left,x));
    else if(x>T->data)
    return (search(T->right,x));
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
preorder(root);
printf("\n");
inorder(root);
printf("\n");
postorder(root);
printf("\nthe minimum value is %d",findmin(root));
printf("\nthe maximum value is %d",findmax(root));
search(root,100);
delete1(root,52);
printf("\nbinary search tree after deletion\n");
inorder(root);
}

    







