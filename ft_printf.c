/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:29:53 by lde-taey          #+#    #+#             */
/*   Updated: 2024/01/31 14:35:32 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_scan(char sign, va_list list)
{
	if (sign == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (sign == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (sign == 'p')
		return (ft_putptr(va_arg(list, void *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (sign == 'u')
		return (ft_putuni(va_arg(list, unsigned int)));
	else if (sign == 'x')
		return (ft_puthexax(va_arg(list, unsigned int)));
	else if (sign == 'X')
		return (ft_puthexaxl(va_arg(list, unsigned int)));
	else if (sign == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *ipstring, ...)
{
	va_list	list;
	int		counter;
	int		i;

	va_start(list, ipstring);
	counter = 0;
	i = 0;
	if (!ipstring)
		return (-1);
	while (ipstring[i] != '\0')
	{
		if (ipstring[i] == '%')
		{
			counter += ft_scan(ipstring[i + 1], list);
			i++;
		}
		else
			counter += ft_putchar(ipstring[i]);
		i++;
	}
	va_end(list);
	return (counter);
}
/*
int	main(void)
{
	// simple tests
	int returnv_0;
	int	preturnv_0;
	
	printf("\n\n\n");
	printf("***SIMPLE FIRST TEST***\n\n");
	returnv_0 = ft_printf("cspdiuxX%%\n");
	preturnv_0 = printf("cspdiuxX%%\n");
	printf("My return value: %i\n", returnv_0);
	printf("Printf return value: %i\n\n", preturnv_0);
	
	// empty and null test
	int returnv_0x;
	int returnv_0xx;
	printf("\n\n\n");
	printf("***TEST FOR NULL AND EMPTY LINE***\n\n");
	returnv_0x = ft_printf(0);
	printf("My return value for null: %i\n", returnv_0x);
	returnv_0xx = ft_printf("");
	printf("My return value for empty line: %i\n\n", returnv_0xx);
	
	// tests for c
	char c = '5';
	int returnv;
	int	preturnv;
	// int returnv1;
	int returnv_;
	int	preturnv_;
	
	printf("\n\n\n");
	printf("***TESTS FOR %%c***\n\n");
	returnv = ft_printf("Character example: %c\n", c);
	preturnv = printf("Character example: %c\n", c);
	printf("My return value: %i\n", returnv);
	printf("Printf return value: %i\n\n", preturnv);
	// returnv1 = ft_printf("Wrong character example: %c\n");
	printf("My return value for wrong character example: %i\n\n", returnv);
	returnv_ = ft_printf("Long character example: %%%%%%%%%c\n", c);
	preturnv_ = printf("Long character example: %%%%%%%%%c\n", c);
	printf("My return value: %i\n", returnv_);
	printf("Printf return value: %i\n\n", preturnv_);
	
	// tests for s
	char *str = "This is a string";
	char *str2 = NULL;
	int returnv5;
	int	preturnv5;
	int returnv6;
	int	preturnv6;
	
	printf("\n\n\n");
	printf("***TESTS FOR %%s***\n\n");
	returnv5 = ft_printf("String example: %s\n", str);
	preturnv5 = printf("String example: %s\n", str);
	printf("My return value: %i\n", returnv5);
	printf("Printf return value: %i\n\n", preturnv5);
	returnv6 = ft_printf("String example: %s\n", str2);
	preturnv6 = printf("String example: %s\n", str2);
	printf("My return value: %i\n", returnv6);
	printf("Printf return value: %i\n\n", preturnv6);

	// tests for p
	void *ptr = &str;
	void *ptr2 = NULL;
	int returnv7;
	int	preturnv7;
	int returnv8;
	int	preturnv8;
	
	printf("\n\n\n");
	printf("***TESTS FOR %%p***\n\n");
	returnv7 = ft_printf("Pointer example: %p\n", ptr);
	preturnv7 = printf("Pointer example: %p\n", ptr);
	printf("My return value: %i\n", returnv7);
	printf("Printf return value: %i\n\n", preturnv7);
	returnv8 = ft_printf("Empty pointer example: %p\n", ptr2);
	preturnv8 = printf("Empty pointer example: %p\n", ptr2);
	printf("My return value: %i\n", returnv8);
	printf("Printf return value: %i\n\n", preturnv8);

	// tests for d
	int	i = -2147483648;
	int i1 = -25895;
	int i2 = 0;
	int returnv9;
	int preturnv9;
	int returnv10;
	int preturnv10;
	int	returnv11;
	int preturnv11;

	printf("\n\n\n");
	printf("***TESTS FOR %%d***\n\n");
	returnv9 = ft_printf("Digit example: %d\n", i);
	preturnv9 = printf("Digit example: %d\n", i);
	printf("Return value: %d\n", returnv9);
	printf("Printf return value: %d\n\n", preturnv9);
	returnv10 = ft_printf("Digit example: %d\n", i1);
	preturnv10 = printf("Digit example: %d\n", i1);
	printf("Return value: %d\n", returnv10);
	printf("Printf return value: %d\n\n", preturnv10);
	returnv11 = ft_printf("Digit example: %d\n", i2);
	preturnv11 = printf("Digit example: %d\n", i2);
	printf("Return value: %d\n", returnv11);
	printf("Printf return value: %d\n\n", preturnv11);

	// tests for i
	int	i3 = -2147483648;
	int i4 = -25895;
	int i5 = 0;
	int returnv12;
	int preturnv12;
	int returnv13;
	int preturnv13;
	int	returnv14;
	int preturnv14;

	printf("\n\n\n");
	printf("***TESTS FOR %%i***\n\n");
	returnv12 = ft_printf("Digit example: %i\n", i3);
	preturnv12 = printf("Digit example: %i\n", i3);
	printf("Return value: %i\n", returnv12);
	printf("Printf return value: %i\n\n", preturnv12);
	returnv13 = ft_printf("Digit example: %i\n", i4);
	preturnv13 = printf("Digit example: %i\n", i4);
	printf("Return value: %i\n", returnv13);
	printf("Printf return value: %i\n\n", preturnv13);
	returnv14 = ft_printf("Digit example: %i\n", i5);
	preturnv14 = printf("Digit example: %i\n", i5);
	printf("Return value: %i\n", returnv14);
	printf("Printf return value: %i\n\n", preturnv14);

	// tests for u
	unsigned int i6 = 2147483648;
	unsigned int i7 = 0;
	int returnv14a;
	int preturnv14a;
	int returnv15;
	int preturnv15;

	printf("\n\n\n");
	printf("***TESTS FOR %%u***\n\n");
	returnv14a = ft_printf("Unsigned int example: %u\n", i6);
	preturnv14a = printf("Unsigned int example: %u\n", i6);
	printf("Return value: %u\n", returnv14a);
	printf("Printf return value: %u\n\n", preturnv14a);
	returnv15 = ft_printf("Unsigned int example: %u\n", i7);
	preturnv15 = printf("Unsigned int example: %u\n", i7);
	printf("Return value: %i\n", returnv15);
	printf("Printf return value: %i\n\n", preturnv15);

	// tests for x
	unsigned int i8 = 2147483648;
	unsigned int i9 = 0;
	int returnv16;
	int preturnv16;
	int returnv17;
	int preturnv17;

	printf("\n\n\n");
	printf("***TESTS FOR %%x***\n\n");
	returnv16 = ft_printf("Hexadecimal example: %x\n", i8);
	preturnv16 = printf("Hexadecimal example: %x\n", i8);
	printf("Return value: %i\n", returnv16);
	printf("Printf return value: %i\n\n", preturnv16);
	returnv17 = ft_printf("Hexadecimal example: %x\n", i9);
	preturnv17 = printf("Hexadecimal example: %x\n", i9);
	printf("Return value: %i\n", returnv17);
	printf("Printf return value: %i\n\n", preturnv17);

	// tests for X
	unsigned int i10 = 2147483648;
	unsigned int i11 = 0;
	int returnv18;
	int preturnv18;
	int returnv19;
	int preturnv19;

	printf("\n\n\n");
	printf("***TESTS FOR %%X***\n\n");
	returnv18 = ft_printf("Hexadecimal example: %X\n", i10);
	preturnv18 = printf("Hexadecimal example: %X\n", i10);
	printf("Return value: %i\n", returnv18);
	printf("Printf return value: %i\n\n", preturnv18);
	returnv19 = ft_printf("Hexadecimal example: %X\n", i11);
	preturnv19 = printf("Hexadecimal example: %X\n", i11);
	printf("Return value: %i\n", returnv19);
	printf("Printf return value: %i\n\n", preturnv19);

	// tests for %
	int returnv2;
	int	preturnv2;
	int returnv3;
	int	preturnv3;
	int	returnv4;
	
	printf("\n\n\n");
	printf("***TESTS FOR %%%%***\n\n");
	returnv2 = ft_printf("Percentage sign example: %%\n");
	preturnv2 = printf("Percentage sign example: %%\n");
	printf("My return value: %i\n", returnv2);
	printf("Printf return value: %i\n\n", preturnv2);
	returnv3 = ft_printf("Long percentage sign example: %%%%%%%%%%\n");	
	preturnv3 = printf("Long percentage sign example: %%%%%%%%%%\n");
	printf("My return value: %i\n", returnv3);
	printf("Printf return value: %i\n\n", preturnv3);
	returnv4 = ft_printf("Wrong percentage sign example: %, \
	and the list goes on\n");
	printf("My return value: %i\n", returnv4);

	// tests with different conversions
	int returnv20;
	int preturnv20;

	printf("\n\n\n");
	printf("***TESTS FOR DIFFERENT CONVERSIONS***\n\n");
	returnv20 = ft_printf("Mixed example: %c, %s, %p, %d, %i, %u, \
	%x, %X, %% and so on \n", c, str2, ptr2, i, i, i6, i6, i6);
	preturnv20 = printf("Mixed example: %c, %s, %p, %d, %i, %u, \
	%x, %X, %% and so on \n", c, str2, ptr2, i, i, i6, i6, i6);
	printf("My return value: %i\n", returnv20);
	printf("Printf return value: %i\n\n", preturnv20);
	
	// test for random arguments
	// int returnv21;
	// int preturnv21;
//
	// printf("\n\n\n");
	// printf("***TESTS FOR RANDOM ARGUMENTS***\n\n");
	// returnv21 = ft_printf("No arguments in this string", i10);
	// preturnv21 = printf("No arguments in this string", i10);
	// printf("My return value: %i\n", returnv21);
	// printf("Printf return value: %i\n\n", preturnv21);
	//
	return (0);
}
*/