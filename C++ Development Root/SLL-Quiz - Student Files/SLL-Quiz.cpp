/*******************************************************************************
** CPSC 131: Part 1 - Sequence Containers
**           Singly Linked List Quiz
**
** 1) TO-DO 1:    Using only the techniques discussed in class, implement the insert_after function for a null-terminated list.
**                Insert at the beginning of a list by passing a null pointer. Return a pointer to the newly inserted node.  Be sure
**                to show all three special cases along with the normal case.  Label each case with comments.
**
** 2) TO-DO 2-6:  Sketch (type) the state of the list after each operation
*******************************************************************************/


import std;




template<typename T>
struct SLL
{
  struct Node
  {
    Node() = default;
    Node( T value ) : _data{ std::move( value ) } {}
    T      _data = T{};
    Node * _next = nullptr;
  };

  Node *      _head = nullptr;
  Node *      _tail = nullptr;
  std::size_t _size = 0;



  Node * insert_after( Node * position, T const & data )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }


  void print();
};






int main()
{
  SLL<unsigned int> theList;
  // Sketch the initial state of the list.
  //
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator exact names, and the arrow syntax.  Be
  // sure to not place your sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
       _head -> 73 -> 94 -> 13 -> Ø       (will also accept NULL instead of Ø, for example   _head -> 73 -> 94 -> 13 -> NULL)
       _tail -> 13
       _size = 3
    ///////////////////////// TO-DO (2) //////////////////////////////

    /////////////////////// END-TO-DO (2) ////////////////////////////
  #endif
  theList.print();


  auto n1 = theList.insert_after( nullptr, 20 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator exact names, and the arrow syntax.  Be
  // sure to not place your sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (3) //////////////////////////////

    /////////////////////// END-TO-DO (3) ////////////////////////////
  #endif


  auto n2 = theList.insert_after( nullptr, 10 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator exact names, and the arrow syntax.  Be
  // sure to not place your sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (4) //////////////////////////////

    /////////////////////// END-TO-DO (4) ////////////////////////////
  #endif


  theList.insert_after( n1, 40 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator exact names, and the arrow syntax.  Be
  // sure to not place your sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (5) //////////////////////////////

    /////////////////////// END-TO-DO (5) ////////////////////////////
  #endif


  theList.insert_after( n2, 30 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  //
  // Be mindful how you sketch.  Note the required 3 lines, attribute and null terminator exact names, and the arrow syntax.  Be
  // sure to not place your sketch in comments (the autograder's code review pass ignores comments) For example:
  #if 0
    ///////////////////////// TO-DO (6) //////////////////////////////

    /////////////////////// END-TO-DO (6) ////////////////////////////
  #endif
}
























template<typename T>
void SLL<T>::print()
{
  using std::print, std::println;
  const std::string NIL{ "\u{00D8}" };    // Unicode for Ø

  // Print entire list starting at the head
  print( "  _head -> " );
  for( const Node * p = _head; p != nullptr; p = p->_next )   print( "{{{:2}, {:014}}} -> ",  p->_data,  static_cast<void const *>( p->_next ) );
  println( "{}", NIL );

  // Print the addresses of the nodes in the list
  if( _head != nullptr )
  {
    print( "             " );
    for( const Node * p = _head; p != nullptr; p = p->_next )    print( "({:014})        ",  static_cast<void const *>(p) );
    println();
  }

  // Print the contents of the tail and the address of the tail node
  if( _tail == nullptr )   println( "  _tail -> {}", NIL );
  else
  {
    print( "  _tail -> {{{:2}, {:014}}}\n"
           "             ({:014})\n",
           _tail->_data,  static_cast<void const *>( _tail->_next ),
           static_cast<void const *>( _tail ) );
  }

  // Print the size of the list
  print( "  _size =  {}\n\n\n",  _size );
}
