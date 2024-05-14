/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:54:00 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/14 12:44:38 by bvelasco         ###   ########.fr       */
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
/*
* Returns 1 if 'c' is in ascii table
* Returns 0 if not
*/
int			ft_isascii(int c);
/*
* Returns 1 if 'c' is the ascii value of an alphabetic character in ascii table
* Returns 0 if not
*/
int			ft_isalpha(int c);
/*
* Returns 1 if 'c' is the ascii value of a digit character in ascii table
* Returns 0 if not
*/
int			ft_isdigit(int c);
/*
* Returns 1 if 'c' if an alpha or a digit value in ascii table
* Returns 0 if not
*/
int			ft_isalnum(int c);
/*
* Returns 1 if 'c' if a printable value in ascii table
* Returns 0 if not
*/
int			ft_isprint(int c);
/*
* Returns 1 if 'c' if a space in ascii table (acording to isspace(3))
* Returns 0 if not
*/
int			ft_isspace(int c);
/*
* Returns 1 if the 'str' string is a sucession of digits with a sign (- or +) at start
* Returns 0 if not
*/
int			ft_isnumber(char *str);
/*
* Returns 1 if the 'str' string is a number and is in integer limits
*/
int			ft_isinteger(char *str);
// Casting Functions
/*convert a string to an integer (copy of atoi(3))*/
int			ft_atoi(const char *str);
/*converts an integer to a string (reverse operation of atoi)*/
char		*ft_itoa(int n);
/*itoa with custom bases*/
char		*ft_ltoa_base(long long lnbr, char *base);
/*itoa with unsigned char and custom bases*/
char		*ft_ultoa_base(unsigned long lnbr, char *base);
// Cleaning Strings and Memory Functions
/*removes all characters of "set" in the start and end of strign 's1'*/
char		*ft_strtrim(char const *s1, char const *set);
// Char transformation Functions
/*if 'c' is an uppercase (in ascii table) converts it to a lowercase*/
int			ft_tolower(int c);
/*if 'c' is a lowercase (in ascii table) converts it to an uppercase*/
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
/*
* creates a new node of t_list with type 'type' and content 'content'
* types are an enum of common types, other types may be calified as 'other'.
* content is an union of common primitive types and pointer for other types
*/
t_list		*ft_lstnew_type(t_type type, t_content content);
/*
* adds the node 'new' to the start of list that first node is pointed by 'lst'
*/
void		ft_lstadd_front(t_list **lst, t_list *new);
/*
* adds the nore 'new' to the end of list that first node is pointed by 'lst' 
*/
void		ft_lstadd_back(t_list **lst, t_list *new);
/*
* returns the number of nodes of list that first node is pointed by 'lst'
*/
int			ft_lstsize(t_list *lst);
/*
* returns the last node of list that first node is pointed by 'lst'
*/
t_list		*ft_lstlast(t_list *lst);
/*
* returns a copy of list of that first node is pointed by 'lst'
* if the copy fails, the already created nodes and his content
* the content of the nodes will be deleted with 'del'
*/
t_list		*ft_lstdup(t_list *lst, void (*del)(t_content, t_type));
/* 
* delete all list node and his contents (with 'del' function)
*/
void		ft_lstclear_type(t_list **lst, void (*del)(t_content, t_type));
/*
* executes 'f' in all nodes of list that first node is pointed by 'lst'
*/
void		ft_lstiter_type(t_list *lst, void (*f)(t_content, t_type));
/*
* executes 'f' in all nodes of list that last node is pointed by 'lst'
*/
void		ft_lstriter_type(t_list *lst, void (*f)(t_content, t_type));
/*
* executes 'f' in all nodes of the list that first node is pointed by 'lst'
* and returns a new list with the result.
* if fails delete already created nodes
* the content of the nodes will be deleted with 'del'
*/
t_list		*ft_lstmap_type(t_list *lst, t_type type,
				t_content (*f)(t_content, t_type),
				void (*del)(t_content, t_type));
/*
* executes 'f' in all nodes of the list that last node is pointed by 'lst'
* and returns a new list with the result.
* if fails delete already created
* the content of the nodes will be deleted with 'del'
*/
t_list		*ft_lstrmap_type(t_list *lst, t_type type,
				t_content (*f)(t_content, t_type),
				void (*del)(t_content, t_type));
/*
* delete a t_list node and his content
* the content will be deleted with 'del' function
*/
void		ft_lstdelone_type(t_list *lst, void (*del)(t_content, t_type));
/*
* returns the node of list that first node is pointed by 'list'
* that content is equal to 'content' 
*/
t_list		*ft_lstfind(t_content content, t_type type, t_list *list);
/*
* returns the node of list that last node is pointed by 'list'
* that content is equal to 'content' 
*/
t_list		*ft_lstrfind(t_content content, t_type type, t_list *list);
//Deprecated List Functions
// deprecated
t_list		*ft_lstnew(void *content);
// deprecated
void		ft_lstclear(t_list **lst, void (*del)(void*));
// deprecated
void		ft_lstiter(t_list *lst, void (*f)(void*));
// deprecated
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// deprecaated
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
