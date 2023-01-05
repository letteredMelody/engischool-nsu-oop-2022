#include <iostream>

#include "BinaryRelation.h"

int main() 
{
    RelationSet<int> rs{std::make_pair<int, int>(1, 1), std::make_pair<int, int>(1, 2), std::make_pair<int, int>(1, 3),
                        std::make_pair<int, int>(2, 1), std::make_pair<int, int>(2, 2), std::make_pair<int, int>(2, 3),
                        std::make_pair<int, int>(3, 1), std::make_pair<int, int>(3, 2), std::make_pair<int, int>(3, 3)};

    try {
        std::set<int> s{1, 2, 3, 4};
        Preorder<int> preorder(rs, s);
    } catch(std::runtime_error error) {
        std::cout << error.what();
    }

    std::set<int> s{1, 2, 3};
    Preorder<int> preorder(rs, s);

    std::cout << "Preorder:\n" << preorder;

    Equivalence<int> equiv(s);

    std::cout << "Equivalence:\n" << equiv;

    PartialOrder<int> part_order(s);

    std::cout << "Partial order:\n" << part_order;

    StrictPartialOrder<int> strict_order(s);

    std::cout << "Strict partial order:\n" << strict_order;

    return 0;
}
