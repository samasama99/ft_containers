![Header](./ft_containers.png)
# ft_containers
This project is an implementation of various container types of the C++ standard template library (STL) in C++98. It provides custom versions of the following containers: vector, map, stack, and pair.

## Contents
The project consists of the following directories and files:

- map/ft_map.hpp: Implementation of the map container, which provides an associative container that stores key-value pairs in a sorted order based on the keys. The internal data structure of the map is implemented using an AVL tree.
- stack/ft_stack.hpp: Implementation of the stack container, which provides a Last-In-First-Out (LIFO) data structure for storing elements.
- pair/ft_pair.hpp: Implementation of the pair utility, which provides a simple key-value pair structure.
- vector/ft_vector.hpp: Implementation of the vector container, which provides a dynamic array-like data structure with random access.
- helpers/: Directory containing various helper files used in the implementations.
    - helpers/enable_if.hpp: Implementation of the enable_if utility, which provides a type-dependent conditional compilation.
    - helpers/equal.hpp: Implementation of the equal utility, which compares two ranges for equality.

    - helpers/is_integral.hpp: Implementation of the is_integral utility, which determines if a type is an integral type.
    - helpers/is_same.hpp: Implementation of the is_same utility, which determines if two types are the same.
    - helpers/iterators_traits.hpp: Implementation of the iterators_traits utility, which provides traits for iterators.
    - helpers/lexicographical_compare.hpp: Implementation of the lexicographical_compare utility, which compares two ranges lexicographically.
Additionally, there are test files for each container:

- tests/test_map.cpp: Test file for the map container.
- tests/test_stack.cpp: Test file for the stack container.
- tests/test_pair.cpp: Test file for the pair utility.
- tests/test_vector.cpp: Test file for the vector container.
- tests/intra_main.cpp: Test file for comparing the custom containers with the STL containers.

## Usage
To use the containers, you can include the respective header files in your C++ program:

```cpp
#include "map/ft_map.hpp"
#include "stack/ft_stack.hpp"
#include "pair/ft_pair.hpp"
#include "vector/ft_vector.hpp"

int main() {
    // Example usage of the containers
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ft::map<int, std::string> map;
    map.insert(ft::make_pair(1, "one"));
    map.insert(ft::make_pair(2, "two"));
    map.insert(ft::make_pair(3, "three"));

    ft::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    ft::pair<int, std::string> pair(1, "one");

    return 0;
}
```
Please note that these containers are not fully compatible with the STL containers and are intended for educational purposes only.

## Testing
The project includes test files for each container. You can compile and run the test files to verify the correctness and functionality of the containers.

To compile and run the test file for a specific container, use the following commands:

```shell
$ make test_map
$ ./test_map

$ make test_stack
$ ./test_stack

$ make test_pair
$ ./test_pair

$ make test_vector
$ ./test_vector
```
Additionally, there is a test file tests/intra_main.cpp that compares the performance and output of the custom containers with the STL containers. You can compile and run this test file to evaluate the differences.

```shell
$ make intra_stl
$ ./intra_stl

$ make intra_ft
$ ./intra_ft
```
## Cleaning
To clean the compiled files, you can use the following commands:

```shell
$ make clean

$ make fclean
```
## References
When implementing the containers, references were made to the following resources:

cplusplus.com
cppreference.com
These resources were used to understand the behavior and requirements of the standard containers in the C++98 standard.
