#include <stdio.h>
#include <stdlib.h>

int input(int **array, int *size);
void output(int *array, int size);
void bubbleSort(int *array, int size);

int main() {
    int is_error = 0;
    int* array = NULL;
    int size = 0;
    is_error = input(&array,&size);
    if (is_error == 0) {
        bubbleSort(array,size);
        output(array,size);
    } else {
        printf("n/a");
    }

    free(array);
    return 0;
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++)
        for (int *p = array; p - array < size - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
}

int input(int **array, int *size) {
    int is_error = 0;

    scanf("%d", size);
    *array = (int*)malloc(sizeof(int) * *size);
    for (int *p = *array; p - *array < *size; p++) {
        if (scanf("%d", p) != 1) {
            is_error = 1;
            break;
        }
    }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        is_error = 1;
    return is_error;
}

void output(int *array, int size) {
    for (int *p = array; p - array < size; p++) {
        printf("%d", *p);
     if (p - array != size -1)
         printf(" ");
    }
}
