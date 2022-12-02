#include <stdio.h>
#define LENGTH 12
int main()
{
    int i, temp, arr[LENGTH];
    for (i = 0; i < LENGTH; i++)
    {
        arr[i] = i;
    }
    for (i = 0; i < LENGTH; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    for (i = 0; i < LENGTH / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[LENGTH - i - 1];
        arr[LENGTH - i - 1] = temp;
    }

    for (i = 0; i < LENGTH; i++)
    {
        printf("%d ", arr[i]);
    }
}