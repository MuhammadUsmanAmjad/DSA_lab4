#include <iostream>
using namespace std;
int get_capacity(string str)
{
    if (str == "single")
        return 1;
    if (str == "double")
        return 2;
    if (str == "triple")
        return 3;
    if (str == "quad")
        return 4;
    if (str == "family")
        return 6;
    if (str == "suite")
        return 10;
    return -1;
}
class cirlinklist
{
    struct node
    {
        string type;
        int no_of_guests;
        int capacity_of_room;
        bool is_full;
        node *next;
        node()
        {
            type = "";
            no_of_guests = 0;
            capacity_of_room = 0;
            is_full = false;
            next = NULL;
        }
        node(string type, int no_of_guests)
        {
            this->type = type;
            this->no_of_guests = no_of_guests;
            capacity_of_room = get_capacity(type);
            if (no_of_guests == capacity_of_room)
                is_full = true;
            else
                is_full = false;
            next = NULL;
        }
    };

public:
    node *head;
    node *tail;
    class Iterator
    {

    public:
        node *curr;
        Iterator()
        {
            curr = NULL;
        }
        Iterator(node *t)
        {
            curr = t;
        }
        int operator*()
        {
            return (curr->no_of_guests);
        }
        Iterator &operator++()
        {
            if (curr->next != NULL)
                curr = curr->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp = *this;
            if (curr->next != NULL)
                curr = curr->next;
            return temp;
        }
        int getsize(Iterator const &itr)
        {
            node *temp = itr.curr;
            int i = 0;
            while (temp->next != NULL)
            {
                i++;
                temp = temp->next;
            }
            return i;
        }
        bool operator!=(const Iterator &itr)
        {
            return (itr.curr != this->curr);
        }
        bool isEmpyt()
        {
            return (curr == NULL);
        }
    };
    Iterator begin()
    {
        Iterator itr;
        itr.curr = head;
        return itr;
    }
    Iterator end()
    {
        Iterator itr;
        itr.curr = tail;
        return itr;
    }
    cirlinklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insert_at_tail(string str, int no_pp)
    {
        node *new_node = new node(str, no_pp);
        Iterator it = begin();
        if (it.isEmpyt())
        {
            it.curr = new_node;
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
        new_node->next = head;
    }

    void allocate_room(string str, int no_pp)
    {
        Iterator it = begin();
        if (it.isEmpyt())
        {
            cout << "No room present.\n";
            return;
        }
        bool flag = false;
        it = begin();
        Iterator et = end();
        ++et;
        do
        {
            if (it.curr->type == str)
            {
                if (it.curr->no_of_guests == 0 && no_pp <= it.curr->capacity_of_room)
                {
                    it.curr->no_of_guests += no_pp;
                    flag = true;
                    if (it.curr->no_of_guests == it.curr->capacity_of_room)
                        it.curr->is_full = true;
                    break;
                }
            }
            ++it;
        } while (it != et);
        // if (flag)
        //     cout << "Successfully updated the room.\n";
        // else
        //     cout << "Room not avalible\n";
    }
    void display_simple()
    {
        node *temp = head;
        do
        {
            cout << "Room Type is:- " << temp->type << endl;
            cout << "Capacity of Room:- " << temp->capacity_of_room << endl;
            cout << "Total Guests in the room:- " << temp->no_of_guests << endl;
            cout << "IS full:- ";
            if (temp->is_full)
                cout << "yes\n";
            else
                cout << "no\n";
            temp = temp->next;
            cout << "\n\n";
        } while (temp != tail->next);
    }
    void display()
    {
        Iterator it = begin();
        Iterator et = end();
        ++et;
        do
        {
            cout << "Room Type is:- " << it.curr->type << endl;
            cout << "Capacity of Room:- " << it.curr->capacity_of_room << endl;
            cout << "Total Guests in the room:- " << it.curr->no_of_guests << endl;
            cout << "IS full:- ";
            if (it.curr->is_full)
                cout << "yes\n";
            else
                cout << "no\n";
            ++it;
            cout << "\n\n";
        } while (it != et);
    }
    ~cirlinklist()
    {
        node *temp = head;
        do
        {
            node *t = head;
            head = head->next;
            delete t;
        } while (head != tail->next);
        cout << "~called\n";
    }
};
int main()
{
    cirlinklist *l1 = new cirlinklist;
    l1->insert_at_tail("family", 3);
    l1->insert_at_tail("single", 0);
    l1->insert_at_tail("triple", 1);
    l1->insert_at_tail("single", 1);
    l1->insert_at_tail("quad", 2);
    l1->insert_at_tail("suite", 4);
    l1->insert_at_tail("family", 6);
    l1->display();
    cout << "_________________________________________\n\n";
    l1->allocate_room("quad", 2);
    l1->allocate_room("family", 2);
    l1->allocate_room("triple", 1);
    l1->allocate_room("suite", 5);
    l1->allocate_room("single", 1);
    l1->display();
    delete l1;
    cout << endl;
    return 0;
}
// Room Type is:- family
// Capacity of Room:- 6
// Total Guests in the room:- 3
// IS full:- no

// Room Type is:- single
// Capacity of Room:- 1
// Total Guests in the room:- 0
// IS full:- no

// Room Type is:- triple
// Capacity of Room:- 3
// Total Guests in the room:- 1
// IS full:- no

// Room Type is:- single
// Capacity of Room:- 1
// Total Guests in the room:- 1
// IS full:- yes

// Room Type is:- quad
// Capacity of Room:- 4
// Total Guests in the room:- 2
// IS full:- no

// Room Type is:- suite
// Capacity of Room:- 10
// Total Guests in the room:- 4
// IS full:- no

// Room Type is:- family
// Capacity of Room:- 6
// Total Guests in the room:- 6
// IS full:- yes

// _________________________________________

// Room Type is:- family
// Capacity of Room:- 6
// Total Guests in the room:- 3
// IS full:- no

// Room Type is:- single
// Capacity of Room:- 1
// Total Guests in the room:- 1
// IS full:- yes

// Room Type is:- triple
// Capacity of Room:- 3
// Total Guests in the room:- 1
// IS full:- no

// Room Type is:- single
// Capacity of Room:- 1
// Total Guests in the room:- 1
// IS full:- yes

// Room Type is:- quad
// Capacity of Room:- 4
// Total Guests in the room:- 2
// IS full:- no

// Room Type is:- suite
// Capacity of Room:- 10
// Total Guests in the room:- 4
// IS full:- no

// Room Type is:- family
// Capacity of Room:- 6
// Total Guests in the room:- 6
// IS full:- yes

// ~called
