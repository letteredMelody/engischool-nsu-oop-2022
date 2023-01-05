#include <set>

template <typename T>
class BinaryRelation;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

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