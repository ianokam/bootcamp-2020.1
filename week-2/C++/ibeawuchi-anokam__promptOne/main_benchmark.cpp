///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Week 2 - Arrays Prompt 1                             //
// Filename:            main_benchmark.cpp                                   //
//---                                                                        //
// Date of Creation:    06/09/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
//- Program Description:                                                     //
//                                                                           //
//      You are given a string.                                              //
//      Find the longest palindromic substring in it.                        //
//      and Return it's value.                                               //
//                                                                           //
//---------------------------------------------------------------------------//
//                                                                           //
//- Example:                                                                 //
//                                                                           //
//      Input:                                                               //
//                  "ababad"                                                 //
//                                                                           //
//        Output:                                                            //
//                  "ababa"                                                  //
//                                                                           //
//        Explanation:                                                       //
//                  Output the longest substring(s) which                    //
//                  are also palindromic                                     //
//                                                                           //
//---------------------------------------------------------------------------//
//- References :  https://en.wikipedia.org/wiki/Palindrome                   //
//---------------------------------------------------------------------------//


//===========================================================================//
//                    F U N C T I O N    M O D U L E   -                     //
//                      G L O B A L    S E C T I O N                         //
//===========================================================================//
//---------------------------------------
// Testing Library                      :
//---------------------------------------
#define CATCH_CONFIG_MAIN   // Allows the Catch2 Library to instantiate a
                            // Main() module of it's own

#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.h"          // Catch2 Unit Test FrameWork (Library)
//---------------------------------------
// System Libraries                     :
//---------------------------------------
#include <iostream>         // Used for Debugging
#include <string>           // container for the INPUT  value
#include <vector>           // container for the RETURN Value
using namespace std;

//===========================================================================//
//        F U N C T I O N    M O D U L E (S)    T O    T E S T               //
//===========================================================================//
vector< string > longest_palindrome(  string& word_container  )
{
// Function Definition -
// This function finds the longest
// palindrome(s) in a given string.
//
// The only ascii characters allowed are
// ascii[ 0-9a-zA-z ], ascii[ .?!', ], and
// a space character.
//-------------------------------------------
    
    
    //--------------------------------------
    // Output Container Declaration        :
    //--------------------------------------
    vector< string > longest_palindromic_substrings;        // The output array
    
    
    //--------------------------------------
    // Check the Characters                :
    //--------------------------------------
    bool is_properformat = true;
    for(  long i = 0;  i < word_container.size();  i++  ){
        
        // Make sure that only the ascii[ 0-9a-zA-z ], ascii[ .?!', ], and
        // space characters are in the string
        // ELSE stop the check:
        if(  !( (word_container.at(i) >= '0'  && word_container.at(i)  <= '9')  ||
                (word_container.at(i) >= 'a'  && word_container.at(i)  <= 'z')  ||
                (word_container.at(i) >= 'A'  && word_container.at(i)  <= 'Z')  ||
                (word_container.at(i) == '.') || (word_container.at(i) == '?')  ||
                (word_container.at(i) == '!') || (word_container.at(i) == '\'') ||
                (word_container.at(i) == ',') || (word_container.at(i) == ' ')      ) )
        {
            is_properformat = false;
            break;
        }
        else{
            // .. IF the character is ascii[ .?!', ] or a space character
            // THEN  Remove the character from the string:
            if(  (word_container.at(i) == '.') || (word_container.at(i) == '?')  ||
                 (word_container.at(i) == '!') || (word_container.at(i) == '\'') ||
                 (word_container.at(i) == ',') || (word_container.at(i) == ' ')      )
            {
                word_container.erase( word_container.begin() + i );
            }
        }
    }
    
    
    //--------------------------------------
    // BEGIN the Palindrome checking phase :
    //--------------------------------------
    if( is_properformat == true ){
        
        //----------------------------------
        // FIND and STORE all the          :
        // substrings                      :
        //----------------------------------
        vector< string >    substrings;
        long max_length =   word_container.size();
        
        // IF the 'word_container' is NOT empty (i.e. the size is greater than zero)
        // Then The For Loops will run:
        for( long i=0;  i < max_length;  i++ ){
            for ( long length = 1; length <= (max_length - i); length++){

                // Store the sustring:
                substrings.push_back(  word_container.substr( i, length ) );
            }
        }
        //----------------------------------
        // Find the Palindromic            :
        // substring(s)                    :
        //----------------------------------
        string lowercase_copy;
        vector< string > palindromic_substrings;
        long longest_length = 0;

        for( auto palindrome: substrings ){
 
            // Make a copy to account for uppercase letters
            // being the same as lowercase letters:
            lowercase_copy = palindrome;
            for( auto character : lowercase_copy ){
                if( character >= 'A' && character <= 'Z' ){
                    character = static_cast<char>(  static_cast<int>(character) + 32  );
                }
            }
            
            // CHECK the 'lowercase_copy' variable and STORE the 'palindrome' variable
            // if the 'lowercase_copy' variable is a palindrome :
            if(  string( lowercase_copy.begin() , lowercase_copy.end()  ) ==
                 string( lowercase_copy.rbegin(), lowercase_copy.rend() )      )
            {
                palindromic_substrings.push_back( palindrome );

                // Account for the longest palindrome(s):
                if( palindrome.size() > longest_length ){
                    longest_length = palindrome.size();
                }
            }
        }
        //----------------------------------
        // Find the Longest Palindromic    :
        // substring(s)                    :
        //----------------------------------
        longest_palindromic_substrings = { };
        
        for( auto longest_palindrome: palindromic_substrings ){

            // FIND and STORE the longest palindrome(s):
            if( longest_palindrome.size() == longest_length ){
                longest_palindromic_substrings.push_back( longest_palindrome );
            }
        }
    }
    //----------------------------------
    // RETURN the Longest Palindromic  :
    // substring(s)                    :
    //----------------------------------
    return ( longest_palindromic_substrings );
}


