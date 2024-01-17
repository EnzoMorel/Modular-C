# **Modular-C** #

### Purpose
Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data and code: data in the form of fields (also
known as attributes or properties), and code, in the form of methods. It is a modern and different approach to programming.

Here is a set of functions and structures allowing to realize oriented object programs in C.

### Main Features
- Class
- Encapsulation
- Inheritance / Multiple inheritance
- Containers / Iterators
- Operators overloading

### Usage
---
new and delete are a pair of functions that perform dynamic memory allocation, object construction and object destruction.
```
Object *new(const Class *class, ...);
void delete(Object *ptr);
```
example :
```
Object  *v1 = new(Vertex, 1, 2, 3);
delete(v1);
```
---
Initialization of a class :
```
typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;
```
- To add a constructor you must pass the address of a function of type `void ctor(Object *this, va_list *args)`
- To add a destructor you must pass the address of a function of type `void ctor(Object *this)`
- To overload arithmetic operators you must pass the address of a function of type `Object *operator(const Object *this, const Object *other)`
- To overload comparison operators you must pass the address of a function of type `bool operator(const Object *this, const Object *other)`

example :
```
static const VertexClass _description = {
    { // Class struct
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
```
example of operators overloading :
```
#define addition(a, b)         ((Class *)a)->__add__(a, b)
#define substraction(a, b)     ((Class *)a)->__sub__(a, b)
#define multiplication(a, b)   ((Class *)a)->__mul__(a, b)
#define division(a, b)         ((Class *)a)->__div__(a, b)
#define eq(a, b)               ((Class *)a)->__eq__(a, b)
#define gt(a, b)               ((Class *)a)->__gt__(a, b)
#define lt(a, b)               ((Class *)a)->__lt__(a, b)

Object *v3 = addition(v1, v2);
Object *v4 = substraction(v1, v2);
Object *v5 = division(v1, v2);
Object *v6 = multiplication(v1, v2);

bool is_eq = eq(v1, v2);
bool is_gt = gt(v1, v2);
bool is_lt = lt(v1, v2);
```
---
Containers and Iterators :

A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

example of how to use the Array container :
```
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
```
