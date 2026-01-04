#ifndef OBJECT_ARRAY_H
#define OBJECT_ARRAY_H

// C
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "array.h"
#include "comparer.h"

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME ObjectArray

OBJECT (const Type *type) INHERIT (Array)
  const Type *type;
  void       *buffer;
END_OBJECT(TYPEOF (void*));

// Fills the array with objects
COLLECTION_EXPORT ObjectArray *_(Fill)(...);

// Fills the array with values
COLLECTION_EXPORT ObjectArray *_(FillValues)(const Type *type, ...);

// Sets the size of the array to the desired value. Recaps if necessary.
COLLECTION_EXPORT int    _(Resize)(int newSize);

// Inserts an object at index
COLLECTION_EXPORT void  *_(Insert)(int index, void *element);

// Inserts an element at index
COLLECTION_EXPORT void  *_(InsertValue)(int index, const Type *type, void *element);

// Pushes a new object onto the array
COLLECTION_EXPORT void  *_(Push)(void *element);

// Pushes a new value onto the array
COLLECTION_EXPORT void  *_(PushValue)(const Type *type, void *element);

// Pushes a new object onto the array
COLLECTION_EXPORT void  *_(Add)(void *element);

// Pushes a new element onto the array
COLLECTION_EXPORT void  *_(AddValue)(const Type *type, void *element);

// Sets the object at index
COLLECTION_EXPORT void  *_(Set)(int index, void *element);

// Sets the value at index
COLLECTION_EXPORT void  *_(SetValue)(int index, const Type *type, void *element);

// Removes the element at index and returns a pointer to it
COLLECTION_EXPORT void  *_(RemoveAt)(int index, int get);

// Pops the last element of the array and returns a pointer to it
COLLECTION_EXPORT void  *_(Pop)(int get);

// Removes the element at index and returns a pointer to it
COLLECTION_EXPORT void  *_(Remove)(int get);

// Removes a range of elements starting at index start
COLLECTION_EXPORT int    _(RemoveRange)(int start, int range);

// Clears the array
COLLECTION_EXPORT void   _(Clear)();

// Returns a copy of the object with type information present
COLLECTION_EXPORT void  *CONST (At)(int index);

// Returns a pointer to the element targeted if present
COLLECTION_EXPORT void  *CONST (Contains)(const void *reference);

// Returns a pointer to the element that contains the targeted base if present
COLLECTION_EXPORT void  *CONST (ContainsKey)(const void *reference);

// Returns the index of the element targeted
COLLECTION_EXPORT int    CONST (IndexOf)(const void *reference);

// Returns the index of the element that contains the targeted base
COLLECTION_EXPORT int    CONST (IndexOfKey)(const void *reference);

// Returns the iterator associated with the array
COLLECTION_EXPORT void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef LIB_EXPORT

#endif
