#include "Doubly_Linked_Lists.h"
#include <iostream>

Doubly_Linked_Lists::Doubly_Linked_Lists(int data) : data(data)
{
    Node *new_node = new Node(data);
    head = tail = new_node;
}

void Doubly_Linked_Lists::printHeadTail()
{
    std::cout << "\nhead : " << head;
    std::cout << "\ntail : " << tail;
}

void Doubly_Linked_Lists::add_node_head(int data)
{
    Node *new_node = new Node(data);
    new_node->next_node = head;
    if (head)
        head->prev_node = new_node;
    head = new_node;

    return;
}

void Doubly_Linked_Lists::add_node_tail(int data)
{
    Node *new_node = new Node(data);
    tail->next_node = new_node;
    new_node->prev_node = tail;
    tail = new_node;

    return;
}

void Doubly_Linked_Lists::add_after_node(int data, int data_after)
{
    Node *curr_node = head;
    while (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;
    }

    Node *new_node = new Node(data, curr_node->next_node);
    curr_node->next_node->prev_node = new_node;
    new_node->prev_node = curr_node;
    curr_node->next_node = new_node;

    if (curr_node == tail)
        tail = new_node;

    return;
}

void Doubly_Linked_Lists::add_before_node(int data, int data_before)
{
    Node *curr_node = head;
    if (head->data != data_before)
    {
        while (curr_node->data != data_before)
        {
            curr_node = curr_node->next_node;
        }

        Node *new_node = new Node(data, curr_node);
        new_node->prev_node = curr_node->prev_node;
        curr_node->prev_node->next_node = new_node;
        curr_node->prev_node = new_node;
    }
    else
    {
        Node *new_node = new Node(data, head);
        head = new_node;
    }

    return;
}

// void Doubly_Linked_Lists::insertInMiddle(int data)
// {
//     if (head)
//     {
//         Node *p1 = head;
//         Node *p2 = tail;

//         while (true)
//         {
//             if (p1 != p2)
//                 p2 = p2->prev_node;

//             if (p1 == p2)
//             {
//                 Node *temp = p2->next_node;
//                 Node *new_node = new Node(data, temp, p1);

//                 if (temp)
//                     temp->prev_node = new_node;
//                 else
//                     tail = new_node;

//                 p1->next_node = new_node;

//                 return;
//             }

//             p1 = p1->next_node;
//         }
//     }
//     else
//         Node *new_node = new Node(data, 0, 0);

//     return;
// }

void Doubly_Linked_Lists::insertInMiddle(int data)
{
    if (head)
    {
        Node *p = head;
        Node *s = head;
        bool flag = false;

        while (p->next_node != 0)
        {
            p = p->next_node;
            if (flag)
                s = s->next_node;
            flag = (!flag);
        }

        Node *new_node = new Node(data, s->next_node, s);
        s->next_node = new_node;

        Node *temp = (new_node)->next_node;
        if (temp)
            temp->prev_node = new_node;

        if (tail == head)
            tail = new_node;
    }
    else
    {
        Node *new_node = new Node(data, 0, 0);
        head = tail = new_node;
    }

    return;
}

void Doubly_Linked_Lists::insertAtFraction(int data, int fraction)
{
    if (head)
    {
        Node *p = head;
        Node *s = head;
        int flag = fraction - 1;

        while (p->next_node != 0)
        {
            p = p->next_node;
            if (flag == 0)
            {
                s = s->next_node;
                flag = fraction - 1;
            }
            else
                --flag;
        }

        Node *new_node = new Node(data, s->next_node, s);
        s->next_node = new_node;

        Node *temp = (new_node)->next_node;
        if (temp)
            temp->prev_node = new_node;

        if (tail == head)
            tail = new_node;
    }
    else
    {
        Node *new_node = new Node(data, 0, 0);
        head = tail = new_node;
    }

    return;
}

bool Doubly_Linked_Lists::move_to_front(int dataFind)
{
    if (head)
    {
        Node *curr = head;

        if (head != tail)
        {
            if (curr->data == dataFind)
                return true;

            while (curr->next_node->data != dataFind)
            {
                curr = curr->next_node;
                if (curr->next_node == 0)
                    return false;
            }

            Node *temp = curr->next_node;
            if (temp == tail)
                tail = curr;
            curr->next_node = temp->next_node;
            temp->next_node = head;
            head = temp;

            return true;
        }

        else
            return curr->data == dataFind;
    }

    return false;
}

void Doubly_Linked_Lists::remove_node_head()
{
    Node *curr_node = head;
    head = curr_node->next_node;
    if (head)
        head->prev_node = 0;
    delete curr_node;

    return;
}

void Doubly_Linked_Lists::remove_node_tail()
{
    tail->prev_node->next_node = 0;
    Node *curr_node = tail;
    tail = tail->prev_node;
    delete curr_node;

    return;
}

