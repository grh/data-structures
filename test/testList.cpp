#include <cassert> // assert
#include <iostream> // cout, endl
#include "List.h"

#define ASSERT_PASS std::cout << "pass" << std::endl;

void test(const char *testTitle) {
    std::cout << testTitle << " --- ";
}

int main() {
    test("can create an empty list");
    List<int> list1;
    assert(list1.isEmpty()); 
    ASSERT_PASS;

    test("can create a list with a single item");
    List<int> list2(1);
    assert(!list2.isEmpty());
    assert(list2.size() == 1);
    ASSERT_PASS;

    test("can insert an item into an empty list");
    List<int> list3;
    list3.insert(1);
    assert(!list3.isEmpty());
    assert(list3.size() == 1);
    ASSERT_PASS;

    test("can insert an item into a non-empty list");
    List<int> list4(1);
    list4.insert(2);
    assert(list4.size() == 2);
    ASSERT_PASS;

    test("can append an item to an empty list");
    List<int> list5;
    list5.append(1);
    assert(!list5.isEmpty());
    assert(list5.size() == 1);
    ASSERT_PASS;

    test("can append an item to a non-empty list");
    List<int> list6(1);
    list6.append(2);
    assert(list6.size() == 2);
    ASSERT_PASS;

    test("can prepend an item to an empty list");
    List<int> list7;
    list7.prepend(1);
    assert(!list7.isEmpty());
    assert(list7.size() == 1);
    ASSERT_PASS;

    test("can prepend an item to a non-empty list");
    List<int> list8(1);
    list8.prepend(2);
    assert(list8.size() == 2);
    ASSERT_PASS;

    test("can access an item by position");
    List<int> list9(1);
    list9.insert(5);
    list9.insert(3);
    assert(list9[0] == 1);
    assert(list9[1] == 3);
    assert(list9[2] == 5);
    ASSERT_PASS;
}
