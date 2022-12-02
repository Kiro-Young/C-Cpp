/*
 * @Author: Kiro_Yang 
 * @Date: 2021-11-26 19:35:43 
 * @Last Modified by:   Kiro_Yang 
 * @Last Modified time: 2021-11-26 19:35:43 
 */

#include <stdio.h>

typedef struct facility{        //定义单链表节点类型
    int id;                     //数据域
    char facility_name[20];
    int usetime;
    struct facility *next;      //指针域
}Facility;

Facility *ptr =(Facility*)malloc(sizeof(Facility));

int main()
{
    
    return 0;
}


bool Initialize(Facility &L){
    L = (Facility*)malloc(sizeof(Facility));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}

void facility_new(Facility &L, int i, ){    //在第i个位置插入
    if(i<1)
        return false;
    Facility *p;                            //指针p指向当前扫描到的节点
    int j=0;                                
    p = L;                                  //L指向头结点，头结点是第0个
    while(p!=NULL && j<i-1){                //依次扫描
            p=p->next;
            j++;
    }
    if(p==NULL)
        return false;
    Facility *s = (Facility *)malloc(sizeof(Facility));
    s->id = 2;
    s->next = p->next;
    p->next = s;
    return true;
}

void test(){
    Facility L;                 //声明一个指向单链表的指针
    Initialize(L);
}
