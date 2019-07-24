#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "djikstra.hpp"

TEST_CASE("Trivial") {
  Graph g(3);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 0, 100);
  Graph d = djikstras(g, 0);
  REQUIRE(d.has_edge(0, 1));
  REQUIRE(d.has_edge(1, 2));
  REQUIRE_FALSE(d.has_edge(2, 0));
}

TEST_CASE("Updating Paths") {
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 3, 2);
  Graph d = djikstras(g, 0);
  REQUIRE(d.has_edge(0, 1));
  REQUIRE(d.has_edge(0, 2));
  REQUIRE(d.has_edge(1, 3));
  REQUIRE_FALSE(d.has_edge(2, 3));
}

TEST_CASE("Updating Paths") {
  Graph g(5);
  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(3, 2, 5);
  g.add_edge(2, 4);
  g.add_edge(1, 4, 5);
  Graph d = djikstras(g, 0);
  REQUIRE(d.has_edge(0, 1));
  REQUIRE(d.has_edge(0, 3));
  REQUIRE(d.has_edge(1, 2));
  REQUIRE(d.has_edge(2, 4));
  REQUIRE_FALSE(d.has_edge(3, 2));
  REQUIRE_FALSE(d.has_edge(1, 4));
}