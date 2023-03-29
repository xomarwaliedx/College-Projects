#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
typedef union
{
    float f;
    char c;
}item;

typedef struct
{
    char items[MAXSIZE];
    int top;
} stack;


stack*initialize()
{
    stack*s=malloc(sizeof(stack));
    s->top=0;
    return s;
}



void push(stack*s,char value)
{
    s->items[s->top]=value;
    s->top++;
}

char pop(stack*s)
{
    char value ;
    s->top--;
    value= s->items[s->top];
    return value;
}

int isEmpty(stack*s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}

int isFull(stack*s)
{
    if(s->top==MAXSIZE)
        return 1;
    else
        return 0;
}


char top(stack*s)
{
    return s->items[s->top-1];
}


//part 2
int isDigit(char n)
{
    if(n!='+' && n!='-' && n!='*' && n!='/' && n!='%' && n!='(' && n!=')')
        return 1;
    else
        return 0;
}

int priority(char c)
{
 switch(c)
 {
 case '*':
 case '/':
 case '%':
 return 1;
 case '+':
 case '-':
 return 0;
 case '(' :
 return 2;
 }
}

void infixTopostfix(char*infix, char*postfix)
{
    stack*s=initialize();


    char*tok=strtok(infix," ");
    int i=0;


    while (tok!=NULL)
    { //printf("%s\n",tok);



        if ((isDigit(tok[0]) ) || (tok[0]=='-' && strlen(tok)>1))
        {

            for(int j=0;j<strlen(tok);j++)
            {
                postfix[i]=tok[j];
                i++;
            }
            postfix[i]='\t';
            i++;

        }

         else if (tok[0]==')')
        {
            while (!isEmpty(s) && top(s)!='(')
            {
                postfix[i] = pop(s);
                postfix[i+1]='\t';
                i+=2;
            }
            pop(s);
        }



        else if(isEmpty(s))
        {
            push(s,tok[0]);

        }

       else
        {

            while(!isEmpty(s) && priority(top(s))>=priority(tok[0]) && top(s)!='(')
            {
                postfix[i] = pop(s);
                postfix[i+1]='\t';
                i+=2;
            }



            push(s,tok[0]);
        }



        tok=strtok(NULL," ");


    }

    while(!isEmpty(s))

    {
        postfix[i] = pop(s);
        postfix[i+1]='\t';
        i+=2;
    }


postfix[i]='\0';


}








int main()
{
    char infix[]="a + b * c / ( e - f )";
    char postfix[100];
    infixTopostfix(infix,postfix);
    printf("%s",postfix);
    return 0;
}
