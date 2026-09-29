#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node{
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = nullptr;
        }
    };

public:

 Node* head; 
 
    LinkedList() { 
        head = nullptr; 
    } 
 
    // --- Operations you will implement in Exercises 1-5 --- 
    void insertAtHead(int value){
        Node* newNode= new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(int value){
        Node* newNode = new Node(value); 
        if (head == nullptr) {
            head = newNode;
            return; 
        } 
        Node* current = head; 
        while (current->next != nullptr) { 
            current = current->next; 
        } 
        current->next = newNode;
        newNode->next = nullptr;
    }
   
    bool deleteValue(int value){
        if (head == nullptr) {
            return false;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }

            current = current->next;
        }
        return false;
    }

    bool search(int value){
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
  
    int length(){
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;    
    }  
    void reverse(){
    
    }
    
    void print(){
        if(head== nullptr){
            cout<<"list is empty";
            return;
        }
        Node* current=head;
        while (current!= nullptr){
            cout<<current->data;
            current = current-> next;
        }
    }
}; 