//===========================================================================//
//                           B E N C H M A R K (S)                           //
//===========================================================================//
TEST_CASE(       "CanGetEmptySet"        ,
               "[weekTwoPromptOne_test]"       )
{
// Test Description -
//
//  This test benchmarks the function, "longest_palindrome",
//  which gives an empty Set and returns its performance.
//--------------------------------------------------------------------

    
    //---------------------------------------------------
    // TEST 1                                           :
    //---------------------------------------------------
    BENCHMARK("EmptySet__SIZE_0"){
        // Input Value:
        string word = "";                                       // EMPTY String
        
        // Answers to Compare:
        vector< string > ans     =  {  };                       // EMPTY Set #1
        
        // CHECK:
        return( longest_palindrome( word ) );                   // EMPTY Set #2-
                                                                // Assertion to
                                                                // check
    };
}
TEST_CASE(       "CanGetNonEmptySet"        ,
               "[weekTwoPromptOne_test]"       )
{
// Test Description -
//
//  This test benchmarks the function, "longest_palindrome",
//  which gives a non-empty Set and returns its performance.
//--------------------------------------------------------------------

    
    //---------------------------------------------------
    // Variable Declarations                            :
    //---------------------------------------------------
    string word;
    vector< string > ans;
    vector< string > output;
    

    //---------------------------------------------------
    // TEST 2.1                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_70"){
        // Input Value:
        word = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";            // EMPTY String
        
        // Answers to Compare:
        ans  =  { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };    // EMPTY Set
        
        // CHECK:
        return( longest_palindrome( word ) );                   // Non-EMPTY Set -
                                                                // Assertion to
                                                                // check
    };
    //---------------------------------------------------
    // TEST 2.2                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_80"){
        // Input Value:
        word = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";            // EMPTY String
        
        // Answers to Compare:
        ans     =  { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };    // EMPTY Set
        
        // CHECK:
        return( longest_palindrome( word ) );                   // Non-EMPTY Set -
                                                                // Assertion to
                                                                // check
    };
    //---------------------------------------------------
    // TEST 2.3                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_86"){
        // Input Value:
        word = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";            // EMPTY String
        
        // Answers to Compare:
        ans     =  { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };    // EMPTY Set
        
        // CHECK:
        return( longest_palindrome( word ) );                   // Non-EMPTY Set -
                                                                // Assertion to
                                                                // check
    };
    //---------------------------------------------------
    // TEST 2.4                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_93"){
        // Input Value:
        word = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";            // EMPTY String
        
        // Answers to Compare:
        ans     =  { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };    // EMPTY Set
        
        // CHECK:
        return( longest_palindrome( word ) );                   // Non-EMPTY Set -
                                                                // Assertion to
                                                                // check
    };
    //---------------------------------------------------
    // TEST 2.5                                         :
    //---------------------------------------------------
    BENCHMARK("NonEmptySet_ProperOutputs__SIZE_100"){
        // Input Value:
        word = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";            // EMPTY String
        
        // Answers to Compare:
        ans     =  { "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" };    // EMPTY Set
        
        // CHECK:
        return( longest_palindrome( word ) );                   // Non-EMPTY Set -
                                                                // Assertion to
                                                                // check
    };
}
