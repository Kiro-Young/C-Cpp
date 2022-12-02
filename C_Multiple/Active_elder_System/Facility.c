#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void facility_scence();
//场馆设施管理系统操作界面
void facility_new();
//新建设施
void facility_data();
//查看设施信息
void facility_book();
//设施预约排队使用

typedef struct facility{
    int id;
    char facility_name[20];
    int usetime;
}Facility;//定义设施结构体

void main()
{
    
}

void facility_scence()
{
    printf(
         "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
         "$   《活力长者社区设施管理系统》   $\n"
         "                                  \n"
         "$  （请输入相应数字选择所需功能）  $\n"
         "                                  \n"
         "$  1.新建娱乐设施                 $\n"
         "$  2.查看设施信息                 $\n"
         "$  3.修改设施信息                 $\n"
         "$  4.返回主菜单                   $\n"
         "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
         );
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            facility_new();
            break;
        case 2:
            facility_data();
            break;
        case 3:
            facility_change();
        case 4:
            main();
            break;
        default:{
            printf("糟老头子坏得很！好好输入！\n");
            facility_scence();
            break;
        }
    }
}//!设施管理系统启动界面

void facility_new()
{
    char facility_name[20];
    printf("请敲出新设施名称：\n");
    scanf("%s",&facility_name);

    FILE * file;
    
    file = fopen("facility_data.txt", "r+");
    


    fclose(file);
    
    

    printf("牛逼！新建娱乐设施成功！\n"
           "设施编号为:%d\n",equipid);
    FILE *fp;
    fp= fopen("equipdata.txt", "a");
    fprintf(fp, "%d,%s,0\n",equipid,facility_name);
    fclose(fp);

    facility_scence(); 
}//!新建设施（提前创建facility_data.txt文件）

void facility_data()
{

}

void facility_use() 
{
    FILE *fp = NULL;
    char buff[255];
    struct facility equiplist[255];
    int k=0;
    fp = fopen("equipdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[3][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct facility newequip;
        if(strcmp(substr[0],info)==0) {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.facility_name[j]= substr[1][j];
            }
            newequip.usestate=1;
            equiplist[k]=newequip;
        } else {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.facility_name[j]= substr[1][j];
            }
            newequip.usestate=atoi(substr[2]);
            equiplist[k]=newequip;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("facility_data.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%s,%d\n",equiplist[i].id,equiplist[i].facility_name,equiplist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    
    
    printf("好运，申请到了!\n");
    facility_scence();
}//!设施使用申请（提前创建facility_data.txt文件）


    
