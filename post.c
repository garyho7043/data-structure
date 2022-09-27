#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 20
#define MALLOC(p,s) if(!((p) = malloc (s))){printf("Insufficient memory");exit(EXIT_FAILURE);}

typedef struct node *treePointer;
typedef struct node
{
    char data;
    treePointer leftChild;
    treePointer rightChild;
};
typedef struct stack *stackPointer;
typedef struct stack
{
    treePointer data;
    stackPointer link;


};
stackPointer top=NULL;

typedef struct stack2 *stackPointer2;
typedef struct stack2
{
    treePointer data;
    stackPointer2 link;


};
stackPointer2 top2=NULL;

typedef struct queue *queuePointer;
typedef struct queue
{
    treePointer data;
    queuePointer link;
};
queuePointer front, rear;

treePointer input(char data[MAX_LENGTH]);
void push(treePointer item);
treePointer pop();
void addq(treePointer item);
treePointer deleteq();
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
void iterPreorder(treePointer ptr);
void iterpostorder(treePointer ptr);


int main()
{
    int i;
    char X[MAX_LENGTH];
    for(i = 0; i < MAX_LENGTH - 1; i++)
    {
        scanf("%c", &X[i]);
        if(X[i] == '!')
        {
            X[i] = '\0';
            break;
        }
    }
    char Y[MAX_LENGTH] = {'a', '+', 'b', '*', 'c', '*', 'd', '+', 'e'};
    char Z[MAX_LENGTH] = {'a', '/', 'b', '*', 'c', '*', 'd', '+', 'e'};
    treePointer node;
    node = input(X);
    printf("inorder: ");
    inorder(node);
    printf("\npreorder: ");
    preorder(node);
    printf("\npostorder: ");
    postorder(node);
    printf("\niterPreorder: ");
    iterPreorder(node);
    printf("\niterPostorder: ");




}

treePointer input(char data[MAX_LENGTH])
{
    treePointer currentNode, tempNode, temp;
    int n = 0;
    MALLOC(currentNode, sizeof(*currentNode));
    currentNode -> data = data[1];
    MALLOC(temp, sizeof(*temp));
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    currentNode -> leftChild = temp;
    (currentNode -> leftChild) -> data = data[0];
    for(n = 1; data[n+2] != '\0'; n += 2)
    {
        if(data[n] == '+' || data[n] == '-')
        {
            if(data[n+2] == '+' || data[n+2] == '-')
            {
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                currentNode -> rightChild = temp;
                (currentNode -> rightChild) -> data = data[n+1];
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> leftChild = currentNode;
                temp -> data = data[n+2];
                currentNode = temp;
            }
            else if(data[n+2] == '*' || data[n+2] == '/')
            {
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> data = data[n+2];
                tempNode = temp;
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                tempNode -> leftChild = temp;
                (tempNode -> leftChild) -> data = data[n+1];
                for(n += 2; data[n+2] == '*' || data[n+2] == '/'; n += 2)
                {
                    MALLOC(temp, sizeof(*temp));
                    temp -> leftChild = NULL;
                    temp -> rightChild = NULL;
                    tempNode -> rightChild = temp;
                    (tempNode -> rightChild) -> data = data[n+1];
                    MALLOC(temp, sizeof(*temp));
                    temp -> leftChild = NULL;
                    temp -> rightChild = NULL;
                    temp -> data = data[n+2];
                    temp -> leftChild = tempNode;
                    tempNode = temp;
                }
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                tempNode -> rightChild = temp;
                (tempNode -> rightChild) -> data = data[n+1];
                currentNode -> rightChild = tempNode;
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> leftChild = currentNode;
                temp -> data = data[n+2];
                currentNode = temp;
            }
        }
        else if(data[n] == '*' || data[n] == '/')
        {
            MALLOC(temp, sizeof(*temp));
            temp -> leftChild = NULL;
            temp -> rightChild = NULL;
            currentNode -> rightChild = temp;
            (currentNode -> rightChild) -> data = data[n+1];
            MALLOC(temp, sizeof(*temp));
            temp -> leftChild = currentNode;
            temp -> data = data[n+2];
            currentNode = temp;
        }
    }
    MALLOC(temp, sizeof(*temp));
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    currentNode -> rightChild = temp;
    (currentNode -> rightChild) -> data = data[n+1];
    return currentNode;
}

