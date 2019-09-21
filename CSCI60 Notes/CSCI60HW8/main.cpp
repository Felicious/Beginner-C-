#include <iostream>
#include "node.h"

int main(){
    //#1
    Node<int>* head=new Node<int>(4,nullptr);
    head=new Node<int>(5,head);
    head=new Node<int>(6,head);
    Node<int>* node = head;
    head=new Node<int>(3,head);
    print_list(head);
    //Node<int>* copyl = copy(head);
    //print_list(copyl);

    //#2
    insert(node,9);
    print_list(head);

    //#3
    remove(node);
    print_list(head);

    return 0;
}

