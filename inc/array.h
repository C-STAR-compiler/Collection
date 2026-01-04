#ifndef ARRAY_H
#define ARRAY_H

// C
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "iterator.h"
#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME Array

OBJECT (size_t element_size) INHERIT (void*)
  int     size;
  int     capacity;
  size_t  element_size;
END_OBJECT(sizeof(void*));

// Fills the array with values
COLLECTION_EXPORT Array *STATIC (From)(int number, size_t element_size, const void *elements);

// Sets the capacity of the array to the desired value. Truncates if necessary.
COLLECTION_EXPORT int    _(Recap)(int newCap);

// Sets the size of the array to the desired value. Recaps if necessary.
COLLECTION_EXPORT int    _(Resize)(int newSize);

// Inserts an element at index
COLLECTION_EXPORT void  *_(Insert)(int index, const void *element);

// Pushes a new element onto the array (last)
COLLECTION_EXPORT void  *_(Push)(const void *element);

// Adds a new element in the array (first)
COLLECTION_EXPORT void  *_(Add)(const void *element);

// Combine two arrays (deletes the other)
COLLECTION_EXPORT void   _(Merge)(Array *that);

// Swaps 2 elements of the array specified by their indexes
COLLECTION_EXPORT int    _(Swap)(int index1, int index2);

// Sets the element at index
COLLECTION_EXPORT void  *_(Set)(int index, const void *element);

// Removes the element at index and returns a pointer to it
COLLECTION_EXPORT void  *_(RemoveAt)(int index);

// Removes the element at index and returns it
COLLECTION_EXPORT void  *_(RemoveAtDeref)(int index);

// Pops the last element of the array and returns a pointer to it
COLLECTION_EXPORT void  *_(Pop)();

// Pops the last element and returns it
COLLECTION_EXPORT void  *_(PopDeref)();

// Removes the element at 0 and returns a pointer to it
COLLECTION_EXPORT void  *_(Remove)();

// Removes the element at 0 and returns it
COLLECTION_EXPORT void  *_(RemoveDeref)();

// Removes a range of elements starting at index start
COLLECTION_EXPORT int    _(RemoveRange)(int start, int range);

// Clears the array
COLLECTION_EXPORT void   _(Clear)();

// Checks if the index is within the array
COLLECTION_EXPORT int    CONST (Index)(int *index);

// Returns a pointer to the element at index
COLLECTION_EXPORT void  *CONST (At)(int index);

// Returns the element at index
COLLECTION_EXPORT void  *CONST (AtDeref)(int index);

// Returns a pointer to the last element of the array
COLLECTION_EXPORT void  *CONST (Last)();

// Returns the last element from the array
COLLECTION_EXPORT void  *CONST (LastDeref)();

// Returns a pointer to the element targeted if present
COLLECTION_EXPORT void  *CONST (Contains)(const void *element);

// Returns the element targeted if present
COLLECTION_EXPORT void  *CONST (ContainsDeref)(const void *element);

// Returns the index of the element targeted
COLLECTION_EXPORT int    CONST (IndexOf)(const void *element);

// Returns the iterator associated with the array
COLLECTION_EXPORT void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef LIB_EXPORT
#endif
