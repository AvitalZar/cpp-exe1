#include "doctest.h"
#include "../../basis/Graph/graph.hpp"
#include "../../basis/algorithms.hpp"
using namespace graph;

TEST_CASE("Dijkstra - simple graph") {
    Graph g(5);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 5);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(3, 4, 1);

    Algorithms a;
    Graph d = a.dijkstra(g, 0);

    // הצלעות שצריכות להיות בעץ:
    // 0 -> 1 (2)
    // 1 -> 2 (1)
    // 1 -> 3 (2)
    // 3 -> 4 (1)

    CHECK(d.get(1)->getNeigh()[0].vertex == 0);
    CHECK(d.get(1)->getNeigh()[0].weight == 2);

    CHECK(d.get(2)->getNeigh()[0].vertex == 1);
    CHECK(d.get(2)->getNeigh()[0].weight == 1);

    CHECK(d.get(3)->getNeigh()[0].vertex == 1);
    CHECK(d.get(3)->getNeigh()[0].weight == 2);

    CHECK(d.get(4)->getNeigh()[0].vertex == 3);
    CHECK(d.get(4)->getNeigh()[0].weight == 1);
}
