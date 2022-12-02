/*
 * @Author: Kiro_Yang 
 * @Date: 2022-03-29 13:14:32 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2022-03-29 14:47:39
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

#include<stdio.h>

int stairs(int n);

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",stairs(n));
}


//! 1.单纯递归；O(2^n)超时；
// int stairs(int n){
//     if(n == 1) return 1;
//     if(n == 2) return 2;
//     return stairs(n - 1) + stairs(n - 2);
// }

//! 2.因重复计算太多，考虑Java的hash map(哈希表)存储数据！时间复杂度O(n)
// int stairs(int n){
    
// }

//! 3.递归自顶向下，还可循环自底而上求解，时间复杂度仍O(n),内存占用略少，但代码复杂度较高，不易理解
int stairs(int n){
    int result = 0;
    int first = 1;
    int second = 2;
    if(n == 1) return 1;
    if(n == 2) return 2;
    for(int i = 3; i <= n; ++i){
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}