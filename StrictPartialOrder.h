#include <set>

template <typename T>
class BinaryRelation;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

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