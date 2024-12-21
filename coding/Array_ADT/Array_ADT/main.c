#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

void display(struct Array A)
{
    for(int i=0;i<A.length;i++)
    {
        printf("%d ",A.A[i]);
    }
}

void append(struct Array *Arr,int value)
{
    if(Arr->length<Arr->size)
    {
        Arr->A[Arr->length++]=value;
    }
}

void insert(struct Array *Arr, int index, int value)
{
    if(index >= 0 && index <= Arr->length)
    {
        for(int i=Arr->length;i>index;i--)
        {
            Arr->A[i]=Arr->A[i-1];
            
        }
        Arr->A[index]=value;
        Arr->length++;
    }
}

void delete(struct Array *arr, int index)
{
    if(index >= 0 && index < arr->length)  //make sure this is properly defined
    {
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int main(int argc, const char * argv[]) {
    struct Array A1 = {{2,4,3,2},4,10};
    //append(A1,3,22);
    //append(&A1,66);
    insert(&A1, 3, 23);         //OP: 2 4 3 23 2
    append(&A1,66);             //OP: 2 4 3 23 2 66
    insert(&A1,7 , 23);         //OP: invalid, as the length of array is small
    display(A1);
    printf("\n");
    delete(&A1, 5);
    display(A1);

    
    return 0;
}
