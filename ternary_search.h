template <typename ArrayLike, typename T>
int ternary_search(const ArrayLike& array, const T& value, int low, int high) {
  int third = low + ((high - low) / 3), two_thirds = low + (2 * (high - low) / 3);
    if (high == low) { //I guess this is the guy I was supposed to have
        return -1;
    } 
    if (value <= array[third]) {
        if (value == array[third]) {
        //std::cout << "checking out array[third]: " << array[third] << std::endl;
          return third;
        }
        else if (high - low <= 1) {
            return -1;
        }
        //std::cout << "babb" << std::endl;
      return ternary_search(array, value, low, third);
    }
    else if (value > array[third] && value < array[two_thirds]){ 
        if (high - third <= 2 && high - two_thirds <= 1) { /
            return -1;
        }
      return ternary_search(array, value, third + 1, two_thirds);
    }
    else if (value >= array[two_thirds]) {
        if (value == array[two_thirds]) {
          return two_thirds;
          }
        else if (high - low <= 1) {
            return -1;
        }
      return ternary_search(array, value, two_thirds + 1, high);
    }
  return -1; 
}
