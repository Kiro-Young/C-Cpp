/*
【问题描述】 
给定 T 个正整数 ai，分别问每个 ai 能否表示为 x_1^y_1 · x_2^y_2的形式，其中 x1, x2为正整数，
y1, y2 为大于等于 2 的正整数
【输入格式】
输入第一行包含一个整数 T 表示询问次数。 接下来 T 行，每行包含一个正整数 ai 。
【输出格式】
对于每次询问, 如果 ai 能够表示为题目描述的形式则输出 yes，否则输出no
【样例输入】 
7 
2 6 12 4 8 24 72
【样例输出】 
no
no 
no
yes 
yes 
no
yes
【样例说明】 
第 4,5,7 个数分别可以表示为： a4 = 22 × 12 ； a5 = 23 × 12 ； a7 = 23 × 32 
*/

#include <stdio.h>
#include <math.h>

int main(){
    int T,x1,x2,y1,y2,i;
    int boolean;
    int a[100000];
    scanf("%d",&T);
    for(i = 0; i < T; i++) scanf("%d",&a[i]);

    for(i = 0; i < T; i++){
        boolean = 0;
        for(x1 = 1; x1 < 10; x1++){
            for(x2 = 1; x2 < 10; x2++){
                for(y1 = 2; y1 < 10; y1++){
                    for(y2 = 2; y2 < 10; y2++){
                        if(a[i] == pow(x1,y1) * pow(x2,y2)) boolean =1;
                    }
                }
            }   
        }
        if(boolean == 1) printf("yes\n");
            else printf("no\n");
    }
}