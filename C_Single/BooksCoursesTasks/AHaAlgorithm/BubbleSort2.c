/*
 * @Author: Kiro_Yang 
 * @Date: 2022-04-04 17:35:33 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2022-04-04 18:16:04
 */

#include <stdio.h>
struct student{
    char name[20];
    int score;
};

int main(){
    struct student a[100],temp;
    int i,j,n;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%s %d",a[i].name,&a[i].score);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n-i; j++){
            if(a[j].score < a[j+1].score){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%s ",a[i].name);
        printf("%d\n",a[i].score);
    }
    return 0;
}