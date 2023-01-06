#include <iostream>
using namespace std;


struct node
{
    int data;
    struct node* next;
};


int isempty(struct node*);
struct node* newNode(float);
void display(struct node*);
int sizeLL(struct node*);
struct node* insertFront(struct node*, float);
struct node* insertBack(struct node*, int);
void insertAfter(struct node*, float);
struct node* deleteFront(struct node*);
struct node* deleteBack(struct node*);
void deleteAfter(struct node*);
float averagelist(struct node*);
int countA(struct node*);
void moveforwardlist(struct node*, struct node*);
struct node* moveback(struct node*, struct node*);
struct node* loadlist(struct node*, int[], int);
struct node* reverse(struct node* header);


int main()
{
    struct node* mylist = NULL ;
    float average;
    char elements;
    int num = 0;
    const int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    mylist = loadlist(mylist, arr, size);
    display(mylist);
    
    moveforwardlist(mylist, mylist->next->next);
    display(mylist);
   // mylist = moveback(mylist, mylist->next->next->next);
    //display(mylist);
    mylist = reverse(mylist);
    display(mylist);



/*
    cout << "How many grades do you want to add to your list?: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "\nPlease enter grade " << i << " in the list: ";
        cin >> arr[i];
        mylist = insertBack(mylist,i);
    }




    cout << "\nYour list has the following elements: ";
    display(mylist);

    cout << "The number of A_grades in your list is: " << countA(mylist) << endl;
   //average = averagelist(mylist);
   //cout << "\nThe average value of elements in your List is: " << average << endl;
 */

    system("PAUSE");
    return 0;
}

int isempty(struct node* header)
{
    return (header == NULL) ? 1 : 0;

}

struct node* newNode(float item)
{
    struct node* temp;

    temp = (struct node*)malloc(sizeof(node));

    temp -> data = item;

    temp->next = NULL;
    return temp;
}

void display(struct node* disp)
{
    struct node* temp = disp;
 
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    
}

int sizeLL(struct node* header)
{
    struct node* temp = header;
    int cnt = 0;

    if (isempty(temp))
        cout << "There is no node in the List. List is Empty." << endl;
    else
    {
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
    }
    return cnt;
}
struct node* insertFront(struct node* insf, float item) 
{
    struct node* temp;

    temp = newNode(item);
    temp->next = insf;
    insf = temp;

    return insf;
}

struct node* insertBack(struct node* insb, int item)
{
    struct node* temp, *insbtemp;

    temp = newNode(item);

    if (isempty(insb))
    {
        insb = temp;
        return insb;
    }
    insbtemp = insb;
    while (insbtemp->next != NULL)
        insbtemp = insbtemp->next;
    insbtemp->next = temp;      
    return insb;
}

void insertAfter(struct node* insaft, float item)
{
    struct node* temp;
    temp = newNode(item);

    temp->next = insaft->next;

    insaft->next = temp;
}

struct node* deleteFront(struct node* delf)
{
    struct node* temp;
    
    if (delf == NULL)
        return delf;
    temp = delf;

    delf = delf->next;
    free(temp);

    return delf;
}

struct node* deleteBack(struct node* delb)
{
    struct node* temp, *delbtemp;

    if (delb == NULL)
        return delb;

    delbtemp = delb;

    while(delbtemp->next->next != NULL)
        delbtemp = delbtemp->next;

    temp = delbtemp->next;
    delbtemp->next = NULL;
    free(temp);
    
    return delb;
}

void deleteAfter(struct node* delaft)
{
    struct node* temp;

    if (delaft->data == NULL || delaft == NULL)
        return;
    temp = delaft->next;

    delaft->next = temp->next;

    free(temp);
}

float averagelist(struct node* average)
{
    struct node* temp = average;
    float sum = 0, avg;
    int cnt = 0;

    while (temp != NULL)
    {
        sum += temp->data;
        cnt++;

        temp = temp->next;
    }
    avg = sum / cnt;

    return avg;
}

int countA(struct node* grades)
{
    struct node* temp = grades;
    int cnt=0;

    while (temp != NULL)
    {
        if (temp->data == 'A')
            cnt++;
        temp = temp->next;
    }
    return cnt;
}

void moveforwardlist(struct node* header, struct node* movenode)
{
    struct node* temp = NULL;
    struct node* headertemp = header;

    while (headertemp->next != movenode)
        headertemp = headertemp->next;

        temp = movenode->next->next;
        headertemp->next = movenode->next;
        movenode->next = temp;
        headertemp->next->next = movenode;
}

struct node* loadlist(struct node* header, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
       header = insertBack(header, arr[i]);
    }
    return header;
}

struct node* moveback(struct node* header, struct node* movenode)
{
    struct node* temp = NULL;
    struct node* headertemp = header;

    while (headertemp->next != movenode)
        headertemp = headertemp->next;

    temp = movenode->next->next;

    headertemp->next = movenode->next;
    movenode->next = temp;
    headertemp->next->next = movenode;

    return header;
}

struct node* reverse(struct node*header) {
    struct node* temp = NULL;
    struct node* prevnode = NULL;
    struct node* afternode = header;

    while (afternode != NULL) 
    {
        temp = afternode->next;
        afternode->next = prevnode;
        prevnode = afternode;
        afternode = temp;
    }
    header = prevnode;
    return header;
}