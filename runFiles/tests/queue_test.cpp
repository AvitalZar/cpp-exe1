#include "../../dataStructs/queInt.hpp"
#include "doctest.h"

TEST_CASE("Queue operations") {
    Queue q;

    SUBCASE("enqueue and dequeue") {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);

        CHECK(q.dequeue() == 1);
        CHECK(q.dequeue() == 2);
        CHECK(q.dequeue() == 3);
    }

    SUBCASE("isEmpty") {
        CHECK(q.isEmpty());

        q.enqueue(10);
        CHECK(!q.isEmpty());

        q.dequeue();
        CHECK(q.isEmpty());
    }

    SUBCASE("peek") {
        q.enqueue(100);
        q.enqueue(200);

        CHECK(q.peek() == 100);
        q.dequeue();
        CHECK(q.peek() == 200);
    }
}
