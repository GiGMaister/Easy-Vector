#ifndef VECTOR_EASY_H
#define VECTOR_EASY_H

#include <stddef.h>   // size_t
#include <stdbool.h>  // bool

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} vector;

vector* vec_init(size_t elem_size);
void    vec_free(vector* ptr);

bool    vec_push_back(vector* ptr, void *value);
void    vec_pop_back(vector* ptr);

void*   vec_get_ptr(vector* ptr, size_t index);
bool    vec_get_var(vector* ptr, size_t index, void* var);
void    vec_show(vector* ptr, size_t index);

void*   vec_begin(vector* ptr);
void*   vec_end(vector* ptr);

size_t  vec_size(vector* ptr);
size_t  vec_capacity(vector* ptr);

bool    vec_reserve(vector* ptr, size_t newCapacity);
bool    vec_resize(vector* ptr, size_t newSize);
void    vec_clear(vector* ptr);
bool    vec_shrink_to_fit(vector* ptr);

bool    vec_is_empty(vector* ptr);

bool    vec_insert(vector* ptr, size_t index, void *value);
void    vec_erase(vector* ptr, size_t index);

#ifdef __cplusplus
}
#endif

#endif // VECTOR_EASY_H