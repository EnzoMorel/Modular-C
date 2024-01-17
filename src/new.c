/*
** Enzo Morel, 2024
** MODULAR C
** File:
** new.c
*/

#include "new.h"

void *new(const Class *class, ...)
{
    va_list ap;
    Object *new_object;

    va_start(ap, class);
    new_object = va_new(class, &ap);
    va_end(ap);
    return (new_object);
}

void *va_new(const Class *class, va_list *ap)
{
    Class *new_object = malloc(class->__size__);

    if (!new_object) {
        raise(OUT_OF_MEMORY);
    }
    memcpy(new_object, class, class->__size__);
    if (!new_object || new_object->__size__ < (sizeof(*class))) {
        raise(OUT_OF_MEMORY);
    }
    if (class->__ctor__) {
        class->__ctor__(new_object, ap);
    }
    return (new_object);
}

void delete(Object *ptr)
{
    const Class *class = ptr;

    if (class->__dtor__) {
        class->__dtor__(ptr);
    }
    free(ptr);
}
