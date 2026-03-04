#ifndef PAIR_H
#define PAIR_H

#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "comparer.h"

#include "collection.export.h"

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME Pair

OBJECT () NOBASE
  void *first;
  void *second;
END_OBJECT();

PUBLIC Pair *STATIC (From)(void *first, void *second);

PUBLIC void *_(SetF)(void *element);
PUBLIC void *_(SetS)(void *element);

PUBLIC void *_(SetValueF)(const Type *type, void *element);
PUBLIC void *_(SetValueS)(const Type *type, void *element);

PUBLIC void     *CONST (FDeref)();
PUBLIC void     *CONST (SDeref)();

#undef TYPENAME
#undef PUBLIC

#endif