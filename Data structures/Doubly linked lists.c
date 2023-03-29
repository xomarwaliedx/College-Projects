#include <stdio.h>
#include <stdlib.h>
/*
 *
 */
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
/*
 *
 */
typedef struct
{
    Node* head;
    Node* tail;
} DoublyLinkedList;
/*
 *
 */

DoublyLinkedList* init()
{
    DoublyLinkedList *list =malloc(sizeof(DoublyLinkedList));
    list->head=NULL;
    list->tail=NULL;
    return list;
}

Node* newNode(int x)
{
    Node * n =malloc(sizeof(Node));
    n->data=x;
    n->next=NULL;
    n->prev=NULL;
    return n;
}
/*
 * convertArrayToDoublyLinkedList
 */
DoublyLinkedList* convertArrayToDoublyLinkedList(int array[], int size)
{
    DoublyLinkedList *list = init();
    Node*n=newNode(array[0]);
    list->head=n;
    list->tail=n;
    for(int i=1; i<size; i++)
    {
        Node*n=newNode(array[i]);
        list->tail->next=n;
        n->prev=list->tail;
        list->tail=n;
    }


    return list;
}
/*
 * destroy
 */
void destroy(DoublyLinkedList* list)
{


    while(list->tail!=list->head)
    {
        Node*temp=list->tail;

        Node*prev=list->tail->prev;
        prev->next=NULL;
        list->tail=prev;

        free(temp);

    }

    free(list->head);
    list->head=NULL;
    list->tail=NULL;


}
/*
 * copy: copy list into a new list and return the new one.
 */
DoublyLinkedList* copy(DoublyLinkedList* list)
{
    DoublyLinkedList *newlist = init();
    if(list->head==NULL)
    {
        return newlist;
    }
    newlist->head=newNode(list->head->data);
    newlist->tail=newlist->head;
    //printf("\n%d %d",newlist->head->data,newlist->tail->data);
    Node*move=list->head->next;

    while(move!=NULL)
    {
        newlist->tail->next=newNode(move->data);

        Node*n=newlist->tail->next;
        n->prev=newlist->tail;
        newlist->tail=n;
        move=move->next;

    }
//printf("\n%d %d %d",newlist->head->data,newlist->head->next->data,newlist->tail->data);
    return newlist;
}
/*
 * concatenate: concatenates the second list to the first one
 */
void concatenate(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
    if(list1->head==NULL)
        list1=copy(list2);
    else if(list2->head==NULL)
        return;
    else
    {
        list1->tail->next=list2->head;
        list2->head->prev=list1->tail;
        list1->tail=list2->tail;
    }
}
/*
 * getDifferenceBetweenLists: get all elements in the first list that don't exist in  the second one.
 */
DoublyLinkedList* getDifferenceBetweenLists(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
    DoublyLinkedList *newlist = init();
    Node* temp1=list1->head;
    Node* temp2=list2->head;
    int d;
    while(temp1&&temp2)
    {
        if(temp1->data==temp2->data)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else
        {
            d=temp1->data;
            temp1=temp1->next;
            if(newlist->head==NULL)
            {
                Node* n=malloc(sizeof(Node));
                n->data=d;
                newlist->head=n;
                newlist->tail=n;
            }
            else
            {
                Node* n=malloc(sizeof(Node));
                n->data=d;
                newlist->tail->next=n;
                n->next=NULL;
                n->prev=newlist->tail;
                newlist->tail=n;
            }
        }
    }
    /* TODO: ADD YOUR CODE HERE */
    return newlist;
}
/*
 * length: count the number of items stored in the list
 */
size_t length(DoublyLinkedList*  list)
{
    size_t count = 0;
    Node*temp=list->head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
/*
 * checkSumofFirstHalfEqualSumOfSecondHalf: check  if sum of first n/2 elements equals sum of the last n/2 elements.
 */

int checkSumofFirstHalfEqualSumOfSecondHalf(DoublyLinkedList*  list)
{
    if(length(list)%2!=0)
        return 0;
    int sum1=0;
    int sum2=0;
    Node*firstHalf=list->head;
    Node*secondHalf=list->tail;
    int i=length(list)/2;
    for(int j=0; j<i; j++)
    {
        sum1+=firstHalf->data;
        sum2+=secondHalf->data;
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->prev;

    }
    if(sum1==sum2)
        return 1;
    else return 0;
}

/*
 * isPalindrome: returns 1 if list is palindrome
 *               returns 0 if list is not palindrome
 *               a palindrome prints forwards as backwards
 *               e.g., 1 2 3 2 1
 *               e.g., 1 2 3 3 2 1
 */
int isPalindrome(DoublyLinkedList * list)
{
    Node*begining=list->head;
    Node*end=list->tail;
    while(begining!=end)
    {
        if(begining->data!=end->data)
            return 0;
        begining=begining->next;
        end=end->prev;

    }

    /* TODO: ADD YOUR CODE HERE */
    return 1;
}
/*
 * areEqual: returns 1 if both lists contain same elements
 *               returns 0 otherwise
 */
int areEqual(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
    Node*temp1=list1->head;
    Node*temp2=list2->head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            return 0;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL || temp2!=NULL)
        return 0;
    return 1;
}
/*
 * printlnListForward: prints the list {1, 3, 5, 7} as 1 3 5 7
 *                    prints end of line at the end
 */
