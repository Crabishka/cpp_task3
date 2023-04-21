
#ifndef UNTITLED_DIRECTEDGRAPH_H
#define UNTITLED_DIRECTEDGRAPH_H

#include <vector>
#include <set>
#include <iostream>

template<typename T>
class Edge;


template<typename T>
class Node {
public:
    explicit Node(T value) : value(value) {};

    T getValue() {
        return value;
    }

    void addEdge(Edge<T> *edge) {
        edges.push_back(edge);
    }

    std::vector<Edge<T> *> getEdges() {
        return edges;
    }

private:
    T value;
    std::vector<Edge<T> *> edges;
};

template<typename T>
class Edge {
public:
    Edge(Node<T> *from, Node<T> *to) : from(from), to(to) {

    };

    Node<T> *getTo() {
        return to;
    };

    Node<T> *getFrom() {
        return from;
    };

private:
    Node<T> *from;
    Node<T> *to;
};


template<typename T>
class DirectedGraph {
public:
    DirectedGraph() {};

    ~DirectedGraph() = default;

    void addNode(Node<T> *node) {
        nodes.push_back(node);
    };

    void addEdge(Node<T> *from, Node<T> *to) {
        Edge<T> *edge = new Edge(from, to);
        from->addEdge(edge);
        edges.push_back(edge);
    };

    std::vector<Node<T> *> getNodes() {
        return nodes;
    }

    std::vector<Edge<T> *> getEdges() {
        return edges;
    }

    void dfsFromFirst() {
        std::set<Node<T> *> visited;
        dfs(nodes.front(), visited);
    }


    void dfs(Node<T> *start, std::set<Node<T> *> &visited) {
        visited.insert(start);
        std::cout << "visit - " << start->getValue() << std::endl;
        // пройдемся по всем соседям и добавим их в visited
        for (Edge<T> *edge: start->getEdges()) {
            Node<T> *neighbour = edge->getTo();

            if (visited.find(neighbour) == visited.end()) {
                dfs(neighbour, visited);
                visited.insert(neighbour);
            }
        }

    }

private:
    std::vector<Node<T> *> nodes;
    std::vector<Edge<T> *> edges;
};


#endif //UNTITLED_DIRECTEDGRAPH_H
