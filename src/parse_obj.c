/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/13 15:57:03 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void str_to_vec(t_vec *vec, char *str)
{
	vec->i  = atof(strtok(str, ","));
	vec->j  = atof(strtok(NULL, ","));
	vec->k  = atof(strtok(NULL, ","));
}

static void	str_to_color(t_color *color, char *str)
{
	color->t = 0;
	color->r = atof(strtok(str, ","));
	color->g = atof(strtok(NULL, ","));
	color->b = atof(strtok(NULL, ","));
}

void	parse_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane	*pl;

	obj = (t_obj *)malloc(sizeof(t_obj));
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !pl)
	{
		free(obj);
		free(pl);
		return ;
	}
	str_to_vec(&pl->center, strv[1]);
	str_to_vec(&pl->normal, strv[2]);
	obj->type = TYPE_PL;
	obj->info = pl;
	str_to_color(&obj->color, strv[3]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_sphere	*sp;

	obj = (t_obj *)malloc(sizeof(t_obj));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !sp)
	{
		free(obj);
		free(sp);
		return ;
	}
	str_to_vec(&sp->center, strv[1]);
	sp->diameter = atof(strv[2]);
	sp->radius = sp->diameter / 2;
	obj->type = TYPE_SP;
	obj->info = sp;
	str_to_color(&obj->color, strv[3]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_cylinder	*cy;

	obj = (t_obj *)malloc(sizeof(t_obj));
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !cy)
	{
		free(obj);
		free(cy);
		return ;
	}
	str_to_vec(&cy->center, strv[1]);
	str_to_vec(&cy->normal, strv[2]);
	cy->height = atof(strv[3]);
	cy->diameter = atof(strv[4]);
	cy->radius = cy->diameter / 2;
	obj->type = TYPE_CY;
	obj->info = cy;
	str_to_color(&obj->color, strv[5]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}
