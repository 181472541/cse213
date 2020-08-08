/**
Name: Md Rabiul Islam Shaon
ID: 181472541
**/

/* Single Way Linked List */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void menu();
Node* create_list_1();
Node* create_list_2();
Node* insert_after(Node *temp, int key, int value);
void Delete_After(Node *head1);
Node* merge_list(Node *list1, Node *list2);
Node* copy_list(Node *temp);
Node* clear(Node *temp);
void print_list(Node *temp);

int main()
{
    menu();

    return 0;
}

void menu()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *list = NULL;
    Node *list1 = NULL;
    Node *list2 = NULL;

    head1 = create_list_1();
    head2 = create_list_2();

    int value, option;
    do
    {
        system("cls");
        printf("1. Insert After\n");
        printf("2. Delete After\n");
        printf("3. Merge Two List\n");
        printf("4. Copy\n");
        printf("5. Clear\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your Option : ");
        scanf("%d", &option);

        if(option == 1)
        {
            int key, x;

            printf("Display List 1: ");
            print_list(head1);

            printf("Enter Value: ");
            scanf("%d",&key);

            printf("Enter Which Value You Want to Insert: ");
            scanf("%d",&x);

            head1 = insert_after(head1, key, x);
            printf("List 1 After Insert: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 2)
        {
            printf("List 1: ");
            print_list(head1);
            Delete_After(head1);
            printf("Deleted After List 1: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 3)
        {
            list1 = head1;
            printf("Display List 1: ");
            print_list(list1);

            list2 = head2;
            printf("Display List 2: ");
            print_list(list2);

            list = merge_list(list1, list2);
            printf("After Merge Two List: ");
            print_list(list);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 4)
        {
            printf("Display List 1: ");
            print_list(head1);

            list1 = copy_list(head1);
            printf("After Copy List 1: ");
            print_list(list1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 5)
        {
            printf("Display List 1: ");
            print_list(head1);

            if(clear(head1)==NULL)
                printf("Clear Linked List\n");
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 6)
        {
            printf("Display List 1: ");
            print_list(head1);

            printf("Display List 2: ");
            print_list(head2);

            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 7)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid Option, Please Option Between '1 to 7'");

            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
    }
    while(option != 7);
}

Node* create_list_1()
{
    Node *a, *b, *c, *d;

    a = (Node *) malloc(sizeof(Node));
    b = (Node *) malloc(sizeof(Node));
    c = (Node *) malloc(sizeof(Node));
    d = (Node *) malloc(sizeof(Node));

    a->value = 10;
    a->next = b;

    b->value = 20;
    b->next = c;

    c->value = 30;
    c->next = d;

    d->value = 40;
    d->next = NULL;

    return a;
}

Node* create_list_2()
{
    Node *a, *b, *c, *d;

    a = (Node *) malloc(sizeof(Node));
    b = (Node *) malloc(sizeof(Node));
    c = (Node *) malloc(sizeof(Node));
    d = (Node *) malloc(sizeof(Node));

    a->value = 50;
    a->next = b;

    b->value = 60;
    b->next = c;

    c->value = 70;
    c->next = d;

    d->value = 80;
    d->next = NULL;

    return a;
}

Node* insert_after(Node *temp, int key, int value)
{
    Node *head = temp;
    int i = 0;
    while(temp)
    {
        if(temp->value == key)
        {
            Node *new_node = (Node*) malloc(sizeof (Node) );
            new_node->value = value;
            new_node->next = temp->next;
            temp->next = new_node;
            i++;
            return head;
        }
        temp = temp->next;
    }
    if(i<1 || i>4)
    {
        printf("Index out of range\n");
        printf("Element Not Found\n");
    }
    return head;
}

void Delete_After(Node *head1)
{
    Node *ptr, *ptr1;
    int i, position;
    printf("Enter Position:");
    scanf("%d",&position);
    ptr=head1;
    for(i=0; i<position; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\n%d Invalid Position\n",position);
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
}

Node* merge_list(Node *list1, Node *list2)
{
    Node *head, *temp;
    head = list1;
    while(list1->next)
    {
        list1 = list1->next;
    }
    list1->next = list2;
    return head;
}

Node* copy_list(Node *temp)
{
    Node *head2;
    Node *temp2;

    temp2 = (Node*) malloc(sizeof (Node));

    temp2->value = temp->value;
    temp2->next = temp->next;

    head2 = temp2;
    temp = temp->next;
    while(temp)
    {
        temp2 = (Node*) malloc(sizeof (Node) ) ;
        temp2->value = temp->value;
        temp2->next = temp->next;
        temp = temp->next;
    }
    return head2;
}

Node* clear(Node *temp)
{
    Node *to_delete;
    while(temp)
    {
        to_delete = temp;
        temp = temp->next;
        free(to_delete);
    }
    return NULL;
}

void print_list(Node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
