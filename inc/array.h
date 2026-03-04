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

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME Array

OBJECT (size_t element_size) INHERIT (void*)
  int     size;
  int     capacity;
  size_t  element_size;
END_OBJECT(sizeof(void*));

// Fills the array with values
PUBLIC Array *STATIC (From)(int number, size_t element_size, const void *elements);

// Sets the capacity of the array to the desired value. Truncates if necessary.
PUBLIC int    _(Recap)(int newCap);

// Sets the size of the array to the desired value. Recaps if necessary.
PUBLIC int    _(Resize)(int newSize);

// Inserts an element at index
PUBLIC void  *_(Insert)(int index, const void *element);

// Pushes a new element onto the array (last)
PUBLIC void  *_(Push)(const void *element);

// Adds a new element in the array (first)
PUBLIC void  *_(Add)(const void *element);

// Combine two arrays (deletes the other)
PUBLIC void   _(Merge)(Array *that);

// Swaps 2 elements of the array specified by their indexes
PUBLIC int    _(Swap)(int index1, int index2);

// Sets the element at index
PUBLIC void  *_(Set)(int index, const void *element);

// Removes the element at index and returns a pointer to it
PUBLIC void  *_(RemoveAt)(int index);

// Removes the element at index and returns it
PUBLIC void  *_(RemoveAtDeref)(int index);

// Pops the last element of the array and returns a pointer to it
PUBLIC void  *_(Pop)();

// Pops the last element and returns it
PUBLIC void  *_(PopDeref)();

// Removes the element at 0 and returns a pointer to it
PUBLIC void  *_(Remove)();

// Removes the element at 0 and returns it
PUBLIC void  *_(RemoveDeref)();

// Removes a range of elements starting at index start
PUBLIC int    _(RemoveRange)(int start, int range);

// Clears the array
PUBLIC void   _(Clear)();

// Checks if the index is within the array
PUBLIC int    CONST (Index)(int *index);

// Returns a pointer to the element at index
PUBLIC void  *CONST (At)(int index);

// Returns the element at index
PUBLIC void  *CONST (AtDeref)(int index);

// Returns a pointer to the last element of the array
PUBLIC void  *CONST (Last)();

// Returns the last element from the array
PUBLIC void  *CONST (LastDeref)();

// Returns a pointer to the element targeted if present
PUBLIC void  *CONST (Contains)(const void *element);

// Returns the element targeted if present
PUBLIC void  *CONST (ContainsDeref)(const void *element);

// Returns the index of the element targeted
PUBLIC int    CONST (IndexOf)(const void *element);

// Returns the iterator associated with the array
PUBLIC void _(Iterator)(Iterator *iterator) VIRTUAL (Iterator);

#undef TYPENAME
#undef PUBLIC
#endif
