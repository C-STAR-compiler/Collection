#ifndef PAIR_H
#define PAIR_H

#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "comparer.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME Pair

OBJECT () NOBASE
  void *first;
  void *second;
END_OBJECT();

COLLECTION_EXPORT Pair *STATIC (From)(void *first, void *second);

COLLECTION_EXPORT void *_(SetF)(void *element);
COLLECTION_EXPORT void *_(SetS)(void *element);

COLLECTION_EXPORT void *_(SetValueF)(const Type *type, void *element);
COLLECTION_EXPORT void *_(SetValueS)(const Type *type, void *element);

COLLECTION_EXPORT void     *CONST (FDeref)();
COLLECTION_EXPORT void     *CONST (SDeref)();

#undef TYPENAME
#undef LIB_EXPORT

#endif