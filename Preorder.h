#include <set>

template <typename T>
class BinaryRelation;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

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