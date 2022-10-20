# Confusing methods in map

## methods
#### operator[]
if the key already exists you get reference to the mapped value
  if not operator[] actually insert the element and return a reference to the mapped value

#### insert
if you insert you get a pair
  the first element in the pair is an iterator pointing to (key, value) pair
  the second is a boolean 
    true if the element is newly inserted 
    false if the element exists
  insert doesn't update the value (the mapped value)

## iterators

``````
        4
      /    \
     2      6
    / \    / \
   1   3  5   7
               \
                8
``````

```
// pseudo code
assert(m.begin() == 1)
assert(m.end() - 1 == 8)

for (it = m.begin(), it != m.end(), it++)
  print (*it.value)

```

Output :: 1 2 3 4 5 6 7 8
