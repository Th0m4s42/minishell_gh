/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:57:37 by thbasse           #+#    #+#             */
/*   Updated: 2024/01/25 14:28:15 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int			ft_isalpha(int character);
int			ft_isdigit(int character);
int			ft_isalnum(int character);
int			ft_isascii(int character);
int			ft_isprint(int character);
size_t		ft_strlen(const char *theString);
void		*ft_memset(void *dest, int value, size_t count);
void		ft_bzero(void *dest, size_t count);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int character);
int			ft_tolower(int character);
char		*ft_strchr(const char *string, int searchedChar);
char		*ft_strrchr(const char *string, int searchedChar);
int			ft_strncmp(const char *first, const char *second, size_t length);
void		*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int			ft_memcmp(const void *pointer1, const void *pointer2,
				size_t size);
char		*ft_strnstr(const char *bigStr, const char *littleStr,
				size_t length);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t elementCount, size_t elementSize);
char		*ft_strdup(const char *source);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
