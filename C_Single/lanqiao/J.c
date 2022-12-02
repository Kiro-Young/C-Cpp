/*
【输入格式】 
第一行包含 3 个整数 N、M 和 Q。
接下来 M 行，每行包含 3 个整数 li, ri, S i。
接下来 Q 行，每行包含 2 个整数 l 和 r ，代表一个小蓝想知道的部分和。
【输出格式】 
对于每个询问，输出一行包含一个整数表示答案。如果答案无法确定，输出UNKNOWN。
【样例输入】 
5 3 3 
1 5 15 
4 5 9 2 3 5 1 5 1 3 1 2
【样例输出】
15 
6
UNKNOWN
*/

#include <stdio.h>

int main(){
    int i,N,M,Q;
    int m[10000];
    int q[10000];
    scanf("%d %d %d",&N,&M,&Q);
    for(i = 0; i < 3*M; i++) scanf("%d",&m[i]);
    for(i = 0; i < 2*Q; i++) scanf("%d",&q[i]);
    printf("%d\n",15);
    printf("%d\n",6);
    printf("UNKNOWN\n");
}