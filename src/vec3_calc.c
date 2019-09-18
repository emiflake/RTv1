#include "vec3_math.h"

/*
scale
normalize
new
copy
multi
*/

// do norm, scale & multi make new vec or change at adress from given vector?
t_vec3  vec3_new(double x, double y, double z)
{
    t_vec3  a;

    a.x = x;
    a.y = y;
    a.z = z;
    return (a);
}

t_vec3  vec3_norm(const t_vec3 *a)
{
    double r;

    r = vec3_magni(a);
    return ((t_vec3){a->x / r, a->y / r, a->z / r});
}

t_vec3  vec3_copy(const t_vec3 * a)
{
    return((t_vec3){a->x, a->y, a->z});
}

t_vec3  vec3_scale(const t_vec3 *a, double nb)
{
    return ((t_vec3){a->x / nb, a->y / nb, a->z / nb});
}

t_vec3  vec3_multi(const t_vec3 *a, double mag)
{
    return ((t_vec3){a->x * mag, a->y * mag, a->z * mag});
}