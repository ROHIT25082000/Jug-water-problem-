#include<stdio.h>
#include<stdlib.h>
#include"A3_header_PES1201800152.h"

void setState(state * curr, int a,int b, int c)     //initializes the states.
{
    curr->a = a;
    curr->b = b;
    curr->c = c;
    curr->next_func_index = 0;
}
int moveAB(const state * src , state * dst)
{
    dst->c = src->c;    // copies the non changing one directly .
    int A = src->a;
    int B = src->b;
    while(A > 0 && B < capacity_b)  // adds until any jug is filled or any jug is empty. 
    {
        A--;
        B++;
    }
    dst->b = B;     
    dst->a = A;
    return is_valid(dst);

}
int moveAC(const state * src , state * dst)
{
    dst->b = src->b;    // copies the non changing one directly
    int A = src->a;
    int C = src->c;
    while(A > 0 && C < capacity_c)   // adds until any jug is filled or any jug is empty.
    {
        A--;
        C++;
    }
    dst->a = A;
    dst->c = C;
    return is_valid(dst);
}
int moveBA(const state * src , state * dst)
{  
    dst->c = src->c;    // copies the non changing one directly
    int B = src->b;
    int A = src->a;
    while(B > 0 && A < capacity_a)  // adds until any jug is filled or any jug is empty.
    {
        B--;
        A++;
    }
    dst->a = A;
    dst->b = B;
    return is_valid(dst);
}
int moveBC(const state * src , state * dst)
{
    dst->a = src->a;    // copies the non changing one directly
    int B = src->b;
    int C = src->c;
    while(B > 0 && C < capacity_c)  // adds until any jug is filled or any jug is empty.
    {
        B--;
        C++;
    }
    dst->c = C;
    dst->b = B;
    return is_valid(dst);
}
int moveCA(const state * src , state * dst)
{
    dst->b = src->b;    // copies the non changing one directly
    int A = src->a;
    int C = src->c;
    while(C > 0 && A < capacity_a)   // adds until any jug is filled or any jug is empty.
    {
        C--;
        A++;
    }
    dst->a = A;
    dst->c = C;
    return is_valid(dst);

}
int moveCB(const state * src , state * dst)
{
    dst->a = src->a;    // copies the non changing one directly
    int C = src->c;
    int B = src->b;
    while(C > 0 && B < capacity_b)    // adds until any jug is filled or any jug is empty.
    {
        C--;
        B++;
    }
    dst->c = C;
    dst->b = B;
    return is_valid(dst);

}
void disp_state(const state * curr)
{
    printf("%d %d %d \n",curr->a ,curr->b ,curr->c); // displays a current stat
}

int is_valid(const state * curr)
{
    return (curr->a <= capacity_a && curr->a >=0 && 
    curr->b <= capacity_b && curr->b >=0 && 
    curr->c <= capacity_c && curr->c >=0);

}
int are_same(const state *lhs, const state *rhs)
{
    return (lhs->a == rhs->a && lhs->b == rhs->b && lhs->c == rhs->c);
}
void initList(List * mylist)
{
    mylist->head = NULL;
    mylist->tail = NULL;
}

void add_at_end(List * mylist, const state * curr)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->curr = *curr;
    if(mylist->head == NULL)
    {
        temp->prev = mylist->tail;
        mylist->head = temp;
        mylist->tail = temp;
        temp->next = NULL;
    }
    else 
    {
        temp->prev = mylist->tail;
        mylist->tail->next = temp;
        mylist->tail = temp;
        temp->next = NULL;
    }
}

void delete_at_end(List * mylist)
{
    if(mylist->head == NULL)
        return;
    else if(mylist->head == mylist->tail)
    {
        free(mylist->head);
        mylist->head = NULL;
        mylist->tail = NULL;
    }
    else 
    {
        Node * temp = mylist->tail;
        mylist->tail = temp->prev;
        mylist->tail->next = NULL;
        free(temp);
    }
}
int is_repeated(List * mylist, const state * curr)
{
    Node * temp = mylist->head;
    while(temp!=NULL)
    {
        if(are_same(&temp->curr,curr))
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void disp_list(const List * mylist)
{
    Node *temp = mylist->head;
    while(temp!=NULL)
    {
        disp_state(&temp->curr);
        temp = temp->next;
    }
}


