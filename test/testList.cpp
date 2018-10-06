#include <cassert> // assert
#include <iomanip> // setfill, setw
#include <iostream> // cout, endl
#include "List.h"

#define ASSERT_PASS std::cout << "pass" << std::endl;
#define ASSERT_FAIL std::cout << "fail" << std::endl;

void test(const char *testTitle) {
    int i, width = 57;

    for (i = 0; testTitle[i] != '\0'; i++) {
        ;
    }

    std::cout << testTitle << " " << std::setw(width-i) << std::setfill('.') << " ";
}

int main() {
    test("can create an empty list"); {
        List<int> list;
        assert(list.isEmpty()); 
        ASSERT_PASS;
    }

    test("can create a list with a single item"); {
        List<int> list(1);
        assert(!list.isEmpty());
        assert(list.size() == 1);
        ASSERT_PASS;
    }

    test("can insert an item into an empty list"); {
        List<int> list;
        list.insert(1);
        assert(!list.isEmpty());
        assert(list.size() == 1);
        ASSERT_PASS;
    }

    test("can insert an item into a non-empty list"); {
        List<int> list(1);
        list.insert(2);
        assert(list.size() == 2);
        ASSERT_PASS;
    }

    test("can append an item to an empty list"); {
        List<int> list;
        list.append(1);
        assert(!list.isEmpty());
        assert(list.size() == 1);
        ASSERT_PASS;
    }

    test("can append an item to a non-empty list"); {
        List<int> list(1);
        list.append(2);
        assert(list.size() == 2);
        ASSERT_PASS;
    }

    test("can prepend an item to an empty list"); {
        List<int> list;
        list.prepend(1);
        assert(!list.isEmpty());
        assert(list.size() == 1);
        ASSERT_PASS;
    }

    test("can prepend an item to a non-empty list"); {
        List<int> list(1);
        list.prepend(2);
        assert(list.size() == 2);
        ASSERT_PASS;
    }

    test("can access an item by position"); {
        List<int> list(1);
        list.insert(5);
        list.insert(3);
        assert(list[0] == 1);
        assert(list[1] == 3);
        assert(list[2] == 5);
        ASSERT_PASS;
    }

    test("cannot access an item out of bounds"); {
        List<int> list(1);
        try {
            assert(list[1]);
            ASSERT_FAIL;
        } catch (int e) {
            ASSERT_PASS;
        }
    }

    test("can check if the list contains an item"); {
        List<int> list(1);
        assert(list.contains(1));
        ASSERT_PASS;
    }

    test("can find the position of an item in the list"); {
        List<int> list(1);
        list.insert(5);
        list.insert(3);
        assert(list.find(1) == 0);
        assert(list.find(3) == 1);
        assert(list.find(5) == 2);
        ASSERT_PASS;
    }

    test("cannot find the position of an item not in the list"); {
        List<int> list;
        assert(list.find(1) == LIST_ITEM_NOT_FOUND);
        ASSERT_PASS;
    }
}
