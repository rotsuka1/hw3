#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cstddef>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int med;
  PComparator compare;
  std::vector<T> vec;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : med(m), compare(c)
{
  if(m<2){
    throw std::invalid_argument("Heap arity must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  vec.push_back(item);
  size_t i = vec.size() - 1;

  while(i>0){
    size_t parent = (i-1) / static_cast<size_t>(med);

    if(!compare(vec[i], vec[parent])){
      break;
    }

    std::swap(vec[i], vec[parent]);
    i = parent;
  }
}

template <typename T, typename PComparator>
const T& Heap<T, PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("Cannot access the top of an empty heap");
  }

  return vec[0];
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Cannot pop an empty heap");
  }

  std::swap(vec.front(), vec.back());
  vec.pop_back();

  size_t i = 0;

  while(i < vec.size()){
    size_t best = i;

    for(int child = 1; child <= med; ++child){
      if(i > (vec.size() - 1) / static_cast<size_t>(med)){
        break;
      }

      size_t child_index = static_cast<size_t>(med) * i + static_cast<size_t>(child);
      
      if(child_index >= vec.size()){
        break;
      }

      if(compare(vec[child_index], vec[best])){
        best = child_index;
      }
    }

    if(best == i){
      break;
    }

    std::swap(vec[i], vec[best]);
    i = best;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
    return vec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
    return vec.size();
}



#endif

