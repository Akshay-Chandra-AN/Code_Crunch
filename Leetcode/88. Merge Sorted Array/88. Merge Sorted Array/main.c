#include <stdlib.h>
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int sizeofNums1=m+n;
    int j=m;
    for(int i=0;i<=m;i++)
    {
        nums1[j] = nums2[i];
        j++;
        if(j>=sizeofNums1)
            break;
    }
    
    for(int i=0;i<sizeofNums1;i++)
    {
        printf("%d ",nums1[i]);
    }
}

int main()
{
    int nums1[]={1};
    int nums2[]={0};
    int m=1;
    int n=0;
    
    merge(nums1,1,m,nums2,1,n);
    
    
    
    return 0;
}
