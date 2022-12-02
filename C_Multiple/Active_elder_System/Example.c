#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void scene0();
void vipscene();
void roomscene();
void settlescene();
void equipmentscene();
void userscene();
void addvip();
void searchvip();
struct vip getdata(char info[]);
void correctvip(char vipid[]);
void changevip(char vipid[]);
void deletevip(char vipid[]);
void changetel(char vipid[]);
void changename(char vipid[]);
void changeid(char vipid[]);
void addroom();
void buyroom();
void purchase(char info[]);
void settleroom(char info[]);
void rentroom(char info[]);
void freeroom(char info[]);
void selectroom(char info[]);

void addequip();
void inoutequip();
void lendequip(char info[20]);
void returnequip(char info[20]);

struct node {
    int data;
    struct node *next;
};//创建单向链表节点

void print(struct node*head)
{
    struct node *temp;
    tep=mhead;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
}//创建链表指针

struct equipment{
    int id;
    char name[20];
    int usestate;
};//定义设施结构体

struct vip {
    char vipid[20];
    char name[20];
    char id[20];
    char tel[20];
};//定义会员结构体

struct room{
    int id;
    int size;
    char info[20];
    int vipid;
    int usestate;
};//定义房屋结构体

int main() {
    scene0();
    int choice1;
    scanf("%d",&choice1);
    switch (choice1) {
        case 1:
            vipscene();
            break;
        case 2:
            roomscene();
            break;
        case 3:
            settlescene();
            break;
        case 4:
            equipmentscene();
            break;
        case 5:
            userscene();
            break;
        case 6:
            printf("退出成功！");
            break;
        default:{printf("选择失败:请输入有效数字!\n");
                main();
                 break;
                }
    }
}//主UI功能

void scene0() {
    printf("****************************************\n"
           "======欢迎登陆活力长者社区管理系统！======\n"
           "****************************************\n"
           "请输入相应数字以选择服务:\n"
           "┌─────────────────────┐\n"
           "│会员管理------------1\n"
           "│房屋管理------------2\n"
           "│入住管理------------3\n"
           "│场馆设施排队管理----4\n"
           "│用户管理------------5\n"
           "│退出系统------------6\n"
           "└─────────────────────┘\n"
           "****************************************\n");
}//主UI

void settlescene() {
    printf("请输入办理入住的房屋编码:\n");
    char info[20];
    scanf("%s",&info);
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        if(strcmp(substr[0],info)==0) {
            selectroom(info);
            break;
        }
    }
    if (feof(fp)) {
        printf("未找到该房屋!\n"
               "***********************\n");
        buyroom();
    }
    fclose(fp);
    }//入住管理

void selectroom(char info[]) {
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL) {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        if (strcmp(substr[0], info)==0) {
            printf("┌───────────────────┐\n"
                   "│房屋面积:%s\n"
                   "│房屋位置:%s\n"
                   "│会员编号:%s\n"
                   "│入住情况:%s\n"
                   "└───────────────────┘\n", substr[1], substr[2], substr[3], substr[4]);
            printf("****************************************\n"
                   "请输入相应数字以选择服务:\n"
                   "┌───────────────────┐\n"
                   "│办理入住-----------1\n"
                   "│房屋出租-----------2\n"
                   "│房屋闲置-----------3\n"
                   "│返回主页-----------4\n"
                   "└───────────────────┘\n"
                   "****************************************\n"
            );
            int choice6;
            scanf("%d", &choice6);
            switch (choice6) {
                case 1:
                    settleroom(info);
                    break;
                case 2:
                    rentroom(info);
                    break;
                case 3:
                    freeroom(info);
                    break;
                case 4:
                    main();
                    break;
                default: {
                    printf("选择失败:请输入有效数字!\n");
                    settlescene();
                    break;
                }
            }
        }
        }
//            printf("该会员不存在!\n");
//            settlescene();
}//查找房屋

