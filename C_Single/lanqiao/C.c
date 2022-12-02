/*
【问题描述】 
给定 n 个整数 a1, a2, · · · , an ，求它们两两相乘再相加的和，即
S = a1 · a2 + a1 · a3 + · · · + a1 · an + a2 · a3 + · · · + an−2 · an−1 + an−2 · an + an−1 · an. 
【输入格式】
输入的第一行包含一个整数 n 。 第二行包含 n 个整数 a1, a2, · · · an。
【输出格式】
 输出一个整数 S，表示所求的和。请使用合适的数据类型进行运算。
*/
#include <stdio.h>
#define MAX 200000
int main(){
    int i,j,n;
    int a[MAX] = {0};
    int s[MAX] = {0};
    int length = 0;
    long int sum = 0;
    scanf("%d",&n);

    for(i = 1; i <= n; i++) scanf("%d",&a[i]);

    for(i = 1; i < n; i++){
        for(j = i+1; j <= n; j++){
           s[i] += a[i] * a[j];
        }
        length++;
    }
    for(i = 1; i <= length;i++){
        sum += s[i]; 
    }
    printf("%ld",sum);
}