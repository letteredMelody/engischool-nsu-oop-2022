#include <set>

template <typename T>
class BinaryRelationProperty;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class Irreflexivity : public BinaryRelationProperty<T> 
{
public:
  Irreflexivity() 
  {
    this->id = 2;
  };
  bool satisfies(RelationSet<T> pair_set, std::set<T> set) const override;
  void reduce(RelationSet<T>& pair_set, std::set<T> set) override;
};

template <typename T>
bool Irreflexivity<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  // std::cout << "ir satisfies\n";
  for (T elem : set)
  {
    if (pair_set.find(std::make_pair<T, T>(std::forward<T>(elem), std::forward<T>(elem))) != pair_set.end())
    {
      return false;
    }
  }

  return true;
};

template <typename T>
void Irreflexivity<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  // std::cout << "ir reduce\n";
  RelationSet<T> new_set = pair_set;

  for (T elem : set)
  {
    auto pair = std::make_pair<T, T>(std::forward<T>(elem), std::forward<T>(elem));
    if (pair_set.find(pair) != pair_set.end())
    {
      new_set.erase(pair);
    }
  }

  pair_set = new_set;
};