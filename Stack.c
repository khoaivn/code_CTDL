#include <stdio.h>
int max = 100;
void createStack(int *top){
    *top = -1;
}
void pushStack(int m, int Arr[], int *top){
    if (*top < 99){
        (*top)++;
        Arr[*top] = m;
    } else 
        printf("Stack full!");
}
void printStack(int Arr[], int top){
    for (int i = 0; i <= top; i++)
        printf("%d  ", Arr[i]);
    printf("\n");
}

int pullStack(int Arr[], int *top){
    if (*top == -1){
        printf("Stack rong!");
        return -1;
    } else {
        int tmp = Arr[*top];
        (*top)--;
        return tmp;
    }
}
int main(){
    int A[max];
    int top;
    createStack(&top);
    // pushStack(3, A, &top);
    // pushStack(1, A, &top);
    // pushStack(6, A, &top);
    // printStack(A, top);
    printf("%d\n", pullStack(A, &top));
    printStack(A, top);
    return 0;
}