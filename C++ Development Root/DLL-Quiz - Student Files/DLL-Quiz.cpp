/*******************************************************************************
** CPSC 131: Part 1 - Sequence Containers
**           Doubly Linked List Quiz
**
** 1) TO-DO 1:  Using only the techniques discussed in class, implement the insert function for a doubly linked circular list with
**              one dummy node that dynamically allocates nodes.
**              -  Return a pointer to the newly inserted node
**              -  Assume the pointer-to-Node called "position" is valid and points to an existing node in the list
**                 o) implement no error checking
**              -  Hint:  Solutions should have no loops or decisions
**
** 2) TO-DO 2-6:  Sketch (type) the state of the list after each operation
*******************************************************************************/


import std;




template<typename T>
struct DLL
{
  struct Node
  {
    Node() = default;
    Node( T value ) : _data( std::move(value) ) {}

    T      _data = T{};
    Node * _next = this;
    Node * _prev = this;
  };

  Node        _sentinel;
  Node *&     _head = _sentinel._next;
  Node *&     _tail = _sentinel._prev;
  std::size_t _size = 0;



  Node * insert( Node * position, T const & data )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }

  Node * begin() { return _head;      }
  Node * end()   { return &_sentinel; }

  void print();
};






int main()
{
  DLL<unsigned int> theList;
  // Sketch the initial state of the list.
  //
  // Be mindful how you sketch.  Note the required 6 lines, attribute exact names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
        +------------------------------------+
        |                                    |
        +-> _sentinel <-> 73 <-> 94 <-> 13 <-+
        _head -> 73
        _tail -> 13
        _size  =  3

    or

        +---------------+
        |               |
        +-> _sentinel <-+
        _head -> _sentinel
        _tail -> _sentinel
        _size  =  0

    ///////////////////////// TO-DO (2) //////////////////////////////

    /////////////////////// END-TO-DO (2) ////////////////////////////
  #endif
  theList.print();






  auto n1 = theList.insert( theList.begin(), 20 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 6 lines, attribute exact names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (3) //////////////////////////////

    /////////////////////// END-TO-DO (3) ////////////////////////////
  #endif






  theList.insert( n1, 10 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 6 lines, attribute exact names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (4) //////////////////////////////

    /////////////////////// END-TO-DO (4) ////////////////////////////
  #endif






  theList.insert( theList.end(), 40 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 6 lines, attribute exact names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (5) //////////////////////////////

    /////////////////////// END-TO-DO (5) ////////////////////////////
  #endif






  theList.insert( n1, 30 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 6 lines, attribute exact names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (6) //////////////////////////////

    /////////////////////// END-TO-DO (6) ////////////////////////////
  #endif
}















template<typename T>
void DLL<T>::print()
{
  using std::print, std::println;
  constexpr unsigned minimumCount = 15;

  print( "+{0:-<{2}}+\n|{1:{2}}|\n+-> _sentinel", '-', ' ', minimumCount + 41 * _size );

  for( auto p = begin(); p != end(); p = p->_next )
  {
    print( " <-> {{{:014}, {:2}, {:014}}}", static_cast<void const *>( p->_prev ), p->_data, static_cast<void const *>( p->_next ) );
  }

  print( " <-+\n {:014}", static_cast<void const *>( end() ) );



  for( auto p = begin(); p != end(); p = p->_next )
  {
    print( "{:^41}", std::format( "{:014}", static_cast<void const *>( p ) ) );
  }
  println();


  print( "_head -> {}\n"
         "_tail -> {}\n"
         "_size  = {}\n\n\n",
         _size == 0 ? "_sentinel" : std::format( "{:2}", _head->_data ),
         _size == 0 ? "_sentinel" : std::format( "{:2}", _tail->_data ),
         _size );
}
