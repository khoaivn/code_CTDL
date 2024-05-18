#include <stdio.h>
int max = 7;
void createQueue(int *l, int *r, int *c){
    *l = 0;
    *r = -1;
    *c = 0;
}
void pushQueue(int m, int Arr[], int *r, int *c){
    if (*c < max){
        if (*r == max - 1)
            *r = 0;
        else
            (*r)++;
        (*c)++;
        Arr[*r] = m;    
    } else
        printf("Queue full!\n");
}
void printQueue(int Arr[], int l, int r){
    for (int i = 0; i < max; i++)
        printf("%d  ", Arr[i]);
    printf("\n");
}

int pullQueue(int Arr[], int *l, int *c){
    if (*c > 0){
        int tmp = Arr[*l];
        if (*l == max - 1)
            *l = 0;
        else
            (*l)++;
        (*c)--;
        return tmp;
    } else {
        printf("Queue empty\n");
        return -1;
    }
}
int main(){
    int A[max];
    int left, right, count;
    createQueue(&left, &right, &count);
    pushQueue(1, A, &right, &count);
    pushQueue(2, A, &right, &count);
    pushQueue(3, A, &right, &count);
    // printQueue(A, left, right);
    printf("%d\n", pullQueue(A, &left, &count));
    printf("%d\n", pullQueue(A, &left, &count));
    // printf("%d\n", pullQueue(A, &left, &count));
    // printQueue(A, left, right);
    pushQueue(4, A, &right, &count);
    pushQueue(5, A, &right, &count);
    pushQueue(6, A, &right, &count);
    pushQueue(7, A, &right, &count);
    pushQueue(8, A, &right, &count);
    pushQueue(9, A, &right, &count);
    printQueue(A, left, right);
    return 0;
}