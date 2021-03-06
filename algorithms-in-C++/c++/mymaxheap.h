
 
#ifndef heap_h
#define heap_h
/*************************Heap*******************************/

#include <iostream>
#include <cstdlib>
#include <vector>

template<typename Type>
class myMaxHeap {
    private:
        int current_size;
        std::vector<Type> data;
        void heapify();
        void percolateDown(int);
        void percolateUp(int);

    public:
        explicit myMaxHeap(int);
        explicit myMaxHeap(const std::vector<Type> &);

        int getSize() const;
        bool isEmpty() const;
        void display() const;
        Type getMax() const;
        Type getItem(int) const;

        void insert(const Type&);
        void deleteMax();
        Type extractMax();
        void increaseKey(int, Type);
        void decreaseKey(int, Type);
        void remove(int);
        void makeEmpty();
};


/* Constructor
 * @pre: create a max-heap
 * @param: a vector of comparable type
 * @post: creates a max-heap
 * @return: none
 */

template<typename Type>
myMaxHeap<Type>::myMaxHeap(const std::vector<Type>& items)
    : current_size(items.size()),
      data(items.size() + 20) {
    for(int i=0; i<items.size(); ++i) {
        data[i + 1] = items[i];
    }
    
    heapify();
}


/*** Private Methods ***/

/* 
 * @pre: keep a max-heap
 * @param: none
 * @post: fix max-heap
 * @return: none
 */
template<typename Type>
void myMaxHeap<Type>::heapify() {
    for (int i = current_size / 2; i > 0; --i)
        percolateDown(i);
}


/** 
 * @pre: keep a max-heap
 * @param: position to start percolation process
 * @post: keep a max-heap
 * @return: none
 */
template<typename Type>
void myMaxHeap<Type>::percolateDown(int pos) {
    int child_idx;
    Type element = std::move(data[pos]);

    for( ; pos * 2 <= current_size; pos = child_idx) {
        child_idx = pos * 2;

        if (child_idx != current_size )
            if (data[child_idx + 1] > data[child_idx] )
               ++ child_idx;

        if (data[child_idx] > element)
            data[pos] = std::move(data[child_idx]);
        else
            break;
    }

    data[pos] = std::move(element);
}

/** 
 * @pre: keep max-heap
 * @param: position to start the percolation process
 * @post: fix the max-heap
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::percolateUp(int pos) {
    int parent_idx;
    Type element = std::move(data[pos]);
    data[0] = std::move(element);
    for (; element > data[pos/2]; pos /= 2) {
        data[pos] = std::move(data[pos/2]);
    }
    data[pos] = std::move(data[0]);
}


/*** Public Methods ***/


/** 
 * @pre: none
 * @param: none
 * @post: print the element in the max-heap
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::display() const {
    for (int i=1; i<=current_size; ++i) {
        std::cout << data[i] << std::endl;
    }
}


/** 
 * @pre: none
 * @param: none
 * @post: none
 * @return: true if heap is empty, false otherwise
 */
template<typename Type>
bool myMaxHeap<Type>::isEmpty() const {
    return (current_size == 0);
}


/** 
 * @pre: none
 * @param: none
 * @post: none 
 * @return: the max-value in the array (root of the tree)
 */
template<typename Type>
Type myMaxHeap<Type>::getMax() const {
    if (current_size == 0) {
        // underflow
    }

    return data[1];
}

/** 
 * @pre: none
 * @param: none
 * @post: none
 * @return: the current size of heap 
 */
template<typename Type>
int myMaxHeap<Type>::getSize() const {
    return current_size;
}

/** 
 * @pre: none
 * @param: position of the heap array
 * @post: none
 * @return: the element stored at that position
 */
template<typename Type>
Type myMaxHeap<Type>::getItem(int pos) const {
    if (pos > current_size) {
        //throw 
    }
    return data[pos];
}



/*** Mutators ***/

/** 
 * @pre: array must remain as max-heap
 * @param: input x 
 * @post: adds the element to heap array
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::insert(const Type& x) {
    if (current_size == data.size() - 1) {
        data.resize(data.size() * 2 );
    }

    int pos = ++current_size;

    data[pos] = std::move(x);
    percolateUp(pos);
}

/** 
 * @pre: heap must remain as max-heap
 * @param: position and a positive value 
 * @post: increase the key stored at position by positive value
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::increaseKey(int pos, Type positiveValue) {
    if (positiveValue < 0) {
        //throw IllegalValueException();
    }
    data[pos] += positiveValue;
    percolateUp(pos);
}

/** 
 * @pre: heap must remain as max-heap
 * @param: position and a positive value
 * @post: decrease he key stored at position by positive value
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::decreaseKey(int pos, Type positiveValue) {
    if (positiveValue < 0) {
       // throw
    }
    data[pos] -= positiveValue;
    percolateDown(pos);
}

/** 
 * @pre: hea must remain as max-heap
 * @param: none
 * @post: delete the root of heap tree
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::deleteMax() {
    if (isEmpty()) {
        //throw UnderflowException();
    }

    data[1] = data[current_size];
    -- current_size;
    percolateDown(1);
}

/** 
 * @pre: heap must remain max-heap
 * @param: none
 * @post: delete the root
 * @return: return the root (max value) 
 */
template<typename Type>
Type myMaxHeap<Type>::extractMax() {
    Type max_element = std::move(getMax());
    deleteMax();
    return max_element;
}

/** 
 * @pre: heap must remain as max-heap
 * @param: position
 * @post: remove element stored at position
 * @return: none 
 */
template<typename Type>
void myMaxHeap<Type>::remove(int pos) {
    if (pos > current_size) {
        //throw 
    }
    data[pos] = data[current_size];
    -- current_size;
    percolateDown(pos);
}

#endif /* heap_h */
