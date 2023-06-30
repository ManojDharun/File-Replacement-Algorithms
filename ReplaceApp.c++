#include"repHdr.h"
int main()
{
    int ch;
    Replace r,l,o;
    do{
    cout<<"--------------------------"<<"\n";
    cout<<"ENTER 1 FOR FIFO PAGE REPLACEMENT"<<endl;
    cout<<"ENTER 2 FOR LRU PAGE REPLACEMENT"<<endl;
    cout<<"ENTER 3 FOR OPTIMAL PAGE REPLACEMENT"<<endl;
    cout<<"ENTER YOUR CHOICE :";
    cin>>ch;
    if(ch==1)
    {
r.getdetails();
r.FIFO(r.page,r.frame,r.n,r.m);
r.display();
    }
    else if(ch==2)
    {
l.getdetails();
l.LRU(l.page,l.frame,l.n,l.m);
l.display();
    }
    else if(ch==3)
    {
o.getdetails();
o.Optimal(o.page,o.frame,o.n,o.m);
o.display();
    }
    }while(ch!=0);
    return 0;
}
