#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

int isempty(struct node*);
struct node* CreateNode(int);
void display(struct node*);
int sizeLL(struct node* header);

int main()
{
    struct node* header;

    header = CreateNode(2);
    header->next = CreateNode(4);
    header->next->next = CreateNode(6);
    header->next->next->next = CreateNode(8);
    header->next->next->next->next = CreateNode(10);
    display(header);
    cout << "Your List has " << sizeLL(header) << " nodes." << endl;

    system("PAUSE");
    return 0;
}

int isempty(struct node* header)
{
    return (header == NULL) ? 1 : 0;

}

struct node* CreateNode(int item)
{
    struct node* temp;

    temp = (struct node*)malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

void display(struct node* disp)
{
    struct node* temp = disp;
    if (isempty(temp))
        cout << "There is no node in the List. List is Empty." << endl;
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
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
        return cnt;
    }
}