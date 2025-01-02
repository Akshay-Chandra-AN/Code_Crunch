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

int LinearSearch(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            return i;
        }
    }
    return -1;
}


void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;  //initial mistake was p = q; changes the local pointer p to point to the same location as q, but this does not affect the actual pointer p passed to the function.
    *q= temp;
}

int ImprovedLinearSearch(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);   //this first to head improvement method.
            //can use trasnposition method where ,swap(&arr->A[i],&arr->A[i-1]).
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int low = 0;
    int high = arr.length-1;
    int mid;
    
    while(low<=high)
    {
        mid = (high + low)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid-1;
        else if(key > arr.A[mid])
            low = mid+1;
        else{
            printf("element not found");
        }
    }
    
    
    //printf("%d",high);
    return 0;
}

int get(struct Array arr, int key)
{
    for(int i=0;i<=arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

int set(struct Array *arr, int index, int key)
{
    if(index >= 0 || index <arr->length)
    {
        for(int i=0;i<=arr->length;i++)
        {
            if(i==index)
            {
                return arr->A[i]=key;
            }
        }
    }
    return -1;
}

int max(struct Array arr)
{
    int m = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>m)
        {
            m=arr.A[i];
        }
    }
    return m;
}

int sum(struct Array arr)
{
    int sum = 0;
    for(int i=0;i<arr.length;i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

void Reverse(struct Array *arr)     //Reverse using auxiliary/extra array
{
    printf("\n Reversing the array\n");
    int *b;
    int i,j;
    
    b =(int *)malloc(arr->length*sizeof(int));
    
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        b[j]=arr->A[i];
    }
    
    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=b[i];
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
    printf("\n");
    printf("the index it is found at %d",ImprovedLinearSearch(&A1,23));
    printf("\n");
    display(A1);
    printf("\n");
    printf("the index it is found at %d",LinearSearch(&A1,23));
     
    //Binary Search
    struct Array A2 = {{11,22,33,44,55,66,77,88,99,222},10,10};
    printf("Element found at index %d ",BinarySearch(A2, 22));
    
    printf("element index is %d\n",get(A2, 55));
    
    set(&A2,4,555);
    display(A2);
    
    
    printf("\nmax element is %d\n",max(A2));
    
    printf("sum element is %d\n",sum(A2));
    
    
    Reverse(&A2);
    display(A2);
    return 0;
    
}
