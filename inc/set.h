#ifndef SET_H
#define SET_H

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "objectarray.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME Set

OBJECT (const Type *type) INHERIT (ObjectArray)
  Comparer comparer;
  Comparer keyComparer;
END_OBJECT(TYPEOF (void*));

COLLECTION_EXPORT int CONST (Contains)(const void *data);
COLLECTION_EXPORT int CONST (ContainsKey)(const void *data);

COLLECTION_EXPORT int   _(Add)(void *data);
COLLECTION_EXPORT int   _(AddValue)(const Type *type, void *data);
COLLECTION_EXPORT int   _(Remove)(const void *data);
COLLECTION_EXPORT int   _(RemoveKey)(const void *data);
COLLECTION_EXPORT Set  *_(Union)(Set *other);
COLLECTION_EXPORT Set  *_(Intersect)(Set *other);

#undef TYPENAME
#undef LIB_EXPORT

#endif