/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_helper_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:05:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:05:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

size_t	count_lines(char *str)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	alloc_and_cpy_line(char **result, t_splt_ctx *ctx, size_t len)
{
	result[ctx->j] = ft_calloc(len + 1, sizeof(char));
	if (!result[ctx->j])
	{
		free_splits(result);
		return (0);
	}
	ft_strlcpy(result[ctx->j], ctx->start, len + 1);
	return (1);
}

char	**split_lines_init(size_t count)
{
	char	**result;

	result = allocate_result(count);
	if (!result)
		return (NULL);
	return (result);
}

char	**split_lines_process(char **result, t_splt_ctx *ctx)
{
	size_t	len;

	if (ctx->str[ctx->i] == '\n' || ctx->str[ctx->i] == '\0')
	{
		len = &ctx->str[ctx->i] - ctx->start;
		if (!alloc_and_cpy_line(result, ctx, len))
			return (NULL);
		ctx->start = &ctx->str[ctx->i + 1];
		ctx->j++;
	}
	ctx->i++;
	return (result);
}

char	**split_lines(char *str, size_t count)
{
	char		**result;
	t_splt_ctx	ctx;

	result = split_lines_init(count);
	if (!result)
		return (NULL);
	ctx.str = str;
	ctx.count = count;
	ctx.i = 0;
	ctx.j = 0;
	ctx.start = str;
	while (ctx.i <= ft_strlen(str))
	{
		result = split_lines_process(result, &ctx);
		if (!result)
			return (NULL);
	}
	return (result);
}
