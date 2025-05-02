// Copyright 2021 NNTU-CS
#include "tpqueue.h"
#include <stdexcept>


TPQueue<SYM>::Node::Node(const SYM& ch) : data(ch), next(nullptr) {}

TPQueue<SYM>::TPQueue() : head(nullptr) {}

TPQueue<SYM>::~TPQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool TPQueue<SYM>::empty() const {
    return head == nullptr;
}

void TPQueue<SYM>::push(const SYM& ch) {
    Node* newNode = new Node(ch);

    if (head == nullptr || ch.prior > head->data.prior) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.prior >= ch.prior) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

SYM TPQueue<SYM>::pop() {
    if (empty()) {
        throw std::out_of_range("pustaya ochered");
    }
    Node* temp = head;
    SYM itog = head->data;
    head = head->next;
    delete temp;
    return itog;
}
