#include<stdio.h>
#include<stdlib.h>


int main(){
	int Arr[4] = {9, 4, 7};
    int *p;
    p = Arr;
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
}
