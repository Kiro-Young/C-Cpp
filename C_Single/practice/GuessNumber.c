/*
 * @Author: Kiro_Yang 
 * @Date: 2022-03-04 20:23:02 
 * @Last Modified by:   Kiro_Yang 
 * @Last Modified time: 2022-03-04 20:23:02 
 */

//输入一个数字，每位数字依此判断，数字对了，位置错了则0A1B；数字错了，0A0B；数字对了，位置对了1A0B；

//todo 写一个函数，能比较三位数位数，再
#include <stdio.h>
//输入
int ShuRu();
//把三位数拆开成每一位
int ChaiShuZi();
//


int main(){
    int KeyN;
    int GuessN;
    printf ("请输入被猜想的三位数（各不相同的的三位整数）.\n");
    scanf("%d",&KeyN);

// 把KeyNumber三位拆成三个数字ge0，shi0，bai0
    int ge0 = KeyN % 10;
    int shi0 = (KeyN / 10) % 10;
    int bai0 = KeyN / 100;
//printf("%d,%d,%d\n",bai0,shi0,ge0);

    printf("请输入猜想的三位数（各不相同的的三位整数）.\n");
    scanf("%d",&GuessN);

//把GuessNumber三位拆成三个数字ge1，shi1，bai1
    int ge1 = GuessN % 10;
    int shi1 = (GuessN / 10) % 10;
    int bai1 = GuessN / 100;
    printf("%d,%d,%d\n",bai1,shi1,ge1);


//验证输出AB数目和结果
    if(a == 3)
        printf("Dalao NB! You are right!\n");
    if(a < 3)
        printf("%dA %dB, 继续努力！\n",a,b);
}

void ChaiShuZi(int Num){
    int ge = Num % 10;
    int shi = (Num / 10) % 10;
    int bai = Num / 100;
}

// 把GN三位数字以此与KN三位数字比较
void BiJiao(){
//定义AB计数器
    int a = 0, b = 0;
    
     if(ge1 == ge0)
        a++;
    if(ge1 == shi0)
        b++;
    if(ge1 == bai0)
        b++;
    
    if(shi1 == ge0)
        b++;
    if(shi1 == shi0)
        a++;
    if(shi1 == bai0)
        b++;
    
    if(bai1 == ge0)
        b++;
    if(bai1 == shi0)
        b++;
    if(bai1 == bai0)
        a++;
    return(a,b);
}  
   