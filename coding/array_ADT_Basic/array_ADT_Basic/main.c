#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10]; //this is in stack now   for array in heap --> int *A;
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

int LinearSearch(struct Array arr,int key)  //pass by value, as you just need to find  and not modify
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int ImprovedLinearSearch(struct Array *arr,int key)  //pass by value, as you just need to find  and not modify
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            //swap(&arr->A[i],&arr->A[i-1]);      //option 1 : swap values and bring to front by 1 index
            swap(&arr->A[i],&arr->A[0]);          //option 2 : swap and bring to index 0
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int h,l,mid;
    l = 0;
    h = arr.length -1;
    
    
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if (key < arr.A[mid])         ////when key is on left side of mid, make high just before mid
            h= mid-1;
        else
            l = mid+1;                     ////when key is on right side of mid, make low just after mid
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    struct Array arr1;
    
    /*****this part of code is array in heap *****
    printf("enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length = 0;                   */
    
    //Input the array property
//    int n,i;
//    printf("Enter number of num \n");    //this is the length of actual array
//    scanf("%d",&n);
//    
//    printf("enter all elements \n");     //Entering the elements of array
//    for(i=0;i<n;i++)
//        scanf("%d",&arr1.A[i]);
//    arr1.length = n;
//    display(arr1);                        //Display the elements of array
    
    
    //Array in stack
    struct Array arr= {{2,3,4,5},10,4};
//    append(&arr, 10);
//    insert(&arr,3,321);               //insert at right index
//    insert(&arr,9,121);               //inserting at wrong index
//    delete(&arr, 0);                    //Deleting at given index
//    printf("Search result %d\n",ImprovedLinearSearch(&arr, 4));
    printf("Search result %d\n",BinarySearch(arr, 4));
    display(arr);
    return 0;
}
