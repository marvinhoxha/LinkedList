#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct Number
{
    int num;
    struct Number * next;
};
typedef struct Number node;

void builtRandList(node **First,int n);
void addNodeEnd(node **First, node n);
void addNodeFront(node **First, node n);

void printList(node **First);
int getSize(node **First);

void deleteEndNode(node **First);
void deleteFrontNode(node **First);
void deleteNodeVal(node **First,node nd);
void deleteNodeAtPos(node **First,int pos);
void deleteAll(node **First);

void insertSorted(node **First, node n);

void fullscreen();
void displyMenu();



int main()
{

    node *First;
    First=NULL;
    node nd;
    int i;
    int n;
    while(1)
    {
        displyMenu();

        printList(&First);
        printf("\nEnter your choice: ");
        scanf("%d",&i);

        switch(i)
        {

        case 1:


            printf("Enter the number of nodes: ");

            scanf("%d",&n);
            builtRandList(&First,n);
            break;

        case 2:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            addNodeEnd(&First,nd);
            break;

        case 3:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            addNodeFront(&First,nd);
            break;

        case 4:

            printf("Enter the number: ");
            scanf("%d",&nd.num);
            insertSorted(&First,nd);
            break;

        case 5:
            deleteEndNode(&First);
            break;

        case 6:
            deleteFrontNode(&First);
            printList(&First);
            break;

        case 7:

            printf("Enter the number to be deleted : ");
            scanf("%d",&nd.num);
            deleteNodeVal(&First,nd);
            break;

        case 8:

            printf("Enter the position of the number to be deleted (0 - n-1): ");
            int pos;
            scanf("%d",&pos);
            deleteNodeAtPos(&First,pos);
            break;

        case 9:
            deleteAll(&First);
            system("pause");
            break;

        case 10:
            printList(&First);
            system("pause");
            break;

        case 11:

            printf("Size of the list is: %d\n",getSize(&First));
            system("pause");
            break;

        case 12:
            return 0;

        default:

            printf(" Invalid option!\n");
            system("pause");
        }

    }
    return 0;
}

void displyMenu()
{
    fullscreen();
    system("cls");
    printf("*********************************\n");
    printf("*        EPOKA UNIVERSITY       *\n");
    printf("*    CEN 110 - C Programming!   *\n");
    printf("*     ==Singly Linked List==    *\n");
    printf("*                               *\n");
    printf("*       List Of Operations      *\n");
    printf("*  ---------------------------  *\n");
    printf("*   1. Built random list.       *\n");
    printf("*   2. Insert to the END        *\n");
    printf("*   3. Insert to the FRONT      *\n");
    printf("*   4. Insert Sorted            *\n");
    printf("*   5. deleteEndNode            *\n");
    printf("*   6. deleteFrontNode          *\n");
    printf("*   7. deleteNodeVal            *\n");
    printf("*   8. deleteNodeAtPos          *\n");
    printf("*   9. deleteAllNodes           *\n");
    printf("*  10. DisplayList              *\n");
    printf("*  11. Size                     *\n");
    printf("*  12. Exit                     *\n");
    printf("*********************************\n");

}



void builtRandList(node **First,int n)
{
     node *temp,*newnode;

    for (int i=1;i<=n;i++)
    {
     newnode=(node*)malloc(sizeof(node));
     scanf("%d",&newnode->num);
     if (i==1)
     {
       *First=temp=newnode;
     }
     else
     {
        temp->next=newnode;
        temp=newnode;
     }
     newnode->next=NULL;
    }

}

void addNodeEnd(node **First, node n)
{

    node *newnode,*temp,*curr;
    newnode=(node *)malloc(sizeof(node));
    newnode->num=n.num;
    temp=*First;
    while (temp!=NULL)
    {
        curr=temp;
        temp=temp->next;
    }
    curr->next=newnode;
    newnode->next=NULL;

}

void addNodeFront(node **First, node n)
{

    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->num=n.num;
    newnode->next=*First;
    *First=newnode;

}

void printList(node **First)
{
    if (*First==NULL){return;}
    node *temp=NULL;
    temp=*First;
    while (temp!=NULL)
    {
        printf("%d\n",temp->num);
        temp=temp->next;
    }

}

int getSize(node **First)
{

    node *temp=*First;
    int cnt=0;
    while (temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }

 return cnt;
}

void deleteEndNode(node **First)
{
    node *temp=*First;
    while(temp->next->next != NULL)
        temp = temp->next;
      node *lastNode = temp->next;
      temp->next = NULL;
      free(lastNode);

}

void deleteFrontNode(node **First)
{
    node *curr=NULL;
    curr=*First;
    *First=curr->next;

}

void deleteNodeVal(node **First,node nd)
{
    node *temp=NULL;
    node *curr=NULL;
    temp=*First;
    while (nd.num!=temp->num)
    {
    curr=temp;
    temp=temp->next;
    }
     curr->next=temp->next;

}

void deleteNodeAtPos(node **First,int pos)
{
    if (*First == NULL) {
      return;
   }
   node *temp = *First;
   if (pos == 0) {
      *First = temp->next;
      free(temp);
      return;
   }
   for (int i = 1; temp != NULL && i < pos; i++) {
      temp = temp->next;
   }
   if (temp == NULL || temp->next == NULL) {
      return;
   }
   node *next = temp->next->next;
   free(temp->next);
   temp->next = next;

}
void deleteAll(node **First)
{

   *First=NULL;

}


void insertSorted(node **First, node n)
{
    node *newnode,*curr,*prev;
    newnode=(node *)malloc(sizeof(node));
    newnode->num=n.num;
    newnode->next=NULL;
    curr=*First;
    if (*First==NULL)
    {
        *First=newnode;
        return;
    }
    if (curr->num <= newnode->num)
    {
        newnode->next=curr;
        *First=newnode;
    }
    else
    {
      while ((curr!=NULL)&&(curr->num > newnode->num))
      {
          prev=curr;
          curr=curr->next;
      }
      if (curr==NULL)
      {
          prev->next=newnode;
      }
      else
      {
          prev->next=newnode;
          newnode->next=curr;
      }

    }

}

void fullscreen()
{
    keybd_event(VK_MENU,	0x38,0,	0);
    keybd_event(VK_RETURN,0x1c,	0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
