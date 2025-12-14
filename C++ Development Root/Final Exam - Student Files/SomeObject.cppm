export module SomeObject;
import std;
export import GroceryItem;



// Programming technique to define the types of objects held in the data structures and to localize changing that type
export struct SomeObject : GroceryItem      // Mix in class, no virtual functions including destructor
{
  using GroceryItem::GroceryItem;           // inherit all constructors

  auto key() const                          // Add a convenience function to get the object's unique key
  {  return upcCode();  }                   // Note: function has internal linkage and is 'inlined"
};





// Specialize the formatter to accept and process SomeObject typed objects
template<>
struct std::formatter<SomeObject> : std::formatter<GroceryItem>
{};
