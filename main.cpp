#include <iostream>
#include "DirectedGraph.h"

// обычный треугольник
void test1() {
    std::cout << "test 1" << std::endl;
    auto *graph = new DirectedGraph<int>();
    Node<int> *node1 = new Node(10);
    Node<int> *node2 = new Node(20);
    Node<int> *node3 = new Node(30);
    graph->addNode(node1);
    graph->addNode(node2);
    graph->addNode(node3);
    graph->addEdge(node1, node2);
    graph->addEdge(node1, node3);
    graph->addEdge(node2, node3);
    graph->dfsFromFirst();
}

void test2() {
    std::cout << "test 2" << std::endl;
    auto *graph = new DirectedGraph<std::string>();
    Node<std::string> *node1 = new Node<std::string>("a");
    Node<std::string> *node2 = new Node<std::string>("b");
    Node<std::string> *node3 = new Node<std::string>("c");
    Node<std::string> *node4 = new Node<std::string>("d");
    Node<std::string> *node5 = new Node<std::string>("e");
    Node<std::string> *node6 = new Node<std::string>("f");
    graph->addNode(node1);
    graph->addNode(node2);
    graph->addNode(node3);
    graph->addNode(node4);
    graph->addNode(node5);
    graph->addNode(node6);
    graph->addEdge(node1, node2);
    graph->addEdge(node1, node3);
    graph->addEdge(node1, node4);
    graph->addEdge(node4, node6);
    graph->addEdge(node6, node5);
    graph->dfsFromFirst();
}

int main() {

    test1();
    test2();

}


