#ifndef ITERATOR_H
#define ITERATOR_H

#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "collection.export.h"

#define LIB_EXPORT COLLECTION_EXPORT
#define TYPENAME Iterator

OBJECT (void *collection) INHERIT (void*)
  void   *collection;
  void   *env;
  int   (*done)(Iterator *this);
  void  (*next)(Iterator *this);
  void  (*end)(Iterator *this);
  int   (*count)(Iterator *this);
END_OBJECT(NULL);

COLLECTION_EXPORT int  done(Iterator *e);
COLLECTION_EXPORT void next(Iterator *e);
COLLECTION_EXPORT int  count(Iterator *e);

#undef TYPENAME
#undef LIB_EXPORT

#endif