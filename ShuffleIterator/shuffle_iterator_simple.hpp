#pragma once

#include <vector>
#include <algorithm>
#include <random>


template <typename T>
class shuffle_iterator{
    using type_obj = std::remove_pointer_t<typename std::iterator_traits<T>::value_type>;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = std::remove_cv_t<typename std::iterator_traits<T>::value_type>;
    using pointer = typename std::iterator_traits<T>::pointer;
    using reference = typename std::iterator_traits<T>::reference;
    using difference_type = ptrdiff_t;


    explicit shuffle_iterator(T it) : it_(it) {}

    type_obj& operator*() {
        return **it_;
    }

    shuffle_iterator& operator++() {
        ++it_;
        return *this;
    }

    bool operator!=(const shuffle_iterator& other) const {
        return it_ != other.it_;
    }

    bool operator==(const shuffle_iterator& other) const {
        return it_ == other.it_;
    }

private:
    T it_;
};

//namespace std {
//    template <typename T>
//    struct iterator_traits<shuffle_iterator<T>> {
//        using iterator_concept = contiguous_iterator_tag;
//        using iterator_category = random_access_iterator_tag;
//        using value_type = typename shuffle_iterator<T>::value_type;
//        using difference_type = typename shuffle_iterator<T>::difference_type;
//        using pointer = typename shuffle_iterator<T>::pointer;
//        using reference = typename shuffle_iterator<T>::reference;
//    };
//}

template <typename Iterator>
class shuffle_range final {
    using pointer_obj = typename std::iterator_traits<Iterator>::pointer;
    using iterator_vec = typename std::vector<pointer_obj>::iterator;
    using iterator_sh = shuffle_iterator<iterator_vec>;

    std::vector<pointer_obj> data_;
    std::default_random_engine rng_;

public:
    shuffle_range(Iterator begin, Iterator end, const std::default_random_engine& rng) : rng_(rng) {
        for (Iterator it = begin; it != end; ++it) {
            data_.push_back(&(*it));
        }
        shuffle();
    }

    shuffle_range(Iterator begin, Iterator end) : shuffle_range(begin, end, std::default_random_engine(std::random_device{}())) { }

    iterator_sh begin() {
        return shuffle_iterator(data_.begin());
    }

    iterator_sh end() {
        return shuffle_iterator(data_.end());
    }

    void shuffle() {
        std::shuffle(data_.begin(), data_.end(), rng_);
    }
};


template <typename Iterator>
shuffle_range<Iterator> make_shuffle(Iterator begin, Iterator end) {
    return shuffle_range<Iterator>(begin, end);
}


template <typename Iterator>
shuffle_range<Iterator> make_shuffle(Iterator begin, Iterator end, const unsigned int seed) {
    return shuffle_range<Iterator>(begin, end, std::default_random_engine(seed));
}