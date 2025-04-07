//tchykzr@gmail.com
#include "../../dataStructs/queInt.hpp"
#include "doctest.h"

TEST_CASE("enqueue and dequeue") {
	Queue q;
	q.enqueue(1);
	/*q.enqueue(2);
	q.enqueue(3);

	CHECK(q.dequeue() == 1);
	CHECK(q.dequeue() == 2);
	CHECK(q.dequeue() == 3);*/
}

TEST_CASE("isEmpty") {
	Queue q;
	CHECK(q.isEmpty());

	q.enqueue(10);
	CHECK(!q.isEmpty());

	q.dequeue();
	CHECK(q.isEmpty());
}

TEST_CASE("peek") {
	Queue q;
	q.enqueue(100);
	q.enqueue(200);

	CHECK(q.peek() == 100);
	q.dequeue();
	CHECK(q.peek() == 200);
}
