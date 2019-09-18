#include "vec3_math.h"

/*
rot_X
rot_y
rot_z
rot_xyz
*/

//!! the rotating factor nb is based on?
t_vec3  vec3_rotx(t_vec3 *a, double nb)
{
    return ((t_vec3){a->x, a->y * cos(nb) - a->z * sin(nb),\
    a->y * sin(nb) + a->z * cos(nb)});
}

t_vec3  vec3_roty(t_vec3 *a, double nb)
{
    return ((t_vec3){a->x * cos(nb) + a->z * sin(nb), a->y, \
    a->z * cos(nb) - a->x * sin(nb)});
}

t_vec3  vec_rotz(t_vec3 *a, double nb)
{
    return ((t_vec3){a->x * cos(nb) - a->y * sin(nb),\
    a->x * sin(nb) - a->y * cos(nb), a->z});
}

/*
!! for rotating first x, then y then z, use of original xyz values
or the new calculated ones.
t_vec3  vec3_rotxyz(t_vec3, double nb)
{

}
*/