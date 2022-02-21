#define DECL_VECTOR_STRUCT(Name, Type) \
    int SIZE; \
    int CAPACITY; \
    int data[CAPACITY];

#define DECL_VECTOR_INIT(Name, Type) \
    static inline void ##NAME_init(struct my_int_vector *vector){ \
        vector = DECL_VECTOR_STRUCT(vector, int) \
        vector->size = 0; \
        vector->capacity = 2; \
        vector->data[vector.capacity]; \
    }

#define DECL_VECTOR_FREE(Name, Type) \
    static inline void ##NAME_free(struct my_int_vector *vector) \
    { \
        free(vector); \
    }

#define DECL_VECTOR_SIZE(Name, Type) \
    static inline size_t ##NAME__size(const struct my_int_vector *vector)\
    { \
        return vector.size; \
    }

#define DECL_VECTOR_INSERT(Name, Type) \
    static inline bool ##NAME_insert(struct my_int_vector *vector, \
            size_t pos, int element);


