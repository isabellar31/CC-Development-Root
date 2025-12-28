import std;

import GroceryItem;
import GroceryItemDatabase;





namespace
{
  // Output some observed behavior. Call this function from within the carefully_move_grocery_items functions, just before kicking
  // off the recursion and then just after each move.

  // trace()
  void trace( std::stack<GroceryItem> const & sourceTrolley, std::stack<GroceryItem> const & destinationTrolley, std::stack<GroceryItem> const & spareTrolley, std::ostream & s = std::clog )
  {
    // Count and label the number of moves
    static std::size_t move_number = 0;

    // First time called will bind parameters to copies.
    //
    // Interrogating the stacks is a destructive process, so local copies of the parameters are made to work with.  The
    // carefully_move_grocery_items algorithm will swap the order of the arguments passed to this functions, but they will always be
    // the same objects - just in different orders. When outputting the stack contents, keep the original order so we humans can
    // trace the movements easier.  A container (std::map) indexed by the object's identity (address) is created to map address to a
    // predictable index and then the index is used so the canonical order remains the same from one invocation to the next.
    auto createMapping = [&]() -> std::map<std::stack<GroceryItem> const *, const unsigned>                             // Let's accommodate mixing up the parameters
    {
      if( destinationTrolley.size() == 0 && spareTrolley.size() == 0 )
      {
        return { {&sourceTrolley, 0}, {&destinationTrolley, 1}, {&spareTrolley, 2} };
      }
      else if( sourceTrolley.size() == 0 && destinationTrolley.size() != 0 && spareTrolley.size() == 0 )
      {
        return { {&sourceTrolley, 1}, {&destinationTrolley, 0}, {&spareTrolley, 2} };
      }
      throw std::invalid_argument( "Error - Invalid argument:  Order of passed parameters passed to function trace(...) is incorrect" );

    };
    static std::map<std::stack<GroceryItem> const *, const unsigned> indexMapping = createMapping();
    struct LabeledTrolley
    {
      std::string             label;
      std::stack<GroceryItem> trolley;
    };
    static std::array groceryTrolleys = { LabeledTrolley{ "Broken Trolley",  {} },
                                          LabeledTrolley{ "Working Trolley", {} },
                                          LabeledTrolley{ "Spare Trolley",   {} } };

    groceryTrolleys[indexMapping[&sourceTrolley]     ].trolley = sourceTrolley;
    groceryTrolleys[indexMapping[&destinationTrolley]].trolley = destinationTrolley;
    groceryTrolleys[indexMapping[&spareTrolley]      ].trolley = spareTrolley;


    // Determine the height of the tallest stack
    std::size_t tallestStackSize = std::max( { groceryTrolleys[0].trolley.size(),
                                               groceryTrolleys[1].trolley.size(),
                                               groceryTrolleys[2].trolley.size() } );


    // Print the header and underline it
    auto obuf_itr = std::ostreambuf_iterator<std::ostream::char_type>( s );

    std::format_to( obuf_itr, "After {:>3} moves:     ", move_number++ );                                               // print the move number
    for( auto && currentTrolley : groceryTrolleys ) std::format_to( obuf_itr, "{:<25.25}", currentTrolley.label );      // print the column labels
    std::format_to( obuf_itr, "\n{0:21}{0:->{1}}\n", "", 25 * groceryTrolleys.size() );                                 // underline the labels




    // Print the stack's contents
    for( ; tallestStackSize > 0;  --tallestStackSize )                                                                  // for each grocery item in a trolley
    {
      std::format_to( obuf_itr, "{:21}", "" );                                                                          // output a left margin to keep things lined up

      for( auto && currentTrolley : groceryTrolleys )                                                                   // for each grocery item trolley
      {
        if( currentTrolley.trolley.size() == tallestStackSize )                                                         // if the current trolley is this tall, print the top grocery item
        {
          std::string_view name = currentTrolley.trolley.top().productName();

          if( name.size() > 24 ) std::format_to( obuf_itr, "{}... ", name.substr( 0, 21 ) );                            // replace last few characters of long names with "..."
          else                   std::format_to( obuf_itr, "{:<25}", name) ;                                            // 24 characters plus a space to separate columns

          currentTrolley.trolley.pop();
        }
        else std::format_to( obuf_itr, "{:25}", "");                                                                    // otherwise, nothing to print in this trolley so print whitespace instead
      }
      s << '\n';
    }
    std::format_to( obuf_itr, "{0:21}{0:=>{1}}\n\n\n\n\n\n\n", "", 25 * groceryTrolleys.size() );                       // display a distinct marker between moves
  }  // trace()







