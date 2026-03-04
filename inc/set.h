#ifndef SET_H
#define SET_H

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "objectarray.h"

#include "collection.export.h"

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME Set

OBJECT (const Type *type) INHERIT (ObjectArray)
  Comparer comparer;
  Comparer keyComparer;
END_OBJECT(TYPEOF (void*));

PUBLIC int CONST (Contains)(const void *data);
PUBLIC int CONST (ContainsKey)(const void *data);

PUBLIC int   _(Add)(void *data);
PUBLIC int   _(AddValue)(const Type *type, void *data);
PUBLIC int   _(Remove)(const void *data);
PUBLIC int   _(RemoveKey)(const void *data);
PUBLIC Set  *_(Union)(Set *other);
PUBLIC Set  *_(Intersect)(Set *other);

#undef TYPENAME
#undef PUBLIC

#endif