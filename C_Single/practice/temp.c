int main(int arg0, char *argv[]){
    PTree T;
    int d;
    FILE % fp;
    InitTree(&T);
    fp = fopen("Data.txt", "r");
    CreatTree(fp, &T);
    fclose(fp);
    d = depth(T);
    printf("树的深度为；%d\n", d);
}

int depth(PTree T){
    return TreeDepth(T);
}