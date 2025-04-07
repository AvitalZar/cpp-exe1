#include "doctest.h"
#include "../../dataStructs/priority_queue.hpp"
using namespace std;


TEST_CASE("Basic operations") {
    PrioQ pq;

    CHECK(pq.isEmpty() == true);

	pq.enqueue(1, 10);
    CHECK(pq.isEmpty() == false);

	CHECK(pq.peek() == 1);
	CHECK(pq.isEmpty()==false);

    pq.enqueue(2, 5);
    CHECK(pq.peek() == 2);
	CHECK(!pq.isEmpty());

    CHECK(pq.dequeue() == 2);
    CHECK(pq.peek() == 1);
	CHECK(!pq.isEmpty());


    CHECK(pq.dequeue() == 1);
    CHECK(pq.isEmpty() == true);
}

TEST_CASE("decreaseKey affects priority") {
    PrioQ pq;
    pq.enqueue(1, 30);
    pq.enqueue(2, 20);
    pq.enqueue(3, 10);

	
    CHECK(pq.peek() == 3);

	pq.decreaseKey(1, 5);

	CHECK(pq.peek() == 1);

	CHECK(pq.dequeue() == 1);
    CHECK(pq.dequeue() == 3);
    CHECK(pq.dequeue() == 2);
    CHECK(pq.isEmpty() == true);
}

TEST_CASE("dequeue and peek on empty queue throws") {
    PrioQ pq;

    CHECK_THROWS_AS(pq.peek(), std::runtime_error);
    CHECK_THROWS_AS(pq.dequeue(), std::runtime_error);
}

TEST_CASE("decreaseKey on non-existing node throws") {
    PrioQ pq;
    pq.enqueue(1, 10);

    CHECK_THROWS_AS(pq.decreaseKey(2, 5), std::runtime_error); // אין כזה
}
