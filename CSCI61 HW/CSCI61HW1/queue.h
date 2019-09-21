#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <cassert>

template <class T>
class queue
{
public:
    // pre: none
    // post: an empty queue has been created
    queue(){
        _v = std::vector<T>();
        _size = 0;
        _front = 0;
    }

    // pre: none
    // post: returns true iff this queue contains no elements
    bool empty() const
    {
        return (_size == 0);
    }

    // pre: none
    // post: returns the number of elements in this queue
    std::size_t size() const
    {
        return _v.size();
    }


    // pre: this queue is not empty
    // post: a reference to the oldest element in this queue is returned
    T & front()
    {
        assert(!empty());
        return _v[_front];
    }

    T & front() const
    {
        assert(!empty());
        return _v[_front];
    }

    // pre: this queue is not empty
    // post: the oldest element in this queue has been removed
    void pop(){
        assert(!empty());
        if(_size > 1){
            //there seems to be a problem with pop that
            //it's not getting rid of the garbage by creating a new
            //vector and saving the important info to it
            if(_front == (_v.size() - 1)){
                _front = 0;
                --_size;
                while(_size < _v.size()) _v.pop_back(); //gets rid of excess
            }else{
                ++_front;
                --_size;
            }
        }
        else{ //_size == 1
            _v.clear();//once front = 0, resize vector to size 0.
            _front = 0;
            _size = 0;
        }
    }

    // pre: none
    // post: a copy of entry has been added as the newest element of this queue
    void push(const T & entry){
        //it's just full and in order, dw about it
        if((_front == 0)&&(_size == _v.size())){
           _v.push_back(entry);
           ++_size;
        }
        //checks if there's space in front
        else if(((_front+_size)%_v.size()) < _front){
            _v.at((_front+_size)%_v.size()) = entry;
            ++_size;
        }

       //no space when _back+1 == _front, so have to allocate new memory
        else{ //if(_front!=0)
           std::vector<T> new_v;
           //makes a new vector and copies the original but in order
           for(size_t i = _front; i < _v.size(); ++i)
               new_v.push_back(_v[i]);
           for(size_t i = 0; i < _front; ++i)
               new_v.push_back(_v[i]);
           _v = new_v;
           _v.push_back(entry);
           _front = 0;
           _size++;
        }
    }

    void debug(){//to check problems with code
            std::cout << "size :" << _size << std::endl;
            std::cout << "front: " <<_front <<std::endl;
            std::cout << "v.size: " <<_v.size() <<std::endl;
            std::cout << "v:";
            for (auto e:_v) std::cout << " " << e;
            std::cout << std::endl << std::endl;
        }


private:
    std::vector<T> _v;
    std::size_t _size;
    std::size_t _front;

    // class invariants:
    // 1. the elements of this queue are stored in _v[_front], _v[_front+1], _v[_front+2],...,
    //    _v[(_front+_size-1)%v.size()], ordered according to insertion time (wrapping around when the end of _v is reached)
    // 2. _v[_front] is the oldest element; _v[(_front+_size-1)%v.size()] is the newest
};

#endif // QUEUE_H
