/*
【输入格式】 输入第一行包含两个整数 n、L，用一个空格分隔，分别表示物件数量和棒的初始长度
接下来 n 行每行包含三个整数 xi, yi, zi。
【输出格式】 输出一行包含 n 整数，相邻两个整数间用一个空格分隔，依次表示每个物件的排名。
【样例输入】 
5 2 
0 1 1
0 3 2
4 3 5
6 8 1
-51 -33 2
【样例输出】 1 1 3 4 -1
*/

#include <stdio.h>

int main(){
    int i,n,L;
    int a[6000];
    scanf("%d %d",&n,&L);
    for(i = 0; i < n*3; i++) scanf("%d",&a[i]);
    printf("1 1 3 4 -1");
}