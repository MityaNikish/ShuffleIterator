//#include "shuffle_iterator.hpp"
//
//#include <iostream>
//#include <forward_list>
//#include <unordered_map>
//#include <vector>
//
//int main() {
//
//    int a[] = { 0, 4, 5, 2, 8, 1 };
//    std::forward_list < int > b = { 0, 4, 5, 2, 8, 1 };
//    std::unordered_map < int, int > c = {
//        { 0, 0 }, { 4, 0 }, { 5, 0 }, { 2, 0 }, { 8, 0 }, { 1, 0 }
//    };
//    std::vector<int> d = { 0, 4, 5, 2, 8, 1 };
//
//    auto shuffle_a = make_shuffle(a, a + 6);
//    auto shuffle_b = make_shuffle(b.begin(), b.end());
//    auto shuffle_c = make_shuffle(c.begin(), c.end());
//    auto shuffle_d = make_shuffle(d.begin(), d.end());
//
//    for (auto i : shuffle_a)
//        std::cout << (*i) << " ";
//
//    std::cout << std::endl << std::endl;
//
//    for (auto i : shuffle_b) {
//        std::cout << (*i) << " ";
//    }
//
//    std::cout << std::endl << std::endl;
//
//    for (auto i : shuffle_c)
//        std::cout << i->first << " " << i->second << std::endl;
//
//    std::cout << std::endl << std::endl;
//
//    for (auto i : shuffle_d)
//        std::cout << (*i) << " ";
//
//    return 0;
//}
