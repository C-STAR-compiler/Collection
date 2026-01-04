#if defined(STR_H) || defined(COLLECTION) || 1
// TODO: Eventually add a preprocessor variable with the name of the lib

#ifndef COLLECTION_STR_H
#define COLLECTION_STR_H

#include <diagnostic.h>
#include <oop.h>
#include <array.h>
#include <objectarray.h>
#include <pair.h>
#include <map.h>
#include <list.h>
#include <str.h>

#include "collection.export.h"

#define TYPENAME String

COLLECTION_EXPORT ObjectArray *_(Split)(const char *other);

#undef TYPENAME

#define TYPENAME Array

COLLECTION_EXPORT String *CONST (ToStringFormat) (const char *format) VIRTUAL (ToStringFormat);

#undef TYPENAME

#define TYPENAME ObjectArray

COLLECTION_EXPORT String *_(Join)(const char *link);

COLLECTION_EXPORT String *CONST (ToString) () VIRTUAL (ToString);

#undef TYPENAME

#define TYPENAME Pair

COLLECTION_EXPORT String *CONST (ToString) () VIRTUAL (ToString);

#undef TYPENAME

#define TYPENAME Map

FOREIGN_VIRTUAL(ToString, ObjectArray_ToString);

#undef TYPENAME

#define TYPENAME Set

FOREIGN_VIRTUAL(ToString, ObjectArray_ToString);

#undef TYPENAME

#define TYPENAME List

COLLECTION_EXPORT String *CONST (ToString) (const char *format) VIRTUAL (ToString);

#undef TYPENAME

#endif

#endif