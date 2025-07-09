#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20]; //this is in stack   for array in heap --> int *A;
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


int main(int argc, const char * argv[]) {
    struct Array arr1;
    
    /*****this part of code is array in heap *****
     
    printf("enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
     */
    
    
    int n,i;
    printf("Enter number of num \n");    //this is the length of actual array
    scanf("%d",&n);
    
    printf("enter all elements \n");     //Entering the elements of array
    for(i=0;i<n;i++)
        scanf("%d",&arr1.A[i]);
    arr1.length = n;
    
    display(arr1);                        //Display the elements of array
    
    
    struct Array arr= {{2,3,4,5},20,4};
    display(arr);
    
    return 0;
}
