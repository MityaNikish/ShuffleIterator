#include <type_traits>
#include <iterator>

template <typename T>
struct my_iterator
{
    using iterator_category = std::random_access_iterator_tag;
    using value_type = std::remove_cv_t<T>;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;
};

int main()
{
	std::iterator_traits<my_iterator<int>>::value_type;
	std::iterator_traits<my_iterator<int>>::pointer;


	return 0;
}