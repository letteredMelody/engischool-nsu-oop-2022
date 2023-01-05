#include <iostream>
#include <set>

#include "Antisymmetry.h"
#include "Irreflexivity.h"
#include "Reflexivity.h"
#include "Symmetry.h"
#include "Transitivity.h"

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class BinaryRelationProperty
{
public:
  RelationSet<T> apply(RelationSet<T> pair_set, std::set<T> set);

  size_t id;

  virtual bool satisfies(RelationSet<T> pair_set, std::set<T> set) const = 0;
  virtual void reduce(RelationSet<T>& pair_set, std::set<T> set) = 0;
};

template <typename T>
RelationSet<T> BinaryRelationProperty<T>::apply(RelationSet<T> pair_set, std::set<T> set) 
{
  if(!satisfies(pair_set, set)) 
  {
    reduce(pair_set, set);
  }

  return pair_set;
}