void push1(treePointer item)
{
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp -> data = item;
    temp -> link = top;
    top = temp;
}

treePointer pop1()
{
    stackPointer temp = top;
    treePointer item;
    if(!temp)
    {
        return NULL;
    }
    item = temp -> data;
    top = top -> link;
    return item;
}

void push2(treePointer item)
{
    stackPointer2 temp;
    MALLOC(temp, sizeof(*temp));
    temp -> data = item;
    temp -> link = top2;
    top2 = temp;
}

treePointer pop2()
{
    stackPointer2 temp = top2;
    treePointer item;
    if(!temp)
    {
        return NULL;
    }
    item = temp -> data;
    top2 = top2 -> link;
    return item;
}




void addq(treePointer item)
{
    queuePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data=item;
    temp->link=NULL;
    if(front)
    rear->link = temp;
    else
    front = temp;
    rear=temp;
}

treePointer deleteq()
{
    queuePointer temp = front;
    treePointer item;
    if(!temp)
    {
        printf("queue is empty");
        system("PAUSE");
    }
    item = temp -> data;
    front = front->link;
    return item;
}

void inorder(treePointer ptr)
{
    if(ptr)
    {
        inorder(ptr -> leftChild);
        printf("%c", ptr -> data);
        inorder(ptr -> rightChild);
    }
}

void preorder(treePointer ptr)
{
    if(ptr)
    {
        printf("%c", ptr -> data);
        preorder(ptr -> leftChild);
        preorder(ptr -> rightChild);
    }
}

void postorder(treePointer ptr)
{
    if(ptr)
    {
        postorder(ptr -> leftChild);
        postorder(ptr -> rightChild);
        printf("%c", ptr -> data);
    }
}

void iterInorder(treePointer ptr)
{
    for(;;)
    {
        for(; ptr; ptr = ptr -> leftChild)
        {
            printf("%c", ptr -> data);
            push1(ptr);
        }
        ptr = pop1();
        if(!ptr)
            break;
        ptr = ptr -> rightChild;
    }
}





void iterpostorder(treePointer ptr)
{
   treePointer ptr2=NULL;
   treePointer ptr3=NULL;
   treePointer ptr4=NULL;
   treePointer ptr5=NULL;

   for(;;)
    {

        for(; ptr; ptr = ptr -> leftChild)
        {
         push1(ptr);
        }
        ptr = pop1();




        if(ptr -> leftChild==NULL  && ptr -> rightChild==NULL)
         {
          printf("%c", ptr -> data);
          ptr5=ptr;
          ptr = pop1();



          ptr4=ptr;
          ptr4 = ptr4 -> rightChild;
          if(ptr4 -> leftChild==NULL  && ptr4 -> rightChild==NULL)
          {

            if(ptr4!=ptr5)
            {
              push2(ptr);
              ptr2=pop2();
              ptr = ptr -> rightChild;
              for(;ptr!=ptr2;)
              {
               printf("%c", ptr -> data);
               ptr = pop1();
              }
               printf("%c", ptr -> data);
               ptr = pop1();
               if(!ptr)   break;
               ptr = ptr -> rightChild;
            }

            else
            {
                 ptr2=pop2();
                 for(;ptr!=ptr2;)
                 {
                 printf("%c", ptr -> data);
                 ptr = pop1();
                 }
                 printf("%c", ptr -> data);
                 ptr = pop1();
                 ptr = ptr -> rightChild;

            }




          }
          else
          {
           push2(ptr);
           ptr = ptr -> rightChild;

          }

        }








    }

}


























