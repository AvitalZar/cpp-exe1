//tchykzr@gmail.com
#include "doctest.h"
#include "../../dataStructs/pq_prim.hpp"


//prim priority queue:


TEST_CASE("Test enqueue and dequeue functionality in PrimQ") {
    PrimQ pq;
    edge e1 = {0, 1, 10};
    edge e2 = {1, 2, 5};
    edge e3 = {2, 3, 2};

    pq.enqueue(e1, 10);
    pq.enqueue(e2, 5);
    pq.enqueue(e3, 2);

    CHECK(pq.isEmpty() == false);
    CHECK(pq.dequeue() == e3);
    CHECK(pq.dequeue() == e2);
    CHECK(pq.dequeue() == e1);
    CHECK(pq.isEmpty() == true);
}

TEST_CASE("Test decreaseKey functionality in PrimQ") {
    PrimQ pq;
    edge e1 = {0, 1, 10};
    edge e2 = {1, 2, 5};
    edge e3 = {2, 3, 2};

    pq.enqueue(e1, 10);
    pq.enqueue(e2, 5);
    pq.enqueue(e3, 2);

    CHECK(pq.dequeue() == e3);
    CHECK(pq.dequeue() == e2);

    pq.decreaseKey(e1, 1);

    CHECK(pq.dequeue() == e1);
}

TEST_CASE("Test isEmpty function in PrimQ") {
    PrimQ pq;
    CHECK(pq.isEmpty() == true);

    edge e1 = {0, 1, 10};
    pq.enqueue(e1, 10);

    CHECK(pq.isEmpty() == false);

    pq.dequeue();

    CHECK(pq.isEmpty() == true);
}

TEST_CASE("Test peek function in PrimQ") {
    PrimQ pq;
    edge e1 = {0, 1, 10};
    edge e2 = {1, 2, 5};
    edge e3 = {2, 3, 2};

    pq.enqueue(e1, 10);
    pq.enqueue(e2, 5);
    pq.enqueue(e3, 2);

    CHECK(pq.peek() == e3);
}

TEST_CASE("Test exception when dequeuing from empty queue") {
    PrimQ pq;
    CHECK_THROWS_AS(pq.dequeue(), std::runtime_error);
}

TEST_CASE("Test exception when decreasingKey on non-existing edge") {
    PrimQ pq;
    edge e1 = {0, 1, 10};
    pq.enqueue(e1, 10);

    edge e2 = {1, 2, 5};
    CHECK_THROWS_AS(pq.decreaseKey(e2, 1), std::runtime_error);
}
