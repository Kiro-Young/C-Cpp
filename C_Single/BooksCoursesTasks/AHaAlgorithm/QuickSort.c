#include <stdio.h>
#define LENGTH 10

void QuickSort(int a[],int left,int right){
    int i,j,base,mid,temp;
    while(){
        base = a[left];
        if(a[left+1] >= a[base] && a[right] <= a[base]){
            a[mid] = a[left];
            temp = a[right];
            a[right] = a[left+1];
            a[left++] = temp;
        }
    }
}
int main(){
    int a[LENGTH],i,n;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    QuickSort(a[LENGTH],0,n);
    for(i = 0; i < n; i++) printf("%d",a[i]);
    return 0;
}