#include<stdio.h>

struct Stack
{
    int q[100],top=-1;

    void push(int x)
    {
        q[++top]=x;
    }

    int pop()
    {
        int t=top;
        top--;
        return q[t];
    }

    void print_()
    {
        for(int i=top; i>=0; i--) printf("%d ",q[i]);
        printf("\n");
    }
};

int main()
{
    Stack st;
    int tp,temp;

    while(scanf("%d",&tp)==1)
    {

        if(tp==1)
        {
            scanf("%d",&temp);
            st.push(temp);
        }
        else if(tp==2)
        {
            printf("%d\n",st.pop());
        }
        else st.print_();
    }

    return 0;
}
