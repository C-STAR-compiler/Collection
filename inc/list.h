#ifndef LIST_H
#define LIST_H

// C
#include <stdarg.h>

// CUT
#include <diagnostic.h>
#include <oop.h>

#include "pair.h"
#include "comparer.h"
#include "iterator.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME List

OBJECT () INHERIT (Pair)
END_OBJECT();

COLLECTION_EXPORT void   *CONST (Head)();
COLLECTION_EXPORT void   *CONST (HeadDeref)();
COLLECTION_EXPORT void   *CONST (Next)();
COLLECTION_EXPORT int     CONST (Empty)();

COLLECTION_EXPORT void   *CONST (At)(int index);
COLLECTION_EXPORT void   *CONST (AtDeref)(int index);
COLLECTION_EXPORT int     CONST (Size)();
COLLECTION_EXPORT void   *CONST (Contains)(const void *element);
COLLECTION_EXPORT void   *CONST (ContainsKey)(const void *key);

COLLECTION_EXPORT List   *CONST (Push)(void *element);
COLLECTION_EXPORT List   *CONST (PushValue)(const Type *type, void *element);

COLLECTION_EXPORT List *_(Fill)(...);

COLLECTION_EXPORT List *_(Pop)(void **object);

COLLECTION_EXPORT List *_(Add)(void *element);
COLLECTION_EXPORT List *_(AddValue)(const Type *type, void *element);

COLLECTION_EXPORT void  _(Remove)(void **object);

COLLECTION_EXPORT List *_(Set)(int index, void *element);
COLLECTION_EXPORT List *_(SetValue)(int index, const Type *type, void *element);

COLLECTION_EXPORT List *_(Insert)(int index, void *element);
COLLECTION_EXPORT List *_(InsertValue)(int index, const Type *type, void *element);

COLLECTION_EXPORT void  _(RemoveAt)(int index, void **object);

COLLECTION_EXPORT void _(Merge)(List *other);

COLLECTION_EXPORT void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef LIB_EXPORT

#endif