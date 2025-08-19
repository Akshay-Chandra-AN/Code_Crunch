#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s
{
    struct node_s *next;
    char data[40];
}node;

node *head = NULL;

int init(char *data)
{
    printf("%p\n", head);   //memory is not allocated hence if i print, head = 0
    
    if(head)    //if head is initialized already then return error code., as we need not initialize it again
    {
        printf("list already initialized");
        return -1;
    }
    
    //we want malloc to allocate some memory for my head
    //how much size? whatever the size of struct node3
    printf("sizeof(node)%ld\n",sizeof(node));
    
    head = malloc (sizeof(node));
    
    if (!head)      // !head is same as if(head == NULL) on linux
    {
        printf("memory allocation failed");
        return -2;      //if head is initialized already then return error code.
    }
    
    printf("%p\n",head);    //mem is allocated, we expect a valid address
    
    //now because it is the first element, the next node needs to be point to null, because there
    //is nothing to point to right now
    head->next = NULL;
    //now copy the data
    memcpy(head->data, data, strlen(data));
    
    //now print, if everything is working as expected
    printf("if address is same as above, working as expected %p\n",head);
    printf("%s\n", head->data);
    
    return 0;
}

int add(char *data)
{
    if(!data) //make sure data is not null, if it is then no point in adding that as a node
    {
        printf("inalid data\n");
        return -1;
    }
    
    node *n = malloc(sizeof(node));
    if(!n) //if memory is allocated then it is not null
    {
        printf("allocation failed\n");
        return -2;
    }
    
    n->next = head;
    memcpy(n->data, data, strlen(data));
    head = n;
    
    return 0;
}

void traverse(void)
{
    for(node *cursor = head;
        cursor != NULL;
        cursor = cursor->next)
    {
        printf("list : %s\n", cursor->data);
    }
}

int main(int argc, const char * argv[]) {
    init("dello");
    add("akshay");
    add("chandra");
    traverse();
    
    
    return 0;
}
