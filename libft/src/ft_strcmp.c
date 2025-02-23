/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:04:12 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/23 09:33:25 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (-1);
	index = 0;
	while (s1[index] && s1[index] == s2[index])
		index++;
	return (s1[index] - s2[index]);
}
