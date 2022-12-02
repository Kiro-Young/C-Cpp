#include <stdio.h>
#include<math.h>
char m[100005][100005];
void paint(int n,int row,int col,char arr[100005][100005]);
void digui(int n,int row ,int col,char lie[100005][100005]);//a是行，b是列
int main() {
    int n;
    scanf("%d", &n);
    int height = 2 * pow(2.0, n - 1);
    int length = 4 * pow(2.0, n - 1);
    for (int i = 0; i <=height ; ++i) {
        for (int j = 0; j <=length ; ++j) {
            m[i][j]=' ';
        }
    }
    

    digui(n, 0, length/2, m);
    for (int i = 0; i <=  height ;i++) {
        for (int j = 1; j <=length; ++j) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }

return 0;
}

    void paint(int n, int row, int col,char arr[100005][100005]) {

        if (n == 1) {
            arr[row][col] = '/';
            arr[row][col + 1] = '\\';
            arr[row + 1][col - 1] = '/';
            arr[row + 1][col + 2] = '\\';
            arr[row + 1][col] = '_';
            arr[row + 1][col + 1] = '_';
          
        }
    }
    void digui(int n, int row, int col,char lie[100005][100005])
    {
        int height = 2 * pow(2.0, n - 1);
        int length = 4 * pow(2.0, n - 1);
        if (n > 1) {
            digui(n - 1, row + height / 2, col +length/4,lie);
            digui(n - 1, row + height / 2, col -length/4,lie);
            digui(n - 1, row, col, lie);

        }
        if (n == 1) { paint(n, row, col, lie); }
    }
