#include <vector>

#include "BinaryRelationProperty.h"

#include "Equivalence.h"
#include "Preorder.h"
#include "PartialOrder.h"
#include "StrictPartialOrder.h"

template <typename T>
class BinaryRelation
{
public:
  BinaryRelation(std::set<T> set);
  BinaryRelation(RelationSet<T> pair_set, std::set<T> set);
  void addProperty(BinaryRelationProperty<T> *property);

  template <typename Tstream>
  friend std::ostream& operator<<(std::ostream &stream, const BinaryRelation<Tstream> &x);
  
  size_t id;

private:
  std::set<T> set;
  std::vector<BinaryRelationProperty<T>*> properties;
  RelationSet<T> pair_set;
};

template <typename T>
BinaryRelation<T>::BinaryRelation(std::set<T> set)
 : properties(), pair_set(), set(set)
{
  for(T first : set)
  {
    for(T second : set)
    {
      pair_set.insert(std::make_pair<T, T>(std::forward<T>(first), std::forward<T>(second)));
    }
  }
};

template <typename T>
BinaryRelation<T>::BinaryRelation(RelationSet<T> pair_set, std::set<T> set)
  : pair_set(pair_set), set(set), properties()
  {
  };

template <typename T>
void BinaryRelation<T>::addProperty(BinaryRelationProperty<T> *property) 
{
  for (auto p : properties) 
  {
    if (p->id == property->id) 
    {
      return;
    }
  }

  this->properties.push_back(property);
  this->pair_set = property->apply(this->pair_set, this->set);
};

template <typename Tstream>
std::ostream& operator<<(std::ostream& stream, const BinaryRelation<Tstream>& x)
{
  for (auto pair : x.pair_set)
  {
    stream << pair.first << "R" << pair.second << ' ';
  }

  stream << "\n";

  return stream;
}
