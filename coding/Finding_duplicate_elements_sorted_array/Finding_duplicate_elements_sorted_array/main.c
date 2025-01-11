#include <stdlib.h>
#include <stdio.h>

void remove_duplicate(int *a)
{
    int duplicate = 0;
    
    for(int i=0;i<10;i++)
    {
        if(a[i]==a[i+1] && a[i]!=duplicate)
        {
            printf("%d ",a[i]);
            duplicate = a[i];
        }
    }
}


int main(int argc, const char * argv[]) {
    int a[]={1,2,3,3,4,5,6,7,7,7,8};
    remove_duplicate(a);
    return 0;
}
