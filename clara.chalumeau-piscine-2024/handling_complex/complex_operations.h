#ifndef COMPLEX_OPERATIONS_H
#define COMPLEX_OPERATIONS_H

#include "complex.h"

struct complex neg_complex(struct complex a);
struct complex add_complex(struct complex a, struct complex b);
struct complex sub_complex(struct complex a, struct complex b);
struct complex mul_complex(struct complex a, struct complex b);
struct complex div_complex(struct complex a, struct complex b);

#endif /* !COMPLEX_OPERATIONS_H */
