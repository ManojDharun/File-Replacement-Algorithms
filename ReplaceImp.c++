#include"repHdr.h"

Node::Node(int num,Node* n)
{
    number = num;
    next = n;
}

Replace::Replace()
{
    first = NULL;
    arr = new int[0];
    n =0;
    m = 0;
    page = new int[0];
    frame = new int*[0];
    frame[0] = new int[0];
}

void Replace::getdetails()
{
    cout<<"ENTER THE NUMBER OF PAGES :";
    cin>>n;
    page = new int[n];
    cout<<"\nENTER THE NUMBER OF FRAMES :";
    cin>>m;
    frame = new int*[m];
    for(int i=0;i<m;i++)
    {
        frame[i] = new int[n];
    }
    cout<<"ENTER THE PAGES :";
    for(int i=0;i<n;i++)
    {
        cin>>page[i];
    }
}

void Replace::FIFO(int* page,int** frame,int n,int m)
{
    int i,j,l=0,count =0,d,k,count1;
    int arr1[20],count2=0,count3 =0;
    bool test = false;
    bool empty,found;
    for(i=0;i<n;i++)
    {
found = false;
empty = false;
test = false;
count1 = 0;
arr1[i] = page[i];
int s = page[i];
count = count + 1;
for(k=0;k<l;k++)
{
if(page[i] == arr[k])
{
found = true;
}
}
if(l<m)
{
if(arr[l-1]!=s and found == false){
arr[l] = s;
}
}
for(k=0;k<m;k++)
        {
        if(page[i]==frame[k][i-1]){
                         test = true;
                }
        }
if(test==false)
{
count2++;
}
else if(test==true)
{
count3++;
}
for(k=0;k<m;k++)
{
        if(frame[k][i-1] == 0)
        {
                empty = true;
        }
}
for(j=0;j<m;j++)
{
   count1 = count1 + 1;
   if(test == true and l<m)
   {
        frame[j][i] = frame[j][i-1];
   }
   else if(frame[j][i]==0 and l<m and test == false)
   {
                frame[j][i] = arr[j];
                if(count1<=1)
                {
                        Node *newnode = new Node(s,NULL);
                        insert(newnode);
                }
   }
   else if(frame[j][i]==0 and l>=m)
            {
                if(test==true)
                {
                    frame[j][i] = frame[j][i-1];
                }
                else if(test == false and empty==true)
                {
                        if(frame[j][i-1]==0)
                                frame[j][i] = page[i];
                        else
                                frame[j][i] = frame[j][i-1];
                }
                else if(test==false){
                        d = getFirstpos();
                        if(d == frame[j][i-1])
                        {
                                frame[j][i] = page[i];
                                Node *newnode = new Node(s,NULL);
                                insert(newnode);
                        }
                        else{
                                frame[j][i] = frame[j][i-1];
                    }
                }
            }
}
if(l>=m and test==false and empty!=true){
              pop();
}
if(arr[l-1]!=s and found == false){
l++;
}
    }
    hit = count3;
    fault = count2;
}



void Replace::pop()
{
    if(first==NULL)
    {

    }
    else{
        Node *temp = first;
        cout<<temp->number;
        first = first->next;
        delete temp;
        temp = NULL;
        }
}

int Replace::getFirstpos()
{
    return first->number;
}

