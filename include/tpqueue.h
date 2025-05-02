struct SYM {
    char ch;
    int prior;
};

class TPQueue {
public:
    TPQueue();
    ~TPQueue();

    void push(const SYM& ch);
    SYM pop();
    bool empty() const;

private:
    struct Node {
        SYM data;
        Node* next;
        Node(const SYM& ch);
    };

    Node* head;
};
