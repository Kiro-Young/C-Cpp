/*
【问题描述】 
给定一个长度为 n 的数列 A1, A2, · · · , An 和一个非负整数 x，给定 m 次查询, 
每次询问能否从某个区间 [l, r] 中选择两个数使得他们的异或等于 x 。 
【输入格式】
输入的第一行包含三个整数 n, m, x 
第二行包含 n 个整数 A1, A2, · · · , An
接下来 m 行，每行包含两个整数 l_i, r_i 表示询问区间 [l_i, r_i] 。
【输出格式】 
对于每个询问, 如果该区间内存在两个数的异或为x,则输出 yes, 否则输出no。
对于 20% 的评测用例，1 ≤ n, m ≤ 100； 
对于 40% 的评测用例，1 ≤ n, m ≤ 1000； 
对于所有评测用例，1 ≤ n, m ≤ 100000 ，0 ≤ x < 220 ，1 ≤ li ≤ ri ≤ n ，0 ≤ Ai < 220

4 4 1
1 2 
3 4
1 4
1 2
2 3
3 3
*/

#include <stdio.h>
#define MAX 1000

int main(){
    int i,j,n,M,x,k,l,r;
    int boolean = 0;
    int a[MAX] = {0};
    int m[200000] = {0};
    scanf("%d %d %d",&n,&M,&x);
    for(i = 1; i <= n; i++) scanf("%d",&a[i]);
    
    for(i = 1; i <= 2*M; i++) scanf("%d",&m[i]);
    
    for(k = 1; k <= M; k++){
        boolean = 0;
        l = m[k];
        r = m[k+1];
        for(i = l; l < r; l++){
            for(j = l+1; j <= r; j++){
                if(a[i]^a[j] == x) boolean = 1;
            }
        }
        if(boolean == 1) printf("yes\n");
            else printf("no\n");
    }
}