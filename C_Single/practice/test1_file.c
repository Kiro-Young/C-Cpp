#include <stdio.h>

int main(){
    FILE *Number;
    Number = fopen("Number.txt","w");
    int a[10000],i;
    for(i = 0; i < 10000; i++){
        a[i] = i;
    }
    for(i = 0; i < 10000; i++){
        while(a[i] > 80){
            a[i] = a[i] - 80; 
        }
        fprintf(Number,"%d\n",a[i]);
    }
}