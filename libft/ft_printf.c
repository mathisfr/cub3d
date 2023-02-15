/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:10 by lloison           #+#    #+#             */
/*   Updated: 2023/01/17 10:07:36 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list			args;
	t_sstring		*string;
	size_t			return_value;

	va_start(args, s);
	string = generate_string(s, args);
	va_end(args);
	if (string == 0)
		return (-1);
	if (string->text == 0 || write(1, string->text, string->length) == -1)
	{
		free_sstring(&string);
		return (-1);
	}
	return_value = string->length;
	free_sstring(&string);
	return (return_value);
}

int	ft_printf_error(const char *s, ...)
{
	va_list			args;
	t_sstring		*string;
	size_t			return_value;

	va_start(args, s);
	string = generate_string(s, args);
	va_end(args);
	if (string == 0)
		return (-1);
	if (string->text == 0 || write(2, string->text, string->length) == -1)
	{
		free_sstring(&string);
		return (-1);
	}
	return_value = string->length;
	free_sstring(&string);
	return (return_value);
}

char	*generate_fstring(const char *s, ...)
{
	va_list			args;
	t_sstring		*string;
	char			*output;

	va_start(args, s);
	string = generate_string(s, args);
	va_end(args);
	if (string == 0)
		return (0);
	output = string->text;
	free(string);
	return (output);
}

/*#include <stdio.h>

#define TEST ">------------<%4.16d>------------<"
#define VALUE 0

void debug(int test_number, char *text, int value)
{
	printf("===========TEST %02d==========================\n", test_number);
	printf("TEXTE : %s | VALEUR %d\n", text, value);
	printf("  %d\n", ft_printf(text, value));
	printf("--------------------------------------------------------\n");
	printf("  %d\n", printf(text, value));
	printf("===========END OF TEST %02d ==================\n\n\n", test_number);
}
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_printf("\n %    4t");
	printf("\n %     4t");
	//debug(1, "\n", 0);
}
*/