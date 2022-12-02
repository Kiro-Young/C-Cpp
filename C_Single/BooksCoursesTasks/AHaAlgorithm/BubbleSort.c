/*
 * @Author: Kiro_Yang 
 * @Date: 2022-04-04 16:19:24 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2022-04-04 17:19:44
 */

#include <stdio.h>

int main(){
    int a[100] = {0},i,n,j,temp;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n-i; j++){
            if(a[j] < a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    return 0;
}