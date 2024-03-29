/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:02:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/22 19:40:45 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int			check_lista_order(t_data **pil, t_data **last)
{
	t_data		*pilea;
	int			i;

	i = 0;
	pilea = *pil;
	while (pilea && pilea->next)
	{
		if (pilea->nb < pilea->next->nb)
			pilea = pilea->next;
		else
		{
			i++;
			pilea = pilea->next;
		}
	}
//	ft_putnbr(pilea->nb);
	*last = pilea;
	if (i)
		return (1);
	return (0);
}

int			check_listb_order(t_data **pil, t_data **last)
{
	t_data		*pilea;
	int			i;

	i = 0;
	pilea = *pil;
	while (pilea && pilea->next)
	{
		if (pilea->nb > pilea->next->nb)
			pilea = pilea->next;
		else
		{
			i++;
			pilea = pilea->next;
		}
	}
	*last = pilea;
	if (i)
		return (1);
	return (0);
}

void		move_pilea(t_data **pilea, t_data **pileb, t_data *last, t_data *last_b)
{
	int		r_a;

	r_a = check_lista_order(pilea, &last);
	check_listb_order(pileb, &last_b);

	if ((*pilea)->nb > last->nb && last->nb < (*pilea)->next->nb)
		do_rra(pilea);
	else if ((*pilea)->nb > (*pilea)->next->nb && (*pilea)->nb > last->nb)
		do_ra(pilea);
	else if ((*pilea)->nb > (*pilea)->next->nb && (*pilea)->next->next && (*pilea)->nb < (*pilea)->next->next->nb)
		do_sa(*pilea);
	else if ((*pilea)->nb > last->nb && (*pilea)->nb < (*pilea)->next->nb)
		do_rra(pilea);
	else if ((*pilea)->nb < last->nb && last->nb < (*pilea)->next->nb)
	{
		do_rra(pilea);
		do_sa(*pilea);
	}
	else if (r_a && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < last->nb)
		do_pb(pilea, pileb);
	else if ((*pilea) && (**pilea).next && (**pilea).next->next && (**pilea).nb > (*pilea)->next->nb && (*pilea)->next->nb < (*pilea)->next->next->nb)
		do_sa(*pilea);
	else if (last_b && *pileb && (*pileb)->next && (*pilea)->nb < last_b->nb
				&& (*pilea)->nb < (*pilea)->next->nb
				&& (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < (*pileb)->next->nb)
	{
		do_pb(pilea, pileb);
		do_rrb(pileb);
	}
	else if (*pilea && (*pilea)->next && *pileb && (*pileb)->next && (*pilea)->nb > (*pilea)->next->nb && (*pilea)->nb > (*pileb)->nb && (*pilea)->nb && (*pilea)->nb > (*pileb)->next->nb)
		do_pb(pilea, pileb);
	else if (last_b && *pileb && last_b->nb < (*pilea)->nb && last_b->nb < (*pileb)->nb && (*pilea)->nb > (*pileb)->nb)
	{
		do_rrb(pileb);
		do_pa(pilea, pileb);
	}
	else if (last_b && *pileb && (*pilea)->next->nb < last_b->nb && (*pilea)->next->nb < (*pilea)->nb && (*pilea)->next->nb < (*pileb)->nb)
	{
		do_sa(*pilea);
		do_pb(pilea, pileb);
		do_rb(pileb);
	}
}

void		move_pileb(t_data **pilea, t_data **pileb, t_data *lasta, t_data *last_b)
{
	int		ra;

	ra = check_lista_order(pilea, &lasta);
	check_listb_order(pileb, &last_b);

	if ((*pilea)->next && (*pileb) && (*pileb)->next && (*pilea)->nb > (*pilea)->next->nb && (*pilea)->nb < (*pileb)->nb && (*pileb)->nb > (*pileb)->next->nb)
	{
		do_rb(pileb);
		while ((*pilea)->nb < (*pileb)->nb)
			do_pb(pilea, pileb);
	}
	else if (*pilea && (*pileb)->nb > lasta->nb && (*pileb)->nb > (*pilea)->nb)
	{
		do_pa(pilea, pileb);
		do_ra(pilea);
	}
	else if (last_b && last_b->nb > (*pileb)->nb)
		do_rb(pileb);
	else if ((*pileb)->nb < (*pileb)->next->nb)
		do_sb(*pileb);
	else if ((*pileb)->nb > last_b->nb && (*pileb)->nb > (*pileb)->next->nb && (*pileb)->nb < (*pilea)->nb && (*pileb)->nb > lasta->nb)
		do_pa(pilea, pileb);
	else if ((*pilea) && (*pilea)->next && (*pilea)->next->next && (*pileb)->nb > (*pilea)->next->nb && (*pileb)->nb > (*pilea)->nb && (*pileb)->nb < (*pilea)->next->next->nb)
	{
		do_rra(pilea);
		do_rra(pilea);
		do_pa(pilea, pileb);
		do_ra(pilea);
		do_ra(pilea);
	}
	else if ((*pileb)->nb > (*pilea)->nb && (*pileb)->nb < (*pilea)->next->nb && (*pileb)->nb < lasta->nb && (*pileb)->nb > (*pileb)->next->nb && (*pileb)->nb > lasta->nb)
	{
		do_pa(pilea, pileb);
		do_sa(*pilea);
	}
	else if ((*pilea) && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < lasta->nb && (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < last_b->nb && (*pilea)->nb < (*pileb)->next->nb)
	{
		do_rrb(pileb);
		do_pb(pilea, pileb);
		do_rb(pileb);
		do_rb(pileb);
	}
	else if (ra && (*pilea) && (*pilea)->next && (*pileb) && (*pileb)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < lasta->nb && (*pilea)->nb > last_b->nb && (*pileb)->next->nb > (*pilea)->nb)
	{
		do_pb(pilea, pileb);
		if ((*pileb)->next)
			do_sb(*pileb);
		if ((*pilea) && (*pilea)->next && (*pileb)->nb < (*pilea)->nb && (*pileb)->nb < (*pilea)->next->nb && (*pileb)->nb > (*pileb)->next->nb)
			do_pa(pilea, pileb);
	}
	else if (!ra && *pilea && *pileb && (*pilea)->next && (*pileb)->next && (*pilea)->nb < (*pileb)->nb && (*pileb)->nb < (*pilea)->next->nb && (*pileb)->nb > (*pileb)->next->nb && (*pilea)->nb < lasta->nb)
	{
		lasta = (*pilea);
		do_ra(pilea);
		do_pa(pilea, pileb);
		while (*pileb && (*pileb)->nb < (*pilea)->nb)
		{
			do_pa(pilea, pileb);
			if ((*pileb)->nb < lasta->nb && (*pilea)->nb > lasta->nb)
			{
				do_rra(pilea);
				check_lista_order(pilea, &lasta);
			}
		}
		if ((*pilea)->nb > lasta->nb)
			do_rra(pilea);
		check_lista_order(pilea, &lasta);
	}
	else if (!ra && *pilea && *pileb && (*pilea)->next && (*pileb)->next && (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < lasta->nb)
	{
		while ((*pilea)->nb < (*pileb)->nb)
		{
			do_ra(pilea);
			if ((*pilea)->next && (*pilea)->nb > (*pilea)->next->nb)
				do_sa(*pilea);
			if ((*pilea)->nb > (*pileb)->nb && (*pilea)->nb <(*pilea)->next->nb)
				do_pa(pilea, pileb);
		}
	}

	else if (*pileb && (*pileb)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < lasta->nb && (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < (*pileb)->next->nb)
	{
		do_ra(pilea);
		while ((*pilea)->nb > (*pileb)->nb)
			do_pa(pilea, pileb);
		do_rra(pilea);
	}
}

void		move_both(t_data **pilea, t_data **pileb, t_data *last, t_data *last_b)
{
	if (last_b && last_b->nb > (*pileb)->nb && (*pilea)->nb > (*pilea)->next->nb && (*pilea)->nb > last->nb)
	do_rr(pilea, pileb);
	if ((*pilea)->nb > last->nb && last->nb < (*pilea)->next->nb && (*pileb)->nb > last_b->nb && (*pileb)->next->nb < last_b->nb)
		do_rrr(pilea, pileb);
	if ((*pileb)->nb < (*pileb)->next->nb && (*pilea)->nb > (*pilea)->next->nb && (*pilea)->next->nb < (*pilea)->next->next->nb)
	do_ss(*pilea, *pileb);
}

int			move_nb(t_data **pilea, t_data **pileb, t_data *last, t_data *last_b)
{
	int				ret_pila;
	int				ret_pilb;

	/*	t_data	*tmp = (*pilea);
	t_data	*tmp2 = (*pileb);
	ft_putstr("\nA   B\n");
	while (tmp || tmp2)
	{
		if (tmp)
		{
			ft_putnbr(tmp->nb);
			tmp = tmp->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (tmp2)
		{
			ft_putnbr(tmp2->nb);
			tmp2 = tmp2->next;
		}
		ft_putchar('\n');
	}
	*/


	ret_pila = -1;
	ret_pilb = -1;
	if (*pilea)
		ret_pila = check_lista_order(pilea, &last);
	if (*pileb)
		ret_pilb = check_listb_order(pileb, &last_b);
	if (!ret_pila && ret_pilb == -1)
	{
		free(*pileb);
		return (1);
	}
	if ((*pilea)->next && (*pilea)->nb > (*pilea)->next->nb)
		do_sa(*pilea);
	else if (*pileb && !ret_pila && !ret_pilb)
		do_pa(pilea, pileb);
	else if (*pilea && (*pilea)->next && *pileb && (*pileb)->next && ((*pilea)->nb > (*pilea)->next->nb && (*pileb)->nb < (*pileb)->next->nb))
		do_ss(*pilea, *pileb);
	if (ret_pila == 1 && ret_pilb == 1 && *pilea && *pileb)
		move_both(pilea, pileb, last, last_b);
	if (ret_pilb == 1 && *pileb && (*pileb)->next)
		move_pileb(pilea, pileb, last, last_b);
	if (!ret_pila && (*pileb) && (*pilea) && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < (*pilea)->next->nb && (*pileb)->nb > last_b->nb && (*pileb)->nb > (*pileb)->next->nb && (*pileb)->nb < (*pilea)->nb && (*pileb)->nb < last->nb)
		do_pa(pilea, pileb);
	if (ret_pila == 1 && *pilea && (*pilea)->next)
		move_pilea(pilea, pileb, last, last_b);
	else if (*pilea && *pileb && last && (*pileb)->next && (*pilea)->nb < (*pileb)->nb && (*pilea)->nb < last->nb && (*pilea)->nb > (*pileb)->next->nb)
	{
		do_pb(pilea, pileb);
		do_sb(*pileb);
	}
	if (!ret_pila && !ret_pilb && (*pileb))
		do_pa(pilea, pileb);
	return (0);
}

void		push_swap(t_data *pilea, t_data *pileb)
{
	t_data		*last;
	t_data		*lastb;
	int			mv_ret;

	last = NULL;
	lastb = NULL;
	mv_ret = 0;
	while (!mv_ret)
		mv_ret = move_nb(&pilea, &pileb, last, lastb);
}
