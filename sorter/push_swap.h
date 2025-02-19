#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack_node
{
    long value;
    int num_rot;

    int ra;
    int rra;
    int rb;
    int rrb;
    int rr;
    int rrr;

    struct s_stack_node *prev;
    struct s_stack_node *next;

}t_list;

//split related functions - fts_split
char            **ft_split(char const *s, char c);
size_t          ft_strcount(char const *s, char c);
size_t          ft_array_sorting(char const *s, char c);
char            *ft_substr(char const *s, unsigned int start, size_t len);
int             ft_check_null(size_t len, char const *s);

//more functions used by split - fts_split2
size_t          ft_strlen(const char *str);
void            *ft_memcpy(void *dest, const void *src, size_t n);
int             ft_split_length(char **temp);

//functions to free memory - fts_free
void            ft_free_stack(t_list **stack);
char            **ft_dealloc(char **str, int i);

//all functions related to swap - fts_swap
void            ft_swap(t_list **stack);
void            ft_sa(t_list **stack_a);
void            ft_sb(t_list **stack_b);
void            ft_ss(t_list **stack_a, t_list **stack_b);

//all functions related to rotate - fts_rotate
void            ft_rotate(t_list **stack);
void            ft_ra(t_list **stack_a);
void            ft_rb(t_list **stack_b);
void            ft_rr(t_list **stack_a, t_list **stack_b);

//all functions related to reverse rotate - fts_rev_rotate
void            ft_reverse_rotate(t_list **stack);
void            ft_rra(t_list **stack_a);
void            ft_rrb(t_list **stack_b);
void            ft_rrr(t_list **stack_a, t_list **stack_b);

//all functions related to push - fts_push
void            ft_push(t_list **stack_a, t_list **stack_b);
void            ft_pa(t_list **stack_a, t_list **stack_b);
void            ft_pb(t_list **stack_a, t_list **stack_b);

//functions all about nodes - fts_for_nodes
bool            ft_create_node(t_list **stack, long number);
t_list          *ft_find_last_node(t_list *head);
t_list          *ft_find_min_node(t_list *stack);
t_list          *ft_find_biggest_node(t_list *head);
bool            ft_check_node(t_list *head, int value);

//functions calculating rotations - fts_calculate_rotations
void            ft_calc_rotations(t_list *node_a, t_list *stack_b);
t_list          *ft_find_target1(t_list *stack1, t_list *stack2);
void            ft_calc_stack_a(t_list *node_a);
void            ft_calc_stack_b(t_list *node_a, t_list *target_node);
t_list          *ft_find_target2(t_list *stack1, t_list *stack2);

//functions for checking and sorting - fts_stack_sorting
void            ft_check_order(t_list **stack_a);
void            ft_three_nbr_sort(t_list **stack_a);
bool            ft_stack_sorted(t_list *head);
int             ft_stack_length(t_list *head);
bool            ft_check_and_clean(t_list **stack, int value);

//functions that deal with updating string - argv to numbers - fts_about_numbers
int             ft_check_number(char *str);
long            ft_atol(const char *str);
int             ft_find_space(char *str);
bool            ft_numbers_check(t_list **stack_a, char **argv, int argc);
bool            ft_check_sub_numbers(t_list **stack, char *argv);

//includes small functions helpers for finding best number to push - ft_find_nbr
t_list          *ft_next_nbr(t_list *stack_a, t_list *stack_b);
void            ft_find_index(t_list *node_a);
void            ft_trim_rot(t_list *node, int ra, int rb, int rr);
void            ft_trim_rev_rot(t_list *node, int rra, int rrb, int rrr);

//functions for stack posible rotations - fts_rot_stack
void            ft_calc_r_and_rr(t_list *target_node, int *r, int *rr);
void            ft_rotate_stack(int *node_int, void (*operation)(t_list **), t_list **stack);
void            ft_rotate_stack2(int *node_int, void (*operation)(t_list **, t_list **), t_list **stack, t_list **stack2);
void            ft_sort_rotation(t_list *node, t_list **stack_a, t_list **stack_b);
void            ft_rotate_and_push_ba(t_list **stack_a, t_list **stack_b);

//main and push function - fts_main_and_push
void            ft_push_swap(t_list **stack_a, t_list **stack_b);
void            ft_first_sort(t_list **stack_a, t_list **stack_b);
int             main(int argc, char **argv);
//void            ft_print(t_list **stack);

//includes small functions helpers for finding best rotation to execute - fts_cases
void            ft_case1(t_list *node, int rr_best1);
void            ft_case2(t_list *node, int rrr_best2);
void            ft_case3(t_list *node, int no);
void            ft_case4(t_list *node, int on);
bool            ft_convert_to_nbr(char *argv, t_list **stack);

#endif