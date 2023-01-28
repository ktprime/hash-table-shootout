#include <inttypes.h>
#include <string>
#include <nata.h>

#define __UNCONST(p) ((void *)((char*)NULL+((char*)p-(char*)NULL)))

#define SETUP_INT void *int_hash = NULL;
#define RESERVE_INT(size) \
	nina48reserve(&int_hash, (size));
#define INSERT_INT(key, value) \
	*nina48ins(&int_hash, key, NULL) = value;
#define DELETE_INT(key) \
	/* nina48del(&int_hash, key, NULL); */
#define FIND_INT_EXISTING(key) \
	if (nina48get(int_hash, key) == NULL) { \
		std::cerr << "error\n"; \
		exit(1); \
	}
#define FIND_INT_MISSING(key) \
	if (nina48get(int_hash, key) != NULL) { \
		std::cerr << "error\n"; \
		exit(1); \
	}
#define FIND_INT_EXISTING_COUNT(key, count) \
	if (nina48get(int_hash, key) != NULL) { \
		count++; \
	}
#define CHECK_INT_ITERATOR_VALUE(iterator, value)
#define ITERATE_INT(key) \
	/*
	uint64_t key = 0; \
	uint64_t *p_value = nina48first(int_hash, &key); \
	for (; p_value != NULL; p_value = nina48next(int_hash, &key)) */
#define LOAD_FACTOR_INT_HASH(int_hash) nina48lf(int_hash)
#define CLEAR_INT nina48free(&int_hash)

#include "template.cc"
