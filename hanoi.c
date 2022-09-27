//output notyet
//Towers Of Hanoi with Linked List
#include<stdio.h>
#include <stdlib.h>
typedef struct listNode2 listNode;
typedef struct listNode2
{
    int firstvalue;
    listNode *listPointer;
}listNode;
typedef struct stack
{
	listNode *top;
}str;
void push(str *,int);
int pop(str *);
void display(str *);
str initialStack() {
    str st ;
    st.top = NULL ;
    return st ;
}
int main()
{
    int i,j,k,l,a,b;
    int value=0;
    int step=0;
    str top1 = initialStack() ;
    str top2 = initialStack() ;
    str top3 = initialStack() ;
    printf("Please enter number of disks:");
    scanf("%d",&i);
    l=i+1;
    for(j=0;j<i;j++)
    {
        l--;
        push(&top1,l);
    }
    //display(&top1);
    //display(&top2);
    //display(&top3);
    for(k=1;k < 1<<i ;k++)
    {
    step++;
	a=(k&k-1)%3;
    b=((k|k-1)+1)%3;
    switch(a)
    {
        case 0: value=pop(&top1);
        break;
        case 1: value=pop(&top2);
        break;
        case 2: value=pop(&top3);
        break;
    }
    switch(b)
    {
        case 0: push(&top1,value);
        break;
        case 1: push(&top2,value);
        break;
        case 2: push(&top3,value);
        break;
    }


    printf("Step %d : Move dick %d from pillar %d to pillar %d", step, value, a, b);
    //display(&top1);
    //display(&top2);
    //display(&top3);
    printf("\n") ;
    }
}
void push(str *s,int t)
{
    listNode *n1 = (listNode*)malloc(sizeof(listNode)) ;
    n1->firstvalue = t;
    n1->listPointer = s->top ;
    s->top = n1 ;
}
int pop(str *s)
{
    listNode *n2 = s->top ;
    s->top = n2->listPointer ;
    char ch = n2->firstvalue ;
    free(n2) ;
    return ch;
}
void display(str *st) {
    listNode *s = st->top ;
    while(s!=NULL)
    {
    printf("%d ",s->firstvalue);
    s = s->listPointer ;
    }
    printf("\n") ;
}
