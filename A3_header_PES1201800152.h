#include<stdio.h>
#include<stdlib.h>

// globally stores the capacity for each jug.
int capacity_a;
int capacity_b;
int capacity_c;

struct state
{
    int a;
    int b;
    int c;
    int next_func_index;
};
typedef struct state state;


void setState(state * curr, int a,int b, int c); // initializes the state

int moveAB(const state * src , state * dst);// moves and checks whether valid and return the same
int moveAC(const state * src , state * dst);// moves and checks whether valid and return the same
int moveBA(const state * src , state * dst);// moves and checks whether valid and return the same
int moveBC(const state * src , state * dst);// moves and checks whether valid and return the same
int moveCA(const state * src , state * dst);// moves and checks whether valid and return the same
int moveCB(const state * src , state * dst);// moves and checks whether valid and return the same


void disp_state(const state * curr);
int is_valid(const state * curr);
int are_same(const state *lhs, const state *rhs); //checks if two states are same or not .

struct node
{
    state curr;
    struct node * prev;
    struct node * next;
};
typedef struct node Node;

struct List
{
    Node * head;
    Node * tail;
};
typedef struct List List;

void initList(List * mylist);
void add_at_end(List * mylist,const state * curr);
void delete_at_end(List * mylist);
int is_repeated(List * mylist, const state * curr); // checks if the node is repeated.
void disp_list(const List * mylist);

