#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

int pop(Node **head)
{
    Node* pred = NULL;
    int val;
    if (head == NULL)
    {
        exit(-1);
    }
    pred = (*head);
    val = pred->value;
    (*head) = (*head)->next;
    if (head != NULL) (*head)->prev = NULL;
    free(pred);
    return val;
}

void printLinkedList(const Node *head)
{
    if (head == NULL) printf("\n--List is empty, enter at least one item with push--\n");
    else
    {
        while (head)
        {
            printf("%d ", head->value);
            head = head->next;
        }
        printf("\n");
    }
}

void my_test_2(Node *head)
{
    Node *tmp = head;
    while(tmp)
    {
        if (tmp->value < 0)
        {
            if(tmp->next != NULL)
            {
                Node *q = tmp->next;
                if (q->next == NULL)
                {
                    tmp->next =NULL;
                    free(q);
                }
                else
                {
                    q = q->next;
                    q->prev = tmp;
                    q = tmp->next;
                    tmp->next = q->next;
                    free(q);
                }
            }
        }
        tmp = tmp->next;
    }
}

int main()
{
    int data,count;
    Node *head = NULL;

    printf("please enter count of elements in spis - ");
    scanf("%d",&count);

    printf("please enter value of element - ");
    scanf("%d",&data);

    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    head = tmp;

    for (int i = 1; i < count; ++i)
    {
        printf("please enter value of element - ");
        scanf("%d",&data);
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->value = data;
        tmp->next = head;
        tmp->prev = NULL;
        head->prev = tmp;
        head = tmp;
    }
    printLinkedList(head);
    my_test_2(head);
    printLinkedList(head);
    while (head->next)
    {
        pop(&head);
        head = head->next;
    }
    free(head);

    system("pause");
    return 0;
}

