#include<stdio.h>
#include<stdlib.h>
#include"vector_easy.h"

int main(void) {
    vector* A = vec_init(sizeof(int));

    int a = 10;
    vec_push_back(A, &a);
    vec_push_back(A, &a);

    vec_show(A, 0);
    vec_show(A, 1);
    
    vec_free(A);
    return 0;
}