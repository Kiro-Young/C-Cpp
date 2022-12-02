/*
 * @Author: Kiro_Yang 
 * @Date: 2022-04-03 17:15:12 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2022-04-03 18:10:23
 动态规划入门
 */
#include <stdio.h>

int min(int a,int b){
    return a < b ? a : b;
}

int main(){
    
}
int minCostClimbingStairs(int* cost, int costSize){
    int i = 0;
    int f[1001] = {0,0};
    for(i = 2; i <= costSize; i++){
        f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);  
    }
    return f[costSize];
}