void Doubly_Linked_Lists::remove_after_node(int data_after)
{
    Node *curr_node = head;

    while (curr_node->data != data_after)
    {
        curr_node = curr_node->next_node;
    }

    Node *node_remove = curr_node->next_node;
    curr_node->next_node = (node_remove)->next_node;
    node_remove->next_node->prev_node = curr_node;

    delete node_remove;

    return;
}

void Doubly_Linked_Lists::remove_before_node(int data_before)
{
    Node *curr_node = head;
    while (curr_node->data != data_before)
    {
        curr_node = curr_node->next_node;
    }

    Node *node_remove = curr_node->prev_node;
    node_remove->prev_node->next_node = curr_node;
    curr_node->prev_node = node_remove->prev_node;
    delete node_remove;

    return;
}

void Doubly_Linked_Lists::remove_node_data(int data_remove)
{
    Node *curr_node = head;
    while (curr_node->data != data_remove)
    {
        curr_node = curr_node->next_node;
    }

    //    Node *node_remove = curr_node;

    curr_node->next_node->prev_node = curr_node->prev_node;
    curr_node->prev_node->next_node = curr_node->next_node;

    delete curr_node;

    return;
}

void Doubly_Linked_Lists::addAtposition(int i, int data)
{
    Node *curr = head;
    int count = 1;
    while (count < i)
    {
        curr = curr->next_node;
        ++count;
    }

    Node *new_node = new Node(data, curr, curr->prev_node);
    if (curr)
        curr->prev_node = new_node;
    else
        tail = new_node;

    Node *temp = new_node->prev_node;
    if (temp)
        temp->next_node = new_node;
    else
        head = new_node;
}

void Doubly_Linked_Lists::remove_numbered_node(int node_no)
{
    Node *curr_node = head;
    int node = 1;
    while (node != node_no)
    {
        curr_node = curr_node->next_node;
        ++node;
    }

    if (curr_node->next_node)
        curr_node->next_node->prev_node = curr_node->prev_node;
    else
    {
        tail = curr_node->prev_node;
        if (tail)
            tail->next_node = 0;
    }

    if (curr_node->prev_node)
        curr_node->prev_node->next_node = curr_node->next_node;
    else
    {
        head = curr_node->next_node;
        if (head)
            head->prev_node = 0;
    }

    delete curr_node;
}

int Doubly_Linked_Lists::total_nodes()
{
    Node *curr_node = head;
    int counter = 0;

    while (curr_node != 0)
    {
        ++counter;
        curr_node = curr_node->next_node;
    }
    delete curr_node;
    return counter;
}

int Doubly_Linked_Lists::total_nodes_given_data(int given_data)
{
    Node *curr_node = head;
    int counter = 0;

    while (curr_node != 0)
    {
        if (curr_node->data == given_data)
            ++counter;
        curr_node = curr_node->next_node;
    }

    delete curr_node;
    return counter;
}

void Doubly_Linked_Lists::display_linked_list()
{
    std::cout << "\nDoubly Linked list : ";
    Node *curr_node = head;

    while (curr_node != 0)
    {
        std::cout << "\n"
                  << curr_node << "   " << curr_node->data << "   " << curr_node->next_node;
        curr_node = curr_node->next_node;
    }

    delete curr_node;
    return;
}

void Doubly_Linked_Lists::reverse_linked_list()
{
    if (head)
        if (head != tail)
        {
            Node *curr_node;
            Node *temp_node = head;
            tail = head;
            curr_node = temp_node->next_node;
            head->next_node = 0;
            while (temp_node != 0)
            {
                temp_node->prev_node = curr_node;
                temp_node = curr_node->next_node;
                curr_node->next_node = head;
                head = curr_node;
                curr_node = temp_node;
            }
        }

    return;
}

void Doubly_Linked_Lists::selection_sort()
{
    if (head != 0)
        if (head != tail)
            for (Node *i = head; i != 0; i = i->next_node)
                for (Node *j = i->next_node; j != 0; j = j->next_node)
                    if (j->data < i->data)
                    {
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }

    return;
}

void Doubly_Linked_Lists::insertion_sort()
{
    if (head != 0)
        if (head != tail)
            for (Node *i = head->next_node; i != 0; i = i->next_node)
                for (Node *j = i->prev_node; j != 0; j = j->prev_node)
                    if (j->data <= i->data)
                    {
                        add_after_node(i->data, j->data);
                        remove_node_data(i->data);
                    }
                    else
                        continue;
    return;
}

void Doubly_Linked_Lists::join_linked_lists(Doubly_Linked_Lists *obj)
{
    tail->next_node = obj->head;
    this->tail = obj->tail;
    // std::cout << "\n"
    //           << tail->data << "   " << tail << "\n";

    return;
}

Doubly_Linked_Lists::~Doubly_Linked_Lists() {}