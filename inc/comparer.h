#ifndef COMPARER_H
#define COMPARER_H

#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "collection.export.h"

typedef int (*Comparer)(const void *against, const void *reference);

COLLECTION_EXPORT Comparer comparer(const Type *type);
COLLECTION_EXPORT Comparer key_comparer(const Type *type);

#endif