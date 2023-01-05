#include <set>

template <typename T>
class BinaryRelationProperty;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class Reflexivity : public BinaryRelationProperty<T> 
{
public:
  Reflexivity() 
  {
    this->id = 1;
  };
  bool satisfies(RelationSet<T> pair_set, std::set<T> set) const override;
  void reduce(RelationSet<T>& pair_set, std::set<T> set) override;
};

template <typename T>
bool Reflexivity<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  // std::cout << "r satisfies\n";
  for (T elem : set)
  {
    if (pair_set.find(std::make_pair<T, T>(std::forward<T>(elem), std::forward<T>(elem))) == pair_set.end())
    {
      return false;
    }
  }

  return true;
};

template <typename T>
void Reflexivity<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  throw std::runtime_error("Can't create reflexive relation!\n");
};