void freeroom(char info[]) {
    FILE *fp = NULL;
    char buff[255];
    struct room roomlist[255];
    int k=0;
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct room newroom;
        if(strcmp(substr[0],info)==0) {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=0;
            roomlist[k]=newroom;
        } else {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=atoi(substr[4]);
            roomlist[k]=newroom;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("roomdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%d,%s,%d,%d\n",roomlist[i].id,roomlist[i].size,roomlist[i].info,roomlist[i].vipid,roomlist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("办理闲置成功!\n");
    main();
}//办理闲置

void rentroom(char info[]) {
    FILE *fp = NULL;
    char buff[255];
    struct room roomlist[255];
    int k=0;
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct room newroom;
        if(strcmp(substr[0],info)==0) {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=2;
            roomlist[k]=newroom;
        } else {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=atoi(substr[4]);
            roomlist[k]=newroom;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("roomdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%d,%s,%d,%d\n",roomlist[i].id,roomlist[i].size,roomlist[i].info,roomlist[i].vipid,roomlist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("办理出租成功!\n");
    main();
}//办理出租

void settleroom(char info[]) {
    FILE *fp = NULL;
    char buff[255];
    struct room roomlist[255];
    int k=0;
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct room newroom;
        if(strcmp(substr[0],info)==0) {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=1;
            roomlist[k]=newroom;
        } else {
            newroom.id = atoi(substr[0]);
            newroom.size= atoi(substr[1]);
            for(int j=0;j<20;j++) {
                newroom.info[j]= substr[2][j];
            }
            newroom.vipid= atoi(substr[3]);
            newroom.usestate=atoi(substr[4]);
            roomlist[k]=newroom;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("roomdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%d,%s,%d,%d\n",roomlist[i].id,roomlist[i].size,roomlist[i].info,roomlist[i].vipid,roomlist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("办理入住成功!\n");
    main();
}//办理入住

void roomscene() {
    printf("****************************************\n"
           "请输入相应数字以选择服务:\n"
           "┌───────────────────┐\n"
           "│新建房屋-----------1\n"
           "│购买房屋-----------2\n"
           "│返回上层-----------3\n"
           "└───────────────────┘\n"
           "****************************************\n"
    );
    int choice5;
    scanf("%d", &choice5);
    switch (choice5) {
        case 1:
            addroom();
            break;
        case 2:
            buyroom();
            break;
        case 3:
            main();
            break;
        default:{
            printf("选择失败:请输入有效数字!\n");
            roomscene();
            break;
        }
    }
}//房屋管理

void buyroom() {
    printf("请输入购买的房屋编号:\n");
    char info[20];
    scanf("%s",&info);
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        if(strcmp(substr[0],info)==0) {
            printf("┌───────────────────┐\n"
                   "│房屋面积:%s\n"
                   "│房屋位置:%s\n"
                   "│会员编号:%s\n"
                   "│入住情况:%s\n"
                   "└───────────────────┘\n"
                   "*****************************\n",substr[1],substr[2],substr[3],substr[4]);
            purchase(info);
            break;
        }
    }
    if (feof(fp)) {
        printf("未找到该房屋!\n"
               "***********************\n");
        buyroom();
    }
    fclose(fp);
    }//购买房屋

void purchase(char info[]) {
    printf("请输入购买会员编号:\n");
    int vipid;
    scanf("%d",&vipid);
    FILE *fp = NULL;
    char buff[255];
    struct room roomlist[255];
    int k=0;
    fp = fopen("roomdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL) {
        char *ptr, *retptr;
        ptr = buff;
        char substr[5][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct room newroom;
        if (strcmp(substr[0], info) == 0) {
            newroom.id = atoi(substr[0]);
            newroom.size = atoi(substr[1]);
            for (int j = 0; j < 20; j++) {
                newroom.info[j] = substr[2][j];
            }
            newroom.vipid = vipid;
            newroom.usestate = atoi(substr[4]);
            roomlist[k] = newroom;
        } else {
            newroom.id = atoi(substr[0]);
            newroom.size = atoi(substr[1]);
            for (int j = 0; j < 20; j++) {
                newroom.info[j] = substr[2][j];
            }
            newroom.vipid = atoi(substr[3]);
            newroom.usestate = atoi(substr[4]);
            roomlist[k] = newroom;
        }
        k++;
    }
   FILE *fp2;
   fp2= fopen("roomdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%d,%s,%d,%d\n",roomlist[i].id,roomlist[i].size,roomlist[i].info,roomlist[i].vipid,roomlist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("购买成功!\n");
    roomscene();
}//处理购买行为

void addroom() {
    int size;
    char info[20];
    printf("请输入房屋面积:\n");
    scanf("%d",&size);
    printf("请输入房屋位置:\n");
    scanf("%s",&info);
    FILE * f = 0;
    int lines=0;
    char line[256];
    f = fopen("roomdata.txt", "r");
    while(fgets(line, 255, (FILE *) f)!=NULL)
    {
        char *ptr, *retptr;
        ptr = line;
        char substr[5][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        lines++;
    }
    fclose(f);
    int roomid=lines+1;
    printf("新建房屋成功！\n"
           "房屋编号为:%d\n",roomid);
    FILE *fp;
    fp= fopen("roomdata.txt", "a");
    fprintf(fp, "%d,%d,%s,0,0\n",roomid,size,info);
    fclose(fp);
    roomscene();
}//新建房屋

void deletevip(char vipid[]) {
    printf("确定删除该会员吗？输入1确认，0取消\n");
    int confirm;
    scanf("%d",&confirm);
    if(confirm==1) {
        FILE *fp = NULL;
        char buff[255];
        struct vip viplist[255];
        int k=0;
        fp = fopen("vipdata.txt", "r");
        while(fgets(buff, 255, (FILE *) fp)!=NULL)
        {
            char *ptr, *retptr;
            ptr = buff;
            char substr[4][20];
            int  i= 0;
            while ((retptr = strtok(ptr, ",")) != NULL) {
                strcpy(substr[i++], retptr);
                ptr = NULL;
            }//分割字符串
            struct vip deletevip;
            if(strcmp(substr[0],vipid)!=0) {
                int j = 0;
                while (j < 20) {
                    deletevip.vipid[j] = substr[0][j];
                    deletevip.name[j] = substr[1][j];
                    deletevip.id[j] = substr[2][j];
                    deletevip.tel[j] = substr[3][j];
                    j++;
                }viplist[k]=deletevip;
                k++;
            }
        }
        FILE *fp2;
        fp2= fopen("vipdata.txt", "w");
        for(int i=0;i<k;i++) {
            fprintf(fp2,"%s,%s,%s,%s\n",viplist[i].vipid,viplist[i].name,viplist[i].id,viplist[i].tel);
        }
        fclose(fp2);
        fclose(fp);
        printf("删除会员成功!\n");
        vipscene();
    }
    else if (confirm==0) {
        printf("已取消删除\n"
               "*****************************");
        correctvip(vipid);
    }
}//删除会员UI

void vipscene() {
    printf("****************************************\n"
           "请输入相应数字以选择服务:\n"
           "┌───────────────────┐\n"
           "│新建会员-----------1\n"
           "│查询会员-----------2\n"
           "│返回上层-----------3\n"
           "└───────────────────┘\n"
           "****************************************\n"
    );
    int choice2;
    scanf("%d", &choice2);
    switch (choice2) {
        case 1:
            addvip();
            break;
        case 2:
            searchvip();
            break;
        case 3:
            main();
            break;
        default:{
            printf("选择失败:请输入有效数字!\n");
            vipscene();
            break;
        }
    }
}//会员管理

void addvip() {
    char name[10];
    char id[18];
    int tel;
    printf("请输入会员姓名:\n");
    scanf("%s",&name);
    printf("请输入会员手机号:\n");
    scanf("%d",&tel);
    printf("请输入会员身份证号:\n");
    scanf("%s",&id);
    FILE * f = 0;
    int lines=0;
    char line[256];
    f = fopen("vipdata.txt", "r");
    while(fgets(line, 255, (FILE *) f)!=NULL)
    {
        char *ptr, *retptr;
        ptr = line;
        char substr[4][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        if(atoi(substr[0])>lines) {
            lines = atoi(substr[0]);
        }
    }
    fclose(f);
    int vipid=lines+1;
    printf("新建会员成功！\n"
           "会员编号为:%d\n",vipid);
    FILE *fp;
    fp= fopen("vipdata.txt", "a");
    fprintf(fp, "%d,%s,%s,%d\n",vipid,name,id,tel);
    fclose(fp);
    vipscene();
}//增会员

void searchvip() {
    printf("请输入会员ID/身份证号/姓名/手机号码:\n");
    char info[20];
    scanf("%s",&info);
    if(strcmp(getdata(info).vipid,"")!=0) {
        printf("┌───────────────────────────┐\n");
        printf("│会员编号:%s\n", getdata(info).vipid);
        printf("│会员姓名:%s\n", getdata(info).name);
        printf("│会员身份证号:%s\n", getdata(info).id);
        printf("│会员手机号:%s\n", getdata(info).tel);
        printf("└───────────────────────────┘\n");
        correctvip(getdata(info).vipid);
    } else {
        printf("未找到此人！\n");
        searchvip();
    }//查找失败
}//查会员

void correctvip(char vipid[]) {
    printf("请输入相应数字选择以下操作:\n"
           "┌─────────────────────┐\n"
           "│修改会员信息---------1\n"
           "│删除会员-------------2\n"
           "│返回上层-------------3\n"
           "└─────────────────────┘\n"
           "*****************************\n");
    int choice3;
    scanf("%d",&choice3);
    switch (choice3) {
        case 1:
            changevip(vipid);
            break;
        case 2:
            deletevip(vipid);
            break;
        case 3:
            vipscene();
            break;
        default: {
            printf("选择失败:请输入有效数字!\n");
            correctvip(vipid);
            break;
        }
    }
}//会员删改UI

void changevip(char vipid[]) {
    printf("请选择修改内容:\n"
           "┌─────────────────┐\n"
           "│电话号码---------1\n"
           "│姓名-------------2\n"
           "│身份证号---------3\n"
           "│取消修改---------4\n"
           "└─────────────────┘\n"
           "*****************************\n");
    int choice4;
    scanf("%d", &choice4);
    switch (choice4) {
        case 1:
            changetel(vipid);
            break;
        case 2:
            changename(vipid);
            break;
        case 3:
            changeid(vipid);
            break;
        case 4:
            vipscene();
            break;
        default: {
            printf("选择失败:请输入有效数字!\n");
            changevip(vipid);
            break;
        }
    }
}//修改会员UI

void changeid(char vipid[]) {
    printf("请输入新的身份证号:\n");
    char newid[18];
    scanf("%s",&newid);
    FILE *fp = NULL;
    char buff[255];
    struct vip viplist[255];
    int k=0;
    fp = fopen("vipdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[4][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct vip idvip;
        if(strcmp(substr[0],vipid)==0) {
            int j = 0;
            while (j < 20) {
                idvip.vipid[j] = substr[0][j];
                idvip.name[j] = substr[1][j];
                idvip.id[j] = newid[j];
                idvip.tel[j] = substr[3][j];
                j++;
            }viplist[k]=idvip;
        } else {
            int j = 0;
            while (j < 20) {
                idvip.vipid[j] = substr[0][j];
                idvip.name[j] = substr[1][j];
                idvip.id[j] = substr[2][j];
                idvip.tel[j] = substr[3][j];
                j++;
            }viplist[k]=idvip;
        }
        k++;

        }
    FILE *fp2;
    fp2= fopen("vipdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%s,%s,%s,%s\n",viplist[i].vipid,viplist[i].name,viplist[i].id,viplist[i].tel);
    }
    fclose(fp2);
    fclose(fp);
    printf("修改成功!\n"
           "*****************************\n");
    changevip(vipid);
}//修改身份证号

void changetel(char vipid[]) {
    printf("请输入新的电话号码:\n");
    char newtel[11];
    scanf("%s",&newtel);
    FILE *fp = NULL;
    char buff[255];
    struct vip viplist[255];
    int k=0;
    fp = fopen("vipdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[4][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct vip telvip;
        if(strcmp(substr[0],vipid)==0) {
            int j = 0;
            while (j < 20) {
                telvip.vipid[j] = substr[0][j];
                telvip.name[j] = substr[1][j];
                telvip.id[j] = substr[2][j];
                telvip.tel[j] = newtel[j];
                j++;
            }viplist[k]=telvip;
        } else {
            int j = 0;
            while (j < 20) {
                telvip.vipid[j] = substr[0][j];
                telvip.name[j] = substr[1][j];
                telvip.id[j] = substr[2][j];
                telvip.tel[j] = substr[3][j];
                j++;
            }viplist[k]=telvip;
        }
        k++;

    }
    FILE *fp2;
    fp2= fopen("vipdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%s,%s,%s,%s\n",viplist[i].vipid,viplist[i].name,viplist[i].id,viplist[i].tel);
    }
    fclose(fp2);
    fclose(fp);
    printf("修改成功!\n"
           "*****************************\n");
    changevip(vipid);
}//修改电话号

void changename(char vipid[]) {
    printf("请输入新的姓名:\n");
    char newname[11];
    scanf("%s",&newname);
    FILE *fp = NULL;
    char buff[255];
    struct vip viplist[255];
    int k=0;
    fp = fopen("vipdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL)
    {
        char *ptr, *retptr;
        ptr = buff;
        char substr[4][20];
        int  i= 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        struct vip namevip;
        if(strcmp(substr[0],vipid)==0) {
            int j = 0;
            while (j < 20) {
                namevip.vipid[j] = substr[0][j];
                namevip.name[j] = newname[j];
                namevip.id[j] = substr[2][j];
                namevip.tel[j] = substr[3][j];
                j++;
            }viplist[k]=namevip;
        } else {
            int j = 0;
            while (j < 20) {
                namevip.vipid[j] = substr[0][j];
                namevip.name[j] = substr[1][j];
                namevip.id[j] = substr[2][j];
                namevip.tel[j] = substr[3][j];
                j++;
            }viplist[k]=namevip;
        }
        k++;

    }
    FILE *fp2;
    fp2= fopen("vipdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%s,%s,%s,%s\n",viplist[i].vipid,viplist[i].name,viplist[i].id,viplist[i].tel);
    }
    fclose(fp2);
    fclose(fp);
    printf("修改成功!\n"
           "*****************************\n");
    changevip(vipid);
}//修改姓名

struct vip getdata(char info[]){
    FILE *fp = NULL;
    char buff[255];
    struct vip nullvip={"","","",""};
    struct vip newvip={"","","",""};
    fp = fopen("vipdata.txt", "r");
    while(fgets(buff, 255, (FILE *) fp)!=NULL) {
        char *ptr, *retptr;
        ptr = buff;
        char substr[4][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        if (strcmp(substr[0], info) == 0 || strcmp(substr[2], info) == 0 || strcmp(substr[1], info) == 0 ||
            strcmp(substr[3], info) == 0) {
            int j = 0;
            while (j < 20) {
                newvip.vipid[j] = substr[0][j];
                newvip.name[j] = substr[1][j];
                newvip.id[j] = substr[2][j];
                newvip.tel[j] = substr[3][j];
                j++;
            }
            return newvip;
        }
    }
        if (feof(fp))
            return newvip;
    fclose(fp);
    return nullvip;

} //读取会员文件取出对象

void equipmentscene() {
    printf("****************************************\n"
           "请输入相应数字以选择服务:\n"
           "┌───────────────────┐\n"
           "│新建设施-----------1\n"
           "│借还设施-----------2\n"
           "│返回上层-----------3\n"
           "└───────────────────┘\n"
           "****************************************\n"
    );
    int choice7;
    scanf("%d", &choice7);
    switch (choice7) {
        case 1:
            addequip();
            break;
        case 2:
            inoutequip();
            break;
        case 3:
            main();
            break;
        default:{
            printf("选择失败:请输入有效数字!\n");
            equipmentscene();
            break;
        }
    }
}//!设备管理

void inoutequip() {
    printf("请输入借还的设施编号:\n");
    char info[20];
    scanf("%s",&info);
    FILE *fp = NULL;
    char buff[255];
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
        if(strcmp(substr[0],info)==0) {
            printf("┌───────────────────┐\n"
                   "│设施名称:%s\n"
                   "│使用情况:%s\n"
                   "└───────────────────┘\n",substr[1],substr[2]);
            if (strcmp(substr[0], info)==0) {
                printf("****************************************\n"
                       "请输入相应数字以选择服务:\n"
                       "┌───────────────────┐\n"
                       "│借用设备-----------1\n"
                       "│归还设备-----------2\n"
                       "│返回上层-----------3\n"
                       "└───────────────────┘\n"
                       "****************************************\n"
                );
                int choice8;
                scanf("%d", &choice8);
                switch (choice8) {
                    case 1:
                        lendequip(info);
                        break;
                    case 2:
                        returnequip(info);
                        break;
                    case 3:
                        equipmentscene();
                        break;
                    default: {
                        printf("选择失败:请输入有效数字!\n");
                        inoutequip();
                        break;
                    }
                }
            }
            break;
        }
    }
    if (feof(fp)) {
        printf("未找到该设施!\n"
               "***********************\n");
        inoutequip();
    }
    fclose(fp);
}//借还设施

void returnequip(char info[20]) {
    FILE *fp = NULL;
    char buff[255];
    struct equipment equiplist[255];
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
        struct equipment newequip;
        if(strcmp(substr[0],info)==0) {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.name[j]= substr[1][j];
            }
            newequip.usestate=0;
            equiplist[k]=newequip;
        } else {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.name[j]= substr[1][j];
            }
            newequip.usestate=atoi(substr[2]);
            equiplist[k]=newequip;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("equipdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%s,%d\n",equiplist[i].id,equiplist[i].name,equiplist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("归还设备成功!\n");
    equipmentscene();
}//!归还设施

void lendequip(char info[20]) {
    FILE *fp = NULL;
    char buff[255];
    struct equipment equiplist[255];
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
        struct equipment newequip;
        if(strcmp(substr[0],info)==0) {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.name[j]= substr[1][j];
            }
            newequip.usestate=1;
            equiplist[k]=newequip;
        } else {
            newequip.id = atoi(substr[0]);
            for(int j=0;j<20;j++) {
                newequip.name[j]= substr[1][j];
            }
            newequip.usestate=atoi(substr[2]);
            equiplist[k]=newequip;
        }
        k++;
    }
    FILE *fp2;
    fp2= fopen("equipdata.txt", "w");
    for(int i=0;i<k;i++) {
        fprintf(fp2,"%d,%s,%d\n",equiplist[i].id,equiplist[i].name,equiplist[i].usestate);
    }
    fclose(fp2);
    fclose(fp);
    printf("借用设备成功!\n");
    equipmentscene();
}//!借用设施

void addequip() {
    char name[20];
    printf("请输入设施名称:\n");
    scanf("%s",&name);
    FILE * f = 0;
    int lines=0;
    char line[256];
    f = fopen("equipdata.txt", "r");
    while(fgets(line, 255, (FILE *) f)!=NULL)
    {
        char *ptr, *retptr;
        ptr = line;
        char substr[3][20];
        int i = 0;
        while ((retptr = strtok(ptr, ",")) != NULL) {
            strcpy(substr[i++], retptr);
            ptr = NULL;
        }//分割字符串
        lines++;
    }
    fclose(f);
    int equipid=lines+1;
    printf("新建设施成功！\n"
           "设施编号为:%d\n",equipid);
    FILE *fp;
    fp= fopen("equipdata.txt", "a");
    fprintf(fp, "%d,%s,0\n",equipid,name);
    fclose(fp);
    equipmentscene();
}//!新建设施