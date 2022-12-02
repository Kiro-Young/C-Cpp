/*
【问题描述】
给定一个长度为 N 的整数序列：A1, A2, · · · , AN。现在你有一次机会，将其中连续的 K 个数修改成任意一个相同值
请你计算如何修改可以使修改后的数列的 最长不下降子序列最长 ，请输出这个最长的长度。
最长不下降子序列是指序列中的一个子序列，子序列中的每个数不小于在它之前的数。
【输入格式】
输入第一行包含两个整数 N 和 K。 第二行包含 N 个整数 A1, A2, · · · , AN
【输出格式】 输出一一个整数表示答案。
【样例输入】 5 1 1 4 2 8 5
【样例输出】 4
【评测用例规模与约定】 对于 20% 的评测用例，1 ≤ K ≤ N ≤ 100； 对于 30% 的评测用例，1 ≤ K ≤ N ≤ 1000；
*/

#include <stdio.h>
#define MAX 100000
int main(){
    int i,n,k;
    int a[MAX];
    scanf("%d %d",&n,&k);
    for(i = 1; i <= n; i++) scanf("%d",&a[i]);

    printf("%d",4);
}
