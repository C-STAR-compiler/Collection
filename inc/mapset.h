#ifndef MAPSET_H
#define MAPSET_H

// C
#include <string.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <oop.h>

#include "set.h"
#include "keyval.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME MapSet

// In maps, efficient comparison is essential
// this is why we compute the comparer in the constructor here

OBJECT (const Type *key) INHERIT (Set)
  KeyValEnvironment env;
END_OBJECT(TYPEOF (const char*));

COLLECTION_EXPORT void _(Env)(EnvComparer comparer, EnvComparer keyComparer, void *env);

COLLECTION_EXPORT KeyVal *_(Set)(void *key, void *value);
COLLECTION_EXPORT KeyVal *_(SetKey)(const void *key, void *value);
COLLECTION_EXPORT KeyVal *_(SetValue)(void *key, const Type *valueType, void *value);
COLLECTION_EXPORT KeyVal *_(SetKeyValue)(const void *key, const Type *valueType, void *value);
COLLECTION_EXPORT void    _(Remove)(const void *key);
COLLECTION_EXPORT void    _(RemoveKey)(const void *key);

COLLECTION_EXPORT KeyVal *CONST (At)(const void *key);
COLLECTION_EXPORT KeyVal *CONST (AtKey)(const void *key);
COLLECTION_EXPORT void   *CONST (ValueAt)(const void *key);
COLLECTION_EXPORT void   *CONST (ValueAtKey)(const void *key);
COLLECTION_EXPORT void   *CONST (ValueAtDeref)(const void *key);
COLLECTION_EXPORT void   *CONST (ValueAtKeyDeref)(const void *key);

#undef TYPENAME
#undef COLLECTION_EXPORT

#endif