/*
 * @Author: Kiro_Yang 
 * @Date: 2021-11-19 19:43:41 
 * @Last Modified by: Kiro_Yang
 * @Last Modified time: 2021-11-19 19:59:18
 */

#include <stdio.h>

int main()
{
    int n,counter=0;
    scanf("%d",&n);
    while(n != 1)
    {
        if(n%2 == 0) 
        {
            n = n/2;
            counter++;
        }
        else 
        {
            n = (3*n +1)/2;
            counter++;
        }
    }
    printf("%d",counter);
    return 0;
}