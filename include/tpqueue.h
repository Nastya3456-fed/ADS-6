#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
public:
    TPQueue();
    ~TPQueue();

    void push(const T& ch);
    T pop();
    bool empty() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& ch);
    };

    Node* head;
};

#endif
