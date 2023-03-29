#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char*data;
    struct node*left;
    struct node*right;
} node;

node * newNode(char*word)
{
    node*n=malloc(sizeof(node));
    n->data=malloc(sizeof(word));
    n->data=word;
    n->left=NULL;
    n->right=NULL;
    return n;
}

node* insert(node* node, char*word)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(word);

    if (strcasecmp(word,node->data)<0)
        node->left = insert(node->left, word);
    else if (strcasecmp(word,node->data)>0)
        node->right = insert(node->right, word);

    return node;
}


node* search( node *t, char*word)
{
    node*temp=t;
    node*leaf=NULL;
    node*succ=NULL;
    node*pred=NULL;
    while (temp!=NULL)
    {
        if (strcasecmp(word,temp->data)==0)
            return t;
        else if (strcasecmp(word,temp->data)<0)
        {
            if(temp->left!=NULL)
                succ=temp;
            leaf=temp;

            temp =temp->left;
        }
        else
        {
            leaf=temp;
            if(temp->right!=NULL)
                pred=temp;
            temp = temp->right;
        }
    }
    printf("suggestion1: %s\n",leaf->data);
    printf("successor:%s \n",succ->data);
    printf("pred:%s \n",pred->data);
    return NULL;
}
void correction(node*root, char*str)
{
    char*token=strtok(str," ");
    while(token!=NULL)
    {
        printf("%s\n",token);
        node*result=search(root,token);
        if(result!=NULL)
            printf("%s: word is correct!\n",token);
        token=strtok(NULL," ");
    }
}

int max(int a, int b)
{
    return a>b?a:b;
}
int height(node *root)
{
    if ( root == NULL)
        return -1;
    else
        return 1 + max(height(root->left),
                       height(root->right));
}

int count(node *root)
{
    if ( root == NULL)
        return 0;
    else
        return 1 + count (root->left) + count
               (root->right);
}
node*load(char*filename)
{
    FILE*f=fopen(filename,"r");
    if(!f)
        printf("File not found\n");
    printf("Dictionary Loaded Successfully...!\n");
    char *temp=malloc(100);
    fscanf(f,"%s",temp);
    node*root=newNode(temp);

    while(!feof(f))
    {
        char *temp2=malloc(100);

        fscanf(f,"%s",temp2);
        root=insert(root,temp2);
    }




    fclose(f);
    return root;
}

int main()
{
 char file[40],input[100];
 printf("Enter file name:\n");
 gets(file);
 node* n=load(file);
 printf("Enter sentence:\n");
 gets(input);
 correction(n,input);
    return 0;
}
