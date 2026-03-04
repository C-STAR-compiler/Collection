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

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME List

OBJECT () INHERIT (Pair)
END_OBJECT();

PUBLIC void   *CONST (Head)();
PUBLIC void   *CONST (HeadDeref)();
PUBLIC void   *CONST (Next)();
PUBLIC int     CONST (Empty)();

PUBLIC void   *CONST (At)(int index);
PUBLIC void   *CONST (AtDeref)(int index);
PUBLIC int     CONST (Size)();
PUBLIC void   *CONST (Contains)(const void *element);
PUBLIC void   *CONST (ContainsKey)(const void *key);

PUBLIC List   *CONST (Push)(void *element);
PUBLIC List   *CONST (PushValue)(const Type *type, void *element);

PUBLIC List *_(Fill)(...);

PUBLIC List *_(Pop)(void **object);

PUBLIC List *_(Add)(void *element);
PUBLIC List *_(AddValue)(const Type *type, void *element);

PUBLIC void  _(Remove)(void **object);

PUBLIC List *_(Set)(int index, void *element);
PUBLIC List *_(SetValue)(int index, const Type *type, void *element);

PUBLIC List *_(Insert)(int index, void *element);
PUBLIC List *_(InsertValue)(int index, const Type *type, void *element);

PUBLIC void  _(RemoveAt)(int index, void **object);

PUBLIC void _(Merge)(List *other);

PUBLIC void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef PUBLIC

#endif