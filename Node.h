#ifndef NODE_H
#define NODE_H
class Node
{
	int data;
	Node *next_node;
	Node *prev_node;
	friend class Doubly_Linked_Lists;

  public:
	Node(int data, Node *next_node = 0, Node *prev_node = 0);
	~Node();
};
#endif