#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
 private:
  T data_;
  Node<T>* next_;

 public:

  Node(T data, Node<T>* next) : data_(data), next_(next) {}

  Node(const Node<T>&) = delete;
  Node<T>& operator=(const Node<T>&) = delete;

  T data() const { return data_; }
  void data(T data) { data_ = data; }

  Node* next() { return next_; }
  const Node* next() const { return next_; }
  void next(Node* next) { next_ = next; } //set next_ to next :D
};

template <typename T>
Node<T>* copy(const Node<T>* head){
    Node<T>* copyhead;
    Node<T>* copytail;
    copyhead = copytail = nullptr;
    for(auto p = head; p != nullptr; p = p->next()){
        if(copyhead == nullptr){
            copytail = copyhead = new Node<T>(head->data(),nullptr);
        }
        else{
            Node<T>* temp = new Node<T>(head->data(),nullptr);
            copytail->next(temp); //set ptr to the next node (temp)
            copytail = temp;
        }
    }
    return copyhead;
}

template <typename T>
void insert(Node<T>* node, const T& value){
    node->next(new Node<T>(value, node->next())); //changing node's pointer to
    //point to the new node, which contains the value
}


template <typename T>
void print_list(Node<T>* head){
  std::cout << "head -> ";
  for (auto n = head; n != nullptr; n = n->next()) {
    std::cout << n->data() << " -> ";
  }
  std::cout << "nullptr" << std::endl;
}

template <typename T>
void remove(Node<T>* node){
    node->next(node->next()->next());
}



#endif // NODE_H
