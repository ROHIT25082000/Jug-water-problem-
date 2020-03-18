#include<stdio.h>
#include<stdlib.h>
#include"A3_header_PES1201800152.h"

int main()
{
    scanf("%d%d%d",&capacity_a,&capacity_b,&capacity_c);		// taking the input 
    state startstate;// start state
    int a;int b;int c;
    scanf("%d%d%d",&a,&b,&c);
    setState(&startstate,a,b,c);
    state goalstate;// end state 
    scanf("%d%d%d",&a,&b,&c);
    setState(&goalstate,a,b,c);

    List solution;	// solution list :contains the final solution 
    initList(&solution);	
    add_at_end(&solution,&startstate);// adding the start state for the initial solution.
    
    state temp;    // this temp will be passed every time 
    int index;
    int count = 0;// counter variable keeps track of number of solutions .
    int (*move[])(const state *src, state * dst) = { moveAB, moveAC, moveBA, moveBC, moveCA, moveCB }; //array of pointers to functions -order
    while(solution.head->curr.next_func_index <5) // check condition to terminate 
    {
        index = solution.tail->curr.next_func_index;
        if(move[index](&solution.tail->curr,&temp) && !is_repeated(&solution,&temp))
        {   // valid and not repeated.
            add_at_end(&solution,&temp);
            if(are_same(&solution.tail->curr,&goalstate))
            {
                count++;
                disp_list(&solution); // if the goal and tail state matches print it
                printf("\n\n");       
            }
        }	
        else
        {
            while(solution.tail->curr.next_func_index == 5) // else delete and the backtrack 
                delete_at_end(&solution);
            solution.tail->curr.next_func_index++;
        }
    }
    printf("%d\n",count);// prints the total count .
}














