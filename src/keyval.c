#include <keyval.h>

#define TYPENAME KeyVal

// Why the env pointer?
// A comparison by key doesn't require the env pointer to work
// We would normally take the typeof the first member of the pair, and
// for that type retrieve the comparer and key comparer.
// The issue with this method is that every time a comparison is made
// the comparer needs to be retrieved, which is unnecessarily costly.
// This specific Pair implementation is meant to be optimized for a 
// map set; by pointing to the env, we can only resolve the comparers
// once at construction time, and then always call the same function.

////////////////////////////////////////////////////////////////////////////////
KeyVal *_(Construct)(KeyValEnvironment *env)
{
  if (Pair_Construct(BASE(0))) {    
    this->env = env;
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  Pair_Destruct(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
int _(Comparer)(KeyVal *reference)
{
  return this->env->comparer(BASE(0)->first, reference->base.first);
}

////////////////////////////////////////////////////////////////////////////////
int _(KeyComparer)(KeyVal *reference)
{
  return this->env->keyComparer(BASE(0)->first, reference->base.first);
}

////////////////////////////////////////////////////////////////////////////////
int _(EnvComparer)(KeyVal *reference)
{
  return ((EnvComparer)this->env->comparer)(BASE(0)->first, reference->base.first, this->env->pointer);
}

////////////////////////////////////////////////////////////////////////////////
int _(EnvKeyComparer)(KeyVal *reference)
{
  return ((EnvComparer)this->env->keyComparer)(BASE(0)->first, reference->base.first, this->env->pointer);
}

#undef TYPENAME
