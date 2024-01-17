/*
** Enzo Morel, 2024
** MODULAR C
** File:
** examples.c
*/

#include <stdio.h>
#include "new.h"
#include "array.h"
#include "vertex.h"

void example_1(void)
{
    Object  *v1 = new(Vertex, 1, 2, 3);
    Object  *v2 = new(Vertex, 4, 5, 6);

    Object *v3 = addition(v1, v2);
    Object *v4 = substraction(v1, v2);
    Object *v5 = multiplication(v1, v2);
    Object *v6 = division(v1, v2);

    eq(v1, v2);
    gt(v1, v2);
    lt(v1, v2);

    delete(v1);
    delete(v2);
    delete(v3);
    delete(v4);
    delete(v5);
    delete(v6);
}

void example_2(void)
{
    Object *array = new(Array, 10, Vertex, 0, 0, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    printf("array size: %zu\n", len(array));

    setitem(array, 5, 1, 2, 3);
    setitem(array, 6, 4, 5, 6);

    while (lt(it, it_end)) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    delete(it);
    delete(it_end);
    delete(array);
}

int main(void)
{
    printf("Example 1 (new, overloading operators) :\n");
    example_1();

    printf("\nExample 2 (containers, iterators, array) :\n");
    example_2();
}
