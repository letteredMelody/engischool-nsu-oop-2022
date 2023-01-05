#include <iostream>

#include "BinaryRelation.h"

int main(int argc, char *argv[]) 
{
    RelationSet<int> rs{std::make_pair<int, int>(1, 1), std::make_pair<int, int>(1, 2), std::make_pair<int, int>(1, 3),
                        std::make_pair<int, int>(2, 1), std::make_pair<int, int>(2, 2), std::make_pair<int, int>(2, 3),
                        std::make_pair<int, int>(3, 1), std::make_pair<int, int>(3, 2), std::make_pair<int, int>(3, 3)};

    try {
        std::set<int> s{1, 2, 3, 4};
        Preorder<int> preorder(rs, s);
    } catch(std::runtime_error e) {
        std::cout << e.what();
    }

    std::set<int> s{1, 2, 3};

    std::cout << "============================================" << "\n";

    Preorder<int> preorder(rs, s);
    std::cout << preorder;

    std::cout << "============================================" << "\n";

    Equivalence<int> equiv(s);
    std::cout << equiv;

    std::cout << "============================================" << "\n";

    PartialOrder<int> part_order(s);
    std::cout << part_order;

    std::cout << "============================================" << "\n";

    StrictPartialOrder<int> strict_order(s);
    std::cout << strict_order;

    return EXIT_SUCCESS;
}
