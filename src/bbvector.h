#ifndef BURNINGBACON_VECTOR_H
#define BURNINGBACON_VECTOR_H

#include <stdbool.h>

typedef struct vector
{
	unsigned int capacity;
	unsigned int length;
	// the size of each piece of data
	unsigned int chunk_size;
	void* data;
} vector;

// functions dealing with memory management
extern void* vector_init(vector* const, const unsigned int);
extern void vector_free(vector* const);
extern void vector_setCap(vector* const, unsigned int);
extern void vector_setCapExact(vector* const, unsigned int);

// functions dealing with data management

/**
  * copies the new data to the end of the array
  * vec: the vector to be added to
  * data: the addresses of the data to be added
  * length: sizeof(*data)
  **/
extern void vector_add(vector* const, const void* const);

extern bool vector_remove(vector* const, const unsigned int);
extern void* vector_insert(vector* const, const void* const, const unsigned int);
extern void* vector_get(const vector* const, const unsigned int);

#endif // BURNINGBACON_VECTOR_H