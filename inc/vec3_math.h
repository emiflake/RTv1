#ifndef VEC3_MATH_H
# define VEC3_MATH_H

# include <math.h>

typedef struct s_vec3
{
    double      x;
    double      y;
    double      z;
}               t_vec3;
//vec3_add
t_vec3  vec3_add(const t_vec3 *a, const t_vec3 *b);
t_vec3  vec3_sub(const t_vec3 *a, const t_vec3 *c);
double  vec3_dot(const t_vec3 *a, const t_vec3 *b);
t_vec3  vec3_cross(const t_vec3 *a, const t_vec3 *b);
double  vec3_magni(const t_vec3 *a);

//vec3_calc
t_vec3  vec3_new(double x, double y, double z);
t_vec3  vec3_norm(const t_vec3 *a);
t_vec3  vec3_copy(const t_vec3 * a);
t_vec3  vec3_scale(const t_vec3 *a, double nb);
t_vec3  vec3_multi(const t_vec3 *a, double mag);

//vec3_rot
t_vec3  vec3_rotx(t_vec3 *a, double nb);
t_vec3  vec3_roty(t_vec3 *a, double nb);
t_vec3  vec_rotz(t_vec3 *a, double nb);


#endif