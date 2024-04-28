#ifndef MS_H
#define MS_H
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class MergeSort{

  // Enumeration for sorting order
  enum class SortOrder {
    Ascending,
      Descending
      };

  static std::vector<T> mergeSort(const std::vector<T>& arr, SortOrder sortOrder);
  static std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right, SortOrder sortOrder);





};

#endif
