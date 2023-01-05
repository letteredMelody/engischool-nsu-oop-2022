#include <set>

template <typename T>
class BinaryRelationProperty;
  
template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class Antisymmetry : public BinaryRelationProperty<T> 
{
public:
  Antisymmetry() 
  {
    this->id = 4;
  };
  bool satisfies(RelationSet<T> pair_set, std::set<T> set) const override;
  void reduce(RelationSet<T>& pair_set, std::set<T> set) override;
};


template <typename T>
bool Antisymmetry<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  // std::cout << "as satisfies\n";
  for (auto l = set.begin(); l != set.end(); ++l)
  {
    for (auto r = std::next(l, 1); r != set.end(); ++r)
    {
      T lf = *l, rf = *r;
      if ((pair_set.find(std::make_pair<T, T>(std::forward<T>(lf), std::forward<T>(rf))) != pair_set.end())
          && (pair_set.find(std::make_pair<T, T>(std::forward<T>(rf), std::forward<T>(lf))) != pair_set.end()))
      {
        return false;
      }
    }
  }

  return true;
};

template <typename T>
void Antisymmetry<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{ 
  // std::cout << "as reduce\n";
  RelationSet<T> new_set;

  for (auto value : pair_set)
  {
    auto first = value.first, second = value.second;
    // auto [first, second] = value;
    auto pair = std::make_pair<T, T>(std::forward<T>(second), std::forward<T>(first));
    if (pair_set.find(pair) != pair_set.end()) 
    {
      if (new_set.find(value) == new_set.end()
          && new_set.find(pair) == new_set.end())
      {
        new_set.insert(value);
      }
    }
  }

  pair_set = new_set;
};