#include<stdio.h>
#include<stdlib.h>
#define MAXINT 99999
#define ARRSIZE 100

int main(){
	int i,k;
	int arr[ARRSIZE];
    scanf("%d", &k);
	
    if(k > ARRSIZE-1){
        exit(0);
    }

	for(i = 0; i <= k; i++){
		if(i == 0){
            arr[i] = 1;
        }else{
		    if(2 * i * arr[i-1] > MAXINT){
                exit(0);
            }else{
                arr[i] = 2 * i * arr[i-1];
            }
		}
	}

    for (i = 0; i <= k; i++){
        if (arr[i] > MAXINT){
            exit(0);
        }else{
            printf("%d", arr[i]);
        }
    }
}