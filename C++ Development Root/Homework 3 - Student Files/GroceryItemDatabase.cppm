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
    // Get a reference to the one and only instance of the database
    static GroceryItemDatabase & instance();

    // Locate and return a reference to a particular record
    GroceryItem * find( const std::string & upc );                                                    // Returns a pointer to the item in the database if
                                                                                                      // found, nullptr otherwise
    // Queries
    std::size_t size() const;                                                                         // Returns the number of items in the database

  private:
    GroceryItemDatabase            ( const std::string & filename );

    GroceryItemDatabase            ( const GroceryItemDatabase & ) = delete;                          // intentionally prohibit making copies
    GroceryItemDatabase & operator=( const GroceryItemDatabase & ) = delete;                          // intentionally prohibit copy assignments

    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Private implementation details
      /// Add any necessary private helper function declarations (prototypes), member attributes, etc.

    /////////////////////// END-TO-DO (2) ////////////////////////////
};
