/*
** Enzo Morel, 2024
** MODULAR C
** File:
** new.h
*/

#ifndef NEW_H_
#define NEW_H_

#include <stdarg.h>
#include "object.h"

#define OUT_OF_MEMORY "No more memory.\n"
#define BAD_PARAMETERS "Invalid parameter.\n"
#define FLOATING_POINT_EXCEPTION "Floating point exception.\n"

void delete(Object *ptr);
Object *new(const Class *class, ...);
Object *va_new(const Class *class, va_list* ap);

#endif // NEW_H_
