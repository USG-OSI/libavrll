#ifndef DEFS_H
#define DEFS_H


#include "types.h"
#include <stdbool.h>

#define PACKED __attribute__((packed))

#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define ABS(x)     (((x) > 0) ? (x) : (-x))


#endif /* DEFS_H */
