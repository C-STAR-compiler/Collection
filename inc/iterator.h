#ifndef ITERATOR_H
#define ITERATOR_H

#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "collection.export.h"

#define PUBLIC COLLECTION_EXPORT
#define TYPENAME Iterator

OBJECT (void *collection) INHERIT (void*)
  void   *collection;
  void   *env;
  int   (*done)(Iterator *this);
  void  (*next)(Iterator *this);
  void  (*end)(Iterator *this);
  int   (*count)(Iterator *this);
END_OBJECT(NULL);

PUBLIC int  done(Iterator *e);
PUBLIC void next(Iterator *e);
PUBLIC int  count(Iterator *e);

#undef TYPENAME
#undef PUBLIC

#endif