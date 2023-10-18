#include "pch.h"
//#include "data.hpp"
////#include "shuffle_iterator_another.hpp"
//#include "shuffle_iterator.hpp"
//
//#include <unordered_map>
//#include <forward_list>
//#include <vector>
//
//////проверка на работоспособность тестов на утечку
////TEST(TestMem, Test) { ;
////	int* value = new int[5];
////}
//
//
////TEST(MyIterator, Type) {
////	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
////
////	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);
////	auto value = shuffle.begin();
////	std::iterator_traits<shuffle_range<std::vector<int>::iterator>::iterator>::value_type a;
////	
////	//EXPECT_TRUE(a);
////}
//
//
//TEST(MyIterator, ValueType) {
//	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
//
//	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);
//
//	const bool a = std::is_same_v<decltype(*vector.begin()), decltype(**shuffle.begin())>;
//	EXPECT_TRUE(a);
//}
//
//
//TEST(MadeArray, TypeInt) {
//	int a[] = { 0, 4, 5, 2, 8, 1 };
//
//	std::vector<int> vector(a, a + 6);
//	std::vector<int> vector_shuffle;
//
//	auto shuffle = make_shuffle(a, a + 6, 12345);
//
//	for (const auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//}
//
//
//TEST(MadeArray, TypeMyClass) {
//	MyClass *a = new MyClass[10];
//
//
//	for (auto i = 0; i < 10; i++)
//	{
//		a[i] = MyClass{i};
//	}
//
//	std::vector<MyClass> vector(a, a + 6);
//	std::vector<MyClass> vector_shuffle;
//
//	auto shuffle = make_shuffle(a, a + 6, 12345);
//
//	for (const auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//
//	delete[] a;
//}
//
// 
//TEST(Vector, TypeInt) {
//	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
//	std::vector<int> vector_shuffle;
//
//	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);
//
//	for (const auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//}
//
//
//TEST(Vector, TypeMyClass) {
//	std::vector<MyClass> vector;
//	std::vector<MyClass> vector_shuffle;
//
//	for (auto i = 0; i < 10; i++)
//	{
//		vector.push_back(MyClass{ i });
//	}
//
//	std::mt19937 rd(12345);
//	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);
//
//	for (auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//}
//
//
//TEST(UnorderedMap, TypeInt) {
//	std::unordered_map<int, int> hash = { { 0, 0 }, { 4, 0 }, { 5, 0 }, { 2, 0 }, { 8, 0 }, { 1, 0 } };
//
//	std::mt19937 rd(12345);
//	auto shuffle = make_shuffle(hash.begin(), hash.end(), 12345);
//
//	std::vector<std::pair<int, int>> vector;;
//	std::vector<std::pair<int, int>> vector_shuffle;
//
//	for (auto i : hash) {
//		vector.push_back(i);
//	}
//
//	for (auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//}
//
//
//TEST(UnorderedMap, TypeMyClass) {
//	std::unordered_map<int, MyClass> hash;
//
//	for (auto i = 0; i < 10; i++)
//	{
//		hash.insert(std::make_pair(i, MyClass{ i }));
//	}
//
//	std::mt19937 rd(12345);
//	auto shuffle = make_shuffle(hash.begin(), hash.end(), 12345);
//
//	std::vector<std::pair<int, MyClass>> vector;;
//	std::vector<std::pair<int, MyClass>> vector_shuffle;
//
//	for (auto i : hash) {
//		vector.push_back(i);
//	}
//
//	for (auto i : shuffle) {
//		vector_shuffle.push_back(*i);
//	}
//
//	EXPECT_TRUE(vector != vector_shuffle);
//}
//
//
//TEST(ForwardList, TypeInt) {
//	std::forward_list<int> list = { 0, 4, 5, 2, 8, 1 };
//	std::forward_list<int> list_shuffle;
//
//	auto shuffle = make_shuffle(list.begin(), list.end(), 12345);
//
//	for (auto i : shuffle) {
//		list_shuffle.push_front(*i);
//	}
//
//	EXPECT_TRUE(list != list_shuffle);
//}
//
//
//TEST(ForwardList, TypeMyClass) {
//	std::forward_list<MyClass> list;
//	std::forward_list<MyClass> list_shuffle;
//
//	for (auto i = 0; i < 10; i++)
//	{
//		list.push_front(MyClass{ i });
//	}
//
//	std::mt19937 rd(12345);
//	auto shuffle = make_shuffle(list.begin(), list.end(), 12345);
//
//	for (auto i : shuffle) {
//		list_shuffle.push_front(*i);
//	}
//
//	EXPECT_TRUE(list != list_shuffle);
//}
//
//
////TEST(Vector, TypeInt) {
////	MyContainer<int> my_cont;
////
////	for (int i = 0; i < 10; i++)
////	{
////		my_cont.push_back(i);
////	}
////
////	std::mt19937 rd(12345);
////	auto shuffle = make_shuffle(my_cont.begin(), my_cont.end());
////
////	std::vector<int> vector;
////	std::vector<int> vector_shuffle;
////
////	for (auto i : my_cont) {
////		vector.push_back(i);
////	}
////
////	for (auto i : shuffle) {
////		vector_shuffle.push_back(*i);
////	}
////
////	EXPECT_TRUE(vector != vector_shuffle);
////}
