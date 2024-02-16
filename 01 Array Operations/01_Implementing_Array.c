#include <stdio.h>
#include <stdlib.h>

// ====================== My Array ======================
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

// ====================== Create Array ======================
void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

// ====================== Show ======================
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

// ====================== Set Val ======================
void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

// ====================== Main ======================
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show now\n");
    show(&marks);

    return 0;
}

// ==================================================================