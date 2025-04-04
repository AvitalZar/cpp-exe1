#include "doctest.h"
#include "../../dataStructs/stack.hpp"

TEST_CASE("Stack basic operations") {
    Stack s;

    CHECK(s.isEmpty() == true);

    s.push(10);
    CHECK(s.isEmpty() == false);
    CHECK(s.peek() == 10);

    s.push(20);
    CHECK(s.peek() == 20);

    CHECK(s.pop() == 20);
    CHECK(s.peek() == 10);

    CHECK(s.pop() == 10);
    CHECK(s.isEmpty() == true);
}

TEST_CASE("Stack handles multiple elements") {
    Stack s;

    for (int i = 0; i < 5; ++i)
        s.push(i);

    for (int i = 4; i >= 0; --i)
        CHECK(s.pop() == i);

    CHECK(s.isEmpty() == true);
}

TEST_CASE("Peek does not remove element") {
    Stack s;
    s.push(42);
    CHECK(s.peek() == 42);
    CHECK(s.peek() == 42);
    CHECK(s.isEmpty() == false);
    CHECK(s.pop() == 42);
    CHECK(s.isEmpty() == true);
}

TEST_CASE("exceptions"){
	Stack s;
	CHECK_THROWS(s.pop());
}
