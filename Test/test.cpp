#include "pch.h"
#include "data.hpp"
#include "shuffle_iterator.hpp"

#include <unordered_map>
#include <forward_list>
#include <vector>

////проверка на работоспособность тестов на утечку
//TEST(TestMem, Test) { ;
//	int* value = new int[5];
//}

TEST(IteratorFunctionality, BeginEnd) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	decltype(shuffle)::iterator iter = shuffle.begin();

	EXPECT_TRUE(*iter == 1);
	*iter = 5;
	EXPECT_TRUE(*iter == 5);
}

//TEST(IteratorFunctionality, ConstBeginEnd) {
//	std::vector<const int> vector = { 1 };
//	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);
//
//	decltype(shuffle)::const_iterator iter = shuffle.begin();
//
//	EXPECT_TRUE(*iter == 1);
//}

//Shuffle iterator < std::_Vector_iterator < std::_Vector_val<std::_Simple_types<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int>>>>>>>
//Shuffle iterator < std::_Vector_const_iterator < std::_Vector_val < std::_Simple_types < std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int>>>


TEST(IteratorFunctionality, Denaming_1) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(*iter == 1);
}

TEST(IteratorFunctionality, Denaming_2) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(iter[0] == 1);
}

TEST(IteratorFunctionality, PostfixIncrement) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(*iter++ == 1);
	EXPECT_TRUE(iter == shuffle.end());
}

TEST(IteratorFunctionality, PrefixIncrement) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(*iter == 1);
	EXPECT_TRUE(++iter == shuffle.end());
}

TEST(IteratorFunctionality, PostfixDecrement) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.end();

	EXPECT_TRUE(iter-- == shuffle.end());
	EXPECT_TRUE(*iter == 1);
}

TEST(IteratorFunctionality, PrefixDecrement) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.end();

	EXPECT_TRUE(iter == shuffle.end());
	EXPECT_TRUE(*--iter == 1);
}

TEST(IteratorFunctionality, Implementation) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(*iter == 1);
	EXPECT_TRUE(iter + 1 == shuffle.end());
	EXPECT_TRUE(*iter == 1);

}

TEST(IteratorFunctionality, ImplementationAndEquals) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.begin();

	EXPECT_TRUE(*iter == 1);
	EXPECT_TRUE((iter += 1) == shuffle.end());
	EXPECT_TRUE(iter == shuffle.end());
}

TEST(IteratorFunctionality, Unimplementation) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.end();

	EXPECT_TRUE(iter == shuffle.end());
	EXPECT_TRUE(*(iter - 1) == 1);
	EXPECT_TRUE(iter == shuffle.end());

}

TEST(IteratorFunctionality, UnimplementationAndEquals) {
	std::vector<int> vector = { 1 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter = shuffle.end();

	EXPECT_TRUE(iter == shuffle.end());
	EXPECT_TRUE(*(iter -= 1) == 1);
	EXPECT_TRUE(*iter == 1);
}

TEST(IteratorFunctionality, Greater) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end() - 1;

	EXPECT_TRUE(iter_left < iter_right);
	EXPECT_TRUE(iter_left < shuffle.end());

	EXPECT_FALSE(iter_left < iter_left);
}

TEST(IteratorFunctionality, GreaterAndEquals) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end() - 1;

	EXPECT_TRUE(iter_left <= iter_right);
	EXPECT_TRUE(iter_left <= shuffle.end());

	EXPECT_TRUE(iter_left <= iter_left);
}

TEST(IteratorFunctionality, Less) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end() - 1;

	EXPECT_TRUE(iter_right > iter_left);
	EXPECT_TRUE(shuffle.end() > iter_left);

	EXPECT_FALSE(iter_left > iter_left);
}

TEST(IteratorFunctionality, LessAndEquals) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end() - 1;

	EXPECT_TRUE(iter_right >= iter_left);
	EXPECT_TRUE(shuffle.end() >= iter_left);

	EXPECT_TRUE(iter_left >= iter_left);
}

TEST(IteratorFunctionality, Equals) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end();

	EXPECT_TRUE(iter_left == shuffle.begin());
	EXPECT_TRUE(iter_right == shuffle.end());
	EXPECT_TRUE(iter_left + 1 == iter_right - 1);

	EXPECT_FALSE(iter_left == iter_right);
}

