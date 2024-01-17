/*
** Enzo Morel, 2024
** MODULAR C
** File:
** vertex.c
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args) {
        raise(BAD_PARAMETERS);
    }
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this) {
        raise(BAD_PARAMETERS);
    }
}

static char *Vertex_str(const VertexClass *obj)
{
    char *string;
    size_t needed;

    if (!obj) {
        raise(BAD_PARAMETERS);
    }
    needed = snprintf(NULL, 0, "<%s (%d, %d, %d)>", obj->base.__name__, obj->x, obj->y, obj->z);
    string = malloc(sizeof(char) * (needed + 1));
    if (!string) {
        raise(OUT_OF_MEMORY);
    }
    sprintf(string, "<%s (%d, %d, %d)>", obj->base.__name__, obj->x, obj->y, obj->z);
    return (string);
}

static Object *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    Object *new_obj = NULL;

    if (!this || !other) {
        raise(BAD_PARAMETERS);
    }
    new_obj = new(Vertex, this->x + other->x, this->y + other->y, this->z + other->z);
    printf("%s + %s = %s\n", str(this), str(other), str(new_obj));
    return (new_obj);
}

static Object *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    Object *new_obj = NULL;

    if (!this || !other) {
        raise(BAD_PARAMETERS);
    }
    new_obj = new(Vertex, this->x - other->x, this->y - other->y, this->z - other->z);
    printf("%s - %s = %s\n", str(this), str(other), str(new_obj));
    return (new_obj);
}

static Object *Vertex_mul(const VertexClass *this, const VertexClass *other)
{
    Object *new_obj = NULL;

    if (!this || !other) {
        raise(BAD_PARAMETERS);
    }
    new_obj = new(Vertex, this->x * other->x, this->y * other->y, this->z * other->z);
    printf("%s * %s = %s\n", str(this), str(other), str(new_obj));
    return (new_obj);
}

static Object *Vertex_div(const VertexClass *this, const VertexClass *other)
{
    Object *new_obj = NULL;

    if (!this || !other) {
        raise(BAD_PARAMETERS);
    }
    if (other->x == 0 || other->y == 0 || other->z == 0) {
        raise(FLOATING_POINT_EXCEPTION);
    }
    new_obj = new(Vertex, this->x / other->x, this->y / other->y, this->z / other->z);
    printf("%s / %s = %s\n", str(this), str(other), str(new_obj));
    return (new_obj);
}

static bool Vertex_eq(const VertexClass *this, const VertexClass *other)
{
    if (!this || !other) {
        raise("Parameter is empty\n");
    }
    printf("%s = %s = ", str(this), str(other));
    if (this->x == other->x && this->y == other->y && this->z == other->z) {
        printf("true\n");
        return (true);
    }
    printf("false\n");
    return (false);
}

static bool Vertex_gt(const VertexClass *this, const VertexClass *other)
{
    if (!this || !other) {
        raise("Parameter is empty\n");
    }
    printf("%s = %s = ", str(this), str(other));
    if (this->x > other->x && this->y > other->y && this->z > other->z) {
        printf("true\n");
        return (true);
    }
    printf("false\n");
    return (false);
}

static bool Vertex_lt(const VertexClass *this, const VertexClass *other)
{
    if (!this || !other) {
        raise("Parameter is empty\n");
    }
    printf("%s < %s = ", str(this), str(other));
    if (this->x < other->x && this->y < other->y && this->z < other->z) {
        printf("true\n");
        return (true);
    }
    printf("false\n");
    return (false);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt,
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
