/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:11:40 by asobrinh          #+#    #+#             */
/*   Updated: 2025/03/29 19:11:49 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	write_error(const char *print)
{
	printf("Erro: %s\n", print);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	result;
	int		sign;
	int		digit;

	while (*str && isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((base == 0 || base == 16) && *str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		base = 16;
		str += 2;
	}
	else if (base == 0 && *str == '0')
		base = 8;
	else if (base == 0)
		base = 10;
	result = 0;
	while (*str)
	{
		digit = -1;
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'z')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'Z')
			digit = *str - 'A' + 10;
		if (digit == -1 || digit >= base)
			break;
		if (result > (2147483647 - digit) / base)
		{
			if (sign == 1)
				result = 2147483647;
			else
				result = -2147483648;
			break;
		}
		result = result * base + digit;
		str++;
	}
	if (endptr)
	{
		*endptr = (char *)str;
	}
	return (sign * result);
}