TEST(IteratorFunctionality, NotEquals) {
	std::vector<int> vector = { 1, 2 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	ShuffleIterator iter_left = shuffle.begin();
	ShuffleIterator iter_right = shuffle.end();

	EXPECT_TRUE(iter_right != iter_left);
	EXPECT_TRUE(iter_right != iter_left + 1);

	EXPECT_FALSE(iter_left != shuffle.begin());
}

TEST(IteratorFunctionality, IteratorTraits) {
	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	using value_type = std::iterator_traits<decltype(shuffle.begin())>::value_type;
	using pointer = std::iterator_traits<decltype(shuffle.begin())>::pointer;

	//value_type a;
	//pointer b;

	bool tess_condition = std::is_same_v<value_type, int>;
	EXPECT_TRUE(tess_condition);

	tess_condition = std::is_same_v<pointer, int*>;
	EXPECT_TRUE(tess_condition);
}

TEST(IteratorFunctionality, IteratorDereference) {
	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	using vector_value_type = decltype(*vector.begin() + 1);
	using shuffle_value_type = decltype(*shuffle.begin() + 1);

	const bool tess_condition = std::is_same_v< vector_value_type, shuffle_value_type>;
	EXPECT_TRUE(tess_condition);
}


TEST(MadeArray, TypeInt) {
	int a[] = { 0, 4, 5, 2, 8, 1 };

	std::vector<int> vector(a, a + 6);
	std::vector<int> vector_shuffle;

	auto shuffle = make_shuffle(a, a + 6, 12345);

	for (const auto i : shuffle) {
		vector_shuffle.push_back(i);
	}

	EXPECT_TRUE(vector != vector_shuffle);
}


TEST(MadeArray, TypeMyClass) {
	MyClass* a = new MyClass[10];


	for (auto i = 0; i < 10; i++)
	{
		a[i] = MyClass{ i };
	}

	std::vector<MyClass> vector(a, a + 6);
	std::vector<MyClass> vector_shuffle;

	auto shuffle = make_shuffle(a, a + 6, 12345);

	for (const auto i : shuffle) {
		vector_shuffle.push_back(i);
	}

	EXPECT_TRUE(vector != vector_shuffle);

	delete[] a;
}


TEST(Vector, TypeInt) {
	std::vector<int> vector = { 1, 5, 8, 0, 4, 3 };
	std::vector<int> vector_shuffle;

	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	int sum = 0;
	for (const auto i : shuffle) {
		vector_shuffle.push_back(i);
		sum += i;
	}

	EXPECT_TRUE(vector != vector_shuffle);
	EXPECT_TRUE(sum == 21);
}


TEST(Vector, TypeInt_NULL) {
	std::vector<int> vector;
	std::vector<int> vector_shuffle;

	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	for (const auto i : shuffle) {
		vector_shuffle.push_back(i);
	}

	EXPECT_TRUE(vector.size() == vector_shuffle.size());
}


TEST(Vector, TypeMyClass) {
	std::vector<MyClass> vector;
	std::vector<MyClass> vector_shuffle;

	for (auto i = 0; i < 10; i++)
	{
		vector.emplace_back(i);
	}

	std::mt19937 rd(12345);
	auto shuffle = make_shuffle(vector.begin(), vector.end(), 12345);

	for (auto i : shuffle) {
		vector_shuffle.push_back(i);
	}

	EXPECT_TRUE(vector != vector_shuffle);
}


TEST(UnorderedMap, TypeInt) {
	std::unordered_map<int, int> hash = { { 0, 0 }, { 4, 0 }, { 5, 0 }, { 2, 0 }, { 8, 0 }, { 1, 0 } };

	std::mt19937 rd(12345);
	auto shuffle = make_shuffle(hash.begin(), hash.end(), 12345);

	std::vector<std::pair<int, int>> vector;
	std::vector<std::pair<int, int>> vector_shuffle;

	for (auto i : hash) {
		vector.emplace_back(i);
	}

	for (const auto i : shuffle) {
		vector_shuffle.emplace_back(i);
	}

	EXPECT_TRUE(vector != vector_shuffle);
}


TEST(UnorderedMap, TypeMyClass) {
	std::unordered_map<int, MyClass> hash;

	for (auto i = 0; i < 10; i++)
	{
		hash.insert(std::make_pair(i, MyClass{ i }));
	}

	std::mt19937 rd(12345);
	auto shuffle = make_shuffle(hash.begin(), hash.end(), 12345);

	std::vector<std::pair<int, MyClass>> vector;;
	std::vector<std::pair<int, MyClass>> vector_shuffle;

	for (auto i : hash) {
		vector.push_back(i);
	}

	for (auto i : shuffle) {
		vector_shuffle.push_back(i);
	}

	EXPECT_TRUE(vector != vector_shuffle);
}


TEST(ForwardList, TypeInt) {
	std::forward_list<int> list = { 0, 4, 5, 2, 8, 1 };
	std::forward_list<int> list_shuffle;

	auto shuffle = make_shuffle(list.begin(), list.end(), 12345);

	for (auto i : shuffle) {
		list_shuffle.push_front(i);
	}

	EXPECT_TRUE(list != list_shuffle);
}


TEST(ForwardList, TypeMyClass) {
	std::forward_list<MyClass> list;
	std::forward_list<MyClass> list_shuffle;

	for (auto i = 0; i < 10; i++)
	{
		list.emplace_front(i);
	}

	std::mt19937 rd(12345);
	auto shuffle = make_shuffle(list.begin(), list.end(), 12345);

	for (auto i : shuffle) {
		list_shuffle.push_front(i);
	}

	EXPECT_TRUE(list != list_shuffle);
}