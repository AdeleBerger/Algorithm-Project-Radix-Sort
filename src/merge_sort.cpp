#include <Rcpp.h>

#include "sort_algorithms.h"

using namespace Rcpp; //to use the NumericVector object



 //' Merge Sort Algorithm (C++ Implementation)
 //' 
 //' @description
 //' This function implements the merge sort algorithm, a comparison-based divide-and-conquer sorting algorithm 
 //' with O(n log n) time complexity. It recursively splits the input vector into two halves, sorts each half, and 
 //' then merges the two sorted halves together.
 //' 
 //' Merge sort is stable, meaning it maintains the relative order of elements with equal values.
 //' 
 //' @param v A numeric vector to be sorted. The function returns the vector sorted in ascending order.
 //' 
 //' @return A sorted numeric vector with the elements arranged in ascending order.
 //' 
 //' @details
 //' Merge sort is a divide-and-conquer algorithm. It splits the input vector into two halves, recursively 
 //' sorts each half, and then merges the sorted halves back together. The merging step ensures that the 
 //' final result is a fully sorted vector. It is stable, meaning that the order of equal elements is preserved.
 //' 
 //' \itemize{
 //'   \item \bold{Time Complexity:} O(n log n) in all cases.
 //'   \item \bold{Space Complexity:} O(n) for temporary storage used during the merging process.
 //' }
 //' Merge sort is efficient and predictable, and its worst-case performance is always O(n log n). It is widely 
 //' used in applications requiring stable sorting or sorting large datasets that don't fit in memory.
 //' 
 //' @examples
 //' v <- c(3, 2, 1)
 //' merge_sort_Rcpp(v)
 //' # Returns: c(1, 2, 3)
 //' @name merge_sort_Rcpp
 //' @export
 // [[Rcpp::export]]
 NumericVector merge_sort_Rcpp(Nullable<NumericVector> v_) {
   if (v_.isNull()) {
     stop("Input cannot be NULL.");
   }
   NumericVector v(v_);
   if (v.size() == 0) return v;
   
   std::vector<double> vec(v.begin(), v.end());
   std::vector<double> sorted_vec = merge_sort(vec);
   return wrap(sorted_vec);
 }
