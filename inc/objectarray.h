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

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME ObjectArray

OBJECT (const Type *type) INHERIT (Array)
  const Type *type;
  void       *buffer;
END_OBJECT(TYPEOF (void*));

// Fills the array with objects
PUBLIC ObjectArray *_(Fill)(...);

// Fills the array with values
PUBLIC ObjectArray *_(FillValues)(const Type *type, ...);

// Sets the size of the array to the desired value. Recaps if necessary.
PUBLIC int    _(Resize)(int newSize);

// Inserts an object at index
PUBLIC void  *_(Insert)(int index, void *element);

// Inserts an element at index
PUBLIC void  *_(InsertValue)(int index, const Type *type, void *element);

// Pushes a new object onto the array
PUBLIC void  *_(Push)(void *element);

// Pushes a new value onto the array
PUBLIC void  *_(PushValue)(const Type *type, void *element);

// Pushes a new object onto the array
PUBLIC void  *_(Add)(void *element);

// Pushes a new element onto the array
PUBLIC void  *_(AddValue)(const Type *type, void *element);

// Sets the object at index
PUBLIC void  *_(Set)(int index, void *element);

// Sets the value at index
PUBLIC void  *_(SetValue)(int index, const Type *type, void *element);

// Removes the element at index and returns a pointer to it
PUBLIC void  *_(RemoveAt)(int index, int get);

// Pops the last element of the array and returns a pointer to it
PUBLIC void  *_(Pop)(int get);

// Removes the element at index and returns a pointer to it
PUBLIC void  *_(Remove)(int get);

// Removes a range of elements starting at index start
PUBLIC int    _(RemoveRange)(int start, int range);

// Clears the array
PUBLIC void   _(Clear)();

// Returns a copy of the object with type information present
PUBLIC void  *CONST (At)(int index);

// Returns a pointer to the element targeted if present
PUBLIC void  *CONST (Contains)(const void *reference);

// Returns a pointer to the element that contains the targeted base if present
PUBLIC void  *CONST (ContainsKey)(const void *reference);

// Returns the index of the element targeted
PUBLIC int    CONST (IndexOf)(const void *reference);

// Returns the index of the element that contains the targeted base
PUBLIC int    CONST (IndexOfKey)(const void *reference);

// Returns the iterator associated with the array
PUBLIC void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef PUBLIC

#endif
