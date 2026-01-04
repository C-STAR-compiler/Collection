#ifndef KEYVAL_H
#define KEYVAL_H

#include <diagnostic.h>
#include <oop.h>

#include "pair.h"
#include "set.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME KeyVal

typedef int (*EnvComparer)(void *against, void *reference, void *envptr);

typedef struct {
  Comparer  comparer;
  Comparer  keyComparer;
  void     *pointer; // Use this to retrieve any information from the comparer
} KeyValEnvironment;

OBJECT (KeyValEnvironment *env) INHERIT (Pair)
  KeyValEnvironment *env;
END_OBJECT(NULL);

COLLECTION_EXPORT int _(Comparer)   (KeyVal *reference) VIRTUAL (Comparer);
COLLECTION_EXPORT int _(KeyComparer)(KeyVal *reference) VIRTUAL (KeyComparer);

COLLECTION_EXPORT int _(EnvComparer)   (KeyVal *reference);
COLLECTION_EXPORT int _(EnvKeyComparer)(KeyVal *reference);

#undef TYPENAME
#undef LIB_EXPORT

#endif