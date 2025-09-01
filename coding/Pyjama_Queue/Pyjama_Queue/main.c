#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *next;
    int data;
}node;

node *head;

void init(int adata)
{
    head = malloc(sizeof(node));
    head->next = NULL;
    head->data = adata;
}

int add_end(int bdata)
{
    node *n;
    n = malloc(sizeof(node));
    
    n->data= bdata;
    n->next = NULL;
    
    node *cursor=head;
    for(cursor = head;
        cursor->next != NULL;
        cursor = cursor->next)
    {
        
    }
    cursor->next = n;
    return 0;
}


void traverse(void)
{
    for(node *cursor = head;
        cursor != NULL;
        cursor = cursor->next)
    {
        printf("%d",cursor->data);
    }
}

int main(int argc, const char * argv[]) {
    init(10);
    add_end(55);
    add_end(552);
    traverse();
    return 0;
}
