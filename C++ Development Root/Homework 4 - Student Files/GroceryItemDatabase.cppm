module;                                                                                               // Global fragment (not part of the module)
  // Empty




/***********************************************************************************************************************************
**  Module GroceryItemDatabase Interface
**
***********************************************************************************************************************************/
///////////////////////// TO-DO (1) //////////////////////////////
  /// Define and export the primary module interface definition for the GroceryItemDatabase module, and then import the modules you
  /// depend on.
  ///
  /// Hint:  Import only what you use, use everything you import
  ///
  /// Do not put anything else in this section, i.e. classes, functions, etc.

/////////////////////// END-TO-DO (1) ////////////////////////////



// Singleton Design Pattern
export class GroceryItemDatabase
{
  public:
    // Public Types
    class Key;

    // Database Access
    static GroceryItemDatabase & instance();
                                                                                // found, nullptr otherwise
    // Queries
    GroceryItem * find( const Key & upc );                                      // Locates and returns a pointer to the item in the database if
    std::size_t   size() const;                                                 // Returns the number of items in the database

  private:
    GroceryItemDatabase( const std::string & filename );

    GroceryItemDatabase( const GroceryItemDatabase & )             = delete;    // intentionally prohibit making copies
    GroceryItemDatabase & operator=( const GroceryItemDatabase & ) = delete;    // intentionally prohibit copy assignments


    std::map<Key /*UPC*/, GroceryItem> _data;                                   // Collection of grocery items indexed by UPC
};




// Not exported, but reachable
class GroceryItemDatabase::Key
{
  public:                                                                       // No implicit conversion from string to Key.
    explicit Key( std::string value );                                          // Causes the default constructor to not be synthesized (intentional), the other 5 are synthesized and just what we want
    std::string const & to_string() const;

    auto operator<=>( Key const & rhs ) const = default;                        // Endow objects with the ability to compare themselves
    bool operator== ( Key const & rhs ) const = default;

  private:
    std::string _upc;                                                           // The key of the Grocery Item is its UPC
};















/***********************************************************************************************************************************
** (C) Copyright 2025 by Thomas Bettens. All Rights Reserved.
**
** DISCLAIMER: The participating authors at California State University's Computer Science Department have used their best efforts
** in preparing this code. These efforts include the development, research, and testing of the theories and programs to determine
** their effectiveness. The authors make no warranty of any kind, expressed or implied, with regard to these programs or to the
** documentation contained within. The authors shall not be liable in any event for incidental or consequential damages in
** connection with, or arising out of, the furnishing, performance, or use of these libraries and programs.  Distribution without
** written consent from the authors is prohibited.
***********************************************************************************************************************************/

/**************************************************
** Last modified:  10-OCT-2025
** Last Verified:  10-OCT-2025
** Verified with:  MS Visual Studio 2022 Version 17.14.9,  Compiler Version 19.44.35213 (/std:c++latest)
**                 GCC version 15.1.0 (-std=c++23 )
**                 Clang version 21.0.0 (-std=c++23 -stdlib=libc++)
***************************************************/
