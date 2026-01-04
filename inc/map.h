#ifndef MAP_H
#define MAP_H

// C
#include <string.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <oop.h>

#include "list.h"
#include "comparer.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME Map

// In maps, efficient comparison is essential
// this is why we compute the comparer in the constructor here

OBJECT (const Type *key) INHERIT (List)
  Comparer comparer;
  Comparer keyComparer;
END_OBJECT(TYPEOF (const char*));

COLLECTION_EXPORT Pair *_(Set)(void *key, void *value);
COLLECTION_EXPORT Pair *_(SetKey)(const void *key, void *value);
COLLECTION_EXPORT Pair *_(SetValue)(void *key, const Type *valueType, void *value);
COLLECTION_EXPORT Pair *_(SetKeyValue)(const void *key, const Type *valueType, void *value);
COLLECTION_EXPORT void  _(Remove)(const void *key);
COLLECTION_EXPORT void  _(RemoveKey)(const void *key);

COLLECTION_EXPORT Pair *CONST (At)(const void *key);
COLLECTION_EXPORT Pair *CONST (AtKey)(const void *key);
COLLECTION_EXPORT void *CONST (ValueAt)(const void *key);
COLLECTION_EXPORT void *CONST (ValueAtKey)(const void *key);
COLLECTION_EXPORT void *CONST (ValueAtDeref)(const void *key);
COLLECTION_EXPORT void *CONST (ValueAtKeyDeref)(const void *key);

#undef TYPENAME
#undef LIB_EXPORT

#endif