# how to use vector

## all insertion methods
#### assign

  ```
    template <class InputIterator>
      void assign (InputIterator first, InputIterator last);

    void assign (size_type n, const value_type& val);
  ```

  -- assign override all values with the given value, reallocate if the size > capacity 
    ** vec = [1, 2, 3] == assign (6, 99) => [99, 99, 99, 99, 99, 99]
    ** vec2 = [1, 2, 3] == assign (vec.begin(), v.end()) => [99, 99, 99, 99, 99, 99]
#### push_back

    ```
    void push_back (const value_type& val);
    ```

    -- push_back add an element to the end of the vector, reallocate if the capacity is full
    ** vec = [1, 2, 3] == push_back (4) => [1, 2, 3]
#### insert

    ```
      iterator insert (iterator position, const value_type& val);

      void insert (iterator position, size_type n, const value_type& val);

      template <class InputIterator>
          void insert (iterator position, InputIterator first, InputIterator last);
    ```

    -- inserting the element before the provided iterator, reallocate if the capacity is full
    ** vec = [1, 2, 3] == insert (vec.begin() + 1, 99) => [1, 99, 2, 3]
    ** vec2 = [6, 2, 3] == insert (vec2.begin(), vec.begin(), v.end()) => [1, 99, 2, 3, 6, 2, 3]
    ** vec3 = [9, 10] == insert (vec3.begin() + 1, 3, 99) => [9, 99, 99, 99 10]
