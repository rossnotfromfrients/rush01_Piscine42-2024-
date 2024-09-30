/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:18 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:26:26 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdlib.h>

# define N 4

typedef struct s_clues
{
	int	top[N];
	int	bottom[N];
	int	left[N];
	int	right[N];
}				t_clues;

void	int_to_str(int num, char *str);
void	print_row(int *row);
void	print_matrix(int grid[N][N]);
int		check_visibility(int *line, int expected_visible);
int		validate_side(int grid[N][N], t_clues clues, int row);
int		validate_column(int grid[N][N], t_clues clues, int col);
int		is_valid(int grid[N][N], t_clues clues);
int		is_safe(int grid[N][N], int row, int col, int num);
int		solve_recursive(int grid[N][N], t_clues clues, int row, int col);
void	initialize_grid_and_solve(t_clues clues);
int		*ft_extrval(char *str);
int		put_val(char *str, t_clues *clues);

#endif
