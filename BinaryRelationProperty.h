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
  std::cout << "Reflexivity\t\tcalled\tsatisfies" << "\n";

  for (T e : set)
  {
    if (pair_set.find(std::make_pair<T, T>(std::forward<T>(e), std::forward<T>(e))) == pair_set.end())
    {
      std::cout << "\t\tbroke on pair " << e << "R" << e << "\n";
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
  std::cout << "Irreflexivity\t\tcalled\tsatisfies" << "\n";

  for (T e : set)
  {
    if (pair_set.find(std::make_pair<T, T>(std::forward<T>(e), std::forward<T>(e))) != pair_set.end())
    {
      std::cout << "\t\tbroke on pair " << e << "R" << e << "\n";
      return false;
    }
  }

  return true;
};

template <typename T>
void Irreflexivity<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  std::cout << "Irreflexivity\t\tcalled\treduce" << "\n";

  RelationSet<T> new_set(pair_set);

  for (T e : set)
  {
    auto pair = std::make_pair<T, T>(std::forward<T>(e), std::forward<T>(e));
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
  std::cout << "Symmetry\t\tcalled\tsatisfies" << "\n";
  // return true;

  for (auto l = set.begin(); l != set.end(); ++l)
  {
    for (auto r = l; r != set.end(); ++r)
    {
      T lf = *l, rf = *r;
      if ((pair_set.find(std::make_pair<T, T>(std::forward<T>(lf), std::forward<T>(rf))) == pair_set.end())
          != (pair_set.find(std::make_pair<T, T>(std::forward<T>(rf), std::forward<T>(lf))) == pair_set.end()))
      {
        std::cout << "\t\tbroke on pair " << lf << "R" << rf << "\n";
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

  // pair_set = RelationSet<T>();
};

// Antisymmetry

template <typename T>
bool Antisymmetry<T>::satisfies(RelationSet<T> pair_set, std::set<T> set) const
{
  std::cout << "Antisymmetry\t\tcalled\tsatisfies" << "\n";
  // return true;

  for (auto l = set.begin(); l != set.end(); ++l)
  {
    for (auto r = std::next(l, 1); r != set.end(); ++r)
    {
      T lf = *l, rf = *r;
      if ((pair_set.find(std::make_pair<T, T>(std::forward<T>(lf), std::forward<T>(rf))) != pair_set.end())
          && (pair_set.find(std::make_pair<T, T>(std::forward<T>(rf), std::forward<T>(lf))) != pair_set.end()))
      {
        std::cout << "\t\tbroke on pair " << lf << "R" << rf << "\n";
        return false;
      }
    }
  }

  return true;
};

template <typename T>
void Antisymmetry<T>::reduce(RelationSet<T>& pair_set, std::set<T> set)
{
  std::cout << "Antisymmetry\t\tcalled\treduce" << "\n";
  
  RelationSet<T> new_set;

  for (auto value : pair_set)
  {
    auto [l, r] = value;
    auto pair = std::make_pair<T, T>(std::forward<T>(r), std::forward<T>(l));
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
  std::cout << "Transitivity\t\tcalled\tsatisfies" << "\n";
  // return true;
  for (auto x = pair_set.begin(); x != pair_set.end(); ++x)
  {
    auto [xl, xr] = *x;

    if (xl == xr) continue;

    for (auto y = std::next(x, 1); y != pair_set.end(); ++y)
    {
      auto [yl, yr] = *y;

      if (yl == yr) continue;

      if (xr == yl) {
        if (pair_set.find(std::make_pair<T, T>(std::forward<T>(xl), std::forward<T>(yr))) == pair_set.end()) {
          std::cout << "\t\tbroke on pair " << xl << "R" << yr << "\n";
          return false;
        }
      }
      
      if (yr == xl) {
        if (pair_set.find(std::make_pair<T, T>(std::forward<T>(yl), std::forward<T>(xr))) == pair_set.end()) {
          std::cout << "\t\tbroke on pair " << yl << "R" << xr << "\n";
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

  // pair_set = RelationSet<T>();
};