#include "Node.h"
#include <iostream>

Node::Node(int data, Node *next_node,Node *prev_node) : data(data), next_node(next_node), prev_node(prev_node)
{
    std::cout << "\nNew node is created with data : " << data << "\n";
}

Node::~Node()
{
    std::cout << "\nNode with data " << data << " is destroyed";
}
