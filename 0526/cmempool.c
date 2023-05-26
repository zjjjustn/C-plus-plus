#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct  Node *next;    
};

static struct Node *head = NULL;

void *my_malloc(size_t size)
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("malloc:\n");
        head = (struct Node *)malloc(sizeof(struct Node) * 50);
        temp = head;
        for (int i =0; i<50;i++)
        {
            temp->next = temp +1;
            temp = temp->next;
        }
        temp->next = NULL;
    }
    temp = head;
    head = head ->next;
    return temp;
}

void my_free(int *p)
{
    struct Node *temp = (struct Node *)p;
    temp->next =head;
    head = temp;
}

int main(int argc,char **argv)
{
    int *p1 = (int *)my_malloc(sizeof(int));
    int *p2 = (int *)my_malloc(sizeof(int));
    printf("p2 = %p\n",p2);
    int *p3 = (int *)my_malloc(sizeof(int));
    *p1 = 10;
    printf("%d\n",*p1);
    my_free(p2);
    int *p4 = (int *)my_malloc(sizeof(int));
    printf("p4 = %p\n",p4);

    return 0;

}