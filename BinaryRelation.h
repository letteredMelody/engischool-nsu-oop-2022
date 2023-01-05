#include <vector>

#include "BinaryRelationProperty.h"

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

/////////////////////////////////////////////////////////////////////////

template <typename T>
class Preorder : private BinaryRelation<T> 
{
public:
  Preorder(std::set<T> set);
  Preorder(RelationSet<T> pair_set, std::set<T> set);

  template <typename Tstream>
  friend std::ostream& operator<<(std::ostream &stream, const Preorder<Tstream> &x) 
  {
    stream << static_cast<const BinaryRelation<Tstream>>(x);
    return stream;
  };
};

template <typename T>
class Equivalence : private BinaryRelation<T>
{
public:
  Equivalence(std::set<T> set);
  Equivalence(RelationSet<T> pair_set, std::set<T> set);

  template <typename Tstream>
  friend std::ostream& operator<<(std::ostream &stream, const Equivalence<Tstream> &x)
  {
    stream << static_cast<const BinaryRelation<Tstream>>(x);
    return stream;
  };
};

template <typename T>
class PartialOrder : private BinaryRelation<T>
{
public:
  PartialOrder(std::set<T> set);
  PartialOrder(RelationSet<T> pair_set, std::set<T> set);

  template <typename Tstream>
  friend std::ostream& operator<<(std::ostream &stream, const PartialOrder<Tstream> &x)
  {
    stream << static_cast<const BinaryRelation<Tstream>>(x);
    return stream;
  };
};

template <typename T>
class StrictPartialOrder : private BinaryRelation<T>
{
public:
  StrictPartialOrder(std::set<T> set);
  StrictPartialOrder(RelationSet<T> pair_set, std::set<T> set);

  template <typename Tstream>
  friend std::ostream& operator<<(std::ostream &stream, const StrictPartialOrder<Tstream> &x)
  {
    stream << static_cast<const BinaryRelation<Tstream>>(x);
    return stream;
  };
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

// Preorder

template <typename T>
Preorder<T>::Preorder(std::set<T> set) : BinaryRelation<T>(set)
{
  this->id = 1;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Transitivity<T>);
};

template <typename T>
Preorder<T>::Preorder(RelationSet<T> pair_set, std::set<T> set) : BinaryRelation<T>(pair_set, set)
{
  this->id = 1;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Transitivity<T>);
};

// Equivalence

template <typename T>
Equivalence<T>::Equivalence(std::set<T> set) : BinaryRelation<T>(set)
{
  this->id = 2;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Symmetry<T>);
  this->addProperty(new Transitivity<T>);
};

template <typename T>
Equivalence<T>::Equivalence(RelationSet<T> pair_set, std::set<T> set) : BinaryRelation<T>(pair_set, set)
{
  this->id = 2;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Symmetry<T>);
  this->addProperty(new Transitivity<T>);
};

// PartialOrder

template <typename T>
PartialOrder<T>::PartialOrder(std::set<T> set) : BinaryRelation<T>(set)
{
  this->id = 3;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Antisymmetry<T>);
  this->addProperty(new Transitivity<T>);
};

template <typename T>
PartialOrder<T>::PartialOrder(RelationSet<T> pair_set, std::set<T> set) : BinaryRelation<T>(pair_set, set)
{
  this->id = 3;
  this->addProperty(new Reflexivity<T>);
  this->addProperty(new Antisymmetry<T>);
  this->addProperty(new Transitivity<T>);
};

// StrictPartialOrder

template <typename T>
StrictPartialOrder<T>::StrictPartialOrder(std::set<T> set) : BinaryRelation<T>(set)
{
  this->id = 4;
  this->addProperty(new Irreflexivity<T>);
  this->addProperty(new Antisymmetry<T>);
  this->addProperty(new Transitivity<T>);
};

template <typename T>
StrictPartialOrder<T>::StrictPartialOrder(RelationSet<T> pair_set, std::set<T> set) : BinaryRelation<T>(pair_set, set)
{
  this->id = 4;
  this->addProperty(new Irreflexivity<T>);
  this->addProperty(new Antisymmetry<T>);
  this->addProperty(new Transitivity<T>);
};
