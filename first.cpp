#include <stdio.h>
#define MAX 100

int arr[MAX], n = 0;

void create() {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void display() {
    int i;
    if (n == 0) { printf("Empty\n"); return; }
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insert() {
    int pos, val, i;
    scanf("%d %d", &pos, &val);
    if (pos < 0 || pos > n) return;
    for (i = n; i > pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    n++;
}

void delete() {
    int pos, i;
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) return;
    for (i = pos; i < n-1; i++) arr[i] = arr[i+1];
    n--;
}

void linear_search() {
    int key, i, f = 0;
    scanf("%d", &key);
    for (i = 0; i < n; i++) if (arr[i] == key) { printf("%d ", i); f = 1; }
    if (!f) printf("Not Found");
    printf("\n");
}

void remove_duplicates() {
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < k; j++) if (arr[i] == arr[j]) { found = 1; break; }
        if (!found) arr[k++] = arr[i];
    }
    n = k;
}

void reverse() {
    int i, t;
    for (i = 0; i < n/2; i++) {
        t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;
    }
}

void matrix_multiply() {
    int r1,c1,r2,c2,i,j,k;
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if (c1 != r2) return;
    int A[r1][c1], B[r2][c2], C[r1][c2];
    for (i=0;i<r1;i++) for (j=0;j<c1;j++) scanf("%d",&A[i][j]);
    for (i=0;i<r2;i++) for (j=0;j<c2;j++) scanf("%d",&B[i][j]);
    for (i=0;i<r1;i++) for (j=0;j<c2;j++) C[i][j]=0;
    for (i=0;i<r1;i++) for (j=0;j<c2;j++) for (k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
    for (i=0;i<r1;i++){ 
        for (j=0;j<c2;j++) printf("%d ",C[i][j]); 
        printf("\n"); 
    }
}

void transpose() {
    int r,c,i,j;
    scanf("%d%d",&r,&c);
    int A[r][c], T[c][r];
    for (i=0;i<r;i++) for (j=0;j<c;j++) scanf("%d",&A[i][j]);
    for (i=0;i<r;i++) for (j=0;j<c;j++) T[j][i] = A[i][j];
    for (i=0;i<c;i++){ 
        for (j=0;j<r;j++) printf("%d ",T[i][j]); 
        printf("\n"); 
    }
}

void row_col_sum() {
    int r,c,i,j;
    scanf("%d%d",&r,&c);
    int A[r][c];
    for (i=0;i<r;i++) for (j=0;j<c;j++) scanf("%d",&A[i][j]);
    for (i=0;i<r;i++){
        int s=0;
        for (j=0;j<c;j++) s+=A[i][j];
        printf("%d ",s);
    }
    printf("\n");
    for (j=0;j<c;j++){
        int s=0;
        for (i=0;i<r;i++) s+=A[i][j];
        printf("%d ",s);
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: linear_search(); break;
            case 6: remove_duplicates(); break;
            case 7: reverse(); break;
            case 8: matrix_multiply(); break;
            case 9: transpose(); break;
            case 10: row_col_sum(); break;
            case 11: return 0;
        }
    }
}
