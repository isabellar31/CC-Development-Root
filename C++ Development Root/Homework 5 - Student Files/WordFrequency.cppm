module;                                                                               // Global fragment (not part of the module)
  // Empty




/***********************************************************************************************************************************
**  Module WordFrequency Interface
**
***********************************************************************************************************************************/
///////////////////////// TO-DO (1) //////////////////////////////
  /// Define and export the WordFrequency module and then import the modules you depend on.
  ///
  /// Hint:  Import only what you use, use everything you import
  ///
  /// Do not put anything else in this section, i.e. classes, functions, etc.
export module WordFrequency;

import std;
/////////////////////// END-TO-DO (1) ////////////////////////////



export template<typename Hasher = std::hash<std::string>>
class WordFrequency
{
  public:
    // Construction and assignment
    WordFrequency( std::istream & iStream = std::cin );                 // (default) constructor, add words from file to hash table


    // Accessors, Queries, and Observers
    std::size_t numberOfWords    (                       ) const;       // returns the number of unique words
    std::size_t wordCount        ( std::string_view word ) const;       // returns the number of occurrences of the given word
    std::string mostFrequentWord (                       ) const;       // returns the most frequent word
    std::size_t maxBucketSize    (                       ) const;       // returns the size of the largest bucket in the hash table
    double      bucketSizeAverage(                       ) const;       // returns the average number of elements per bucket


  private:
    // Instance Attributes - See requirements
    ///////////////////////// TO-DO (2) //////////////////////////////
      /// The class should have a single instance attribute of type std::unordered_map, which is the C++ Standard Library's
      /// implementation of a hash table, to store the association of words (key) to the number of times a word occurs (value). Be
      /// sure to provide all three types when defining the std::unordered_map, including setting std::unordered_map's third
      /// argument to Hasher (WordFrequency's template parameter).
    std::unordered_map<std::string, std::size_t, Hasher> _wordCounts;
    /////////////////////// END-TO-DO (2) ////////////////////////////
};    // class WordFrequency















// Not exported but reachable
/***********************************************************************************************************************************
************************************************************************************************************************************
** Template Implementation
*
************************************************************************************************************************************
***********************************************************************************************************************************/

inline std::string sanitize( std::string_view word )
{
  constexpr char bad_char[] = " \t\r\n\b\v_-\"'(){}+/*,=.!?:;";                       // leading and trailing characters to be removed
  static const std::locale locality;

  auto startIndex = word.find_first_not_of( bad_char );                               // start with the first non-bad character
  if( startIndex == std::string_view::npos ) startIndex = word.size();                // if the word contains only bad characters ...

  std::size_t count    = 0;                                                           // assume the word contains only bad characters ...
  auto        endIndex = word.find_last_not_of( bad_char );                           // end with the first non-bad character

  if( endIndex != std::string_view::npos ) count = endIndex - startIndex + 1;         // number of characters to use in results

  std::string result{ word.substr( startIndex, count ) };                             // strip the leading and trailing bad characters
  for( auto & c : result ) c = std::tolower( c, locality );                           // convert to lower case

  return result;                                                                      // result is moved optimized (copy elision) to the caller, std::move( result ) not required
}







// Implement WordFrequency::WordFrequency( std::istream ) - See requirements
///////////////////////// TO-DO (3) //////////////////////////////
template<typename Hasher>
WordFrequency<Hasher>::WordFrequency( std::istream & iStream )
{
  std::string word;
  while( iStream >> word )
  {
    auto clean = sanitize( word );
    if( !clean.empty() )
    {
      ++_wordCounts[ clean ];
    }
  }
}
/////////////////////// END-TO-DO (3) ////////////////////////////







// Implement WordFrequency::numberOfWords() const - See requirements
///////////////////////// TO-DO (4) //////////////////////////////
template<typename Hasher>
std::size_t WordFrequency<Hasher>::numberOfWords() const
{
  return _wordCounts.size();
}
/////////////////////// END-TO-DO (4) ////////////////////////////







// Implement WordFrequency::wordCount( const std::string & ) const - See requirements
///////////////////////// TO-DO (5) //////////////////////////////
template<typename Hasher>
std::size_t WordFrequency<Hasher>::wordCount( std::string_view word ) const
{
  auto clean = sanitize( word );
  auto iter  = _wordCounts.find( clean );

  return iter == _wordCounts.end() ? 0u : iter->second;
}
/////////////////////// END-TO-DO (5) ////////////////////////////







// Implement WordFrequency::mostFrequentWord() const - See requirements
///////////////////////// TO-DO (6) //////////////////////////////
template<typename Hasher>
std::string WordFrequency<Hasher>::mostFrequentWord() const
{
  if( _wordCounts.empty() ) return "";

  auto maxIter = _wordCounts.begin();
  for( auto iter = _wordCounts.begin(); iter != _wordCounts.end(); ++iter )
  {
    if( iter->second > maxIter->second )
    {
      maxIter = iter;
    }
  }

  return maxIter->first;
}
/////////////////////// END-TO-DO (6) ////////////////////////////







// Implement WordFrequency::maxBucketSize() const - See requirements
///////////////////////// TO-DO (7) //////////////////////////////
  /// Hint: see the unordered_map's bucket interface at https://en.cppreference.com/w/cpp/container/unordered_map
template<typename Hasher>
std::size_t WordFrequency<Hasher>::maxBucketSize() const
{
  std::size_t maxSize = 0;

  for( std::size_t i = 0; i < _wordCounts.bucket_count(); ++i )
  {
    maxSize = std::max( maxSize, _wordCounts.bucket_size( i ) );
  }

  return maxSize;
}
/////////////////////// END-TO-DO (7) ////////////////////////////







// Implement WordFrequency::bucketSizeAverage() const - See requirements
///////////////////////// TO-DO (8) //////////////////////////////
template<typename Hasher>
double WordFrequency<Hasher>::bucketSizeAverage() const
{
  if( _wordCounts.bucket_count() == 0 ) return 0.0;

  return static_cast<double>( _wordCounts.size() ) /
         static_cast<double>( _wordCounts.bucket_count() );
}
/////////////////////// END-TO-DO (8) ////////////////////////////















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
** Last modified:  14-NOV-2025
** Last Verified:  14-NOV-2025
** Verified with:  MS Visual Studio 2022 Version 17.14.20,  Compiler Version 19.44.35220 (/std:c++latest)
**                 GCC version 15.1.0 (-std=c++23 )
**                 Clang version 21.0.0 (-std=c++23 -stdlib=libc++)
***************************************************/
