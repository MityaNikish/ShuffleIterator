#pragma once

#include <vector>
#include <algorithm>
#include <random>


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
public:

    shuffle_range(Iterator begin, Iterator end, const std::default_random_engine &rng) : rng_(rng) {
        for (Iterator it = begin; it != end; ++it) {
            data_.push_back(&(*it));
        }
        shuffle();
    }

    shuffle_range(Iterator begin, Iterator end) : shuffle_range(begin, end, std::default_random_engine(std::random_device{}())) { }


    class shuffle_iterator : public std::iterator<std::input_iterator_tag, typename std::iterator_traits<Iterator>::pointer> {
    public:
        using type_obj = typename std::iterator_traits<Iterator>::value_type;
        using value_type = typename std::iterator_traits<Iterator>::pointer;
        //typedef typename std::iterator_traits<Iterator>::pointer value_type;

        explicit shuffle_iterator(typename std::vector<typename std::iterator_traits<Iterator>::pointer>::iterator it) : it_(it) {}

        type_obj operator*() {
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
        typename std::vector<typename std::iterator_traits<Iterator>::pointer>::iterator it_;
    };



    shuffle_iterator begin() {
        return shuffle_iterator(data_.begin());
    }

    shuffle_iterator end() {
        return shuffle_iterator(data_.end());
    }

    void shuffle() {
        std::shuffle(data_.begin(), data_.end(), rng_);
    }

    //using value_type = typename std::iterator_traits<Iterator>::pointer;

private:
    std::vector<typename std::iterator_traits<Iterator>::pointer> data_;
    std::default_random_engine rng_;
};


template <typename Iterator>
shuffle_range<Iterator> make_shuffle(Iterator begin, Iterator end) {
    return shuffle_range<Iterator>(begin, end);
}


template <typename Iterator>
shuffle_range<Iterator> make_shuffle(Iterator begin, Iterator end, const unsigned int seed) {
    return shuffle_range<Iterator>(begin, end, std::default_random_engine(seed));
}

//template <typename Iterator>
//typename std::enable_if<
//    std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::input_iterator_tag>::value ||
//    std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::output_iterator_tag>::value ||
//    std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::forward_iterator_tag>::value ||
//    std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::bidirectional_iterator_tag>::value ||
//    std::is_same<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>::value,
//    shuffle_range<Iterator>
//>::type
//make_shuffle(Iterator begin, Iterator end) {
//    return shuffle_range<Iterator>(begin, end);
//}
