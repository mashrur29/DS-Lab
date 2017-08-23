#include<stdio.h>

struct Queue
{
    int q[100],front_=0,rear_=-1,mod=100;

    void push(int temp)
    {
        rear_=(rear_+1)%mod;
        q[rear_]=temp;
    }

    int pop()
    {
        int t=front_;
        front_=(front_+1)%mod;
        return q[t];
    }

    void print_()
    {
        if((rear_+1)%mod==front_)
        {
            printf("Empty Queue\n");
            return;
        }

        if(rear_<front_)
        {
            for(int i=front_; i<mod; i++) printf("%d ",q[i]);
            for(int i=0; i<=rear_; i++) printf("%d ",q[i]);
            printf("\n");
            return;
        }

        for(int i=front_; i<=rear_; i++) printf("%d ",q[i]);
        printf("\n");
    }

};

int main()
{
    Queue q;
    int tp,temp;

    while(scanf("%d",&tp)==1 && tp)
    {

        if(tp==1)
        {
            scanf("%d",&temp);
            q.push(temp);
        }
        else if(tp==2)
        {
            printf("%d\n",q.pop());
        }
        else q.print_();
    }

    return 0;
}
