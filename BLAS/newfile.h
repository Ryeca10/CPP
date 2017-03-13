 /****************************************************************/
 /* Parallel Combinatorial BLAS Library (for Graph Computations) */

 /*
00008 Copyright (c) 2011, Aydin Buluc
00009 
00010 Permission is hereby granted, free of charge, to any person obtaining a copy
00011 of this software and associated documentation files (the "Software"), to deal
00012 in the Software without restriction, including without limitation the rights
00013 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
00014 copies of the Software, and to permit persons to whom the Software is
00015 furnished to do so, subject to the following conditions:
00016 
00017 The above copyright notice and this permission notice shall be included in
00018 all copies or substantial portions of the Software.
00019 
00020 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
00021 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
00022 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
00023 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
00024 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
00025 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
00026 THE SOFTWARE.
00027 */
 
 #ifndef _COMPARE_H_
#define _COMPARE_H_
 
 #include <cmath>
 #include "SpDefs.h"
 #include "CombBLAS.h"


template <class T>
00038 struct ErrorTolerantEqual:
00039         public binary_function< T, T, bool >
00040         {
00041                 ErrorTolerantEqual(const T & myepsilon):epsilon(myepsilon) {};
00042                 inline bool operator() (const T & a, const T & b) const
00043                 {
00044                         // According to the IEEE 754 standard, negative zero and positive zero should 
00045                         // compare as equal with the usual (numerical) comparison operators, like the == operators of C++ 
00046 
00047                         if(a == b)      // covers the "division by zero" case as well: max(a,b) can't be zero if it fails
00048                                 return true;    // covered the integral numbers case
00049 
00050                         return ( std::abs(a - b) < epsilon || (std::abs(a - b) / max(std::abs(a), std::abs(b))) < epsilon ) ;
00051                 }
00052                 T epsilon;
00053         };


template < typename T >
struct absdiff : binary_function<T, T, T>
 {
        T operator () ( T const &arg1, T const &arg2 ) const
        {
                using std::abs;
                 return abs( arg1 - arg2 );
         }
 };


template<class IT, class NT>
00067 struct TupleEqual:
00068         public binary_function< tuple<IT, IT, NT>, tuple<IT, IT, NT>, bool >
00069         {
00070                 inline bool operator()(const tuple<IT, IT, NT> & lhs, const tuple<IT, IT, NT> & rhs) const
00071                 {
00072                         return ( (get<0>(lhs) == get<0>(rhs)) && (get<1>(lhs) == get<1>(rhs)) );
00073                 } 
00074         };


template <class IT, class NT>
struct ColLexiCompare:  // struct instead of class so that operator() is public
         public binary_function< tuple<IT, IT, NT>, tuple<IT, IT, NT>, bool >  // (par1, par2, return_type)
         {
                inline bool operator()(const tuple<IT, IT, NT> & lhs, const tuple<IT, IT, NT> & rhs) const
                 {
                        if(get<1>(lhs) == get<1>(rhs))
                        {
                                 return get<0>(lhs) < get<0>(rhs);
                         }
                         else
                         {
                                return get<1>(lhs) < get<1>(rhs);
                         }
                 }
       };


// Non-lexicographical, just compares columns
template <class IT, class NT>
struct ColCompare:  // struct instead of class so that operator() is public
public binary_function< tuple<IT, IT, NT>, tuple<IT, IT, NT>, bool >  // (par1, par2, return_type)
        {
                inline bool operator()(const tuple<IT, IT, NT> & lhs, const tuple<IT, IT, NT> & rhs) const
                 {
                         return get<1>(lhs) < get<1>(rhs);
                 }
         };


// Non-lexicographical, just compares columns
template <class IT, class NT>
struct RowCompare:  // struct instead of class so that operator() is public
         public binary_function< tuple<IT, IT, NT>, tuple<IT, IT, NT>, bool >  // (par1, par2, return_type)
        {
                inline bool operator()(const tuple<IT, IT, NT> & lhs, const tuple<IT, IT, NT> & rhs) const
                 {
                         return get<0>(lhs) < get<0>(rhs);
                 }
        };


template <class IT, class NT>
struct ColLexiCompareWithID:  // struct instead of class so that operator() is public
         public binary_function< pair< tuple<IT, IT, NT> , int > , pair< tuple<IT, IT, NT> , int>, bool >  // (par1, par2, return_type)
         {
               inline bool operator()(const pair< tuple<IT, IT, NT> , int > & lhs, const pair< tuple<IT, IT, NT> , int > & rhs) const
                {
                         if(get<1>(lhs.first) == get<1>(rhs.first))
                       {
                                return get<0>(lhs.first) < get<0>(rhs.first);
                        }
                        else
                         {
                                return get<1>(lhs.first) < get<1>(rhs.first);
                         }
                 }
        };
 
 #endif