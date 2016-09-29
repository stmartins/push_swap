/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/29 17:13:45 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(t_data *pilea)
{
	if (pilea && pilea->next)
		ft_swap(&pilea->nb, &pilea->next->nb);
	ft_putendl("sa");
}

void		do_sb(t_data *pileb)
{
	if (pileb && pileb->next)
		ft_swap(&pileb->nb, &pileb->next->nb);
	ft_putendl("sb");
}

void		do_ss(t_data *pilea, t_data *pileb)
{
	do_sa(pilea);
	do_sb(pileb);
	ft_putendl("ss");
}

void		do_pb(t_data **pilea, t_data **pileb)
{
	t_data		*newelem;
	t_data		*tmp;

	tmp = *pileb;
	newelem = NULL;
	if (!*pileb && *pilea)
	{
		newelem = list_newnode((*pilea)->nb);
		*pileb = newelem;
		*pilea = (*pilea)->next;
	}
	else if (*pilea && *pileb)
	{
		newelem = list_newnode((*pilea)->nb);
		newelem->next = tmp;
		*pileb = newelem;
		*pilea = (*pilea)->next;
	}
	else
		ft_putendl("pile a vide, rien n a ete fait");
	ft_putendl("pb");
}

void		do_pa(t_data **pilea, t_data **pileb)
{
	t_data		*newelem;
	t_data		*tmp;

	tmp = *pilea;
	newelem = NULL;
	if (!*pilea && *pileb)
	{
		newelem = list_newnode((*pileb)->nb);
		*pilea = newelem;
		*pileb = (*pileb)->next;
	}
	else if (*pilea && *pileb)
	{
		newelem = list_newnode((*pileb)->nb);
		newelem->next = tmp;
		*pilea = newelem;
		*pileb = (*pileb)->next;
	}
	else
		ft_putendl("pile b vide, rien n a ete fait");
	ft_putendl("pa");
}

void		do_ra(t_data **pilea)
{
	t_data		*newelem;

	if (*pilea)
	{
		newelem = list_newnode((*pilea)->nb);
		*pilea = (*pilea)->next;
		list_addend(newelem, pilea);
	}
	ft_putendl("ra");
}

void		do_rb(t_data **pileb)
{
	t_data		*newelem;

	if (*pileb)
	{
		newelem = list_newnode((*pileb)->nb);
		*pileb = (*pileb)->next;
		list_addend(newelem, pileb);
	}
	ft_putendl("rb");
}

void		do_rr(t_data **pilea, t_data **pileb)
{
	do_ra(pilea);
	do_rb(pileb);
	ft_putendl("rr");
}

void		do_rra(t_data **pilea)
{
	t_data		*last_node;
	t_data		*tmp;

	if (*pilea && (*pilea)->next && (*pilea)->next->next)
	{
		tmp = *pilea;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->next->next)
			{
				last_node = tmp->next;
				tmp->next = NULL;
			}
		}
		last_node->next = *pilea;
		*pilea = last_node;
	}
	else
		do_sa(*pilea);
	ft_putendl("rra");
}

void		do_rrb(t_data **pileb)
{
	t_data		*last_node;
	t_data		*tmp;

	if (*pileb && (*pileb)->next && (*pileb)->next->next)
	{
		tmp = *pileb;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->next->next)
			{
				last_node = tmp->next;
				tmp->next = NULL;
			}
		}
		last_node->next = *pileb;
		*pileb = last_node;
	}
	else
		do_sb(*pileb);
	ft_putendl("rrb");
}

void		do_rrr(t_data **pilea, t_data **pileb)
{
	do_rra(pilea);
	do_rrb(pileb);
	ft_putendl("rrr");
}
