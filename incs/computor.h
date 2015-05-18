/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 17:44:16 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:44:29 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct		s_terme
{
	double				a;
	char				*b;
	struct s_terme		*next;
}					t_terme;

typedef struct		s_parts
{
	t_terme				*b_e;
	t_terme				*a_e;
}					t_parts;

/*
** PARSER
*/
t_parts				*parser_controller(char *input);
char				**parser_make_parts(char *input);
int					parser_count_parts(char *input);
char				*parser_next_part(char *input);
int					parser_is_part(char c);
int					parser_checker(char **tab, char *available);
int					check_unknown(char p);
int					check_exponent(char p, char s);
int					check_other(char c, char p, char s);
int					check_nbr(char *part);
t_terme				*parser_make_termes(char **parts);
int					signe_produit(char *part);
t_terme				*parser_terme_one(t_terme *terme, char *part);
t_terme				*parser_terme_two(t_terme *terme, char *part);
t_terme				*parser_sort_termes(t_terme *lst);
float				parser_sort_get(char *str);
t_terme				*terme_init(void);
t_parts				*parts_init(void);
void				parts_del(t_parts **parts);
void				terme_delone(t_terme **terme);
void				terme_delall(t_terme **terme);

/*
** FORMS
*/
t_parts				*reduced_controller(t_parts *parts);
t_terme				*find_same_terme(t_terme *lst, t_terme *elem);
t_terme				*termes_to_opposite(t_terme *lst);
int					termequ(char *a, char *b);
void				reduced_put(t_parts *parts);
float				polynomial_controller(t_terme *termes);
char				*polynomial_name(float nb);
void				polynomial_put(float nb);

/*
** SOLVER
*/
int					solver_deg2(t_terme *lst);
void				solver_deg2_szero(double a, double b, double delta);
void				solver_deg2_izero(double a, double b, double delta);
void				solver_deg2_ezero(double a, double b);
int					solver_deg1(t_terme *lst);
int					solver_deg0(t_terme *lst);

/*
** MATH
*/
double				ft_pow(double base, double exponent);
double				ft_sqrt(double x);

/*
** OPERATIONS
*/
int					operation_add(t_terme **a, t_terme **b);

/*
** OTHER
*/
t_terme				*terme_pop(t_terme *lst, t_terme *elem);
t_terme				*termes_clear(t_terme *lst);
t_terme				*terme_swap(t_terme *lst, t_terme *elem);
int					termes_count(t_terme *lst);

/*
**MAIN
*/
int					solver_launcher(t_terme *lst, int poly_nb);
void				put_part(t_terme *termes);

#endif
