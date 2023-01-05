#include <set>

template <typename T>
class BinaryRelationProperty;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class Symmetry : public BinaryRelationProperty<T> 
{
public:
  Symmetry()
  {
    this->id = 3;
  };
  bool satisfies(RelationSet<T> pair_set, std::set<T> set) const override;
  void reduce(RelationSet<T>& pair_set, std::set<T> set) override;
};

template <typename T>
bool Symmetry<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  // std::cout << "s satisfies\n";
  for (auto l = set.begin(); l != set.end(); ++l)
  {
    for (auto r = l; r != set.end(); ++r)
    {
      T lf = *l, rf = *r;
      if ((pair_set.find(std::make_pair<T, T>(std::forward<T>(lf), std::forward<T>(rf))) == pair_set.end())
          != (pair_set.find(std::make_pair<T, T>(std::forward<T>(rf), std::forward<T>(lf))) == pair_set.end()))
      {
        return false;
      }
    }
  }

  return true;
};

template <typename T>
void Symmetry<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  throw std::runtime_error("Can't create symmetric relation!\n");
};