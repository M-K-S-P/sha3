#include<stdio.h>
#define BUFFER_SIZE 1024

int* read_arr(int *si){

    char *t = NULL;
    int *arr = (int*)realloc(t, BUFFER_SIZE*sizeof(int));
    printf("letter \"a\" is the condition, when array ends\n");
    char cond = 'q';
    int co = 0;
    while(cond != 'a'){

        scanf("%c", &cond);
        if(cond != 'a'){ 
        
            arr[co] = (int)cond;
            co += 1;

        }

    }
    *si = co;
    return arr;

}