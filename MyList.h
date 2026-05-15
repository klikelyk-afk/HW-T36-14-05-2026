#pragma once
#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class Node {
public:
    T info;
    Node* next;

    Node(T value) { info = value; next = nullptr; }
    void show()const {
        cout << "INFO: " << info << endl;
        cout << "\tNEXT: " << next << endl << endl;
    }
};

template <typename T>
class DNode {
public:
    T info;
    DNode* prev;
    DNode* next;

    DNode(T value) { info = value; next = prev = nullptr; }
    void show()const {
        cout << "INFO: " << info << endl;
        cout << "\tPREV: " << prev << endl << endl;
        cout << "\tNEXT: " << next << endl << endl;
    }
};


template <typename U>
class List {
    Node<U>* head;
    Node<U>* tail;
public:
    List() {
        head = tail = nullptr;
    }


    void push_back(U value) {
        //1. Створюємо вузол
        Node<U>* item = new Node<U>(value);

        //2. Чи це перший вузол в списку?
        if (head == nullptr || tail == nullptr) {
            head = tail = item;
        }
        else {
            //3 Якщо НЕ перший вузол в списку
            tail->next = item;
            tail = item;
        }
    }

    void showList() {
        Node<U>* p = head;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
    }


};



template <typename U>
class DList {
    DNode<U>* head;
    DNode<U>* current;
public:
    DList() { head = nullptr; current = nullptr; }
    ~DList() {
        DNode<U>* p = head;

        if (p == nullptr) return;

        if (p->next == nullptr) {
            delete p;
            head = current = nullptr;
        }
        else {
            while (p->next != nullptr) {
                p = p->next;
                cout << "DELETE: " << p->prev->info << endl;
                delete p->prev;
            }
            cout << "DELETE: " << p->info << endl;
            delete p;

            head = current = nullptr;
        }
    }

    void push_back(U value) { //Добавлення нового вузла в кінець списку
        //1. Створюємо новий вузол
        DNode<U>* item = new DNode<U>(value);

        //2. Чи ПЕРШИЙ вузол в списку?
        if (head == nullptr || current == nullptr) {
            head = current = item;
        }
        else {
            //3. НЕ перший вузол
            current->next = item;
            item->prev = current;

            current = item;
        }

    }
    void show() {//Виведення списку на екран
        DNode<U>* p = head;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
    void show_reverse() {
        DNode<U>* p = current;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->prev;
        }
        cout << endl;
    }

    DNode<U>* search(U value) { // Пошук вузла із заданим значенням
        DNode<U>* p = head;
        while (p != nullptr) {
            if (p->info == value) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }




   //Домашнє



    void push_front(U value) {
        DNode<U>* item = new DNode<U>(value);
        if (head == nullptr) {
            head = current = item;
        }
        else {
            item->next = head;
            head->prev = item;
            head = item;
        }
    }

    void insertBefore(U before, U value) {
        DNode<U>* target = search(before);
        if (target == nullptr) return;

        if (target == head) {
            push_front(value);
            return;
        }

        DNode<U>* item = new DNode<U>(value);
        item->next = target;
        item->prev = target->prev;
        target->prev->next = item;
        target->prev = item;
    }

    void insertAfter(U after, U value) {
        DNode<U>* target = search(after);
        if (target == nullptr) return;

        if (target == current) {
            push_back(value);
            return;
        }

        DNode<U>* item = new DNode<U>(value);
        item->prev = target;
        item->next = target->next;
        target->next->prev = item;
        target->next = item;
    }

    void erase(U value) {
        DNode<U>* target = search(value);
        if (target == nullptr) return;

        if (target == head) {
            head = target->next;
        }
        if (target == current) {
            current = target->prev;
        }

        if (target->next != nullptr) {
            target->next->prev = target->prev;
        }
        if (target->prev != nullptr) {
            target->prev->next = target->next;
        }

        delete target;
    }


};



