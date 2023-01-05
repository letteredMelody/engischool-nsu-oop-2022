#include <set>

template <typename T>
class BinaryRelation;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

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