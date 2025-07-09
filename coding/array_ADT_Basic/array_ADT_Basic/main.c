#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10]; //this is in stack   for array in heap --> int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("\n Elements are ");
    for(i = 0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    
        
}

void append(struct Array *arr, int x) //call by address -> to modify array
{
    //check space is there r not
    if(arr->length < arr->size)
        arr->A[arr->length++]= x;
}

void insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        
        arr->A[index]=x;
        arr->length++;
    }
    
    else
        printf("cant insert at index");
        
}


int delete(struct Array *arr, int index)
{
    int x=0;
    if(index >= 0 && index <=arr->length)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}



int main(int argc, const char * argv[]) {
    struct Array arr1;
    
    /*****this part of code is array in heap *****
     
    printf("enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
     */
    
    //Input the array property
    int n,i;
    printf("Enter number of num \n");    //this is the length of actual array
    scanf("%d",&n);
    
    printf("enter all elements \n");     //Entering the elements of array
    for(i=0;i<n;i++)
        scanf("%d",&arr1.A[i]);
    arr1.length = n;
    
    display(arr1);                        //Display the elements of array
    
    
    
    //Array in stack
    struct Array arr= {{2,3,4,5},10,4};
    append(&arr, 10);
    insert(&arr,3,321);               //insert at right index
    insert(&arr,9,121);               //inserting at wrong index
    delete(&arr, 0);                    //Deleting at given index
    display(arr);
    return 0;
}
