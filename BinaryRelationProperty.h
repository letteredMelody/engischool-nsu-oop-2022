#include <set>
#include <iostream>

template <typename T>
using RelationSet = std::set<std::pair<T, T>>;

template <typename T>
class BinaryRelationProperty
{
public:
  RelationSet<T> apply(RelationSet<T> pair_set, std::set<T> set);

  size_t id;

  virtual bool satisfies(RelationSet<T> pair_set, std::set<T> set) const = 0;
  virtual void reduce(RelationSet<T>& pair_set, std::set<T> set) = 0;
};

//////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
RelationSet<T> BinaryRelationProperty<T>::apply(RelationSet<T> pair_set, std::set<T> set) 
{
  if(!satisfies(pair_set, set)) 
  {
    reduce(pair_set, set);
  }

  return pair_set;
}

// Reflexivity

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

// Irreflexivity

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

// Symmetry

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

// Antisymmetry

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

// Transitivity

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