void Replace::insert(Node* newnode)
{
    if(first==NULL)
    {
        first = newnode;
    }
    else{
        Node* temp = first;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void Replace::display()
{
    int i,j;
    Node* temp = first;
    cout<<"page :    ";
    for(i=0;i<n;i++)
    {
        cout<<page[i]<<" ";
    }
    for(i=0;i<m;i++)
    {
        cout<<"\n";
        cout<<"F1: ";
        for(j=0;j<n;j++)
        {
            cout<<frame[i][j]<<" ";
        }
    }
    cout<<"\nHIT RATIO  :\n";
    cout<<hit<<":"<<n<<"\n";
    cout<<"\nFAULT RATIO :\n";
    cout<<fault<<":"<<n;
}

void Replace::LRU(int* page,int** frame,int n,int m)
{
    int i,j,l=0,count =0,d,k,count1;
    int arr1[20],mini,d1[3],d2,d3,count2=0,count3 = 0;
    bool test = false;
    bool empty,found;
    for(i=0;i<n;i++)
    {
found = false;
empty = false;
test = false;
count1 = 0;
arr1[i] = page[i];
int s = page[i];
count = count + 1;
for(k=0;k<l;k++)
{
if(page[i] == arr[k])
{
found = true;
}
}
if(l<m)
{
if(arr[l-1]!=s and found == false){
arr[l] = s;
}
}
for(k=0;k<m;k++)
        {
        if(page[i]==frame[k][i-1]){
                         test = true;
                }
        }
if(test==false)
{
count2++;
}
else if(test==true)
{
count3++;
}
        for(k=0;k<m;k++)
{
if(frame[k][i-1] == 0)
{
empty = true;
}
}
        k = 0;
        for(k=0;k<m;k++)
        {
                d1[k] = findindex(page,frame[k][i-1],i);
        }
        mini = findmin(d1);
for(j=0;j<m;j++)
{
   count1 = count1 + 1;
   if(test == true and l<m)
   {
frame[j][i] = frame[j][i-1];
   }
   else if(frame[j][i]==0 and l<m)
   {
                frame[j][i] = arr[j];
if(count1<=1)
{
                Node *newnode = new Node(s,NULL);
                insert(newnode);
}
            }
   else if(frame[j][i]==0 and l>=m)
            {
                if(test==true)
                {
                    frame[j][i] = frame[j][i-1];
                }
  else if(test == false and empty==true)
                {
                        if(frame[j][i-1]==0)
                                frame[j][i] = page[i];
                        else
                                frame[j][i] = frame[j][i-1];
                }
                else if(test==false){
   d = page[mini];
                    if(d == frame[j][i-1])
                    {
                        frame[j][i] = page[i];
                        Node *newnode = new Node(s,NULL);
                        insert(newnode);
                    }
                    else{
                        frame[j][i] = frame[j][i-1];
                    }
                }
            }
}
if(arr[l-1]!=s and found == false){
l++;
}
    }
    hit = count3;
    fault = count2;
}

void Replace::Optimal(int* page,int** frame,int n,int m)
{
    int i,j,l=0,count =0,d,k,count1;
    int arr1[20],maxi,d1[3],d2,d3,count2=0,count3 = 0;
    bool test = false;
    int pos,count4 = 0;
    bool empty,found,not_maxi;
    for(i=0;i<n;i++)
    {
        count4 = 0;
        pos = 0;
        not_maxi = false;
        found = false;
        empty = false;
        test = false;
        count1 = 0;
        arr1[i] = page[i];
        int s = page[i];
        count = count + 1;
        for(k=0;k<l;k++)
        {
                if(page[i] == arr[k])
                {
                        found = true;
                }
        }
        if(l<m)
        {
                if(arr[l-1]!=s and found == false){
                        arr[l] = s;
                }
        }
        for(k=0;k<m;k++)
        {
                if(page[i]==frame[k][i-1]){
                         test = true;
                }
        }
        if(test==false)
        {
                count2++;
        }
        else if(test==true)
        {
                count3++;
        }
        for(k=0;k<m;k++)
        {
                if(frame[k][i-1] == 0)
                {
                        empty = true;
                }
        }
        k = 0;
        for(k=0;k<m;k++)
        {
                d1[k] = findindex1(page,frame[k][i-1],i);
        }
        cout<<endl;
        maxi = findmax(d1);
        for(k=0;k<m;k++)
        {
                if(d1[k] == -1)
                        count4 = count4 + 1;
        }
        if(count4 == m)
        {
                not_maxi = true;
        }
        for(j=0;j<m;j++)
        {
                count1 = count1 + 1;
                if(test == true and l<m)
                {
                        frame[j][i] = frame[j][i-1];
                }
                else if(frame[j][i]==0 and l<m)
                {
                        frame[j][i] = arr[j];
                        if(count1<=1)
                        {
                               Node *newnode = new Node(s,NULL);
                                insert(newnode);
                        }
                }
                else if(frame[j][i]==0 and l>=m)
                {
                        if(test==true)
                        {
                                 frame[j][i] = frame[j][i-1];
                        }
                        else if(test == false and empty==true)
                        {
                                if(frame[j][i-1]==0)
                                        frame[j][i] = page[i];
                                else
                                        frame[j][i] = frame[j][i-1];
                        }
                        else if(test == false and not_maxi == true){
                                d = getFirstpos();
                                if(d == frame[j][i-1])
                                {
                                        frame[j][i] = page[i];
                                        Node *newnode = new Node(s,NULL);
                                        insert(newnode);
                                }
                                else{
                                        frame[j][i] = frame[j][i-1];
                                }
                        }
                        else if(test==false and not_maxi == false){
                                d = page[maxi];
                                if(d == frame[j][i-1])
                                {
                                        pos = frame[j][i-1];
                                       frame[j][i] = page[i];
                                       Node *newnode = new Node(s,NULL);
                                        insert(newnode);
                                }
                                else{
                                        frame[j][i] = frame[j][i-1];
                                }
                        }
                }
}
if(l>=m and test==false and empty!=true and not_maxi==true){
              pop();
}
else if(l>=m and test == false and empty!=true and not_maxi==false){
        deletenode(pos);
}
if(arr[l-1]!=s and found == false){
l++;
}
    }
    hit = count3;
    fault = count2;
}

void Replace::deletenode(int pos)
{
Node* temp = first;
Node* prev = first;
while(temp->next!=NULL and temp->number!=pos)
{
prev = temp;
temp = temp->next;
}
if(temp->number == pos)
{
prev->next = temp->next;
delete temp;
temp = NULL;
}
}

bool Replace::comp(int a,int b)
{
return (a<b);
}

int Replace::findindex(int *page,int n,int l)
{
int i;
for(i=l;i>=0;i--)
{
if(page[i]==n)
{
return i;
      }
}
return -1;
}

int Replace::findmin(int arr[])
{
    int min = arr[0];

    //Loop through the array
    for (int i = 0; i < 3; i++) {
        //Compare elements of array with min
       if(arr[i] < min)
           min = arr[i];
    }
    return min;
}

int Replace::findindex1(int *page,int s,int l)
{
        int i;
        for(i=l;i<n;i++)
        {
                if(page[i]==s)
                {
                        return i;
                }
        }
        return -1;
}

int Replace::findmax(int arr[])
{
    int max = arr[0];

    //Loop through the array
    for (int i = 0; i < 3; i++) {
        //Compare elements of array with min
       if(arr[i] > max)
           max = arr[i];
    }
    return max;
}
