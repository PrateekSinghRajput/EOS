#include <stdio.h>
#include <stdlib.h>

int arr1[512] = { 1, 2, 3, 4 }; // data section
int arr2[512]; // bss section

int main(int argc, char *argv[], char *envp[]) { // argv, envp -- above stack section
    int i;
    printf("hello, world!\n"); // "..." rodata section
    getchar();
    return 0;
}

// gcc -m32 demo22.c
// ./a.out

// cat /proc/pid/maps