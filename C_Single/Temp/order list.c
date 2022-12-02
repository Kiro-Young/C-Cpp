/*
 * @Author: Kiro_Yang 
 * @Date: 2021-11-26 19:35:43 
 * @Last Modified by:   Kiro_Yang 
 * @Last Modified time: 2021-11-26 19:35:43 
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXF 20;

void Initialize(Facility &list);
void facility_new(Facility &list, int i, );

typedef struct facility{        //定义单链表节点类型
    int id;                     //数据域
    char facility_name[20];
    int usetime;
    struct facility *next;      //指针域
}Facility;

int main()
{
    Facility list;
    Initialize(list);
    
    return 0;
}

void Initialize(Facility &list){
   for(int i=0; i<MAXF; i++)
        list.id = 0;
}

void facility_new(Facility &list, int i, ){    //在第i个位置插入
    
}


