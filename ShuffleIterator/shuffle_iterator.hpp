#pragma once

#include <vector>
#include <algorithm>
#include <random>


template <typename Iter>
concept AcceptableIterator = std::indirectly_readable<Iter> && requires()
{
    typename std::iterator_traits<Iter>::value_type;
    typename std::iterator_traits<Iter>::pointer;
    typename std::iterator_traits<Iter>::reference;
};


template <typename T>
class ShuffleIterator final {
    using iterator_type = typename std::iterator_traits<T>::value_type;

public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = std::remove_cv_t<typename std::iterator_traits<iterator_type>::value_type>;
    using pointer = typename std::iterator_traits<iterator_type>::pointer;
    using reference = typename std::iterator_traits<iterator_type>::reference;


    explicit ShuffleIterator(T it) : it_(it) {}

    reference operator*() const noexcept  {
        return **it_;
    }

    pointer operator->() const noexcept {
        return this->it_;
    }

    reference operator[](const difference_type index) const noexcept {
        return **(it_ + index);
    }

    bool operator!=(const ShuffleIterator& other) const noexcept {
        return it_ != other.it_;
    }
    bool operator==(const ShuffleIterator& other) const noexcept {
        return it_ == other.it_;
    }

    ShuffleIterator operator+(const difference_type value) const noexcept {
        ShuffleIterator temp = *this;
        temp.it_ += value;
        return temp;
    }
    ShuffleIterator operator-(const difference_type value) const noexcept  {
        ShuffleIterator temp = *this;
        temp.it_ -= value;
        return temp;
    }

    ShuffleIterator& operator+=(const difference_type value) noexcept {
        this->it_ += value;
        return *this;
    }
    ShuffleIterator& operator-=(const difference_type value) noexcept {
        this->it_ -= value;
        return *this;
    }

    bool operator<(const ShuffleIterator& other) const noexcept {
        return it_ < other.it_;
    }
    bool operator>(const ShuffleIterator& other) const noexcept {
        return it_ > other.it_;
    }
    bool operator<=(const ShuffleIterator& other) const noexcept {
        return it_ <= other.it_;
    }
    bool operator>=(const ShuffleIterator& other) const noexcept {
        return it_ >= other.it_;
    }

    ShuffleIterator& operator++() noexcept {
        ++it_;
        return *this;
    }
    ShuffleIterator operator++(int) noexcept {
        ShuffleIterator temp = *this;
        ++it_;
        return temp;
    }

    ShuffleIterator& operator--() noexcept {
        --it_;
        return *this;
    }
    ShuffleIterator operator--(int) noexcept {
        ShuffleIterator temp = *this;
        --it_;
        return temp;
    }

private:
    T it_;
};


template <typename Iterator>
class ShuffleRange final {
    std::vector<Iterator> data_;
    std::default_random_engine rng_;

public:
    ShuffleRange(Iterator begin, Iterator end, const std::default_random_engine& rng) : rng_(rng) {
        for (Iterator it = begin; it != end; ++it) {
            data_.push_back(it);
        }
        shuffle();
    }

    ShuffleRange(Iterator begin, Iterator end) : ShuffleRange(begin, end, std::default_random_engine(std::random_device{}())) { }


    typedef ShuffleIterator<typename std::vector<Iterator>::iterator> iterator;
    typedef ShuffleIterator<typename std::vector<Iterator>::const_iterator> const_iterator;

    iterator begin() noexcept
    {
        return ShuffleIterator(data_.begin());
    }

    iterator end() noexcept
    {
        return ShuffleIterator(data_.end());
    }

    const_iterator begin() const noexcept
    {
        return ShuffleIterator(data_.begin());
    }

    const_iterator end() const noexcept
    {
        return ShuffleIterator(data_.end());
    }

private:
    void shuffle() {
        std::shuffle(data_.begin(), data_.end(), rng_);
    }
};


template <AcceptableIterator Iterator>
ShuffleRange<Iterator> make_shuffle(Iterator begin, Iterator end) {
    return ShuffleRange<Iterator>(begin, end);
}


template <AcceptableIterator Iterator>
ShuffleRange<Iterator> make_shuffle(Iterator begin, Iterator end, const unsigned int seed) {
    return ShuffleRange<Iterator>(begin, end, std::default_random_engine(seed));
}