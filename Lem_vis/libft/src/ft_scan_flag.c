/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:35:24 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:58:04 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_scan_flag(const char *format, int cursor)
{
	if (format[cursor - 1] == 'h' && format[cursor - 2] == 'h')
		return ('H');
	else if (format[cursor - 1] == 'h')
		return ('h');
	else if (format[cursor - 1] == 'l' && format[cursor - 2] == 'l')
		return ('L');
	else if (format[cursor - 1] == 'l')
		return ('l');
	else if (format[cursor - 1] == 'L')
		return ('I');
	else
		return (0);
}
