#include <set>

template <typename T>
class BinaryRelationProperty;

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class Transitivity : public BinaryRelationProperty<T> 
{
public:
  Transitivity() 
  {
    this->id = 5;
  };
  bool satisfies(RelationSet<T> pair_set, std::set<T> set) const override;
  void reduce(RelationSet<T>& pair_set, std::set<T> set) override;
};

template <typename T>
bool Transitivity<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  // std::cout << "t satisfies\n";
  for (auto x = pair_set.begin(); x != pair_set.end(); ++x)
  {
    auto xf = (*x).first, xs = (*x).second;
    if (xf == xs) continue;
    for (auto y = std::next(x, 1); y != pair_set.end(); ++y)
    {
      auto yf = (*y).first, ys = (*y).second;
      if (yf == ys) continue;
      if (xs == yf) {
        if (pair_set.find(std::make_pair<T, T>(std::forward<T>(xf), std::forward<T>(ys))) == pair_set.end()) {
          return false;
        }
      }
      if (ys == xf) {
        if (pair_set.find(std::make_pair<T, T>(std::forward<T>(yf), std::forward<T>(xs))) == pair_set.end()) {
          return false;
        }
      }
    }
  }

  return true;
};

template <typename T>
void Transitivity<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  throw std::runtime_error("Can't create transitive relation!\n");
};