# Easy-Vector Commands File

### vector* vec_init(size_t elem_size);
- **size_t elem_size** : *Size in bytes of a single vector element*

### Function : *Allocates and initializes a new empty vector with an initial capacity of 2*
---
### bool vec_push_back(vector* ptr, void* value);
- **vector* ptr** : *Pointer to the vector structure*
- **void* value** : *Pointer to the value that will be inserted or copied into the vector*

**Function** : *Appends an element to the end of the vector, growing capacity if needed*
<br><br>
<br><br>


### bool vec_pop_back(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure* 

**Function** : *Removes the last element by decreasing size (without reducing capacity)*
<br><br>
<br><br>




### void vec_free(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Frees all memory allocated by the vector and the structure itself*
<br><br>
<br><br>




### void* vec_get_ptr(vector* ptr, size_t index);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t index** : *Index of an element inside the vector*

**Function** : *Returns a direct pointer to the element at the given index (without copying)*
<br><br>
<br><br>



### bool vec_get_var(vector* ptr, size_t index, void* var);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t index** : *Index of an element inside the vector*
- **void* var** : *Pointer to an external variable where the retrieved vector value will be copied*

**Function** : *Copies the element at the given index into the variable pointed to by var*
<br><br>
<br><br>



### void vec_show(vector* ptr, size_t index);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t index** : *Index of an element inside the vector*

**Function** : *Shows the element at the given index*
<br><br>
<br><br>



### void* vec_begin(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Returns a pointer to the first element of the vector (or NULL if empty)*
<br><br>
<br><br>



### void* vec_end(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Returns a pointer to the position one past the last element (useful for iteration)*
<br><br>
<br><br>



### size_t vec_size(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Returns the current number of elements in the vector*
<br><br>
<br><br>



### size_t vec_capacity(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Returns the maximum number of elements the vector can hold without reallocating*
<br><br>
<br><br>



### bool vec_reserve(vector* ptr, size_t newCapacity);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t newCapacity** : *New minimum capacity requested for the vector*

**Function** : *Ensures the vector has at least newCapacity capacity without changing its size*
<br><br>
<br><br>



### bool vec_resize(vector* ptr, size_t newSize);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t newSize** : *New logical size of the vector*

**Function** : *Changes the vector's size, truncating or zero-extending and reallocating if necessary*
<br><br>
<br><br>



### void vec_clear(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Remove all elements by setting size to 0 (without freeing memory)*
<br><br>
<br><br>



### bool vec_shrink_to_fit(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Reduces the vector's capacity to match its current size (or 2 if empty)*
<br><br>
<br><br>



### bool vec_is_empty(vector* ptr);
- **vector* ptr** : *Pointer to the vector structure*

**Function** : *Returns true if the vector contains no element (size == 0)*
<br><br>
<br><br>



### bool vec_insert(vector* ptr, size_t index, void *value);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t index** : *Index of an element inside the vector*
- **void* value** : *Pointer to the value that will be inserted or copied into the vector*

**Function** : *Copies an element at the givin index, shifting subsequent elements to the right*
<br><br>
<br><br>

### void vec_erase(vector* ptr, size_t index);
- **vector* ptr** : *Pointer to the vector structure*
- **size_t index** : *Index of an element inside the vector*

**Function** : *Removes the element at the given index, shifting subsequent elements to the left*


