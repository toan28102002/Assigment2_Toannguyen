#include "Single_Linked_List.h"
#include <stdexcept>

// Constructor for the Single_Linked_List class
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Adds a new node with the given item to the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (!head) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

// Adds a new node with the given item to the back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (!head) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Removes the first node in the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (!head) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
}

// Removes the last node in the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!head) {
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// Returns the data in the first node
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

// Returns the data in the last node
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!tail) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

// Returns the number of items in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// Inserts an item at a specific index (0-based). If the index is out of bounds, it inserts at the beginning or end as appropriate
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index < 0) {
        index = 0;
    }
    if (index > num_items) {
        index = num_items;
    }

    Node* new_node = new Node(item);
    if (index == 0) {
        new_node->next = head;
        head = new_node;
        if (!tail) {
            tail = new_node;
        }
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (current == tail) {
            tail = new_node;
        }
    }
    num_items++;
}

// Removes the item at a specific index. If the index is out of bounds, it returns false
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index < 0 || index >= num_items) {
        return false;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        if (!current->next) {
            tail = current;
        }
    }
    num_items--;
    return true;
}

// Searches for an item in the list and returns the index of its first occurrence. If not found, it returns the list's size
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // Item not found, return the size of the list
}

// Prints the contents of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Explicit Instantiation for Integers (or other types)
template class Single_Linked_List<int>;
