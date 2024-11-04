// LIFO (Last in; first out)
#include <stdio.h>
#include <stdlib.h>

int *array;

int size = 2;
int top = 0;

int pop() {
    if (top <= size / 4) {
        int *array2 = (int *) malloc(sizeof(int) * size / 2);
        for (int i = 0; i < size; i++) {
            array2[i] = array[i];
        }
        free(array);
        array = array2;
        size = size / 2;
    }
    return array[--top];
}

void push(int newValue) {
    if (top >= size) {
        int *array2 = (int *) malloc(sizeof(int) * size * 2);
        for (int i = 0; i < size; i++) {
            array2[i] = array[i];
        }
        free(array);
        array = array2;
        size = size * 2;
    }
    array[top++] = newValue;
}

void printArray() {
    for (int i = 0; i < top; i++) {
        printf("%d\n", array[i]);
    }
}

int main() {
    array = (int *) malloc(sizeof(int) * 2);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printArray();
    pop();
    pop();
    pop();
    printf("/****************/\n");
    printArray();
    //printf("%d", array[]);
}