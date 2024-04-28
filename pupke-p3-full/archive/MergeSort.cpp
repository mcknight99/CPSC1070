#include "MergeSort.h"


//this is code that i wrote a long time ago in JS for a different project that I converted for here in c++ 


// mergeSort function
template <typename T>
std::vector<T> MergeSort<T>::mergeSort(const std::vector<T>& arr, SortOrder sortOrder) {
  if (arr.size() == 1) {
    return arr;
  }

  // Send left and right to the mergeSort to break it down into pieces
  return merge(mergeSort(std::vector<T>(arr.begin(), arr.begin() + arr.size() / 2), sortOrder),
	       mergeSort(std::vector<T>(arr.begin() + arr.size() / 2, arr.end()), sortOrder), sortOrder);
}

// merge function
template <typename T>
std::vector<T> MergeSort<T>::merge(const std::vector<T>& left, const std::vector<T>& right, SortOrder sortOrder) {
  std::vector<T> result;
  size_t l = 0;
  size_t r = 0;

  while (l < left.size() && r < right.size()) {
    if (sortOrder == SortOrder::Ascending) {
      if (left[l] < right[r]) {
	result.push_back(left[l++]);
      } else {
	result.push_back(right[r++]);
      }
    } else if (sortOrder == SortOrder::Descending) {
      if (left[l] > right[r]) {
	result.push_back(left[l++]);
      } else {
	result.push_back(right[r++]);
      }
    } else {
      std::cerr << "ERROR #01" << std::endl;
      // If you're reading my comments still, hello!
    }
  }

  result.insert(result.end(), left.begin() + l, left.end());
  result.insert(result.end(), right.begin() + r, right.end());

  return result;
}

/*
int main() {
  // Example usage
  std::vector<int> numbers = {4, 2, 7, 1, 9, 3, 6, 5, 8};
  std::vector<int> sortedNumbers = mergeSort(numbers, SortOrder::Ascending);

  // Print sorted numbers
  for (const auto& num : sortedNumbers) {
    std::cout << num << " ";
  }

  return 0;
}
*/

template class MergeSort<std::string>;

