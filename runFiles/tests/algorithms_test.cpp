//tchykzr@gmail.com
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




TEST_CASE("Prim basic test without vector") {
    Graph g(5);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 6);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 8);
    g.add_edge(1, 4, 5);
    g.add_edge(2, 4, 7);
    g.add_edge(3, 4, 9);

    Algorithms a;
    Graph mst = a.prim(g, 0);


    int found_weights[4] = {0, 0, 0, 0};
    int count = 0;
    for (int i = 0; i < mst.numOfVer(); ++i) {
        Vertex* n = mst.get(i);
        int size = n->numOfNeigh();
        for (int j = 0; j < size; ++j) {
            if (i < n->getNeigh()[j].vertex && count < 4) {
                found_weights[count++] = n->getNeigh()[j].weight;
            }
        }
    }

    CHECK(count == 4);
    CHECK(
        (found_weights[0] == 2 || found_weights[1] == 2 || found_weights[2] == 2 || found_weights[3] == 2)
    );
    CHECK(
        (found_weights[0] == 3 || found_weights[1] == 3 || found_weights[2] == 3 || found_weights[3] == 3)
    );
    CHECK(
        (found_weights[0] == 5 || found_weights[1] == 5 || found_weights[2] == 5 || found_weights[3] == 5)
    );
    CHECK(
        (found_weights[0] == 6 || found_weights[1] == 6 || found_weights[2] == 6 || found_weights[3] == 6)
    );
}
