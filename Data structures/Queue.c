#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 1000
#include <string.h>
/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 */
typedef struct
{
    char *name;
    int starting_time;
    int remaining_time;
} Process;
/*
 *
 */
typedef struct Node
{
    Process data;
    struct Node* next;
} Node;
/*
 *
 */
typedef struct
{
    Node* rear;
    Node* front;
    int numberofitems;
    /* TODO: ADD YOUR CODE HERE */
} Queue;
/*
 *
 */
Queue* init()
{
    Queue *q = malloc(sizeof(Queue));
    q->rear=NULL;
    q->front=NULL;
    q->numberofitems=0;
    return q;
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
int isEmpty(Queue *q)
{
    if(q->numberofitems==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    /* TODO: ADD YOUR CODE HERE */

}
/*
 *
 */
Process dequeue(Queue *q)
{
    /* TODO: ADD YOUR CODE HERE */
    Process p;
    if(q->numberofitems>0)
    {
        p=q->front->data;
        Node* n=q->front->next;
        free(q->front);
        q->front=n;
        q->numberofitems=q->numberofitems-1;
    }
    else
    {
        p.name=NULL;
        p.remaining_time=0;
        p.starting_time=0;
    }
    return p;
}
/*
 *
 */
void enqueue(Queue *q, Process x)
{
    if(q->numberofitems==0)
    {
        Node *n=malloc(sizeof(Node));
        n->data=x;
        q->front=n;
        q->rear=n;
        q->numberofitems=1;
    }
    else
    {
        Node *n=malloc(sizeof(Node));
        n->data=x;
        q->rear->next=n;
        q->numberofitems=q->numberofitems+1;
        q->rear=n;
    }

    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
void destroy(Queue *q)
{
    while(q->numberofitems>0)
    {
        dequeue(q);
    }
    free(q);
    /* TODO: ADD YOUR CODE HERE */
}
/*
 * RoundRobin Scheduling
 */
void RoundRobin(char* filename)
{
    FILE *fp;
    int i,j;
    char str[MAXCHAR];
    Process proc[100];
    for(int t=0; t<100; t++)
    {
        proc[t].name=(char*)malloc(sizeof(char)*MAXCHAR);
    }
    char* s;
    int counter=0;
    int timeslots;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s",filename);
    }
    int newLine = 0;
    while (!feof(fp))
    {
        if (newLine==0)
        {
            fgets(str, MAXCHAR, fp);
            s =strtok(str," ");
            for(int i=0; i<4; i++)
            {
                s =strtok(NULL," ");
            }
            timeslots=atoi(s);
            newLine++;
        }
        else
        {
            fscanf(fp,"%s %d %d",proc[counter].name,&proc[counter].starting_time,&proc[counter].remaining_time);

            counter++;
        }
    }
    Queue* q=init();

    for(i=0; i<timeslots; i++)
    {
        for(j=0; j<counter; j++)
        {
            if (proc[j].starting_time == i && proc[j].remaining_time > 0)
            {
                enqueue(q,proc[j]);
//printf("\n1\n");
            }
//printf("\n2\n");
        }
        Process pp;
        if(!isEmpty(q))
        {
//printf("\n3\n");
        pp=dequeue(q);

            if(pp.remaining_time>0)
            {
//printf("\n4\n");
                pp.remaining_time--;
                if(pp.remaining_time>0)
                {
//printf("\n5\n");
                    enqueue(q,pp);
                }
            }
            else
            {
//printf("\n6\n");

                pp.remaining_time=0;
            }
            printf("%s (%d-->%d) ",pp.name,i,i+1);
            if(pp.remaining_time==0)
            {
//printf("\n7\n");
                printf("%s abort\n",pp.name);
            }
            else
            {
//printf("\n8\n");
                printf("\n");
            }
        }
        else
        {
            printf("idle (%d-->%d)\n",i,i+1);
        }

    }
    printf("stop\n");
    fclose(fp);
    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
int main()
{
    char filename[261];
    puts("Enter file name or Ctrl+Z to exit:");
    puts("----------------------------------");
    while(fgets(filename, 260, stdin) != NULL)
    {
        filename[strlen(filename)-1]='\0';
        if(fopen(filename,"r"))
            RoundRobin(filename);
        else
        {
            puts("File Not Found!");
            puts("----------------------------------");
        }
        puts("Enter file name or Ctrl+Z to exit:");
        puts("----------------------------------");
    }

    return 0;
}
