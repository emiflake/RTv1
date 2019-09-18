#include "vec3_math.h"

/*
    add
    sub
    dot
    cross
    magnitude
*/

t_vec3  vec3_add(const t_vec3 *a, const t_vec3 *b)
{
    return ((t_vec3){a->x + b->x, a->y + b->y, a->z + b->z});
}

t_vec3  vec3_sub(const t_vec3 *a, const t_vec3 *b)
{
    return ((t_vec3){a->x - b->x, a->y - b->y, a->z - b->z});
}

double  vec3_dot(const t_vec3 *a, const t_vec3 *b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3  vec3_cross(const t_vec3 *a, const t_vec3 *b)
{
    return ((t_vec3){a->y * b->z - a->z * b->y,\
    a->z * b->x - b->z * a->x, a->x * b->y - b->x * a->y});
}

double vec3_magni(const t_vec3 *a)
{
    return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

