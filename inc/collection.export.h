#ifndef COLLECTION_EXPORT_H
#define COLLECTION_EXPORT_H


#ifdef WIN
#ifdef COLLECTION_EXPORTS
#define COLLECTION_EXPORT __declspec(dllexport)
#else
#define COLLECTION_EXPORT __declspec(dllimport)
#endif
#else
#define COLLECTION_EXPORT __attribute__((visibility("default")))
#endif
#endif