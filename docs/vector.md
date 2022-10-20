# How to use vector

## All insertion methods
#### assign

```

template <class InputIterator>
void assign (InputIterator first, InputIterator last);

void assign (size_type n, const value_type& val);

```

Assign override all values with the given value, reallocate if the size > capacity 
-- vec = [1, 2, 3] == assign (6, 99) => [99, 99, 99, 99, 99, 99]
-- vec2 = [1, 2, 3] == assign (vec.begin(), v.end()) => [99, 99, 99, 99, 99, 99]
#### push_back

```

void push_back (const value_type& val);

```

Push_back add an element to the end of the vector, reallocate if the capacity is full
-- vec = [1, 2, 3] == push_back (4) => [1, 2, 3]
#### insert

```

iterator insert (iterator position, const value_type& val);

void insert (iterator position, size_type n, const value_type& val);

template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last);

```

Inserting the element before the provided iterator, reallocate if the capacity is full
-- vec = [1, 2, 3], insert (vec.begin() + 1, 99) => [1, 99, 2, 3]
-- vec2 = [6, 2, 3], insert (vec2.begin(), vec.begin(), v.end()) => [1, 99, 2, 3, 6, 2, 3]
-- vec3 = [9, 10], insert (vec3.begin() + 1, 3, 99) => [9, 99, 99, 99 10]


## Other intresting methods
#### resize
```

void resize (size_type n, value_type val = value_type());

```

Resizes vector so that it contains n elements
If n < size, remove all elements until the size is n
If n > size, inserting elements until the size is n assigning val to the new elements 
If n > capacity, an automatic reallocation will happen
-- [1, 2, 3, 4, 5], resize(3, 0) => [1, 2, 3]
-- [1, 2, 3, 4, 5], resize(7, 0) => [1, 2, 3, 4, 5, 0, 0]

#### reserve
```

void reserve (size_type n);

```

reserve make sure that the vector at least can hold n elements (capacity >= n)

If n > capacity, an automatic reallocation will happen
reserve has no effect on the vector size and cannot alter its elements.


#### erase

```

iterator erase (iterator position);

iterator erase (iterator first, iterator last);

```

remove a single element or a range, only destroying (no deallocation) and reducing the size

[1, 2, 3], erase(begin() + 1) => [1, 3]
[1, 2, 3, 4, 5, 6], erase(begin(), begin() + 3) => [4, 5, 6]
