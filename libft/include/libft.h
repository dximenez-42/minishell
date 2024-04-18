/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:54:00 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/18 16:14:53 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

// Most frecuently Bases
# define LOW_HEX "0123456789abcdef"
# define UPP_HEX "0123456789ABCDEF"
# define DEC "0123456789"
// Structs

typedef union u_content
{
	int			i;
	long		l;
	long long	ll;
	char		c;
	float		f;
	double		d;
	void		*ptr;
	char		*str;
	void		*oth;
}			t_content;

typedef enum e_type
{
	INT,
	LONG,
	LONG_LONG,
	CHAR,
	FLOAT,
	DOUBLE,
	PTR,
	STR,
	OTHER
}			t_type;

typedef struct s_list
{
	t_type				type;
	t_content			content;
	struct s_list		*next;
	struct s_list		*prev;
}				t_list;

typedef struct s_bufflist
{
	int					readrtn;
	char				buff[BUFFER_SIZE];
	struct s_bufflist	*next;
}				t_bufflist;

// Pseudooolean type Functions (is_x)
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isnumber(char *str, int sign);
int			ft_isinteger(char *str);
int			ft_isprint(int c);
int			ft_isspace(int c);
// Casting Functions
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_ltoa_base(long long lnbr, char *base);
char		*ft_ultoa_base(unsigned long lnbr, char *base);
// Cleaning Strings and Memory Functions
char		*ft_strtrim(char const *s1, char const *set);
// Char transformation Functions
int			ft_tolower(int c);
int			ft_toupper(int c);
// Copy, concat and split Fuctions
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
// Fuctions Pointers Functions
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
// Info Functions
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_numlen_base(long long lnbr, long long base_len);
size_t		ft_unumlen_base(unsigned long lnbr, unsigned long base_len);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// Inicialization Functions
void		*ft_bzero(void *b, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
//List Funcions
t_list		*ft_lstnew_type(t_type type, t_content content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstdup(t_list *lst, void (*del)(t_content, t_type));
void		ft_lstclear_type(t_list **lst, void (*del)(t_content, t_type));
void		ft_lstiter_type(t_list *lst, void (*f)(t_content, t_type));
void		ft_lstriter_type(t_list *lst, void (*f)(t_content, t_type));
t_list		*ft_lstmap_type(t_list *lst, t_type type,
				t_content (*f)(t_content, t_type),
				void (*del)(t_content, t_type));
t_list		*ft_lstrmap_type(t_list *lst, t_type type,
				t_content (*f)(t_content, t_type),
				void (*del)(t_content, t_type));
void		ft_lstdelone_type(t_list *lst, void (*del)(t_content, t_type));
t_list		*ft_lstfind(t_content content, t_type type, t_list *list);
t_list		*ft_lstrfind(t_content content, t_type type, t_list *list);
//Deprecated List Functions
t_list		*ft_lstnew(void *content);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
// Put_x_fd Functions
void		ft_putchar_fd(char c, int fd);
int			ft_putptr_fd(void *ptr, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putlnbr_base_fd(long long nbr, char *base, int fd);
int			ft_putulnbr_base_fd(unsigned long nbr, char *base, int fd);
// Search Char or String in Memory or Null terminated Strings Functions
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
// Added Functions
//  ft_printf
int			ft_printf(char const *format, ...);
int			ft_fdprintf(int fd, char const *format, ...);
//  get_next_line
char		*get_next_line(int fd);
t_bufflist	*newbuff(t_bufflist *list, int fd);
size_t		char_count_buff(t_bufflist *first);
char		*bufflist_to_str(t_bufflist *first);
void		*freebuff(t_bufflist **bufflist);
void		clearbuff(t_bufflist **bufflist);
char		*findnl(t_bufflist *arr);
// strarr functions
char		**ft_split(char const *s, char c);
size_t		strarr_len(char **strarr);
int			*strarr_to_intarr(char **sarr);
//  sort functions
int			issorted_int(int *numbers, size_t len);
void		bubblesort_int(int *numbers, size_t len);
// new memory functions
void		ft_free_ptr_array(void	*to_free);
void		*ft_memdup(const void *mem, size_t len);
#endif
