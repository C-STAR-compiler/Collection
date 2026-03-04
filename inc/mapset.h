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

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME MapSet

// In maps, efficient comparison is essential
// this is why we compute the comparer in the constructor here

OBJECT (const Type *key) INHERIT (Set)
  KeyValEnvironment env;
END_OBJECT(TYPEOF (const char*));

PUBLIC void _(Env)(EnvComparer comparer, EnvComparer keyComparer, void *env);

PUBLIC KeyVal *_(Set)(void *key, void *value);
PUBLIC KeyVal *_(SetKey)(const void *key, void *value);
PUBLIC KeyVal *_(SetValue)(void *key, const Type *valueType, void *value);
PUBLIC KeyVal *_(SetKeyValue)(const void *key, const Type *valueType, void *value);
PUBLIC void    _(Remove)(const void *key);
PUBLIC void    _(RemoveKey)(const void *key);

PUBLIC KeyVal *CONST (At)(const void *key);
PUBLIC KeyVal *CONST (AtKey)(const void *key);
PUBLIC void   *CONST (ValueAt)(const void *key);
PUBLIC void   *CONST (ValueAtKey)(const void *key);
PUBLIC void   *CONST (ValueAtDeref)(const void *key);
PUBLIC void   *CONST (ValueAtKeyDeref)(const void *key);

#undef TYPENAME
#undef PUBLIC

#endif