void printlnListForward(DoublyLinkedList * list)
{
    Node* temp=list->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
/*
 * printlnListBackward: prints the list {1, 3, 5, 7} as 7 5 3 1
 *                    prints end of line at the end
 */
void printlnListBackward(DoublyLinkedList * list)
{
    Node* temp=list->tail;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
/*
 *
 */
void Investigate(char* title, DoublyLinkedList * list)
{
    printf("%s\n", title);
    printf("List =         ");
    printlnListForward(list);
    printf("Reverse List = ");
    printlnListBackward(list);
    printf("List Length = %u\n", length(list));
    printf("List isPalindrome = %d\n", isPalindrome(list));
    printf("...................................................\n");
}
/*
 *
 */
void testConcatenate1(DoublyLinkedList *list1)
{
    puts("\nSTART testConcatenate1\n");
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList* list3,*emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(list3, emptyList1);
    Investigate("List3<->EmptyList1\n==========================", list3);
    destroy(list3);
    Investigate("List3 (after destroy)\n=====================", list3);
    destroy(emptyList1);
    puts("\nEND testConcatenate1\n");
}
/*
 *
 */
void testConcatenate2(DoublyLinkedList * list1)
{
    puts("\nSTART testConcatenate2\n");
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList * list3, * emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(emptyList1, list3);
    Investigate("EmptyList1<->List3\n==========================", emptyList1);
    destroy(emptyList1);
    Investigate("EmptyList1 (after destroy)\n=====================", emptyList1);
    puts("\nEND testConcatenate2\n");

}
/*
 *
 */
void testConcatenate3(DoublyLinkedList *list1, DoublyLinkedList *list2)
{
    puts("\nSTART testConcatenate3\n");
    DoublyLinkedList* list3, *list4,* emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    list4 = copy(list2);
    Investigate("list4 = copy(List2)\n==================", list4);
    concatenate(list3, list4);
    Investigate("List3<->List4\n=====================", list3);
    destroy(list3);
    Investigate("list3 (after destroy)\n=====================", list3);
    puts("\nEND testConcatenate3\n");

}
/*
 *
 */
void testConcatenate()
{
    int array1[] = {0, 1, 2, 3, 4, 5, 6};
    int array2[] = {7, 8, 9};

    DoublyLinkedList *list1 = convertArrayToDoublyLinkedList(array1, sizeof(array1)/sizeof(*array1));
    Investigate("List1\n=====", list1);
    DoublyLinkedList *list2 = convertArrayToDoublyLinkedList(array2, sizeof(array2)/sizeof(*array2));
    Investigate("List2\n=====", list2);

    testConcatenate1(list1);
    testConcatenate2(list1);
    testConcatenate3(list1, list2);

    destroy(list1);
    destroy(list2);
}
/*
 *
 */
void testPalindrome()
{
    puts("\nSTART testPalindrome\n");
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array4[] = {7, 8, 9, 9, 8, 7};

    DoublyLinkedList* list5 = convertArrayToDoublyLinkedList(array3, sizeof(array3)/sizeof(*array3));
    Investigate("List5\n=====", list5);
    DoublyLinkedList *list6 = convertArrayToDoublyLinkedList(array4, sizeof(array4)/sizeof(*array4));
    Investigate("List6\n=====", list6);

    destroy(list5);
    destroy(list6);
    puts("\nEND testPalindrome\n");

}
/*
 *
 */
void testAreEqual()
{
    puts("\nSTART testAreEqual\n");
    int array7[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array8[] = {7, 8, 9, 9, 8, 7};
    int array9[] = {0, 1, 2, 3, 4, 5};
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList *list7 = convertArrayToDoublyLinkedList(array7, sizeof(array7)/sizeof(*array7));
    Investigate("List7\n=====", list7);
    DoublyLinkedList *list8 = convertArrayToDoublyLinkedList(array8, sizeof(array8)/sizeof(*array8));
    Investigate("List8\n=====", list8);
    DoublyLinkedList *list9 = convertArrayToDoublyLinkedList(array9, sizeof(array9)/sizeof(*array9));
    Investigate("List9\n=====", list9);
    DoublyLinkedList *emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", emptyList1);
    DoublyLinkedList *emptyList2 = copy(EmptyList);
    Investigate("EmptyList2 = copy(EmptyList)\n===========================", emptyList2);

    printf("areEqual(list7, list7) = %d\n", areEqual(list7, list7));
    printf("areEqual(list7, list8) = %d\n", areEqual(list7, list8));
    printf("areEqual(list7, list9) = %d\n", areEqual(list7, list9));
    printf("areEqual(list8, list7) = %d\n", areEqual(list8, list7));
    printf("areEqual(list7, EmptyList1) = %d\n", areEqual(list7, emptyList1));
    printf("areEqual(EmptyList1, list7) = %d\n", areEqual(emptyList1, list7));
    printf("areEqual(EmptyList1, EmptyList2) = %d\n", areEqual(emptyList1, emptyList2));

    destroy(list7);
    destroy(list8);
    destroy(list9);
    puts("\nEND testAreEqual\n");

}
/*
 *
 */
void testDifference()
{
    puts("\nSTART testDifference\n");
    int array10[] = {2, 4, 8, 9, 13, 17,20};
    int array11[] = {2, 8, 17,20};
    DoublyLinkedList *list10 = convertArrayToDoublyLinkedList(array10, sizeof(array10)/sizeof(*array10));
    Investigate("list10\n=====", list10);
    DoublyLinkedList *list11 =convertArrayToDoublyLinkedList(array11, sizeof(array11)/sizeof(*array11));
    Investigate("List11\n=====", list11);
    DoublyLinkedList *list12 = getDifferenceBetweenLists(list10,list11);
    Investigate("list12\n=====", list12);
    destroy(list10);
    destroy(list11);
    destroy(list12);
    puts("\nEND testDifference\n");

}
void testSum()
{
    puts("\nSTART testSum\n");
    int array5[] = {12, 4, 8, 9, 13, 2};
    int array6[] = {2, 18, 17,4};
    int array7[]= {2,3,4};
    DoublyLinkedList *list13 = convertArrayToDoublyLinkedList(array5, sizeof(array5)/sizeof(*array5));
    Investigate("list13\n=====", list13);
    DoublyLinkedList *list14 =convertArrayToDoublyLinkedList(array6, sizeof(array6)/sizeof(*array6));
    Investigate("list14\n=====", list14);
    DoublyLinkedList *list15 =convertArrayToDoublyLinkedList(array7, sizeof(array7)/sizeof(*array7));
    Investigate("list15\n=====", list15);
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list13) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list13));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list14) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list14));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list15) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list15));

    destroy(list13);
    destroy(list14);
    destroy(list15);
    puts("\nEND testSum\n");
}
int main()
{
    testConcatenate();
    testPalindrome();
    testAreEqual();
    testDifference();
    testSum();
//    int arr[1];
//    arr[0]=1;
//
//    DoublyLinkedList*l=convertArrayToDoublyLinkedList(arr,1);
//    printf("%d %d %d\n",l->head->data,l->head->next->data,l->tail->data);
//    printf("%d",length(l));
//    int arr2[1];
//
//    arr2[0]=5;
//    DoublyLinkedList*l2=convertArrayToDoublyLinkedList(arr2,1);
//    printf("%d\n",checkSumofFirstHalfEqualSumOfSecondHalf(l2));
//    concatenate(l,l2);
//    printf("%d\n",checkSumofFirstHalfEqualSumOfSecondHalf(l));
//    printlnListForward(l);
//    printlnListBackward(l);
//    printf("%d %d %d %d  ",l->head->data,l->head->next->data,l->tail->prev->data,l->tail->data);
//    printf("\n%d %d %d\n",l->head->data,l->head->next->data,l->tail->data);
//    printf("\n%d",areEqual(l,l2));
//    destroy(l);
//    printf("\n%d %d  %d",l->head->data,l->head->next->data,l->tail->data);
//    printf("hello");
//
//    printf("\n%d",isPalindrome(l2));
//    DoublyLinkedList*l3=copy(l2);
//    printf("m");
//    destroy(l3);
//    printf("l");
//    printf("\n%d %d %d\n",l3->head->data,l3->head->next->data,l3->tail->data);
//
//    concatenate(l2,l3);
//    //printf("\n%d %d %d %d %d %d",l2->head,)
//    testConcatenate();
//    testPalindrome();
//    testAreEqual();
//    testDifference();
//    testSum();
    return 0;
}
