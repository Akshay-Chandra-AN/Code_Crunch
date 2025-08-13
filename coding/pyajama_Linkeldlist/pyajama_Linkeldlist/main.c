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
    
    //we want malloc to allocate some memory for my head
    //how much size? whatever the size of struct node3
    printf("sizeof(node)%ld\n",sizeof(node));
    
    head = malloc (sizeof(node));
    
    if(head == NULL)
    {
        printf("memory allocation failed");
        return -1;
    }
    
    printf("%p\n",head);    //mem is allocated, we expect a valid address
    
    //now because it is the first element, the next node needs to be point to null
    head->next = NULL;
    memcpy(head->data, data, strlen(data));
    
    //now print, if everything is working as expected
    printf("if address is same as above, working as expected %p\n",head);
    printf("%s\n", head->data);
    
    return 0;
}


int main(int argc, const char * argv[]) {
    init("hello");
    
    
    
    
    return 0;
}
