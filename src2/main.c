/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:58:14 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/20 18:17:33 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(t_data *pilea, t_data *pileb, long *nb)
{
	(void)pileb;
	if (check_double(pilea->lima, nb))
		return ;
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	*pilea;
	static t_data	*pileb;

	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(av, nb, &pilea)))
	{
		pilea->lima = ac - 1;
		call_fctn(pilea, pileb, nb);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
