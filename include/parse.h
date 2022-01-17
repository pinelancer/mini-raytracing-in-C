/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:44:44 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:50:35 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libftx.h"
# define FOCAL_LEN 1.0f
typedef enum e_type {
	TYPE_SP,
	TYPE_PL,
	TYPE_CY
}	t_type;

enum e_spec {
	SPEC_A,
	SPEC_C,
	SPEC_L,
	SPEC_PL,
	SPEC_SP,
	SPEC_CY,
	SPEC_NO
};

typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_light t_light;
typedef struct s_ambient t_ambient;
typedef struct s_obj t_obj;
typedef struct s_cam    t_cam;
typedef struct s_view   t_view;
typedef struct s_scene    t_scene;
typedef struct s_hit_record t_hit_record;
typedef struct s_data t_data;


struct s_sphere
{
	t_vec	center;
	double	diameter;
	double	radius;
};

struct s_plane
{
	t_vec	center;
	t_vec	normal;
};

struct s_cylinder
{
    t_vec   center;
    t_vec	normal;
    double	height;
    double	diameter;
    double	radius;
};

struct s_light
{
	t_vec	spot;
	double	ratio;
};

struct s_ambient
{
	double	ratio;
	t_color	color;
};

struct s_obj {
	t_type		type;
	void		*info;
	t_color		color;
	t_obj	*next;
};

struct s_cam {
	t_vec	origin;
	t_vec	dir;
	t_vec	up;
	double	fov;
	double	focal_len;
	t_vec	basis_i;
	t_vec	basis_j;
	t_vec	basis_k;
};

struct s_view {
	double	width;
	double	height;
	t_vec	**matrix;
};

struct s_scene {
	t_cam	cam;
	t_view	view;
};

typedef struct s_ray
{
	t_point	orig;	// 정점.시작점
	t_vec	dir;    // 방향 벡터(단위 벡터O)
} t_ray;

struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	double		tmin;
	double		tmax;
	double		t;
	int			front_face;
	t_color		color;
};

struct s_data {
	void			*mlx_ptr;
	t_win			win;
	t_img			img;
	t_scene			scene;
	t_obj			*first_obj;
	t_light			light;
	t_ambient		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

void	parse_ambient(t_data *data, char *strv[]);
void	parse_light(t_data *data, char *strv[]);
void	parse_camera(t_data *data, char *strv[]);

void	parse(int fd, t_data *data);
void	parse_plane(t_data *data, char *strv[]);
void	parse_sphere(t_data *data, char *strv[]);
void	parse_cylinder(t_data *data, char *strv[]);
void	add_object_front(t_obj **first_obj, t_obj *new);

int		ft_isfloatform(char *str);
int		ft_isvecform(char *str);
int		ft_iscolorform(char *str);
int		ft_isintform(char *str);

#endif
