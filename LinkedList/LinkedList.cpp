#include <iostream>

using namespace std;

struct node
{
    float data;
    struct node* next;
};


int isempty(struct node*);
struct node* newNode(float);
void display(struct node*);
int sizeLL(struct node*);
struct node* insertFront(struct node*, float);
struct node* insertBack(struct node*, float);
void insertAfter(struct node*, float);
struct node* deleteFront(struct node*);
struct node* deleteBack(struct node*);
void deleteAfter(struct node*);
float averagelist(struct node*);


int main()
{
    struct node* mylist = NULL ;
    

   mylist = insertBack(mylist, 1.5);
   mylist = insertFront(mylist, 2.5);
   mylist = deleteBack(mylist);
   mylist = insertBack(mylist, 4.5);
  
   display(mylist);

   

   cout << "The average of elements in your List is " << averagelist(mylist) << endl;

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

struct node* insertBack(struct node* insb, float item)
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