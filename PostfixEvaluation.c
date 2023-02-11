/*
Infix to Postfix
By Sujal Agrawal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stackInt{
    int st[10];
    int top;
    int size;
};



void pushInt(struct stackInt* sk,int val){
    sk->top++;
    sk->st[sk->top]=val;
}

int popInt(struct stackInt* sk){
    int x=sk->st[sk->top];
    sk->top--;
    return x;
}

int peekInt(struct stackInt* sk){
    return sk->st[sk->top];
}




struct stack
{
    char st[50];
    int top;
    int size;
};

int isempty(struct stack *sk)
{
    if (sk->top == -1)
        return 1;
    return 0;
}
void push(struct stack *sk, char ch)
{
    sk->top++;
    sk->st[sk->top] = ch;
}

char pop(struct stack *sk)
{

    char x = sk->st[sk->top];
    sk->top--;
    return x;
}

char peek(struct stack *sk)
{
    return sk->st[sk->top];
}

int precedence(char op)
{
    switch (op)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
}

int superPop(struct stack *sk, char *postFix, int i)
{
    while (!isempty(sk))
    {
        postFix[i++] = pop(sk);
    }
    return i;
}

void postFix(struct stack *sk, char *infix, char *Postfix)
{
    int k = 0, i = 0;
    while (infix[k] != '#')
    {
        if ((infix[k] >= 65 && infix[k] <= 90) || (infix[k] >= 97 && infix[k] <= 122))
        {
            Postfix[i++] = infix[k];
        }
        else if (infix[k] == '(')
        {
            push(sk, '(');
        }
        else if (infix[k] == ')')
        {
            while (!isempty(sk) && peek(sk) != '(')
            {
                char operater = pop(sk);
                Postfix[i++] = operater;
            }
            if (peek(sk) == '(')
            {
                pop(sk);
            }
        }
        else
        {
            if (isempty(sk) || peek(sk) == '(')
            {
                push(sk, infix[k]);
            }
            else
            {
                while (!isempty(sk) && peek(sk) != '(' && precedence(infix[k]) <= precedence(peek(sk)))
                {
                    char oper = pop(sk);
                    Postfix[i++] = oper;
                }
                push(sk, infix[k]);
            }
        }
        k++;
    }
    int m = superPop(sk, Postfix, i);
    Postfix[m] = '\0';
}

int postfixEvaluation(char *s){
    struct stackInt st;
    st.top = -1;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='0' && s[i]<='9'){
            pushInt(&st,s[i]-'0');
        }
        else{
            int a=popInt(&st);
            int b=popInt(&st);
            switch(s[i]){
                case '+': pushInt(&st,b+a);break;
                case '-': pushInt(&st,b-a);break;
                case '/': pushInt(&st,b/a);break;
                case '*': pushInt(&st,b*a);break;
                case '^': pushInt(&st,pow(b,a));break;
            }
        }
        i++;
    }
    return popInt(&st);
}

int main()
{
    char infix[50];
    printf("Enter the infix expression : \n");
    scanf("%s", infix);
    struct stack sk;
    sk.top = -1;
    int sz = strlen(infix);
    infix[sz] = '\0';
    infix[sz] = '#';
    char Postfix[50];
    Postfix[0] = '\0';
    postFix(&sk, infix, Postfix);
    printf("The required Postfix expression is : \n");
    printf("%s\n", Postfix);
    printf("The output of the given infix expression is : ");
    printf("%d",postfixEvaluation(Postfix));
    return 0;
}
