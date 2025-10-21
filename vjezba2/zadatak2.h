#ifndef VCT
#define VCT

struct vctr {
	int* el;
	size_t logVel;
	size_t fizVel;
};

vctr* vector_new(size_t in = 10);

size_t vector_size(const vctr* v);

int vector_front(const vctr* v);

int vector_back(const vctr* v);

void vector_delete(vctr* v);

void vector_push_back(vctr* v, int vr);

void vector_pop_back(vctr* v);


#endif