  // carefully_move_grocery_items() - recursive
  /*********************************************************************************************************************************
  ** A recursive algorithm to carefully move grocery items from a broken trolley to a working trolley is given as follows:
  ** START
  ** Procedure carefully_move_grocery_items( number_of_items_to_be_moved, broken_trolley, working_trolley, spare_trolley )
  **
  **    IF number_of_items_to_be_moved == 1, THEN
  **       move top item from broken_trolley to working_trolley
  **       trace the move
  **
  **    ELSE
  **       carefully_move_grocery_items( number_of_items_to_be_moved-1, broken_trolley, spare_trolley, working_trolley )
  **       move top item from broken_trolley to working_trolley
  **       trace the move
  **       carefully_move_grocery_items( number_of_items_to_be_moved-1, spare_trolley, working_trolley, broken_trolley )
  **
  **    END IF
  **
  ** END Procedure
  ** STOP
  **
  ** As a side note, the efficiency class of this algorithm is exponential.  That is, the Big-O is O(2^n).
  *********************************************************************************************************************************/
  void carefully_move_grocery_items( std::size_t quantity, std::stack<GroceryItem> & broken_trolley, std::stack<GroceryItem> & working_trolley, std::stack<GroceryItem> & spare_trolley )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      /// Implement the algorithm above.

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }



  // carefully_move_grocery_items() - starter
  void carefully_move_grocery_items( std::stack<GroceryItem> & from, std::stack<GroceryItem> & to )
  {
    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Implement the starter function for the above algorithm.  If the "from" trolley contains grocery items, move those grocery
      /// items to the "to" trolley while ensuring the breakable grocery items are always on top of the nonbreakable grocery items,
      /// just like they already are in the "from" trolley.  That is, call the above carefully_move_grocery_items function to start
      /// moving grocery items recursively.  Call the above trace function just before calling carefully_move_grocery_items to get a
      /// starting point reference in the movement report.

    /////////////////////// END-TO-DO (2) ////////////////////////////
  }
}    // namespace




// main()
int main( int argc, char * argv[] )
{
  try
  {
    std::locale::global( std::locale( "en_GB.UTF-8" ) );

    // Snag an empty trolley as I enter the grocery store
    ///////////////////////// TO-DO (3) //////////////////////////////
      /// Create an empty grocery item trolley as a stack of grocery items and call it myTrolley.

    /////////////////////// END-TO-DO (3) ////////////////////////////




    // Shop for a while placing grocery items into my grocery item trolley
    //
    // Put the following grocery items into your trolley with the heaviest grocery item on the bottom and the lightest grocery item on
    // the top according to the ordering given in the table below
    //
    //      UPC Code         Name             Brand
    //      --------------   -------------    ---------------
    //      00688267039317   eggs             any                     <=== lightest item, put this on the top so heavy items wont break them
    //      00835841005255   bread            any
    //      09073649000493   apple pie        any
    //      00025317533003   hotdogs          Applegate Farms
    //      00038000291210   rice krispies    Kellogg's
    //      00075457129000   milk             any                     <===  heaviest item, put this on the bottom

    ///////////////////////// TO-DO (4) //////////////////////////////

    /////////////////////// END-TO-DO (4) ////////////////////////////




    // A wheel on my trolley has just broken and I need to move grocery items to a new trolley that works
    ///////////////////////// TO-DO (5) //////////////////////////////
      /// Create an empty grocery item trolley as a stack of grocery items and call it workingTrolley.  Then carefully move the grocery
      /// items in your now broken trolley to this working trolley by calling the above carefully_move_grocery_items function with two
      /// arguments.

    /////////////////////// END-TO-DO (5) ////////////////////////////




    // Time to checkout and pay for all this stuff.  Find a checkout line and start placing grocery items on the counter's conveyor belt
    ///////////////////////// TO-DO (6) //////////////////////////////
      /// Create an empty checkout counter as a queue of grocery items and call it checkoutCounter.  Then remove the grocery items
      /// from your working trolley and place them on the checkout counter, i.e., put them in this checkoutCounter queue.

    /////////////////////// END-TO-DO (6) ////////////////////////////




    // Now add it all up and print a receipt
    double amountDue = 0.0;
    GroceryItemDatabase & worldWideDatabase = GroceryItemDatabase::instance();                                          // Get a reference to the world wide database of grocery items. The database
                                                                                                                        // contains the full description and price of the grocery item.

    ///////////////////////// TO-DO (7) //////////////////////////////
      /// For each grocery item in the checkout counter queue, find the grocery item by UPC in the world wide grocery item database.
      /// If the grocery item on the counter is found in the database then accumulate the amount due and print the grocery item's full
      /// description and price on the receipt (i.e. write the grocery item's full description and price to standard output).
      /// Otherwise, print a message on the receipt that a description and price for the grocery item wasn't found and there will be
      /// no charge.

    /////////////////////// END-TO-DO (7) ////////////////////////////



    // Now check the receipt - are you getting charged the correct amount?
    // You can either pass the expected total when you run the program by supplying a parameter, like this:
    //    program 35.89
    // or if no expected results is provided at the command line, then prompt for and obtain expected result from standard input
    double expectedAmountDue = 0.0;
    if( argc >= 2 )
    {
      try
      {
        expectedAmountDue = std::stod( argv[1] );
      }
      catch( std::invalid_argument & ) {}                                                                               // ignore anticipated bad command line argument
      catch( std::range_error &      ) {}                                                                               // ignore anticipated bad command line argument
    }
    else
    {
      std::cout << "What is your expected amount due?  ";
      std::cin  >> expectedAmountDue;
    }

    // No "easy" way to get the current locale's currency symbol, but it is out there ...
    auto currency_symbol = std::use_facet<std::moneypunct<char>>( std::locale() ).curr_symbol();
    std::print( std::cout, "{:->25}\nTotal  {}{:.2Lf}\n\n\n", "", currency_symbol, amountDue );

    if( std::abs(amountDue - expectedAmountDue) < 1E-4 ) std::clog << "PASS - Amount due matches expected\n";
    else                                                 std::clog << "FAIL - You're not paying the amount you should be paying\n";
  }

  catch( std::exception & ex )
  {
    std::print( std::cerr, "Fatal Error:  unhanded exception {:?}\n"
                           "{}\n",
                           typeid( ex ).name(),
                           ex.what() );
  }
  return 0;
}
