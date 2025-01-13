#include <cstdio>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>

using Graph = boost::adjacency_list<
        boost::listS,
        boost::vecS,
        boost::directedS,
        boost::no_property,
        boost::property<boost::edge_weight_t, double>>;

using Vertex = boost::graph_traits<Graph>::vertex_descriptor;
using Edge = boost::graph_traits<Graph>::edge_descriptor;

int main(int argc, char* argv[])
{
    Graph g;

    add_edge(0, 1, 1.5, g);
    add_edge(0, 2, 2.0, g);
    add_edge(1, 2, 1.0, g);
    add_edge(2, 3, 2.5, g);
    add_edge(3, 0, 3.0, g);

    auto weightmap = get(boost::edge_weight, g);
    std::printf("Graph edges and weights:\n");
    for (auto [ei, ei_end] = edges(g); ei != ei_end; ++ei) {
        std::printf("Edge (%zu -> %zu) with weight: %.2f\n",
                    source(*ei, g),
                    target(*ei, g),
                    weightmap[*ei]);
    }
    return 0;
}
