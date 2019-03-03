#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H
#include "Node.h"

class Doubly_Linked_Lists
{
	int data;
	Node *head;
	Node *tail;

  public:
	Doubly_Linked_Lists(int data);
	void printHeadTail();
	void add_node_head(int);
	void add_node_tail(int);
	void add_after_node(int, int);
	void add_before_node(int, int);
	void addAtposition(int, int);
	void remove_node_head();
	void remove_node_tail();
	void remove_after_node(int);
	void remove_before_node(int);
	void remove_node_data(int);
	void remove_numbered_node(int);
	void replace(int, int);
	int total_nodes();
	int total_nodes_given_data(int);
	void display_linked_list();
	void reverse_linked_list();
	void selection_sort();
	void insertion_sort();
	void insertInMiddle(int);
	void insertAtFraction(int, int);
	bool move_to_front(int);
	void join_linked_lists(Doubly_Linked_Lists *);
	~Doubly_Linked_Lists();
};

#endif
