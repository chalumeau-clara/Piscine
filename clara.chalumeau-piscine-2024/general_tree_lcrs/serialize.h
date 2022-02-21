#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "gtree.h"

int gtree_serialize(const char *filename, struct gtree *root);
struct gtree *gtree_deserialize(const char *filename);

#endif /* !SERIALIZE_H */
