/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:00:40 by wweng             #+#    #+#             */
/*   Updated: 2018/08/12 16:01:15 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 50
#define OP 5
char op[OP] = {'(','+','-','*','/',};
int op_priority[OP] = {0,1,1,2,2};
int priority(char c);
void to_postfix(char infix[], char postfix[]);
char stack[N]; // This is a global variable.
int top = -1;
void push(char item){
    if (top >= N-1){
        write(1, "Stack full!\n", 12);
        exit(-1);
    }
    stack[++top]=item;
}
int pop(){
    if (top == -1){
        write(1, "Stack empty!\n", 13);
        exit(-1);
    }
    return stack[top--];
}
void stackPrint(){
    int i;
    write(1, "stack =", 7);
    while (i <= top)
    {
        write(1, &stack[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
bool IsEmpty(void)
{
    return (top < 0) ? true : false;
}
bool IsFull()
{
    return (top >= N - 1) ? true : false;
}
char top_data()
{
    return (stack[top]);
}
int priority(char c)
{
    int i;
    while (i < OP)
    {
        if(op[i] == c)
            return (op_priority[i]);
        i++;
    }
    return (-1);
}
void to_postfix(char infix[], char postfix[])
{
    int i;
    int j;
    char x, y;
    i = 0;
    j = -1;
    while ((x = infix[i++]) != '\0'){
        if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (! IsEmpty() && (x = pop()) != '(')
                postfix[++j] = x;
        }
        else if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            y = top_data();
            while (priority(y) >= priority(x))
            {
                postfix[++j] = pop();
                y = top_data();
            }
            push(x);
        }
        else
        {
            postfix[++j] = x;
        }
    }
    while (! IsEmpty())
        postfix[++j] = pop();
    postfix[++j] = '\0';
}
bool IsDight(char c)
{
    return (c >= '0' && c <= '9');
}
int calculate(char postfix[])
{
    int a;
    int b;
    int c;
    int point;
    point = 0;
    while (postfix[point]!='\0')
    {
        while (IsDight(postfix[point]))
            push(postfix[point++]);
        a = pop() - '0';
        b = pop() - '0';
        c = 0;
        if (postfix[point] == '+')
            c = b + a;
        else if (postfix[point] == '-')
            c = b - a;
        else if (postfix[point] == '*')
            c = b * a;
        else if (postfix[point] == '/')
            c = b / a;
        push(c + '0');
        point++;
    }
    return (pop() - '0');
}
int main(void)
{
    char infix[50];
    char postfix[50];

    write(1, "5*5+8-4/1 ", 10) ;
    read(0, infix, 50);
    to_postfix(infix, postfix);
    printf("\n\nINFIX : %s \tPOST-F : %s\n",infix , postfix);
    printf("ANS： %d\n", calculate(postfix));
    return (0);
}