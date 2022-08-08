// Student ID: 20522682
// Queue.h
//
//

#ifndef Queue_h
#define Queue_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> _data;
    size_t _head, _tail;
    static T _sentinel;
public:
    static const int MAX_DISP_ELEMS = 100;
    
    void resetHead(){
        _head = 0;
    }
    
    void resetTail(){
        _tail = 0;
    }
    
    void resetVect(){
        _data.clear();
    }
    
    Queue(size_t size);
    
    static void set_sentinel(const T& elem) { _sentinel = elem; }
    static T get_sentinel() { return _sentinel; }
    
    bool is_empty() const{
        
        return (_head == _tail);
    }
    
    bool enqueue(const T& elem){
        if (_head == (_tail + 1) % _data.size()){
            return false;
        }
        
        _data[_tail%_data.size()] = elem;
        _tail = (_tail + 1) % _data.size();
        return true;
    }
    
    bool dequeue(){
        if (is_empty()){
            return false;
        }
//        _data[_head] = get_sentinel();
        _head = (_head + 1) % _data.size();
        return true;
    }
    
    const T& peek() const{
        if (is_empty()){
            return _sentinel;
        }
        
        return _data[_head%_data.size()];
    }
    
    size_t size() const{
        return (_tail - _head);
    }
    
    void resize(size_t size){
        Queue cy(size);
        size_t index = _head;

        if (size > _data.size()){
            _data.resize(size + 1);
        } else if (size < _data.size()) {
            for (size_t i=0; i < size; i++){

                cy.enqueue(_data[index]);
                index++;
            }
            *this = cy;
//            _data.resize(size + 1);
//            _tail = _head + size;
        }
    }
        
        
//        cannot pass resize down
//        _data.resize(size + 1);
    
    string to_string(size_t limit = MAX_DISP_ELEMS) const{
        std::string result = "";
        size_t index = _head;
        result += "# Queue - size = " + std::to_string(size()) + "\n"
        + "data :";
        for (size_t i = 0; i < size(); i++){
            result += std::to_string(_data[index]) + " ";
            index++;
        }

        if (size() > limit) {
            result += " ... etc. up to limit";
        }
        
        result += "\n";
        
        return result;
    }
    
    friend class Tests;
};

template <typename T> void popalot (Queue<T>& q){
    q.resetVect();
    q.resetHead();
    q.resetTail();
//    while (!q.is_empty()){
//        q.dequeue();
//    }
}

template <typename T> T Queue<T>::_sentinel = T();

template <typename T>
Queue<T>::Queue(size_t size){
    _data.resize(size + 1);
    _head = 0;
    _tail = 0;
}

#endif /* Queue_h */
