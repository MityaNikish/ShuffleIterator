#pragma once

#include <vector>

class MyClass
{
public:
	MyClass() { value = 0; }
	MyClass(int value) : value(value) { }
	int getValue() { return value; }
	bool operator==(const MyClass&) const = default;
private:
	int value;
};


//template <typename T>
//class MyContainer
//{
//public:
//    class shuffle_iterator {
//    public:
//        shuffle_iterator(typename std::vector<T>::shuffle_iterator it) : it_(it) {}
//
//        T operator*() {
//            return *it_;
//        }
//
//        shuffle_iterator& operator++() {
//            ++it_;
//            return *this;
//        }
//
//        bool operator!=(const shuffle_iterator& other) const {
//            return it_ != other.it_;
//        }
//
//    private:
//        typename std::vector<T>::shuffle_iterator it_;
//    };
//
//    shuffle_iterator begin() {
//        return shuffle_iterator(data_.begin());
//    }
//
//    shuffle_iterator end() {
//        return shuffle_iterator(data_.end());
//    }
//
//    push_back(T arg)
//    {
//        data_.push_back(arg);
//    }
//
//private:
//	std::vector<T> data_;
//};