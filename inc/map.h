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

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME Map

// In maps, efficient comparison is essential
// this is why we compute the comparer in the constructor here

OBJECT (const Type *key) INHERIT (List)
  Comparer comparer;
  Comparer keyComparer;
END_OBJECT(TYPEOF (const char*));

PUBLIC Pair *_(Set)(void *key, void *value);
PUBLIC Pair *_(SetKey)(const void *key, void *value);
PUBLIC Pair *_(SetValue)(void *key, const Type *valueType, void *value);
PUBLIC Pair *_(SetKeyValue)(const void *key, const Type *valueType, void *value);
PUBLIC void  _(Remove)(const void *key);
PUBLIC void  _(RemoveKey)(const void *key);

PUBLIC Pair *CONST (At)(const void *key);
PUBLIC Pair *CONST (AtKey)(const void *key);
PUBLIC void *CONST (ValueAt)(const void *key);
PUBLIC void *CONST (ValueAtKey)(const void *key);
PUBLIC void *CONST (ValueAtDeref)(const void *key);
PUBLIC void *CONST (ValueAtKeyDeref)(const void *key);

#undef TYPENAME
#undef PUBLIC

#endif