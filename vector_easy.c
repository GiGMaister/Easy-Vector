#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "vector_easy.h"

static size_t next_power_of_two(size_t n) {
    if (n == 0) {
        return 1;
    }

    size_t cap = 1;

    while (cap < n) {
        cap <<= 1;  
    }

    return cap;
}

static int vec_ensure_capacity(vector* ptr, size_t min_capacity)
{
    if(ptr == NULL) {
        return 0;
    }

    if(ptr->capacity >= min_capacity) {
        return 1;
    }

    size_t newCapacity = next_power_of_two(min_capacity);

    void* tmp = realloc(ptr->data, newCapacity * ptr->elem_size);

    if(tmp == NULL) {
        return 0;
    }

    ptr->data = tmp;
    ptr->capacity = newCapacity;

    return 1;
}

// Allocates and initializes a new empty vector with an initial capacity of 2
vector* vec_init(size_t elem_size) {
    vector *ptr = malloc(sizeof(vector));

    if(ptr == NULL) {
        return NULL;
    }

    ptr->size = 0;
    ptr->capacity = 2;
    ptr->elem_size = elem_size;
    ptr->data = malloc(ptr->capacity * elem_size);

    if(!ptr->data) {
        free(ptr);
        return NULL;
    }

    return ptr;
}

//Appends an element to the end of the vector, growing capacity if needed
bool vec_push_back(vector* ptr, void *value)
{
    if(!ptr || !value) {
        return false;
    }

    if(!vec_ensure_capacity(ptr, ptr->size + 1)) {
        return false;
    }

    void* dst = (char*)ptr->data + (ptr->size * ptr->elem_size);
    memcpy(dst, value, ptr->elem_size);
    ptr->size++;
    return true;
}

//Removes the last element by decreasing size (without reducing capacity)
bool vec_pop_back(vector* ptr) {
    if(ptr == NULL) {
        return false;
    }
    if(ptr->size > 0) {
        ptr->size--;
    }
    return true;
}

//Returns the current number of elements in the vector
size_t vec_size(vector* ptr) {
    return (ptr == NULL) ? 0 : ptr->size;
}

//Returns the maximum number of elements the vector can hold without reallocating
size_t vec_capacity(vector* ptr) {
    return (ptr == NULL) ? 0 : ptr->capacity;
}

//Ensures the vector has at least newCapacity capacity without changing its size 
bool vec_reserve(vector* ptr, size_t newCapacity) {
    if(ptr == NULL) {
        return false;
    }

    if(!vec_ensure_capacity(ptr, newCapacity)) {
        return false;
    }
    return true;
}

//Changes the vector's size, truncating or zero-extending and reallocating if necessary
bool vec_resize(vector* ptr, size_t newSize) {
    if(ptr == NULL || ptr->size == newSize) return false;

    if(newSize > ptr->size) {
        if(!vec_ensure_capacity(ptr, newSize)) {
            return false;
        }
    }

    ptr->size = newSize;
    return true;
}

//Remove all elements by setting size to 0 (without freeing memory)
void vec_clear(vector* ptr) {
    if(ptr == NULL) {
        return;
    }

    ptr->size = 0;
}

//Returns true if the vector contains no element (size == 0)
bool vec_is_empty(vector* ptr) {
    if(ptr == NULL) {
        return true;
    }

    return (ptr->size == 0) ? true : false;
}

//Reduces the vector's capacity to match its current size (or 2 if empty)
bool vec_shrink_to_fit(vector* ptr) {
    if(!ptr) return false;

    size_t newCapacity = (ptr->size == 0) ? 2 : ptr->size;

    void* tmp = realloc(ptr->data, newCapacity * ptr->elem_size);

    if(!tmp) return false;

    ptr->data = tmp;
    ptr->capacity = newCapacity;
    return true;
}

//Frees all memory allocated by the vector and the structure itself
void vec_free(vector* ptr){
    if(ptr == NULL) {
        return;
    }

    free(ptr->data);
    ptr->data = NULL;

    ptr->capacity = 0;
    ptr->size = 0;
    ptr->elem_size = 0;

    free(ptr);
}

//Returns a direct pointer to the element at the given index (without copying)
void* vec_get_ptr(vector* ptr, size_t index) {
    if (ptr == NULL || index >= ptr->size) {
        return NULL;  
    }
    return (char*)ptr->data + (index * ptr->elem_size);
}

//Copies the element at the given index into the variable pointed to by var
bool vec_get_var(vector* ptr, size_t index, void* var) {
    if (ptr == NULL || var == NULL || index >= ptr->size) {
        return false;  
    }
    void *src = (char*)ptr->data + (index * ptr->elem_size);
    memcpy(var, src, ptr->elem_size);
    return true;
}

//Shows the element at the given index
void vec_show(vector* ptr, size_t index) {
    unsigned char* bytes = (unsigned char*)ptr->data + (index * ptr->elem_size);
    size_t Sum = 0;

    for(size_t i = 0; i < ptr->elem_size; i++) {
        Sum += bytes[i];
    }
    printf("%zu\n", Sum);
}

//Copies an element at the givin index, shifting subsequent elements to the right
bool vec_insert(vector* ptr, size_t index, void *value)
{
    if(!ptr || !value || index > ptr->size) return false;

    if(!vec_ensure_capacity(ptr, ptr->size + 1)) {
        return false;
    }

    if(index < ptr->size) {
        void *dst = (char*)ptr->data + ((index + 1) * ptr->elem_size);
        void *src = (char*)ptr->data + (index * ptr->elem_size);

        memmove(dst, src, (ptr->size - index) * ptr->elem_size);
    }

    memcpy((char*)ptr->data + (index * ptr->elem_size),
           value,
           ptr->elem_size);

    ptr->size++;
    return true;
}

//Removes the element at the given index, shifting subsequent elements to the left
void vec_erase(vector* ptr, size_t index) {
    if(ptr == NULL || index >= ptr->size || ptr->size == 0) {
        return;
    }
    if(index < ptr->size - 1) {
        void* dst = (char*)ptr->data + (index * ptr->elem_size);
        void* src = (char*)ptr->data + ((index + 1) * ptr->elem_size);

        memmove(dst, src, (ptr->size - index - 1) * ptr->elem_size);
    }
    ptr->size--;
}

//Returns a pointer to the first element of the vector (or NULL if empty)
void* vec_begin(vector* ptr) {
    if(ptr == NULL) {
        return NULL;
    }
    return ptr->data;
}

//Returns a pointer to the position one past the last element (useful for iteration)
void* vec_end(vector* ptr) {
    if(ptr == NULL) {
        return NULL;
    }
    return (char*)ptr->data + (ptr->size * ptr->elem_size);
}