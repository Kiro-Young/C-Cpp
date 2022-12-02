/*
 * @Author: Kiro_Yang 
 * @Date: 2022-04-01 20:54:39 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2022-04-04 17:22:00
 */

//桶排序适合元素集合少的情况

#include <stdio.h>

int main(){
    int i,j,k,n;
    int a[1001];
    for(i = 0; i <= 1000; i++){
        a[i] = 0;
    }
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d",&k);
        a[k]++; 
    }
    for(i = 0; i <= 1000; i++){
        for(j = 0; j < a[i]; j++){
            printf("%d ",i);
        }                                                          
    }
    getchar();
    return 0;
}