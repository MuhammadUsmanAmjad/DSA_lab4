#include <iostream>
using namespace std;
template <typename T>
class circularll
{
    struct node
    {
        T data;
        node *next;
        node *prev;
        node()
        {
            next = NULL;
            prev = NULL;
        }
        node(T data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
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
        T operator*()
        {
            return (curr->data);
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
    circularll<T>()
    {
        head = NULL;
        tail = NULL;
    }
    void insert_at_tail(T data)
    {
        node *n_node = new node(data);
        Iterator it = end();
        if (it.curr == NULL)
        {
            it.curr = n_node;
            head = n_node;
            tail = n_node;
            return;
        }
        tail->next = n_node;
        n_node->prev = tail;
        n_node->next = head;
        head->prev = n_node;
        tail = n_node;
    }
    int get_even_numbers(int data)
    {
        int t = data;
        int s = 0;
        while (t != 0)
        {
            s += t % 10;
            t = t / 10;
        }
        return s;
    }
    void print()
    {
        if (head == NULL)
            return;
        node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
    void get_odd_sum_node()
    {
        node *temp = head;
        do
        {
            int s = get_even_numbers(temp->data);
            bool flag = false;
            node *t = temp;
            if (s % 2 == 0)
            {
                node *t = temp;
                if (temp == head)
                {
                    head = head->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                flag = true;
            }

            temp = temp->next;
            if (flag)
                delete t;
        } while (temp != tail->next);
    }
    int get_sum()
    {
        node *temp = head;
        int s = 0;
        do
        {
            s += temp->data;
            temp = temp->next;
        } while (temp != tail->next);
        return s;
    }
    int get_p()
    {
        node *temp = head;
        int s = 1;
        do
        {
            s *= temp->data;
            temp = temp->next;
        } while (temp != tail->next);
        return s;
    }
    void moveOccur(T key)
    {
        node *temp = head;
        node *tail_S = tail;
        do
        {
            bool flag1 = false;
            node *t = temp;
            if (temp->data == key)
            {

                if (temp == head)
                {
                    head = head->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                insert_at_tail(temp->data);
                flag1 = true;
            }
            temp = temp->next;
            if (flag1)
                delete t;
        } while (temp != tail_S);
    }
};
int main()
{
    circularll<int> *l1 = new circularll<int>;
    l1->insert_at_tail(9);
    l1->insert_at_tail(11);
    l1->insert_at_tail(34);
    l1->insert_at_tail(6);
    l1->insert_at_tail(13);
    l1->insert_at_tail(21);
    l1->print();
    l1->get_odd_sum_node();
    l1->print();
    cout << "Sum is:- " << l1->get_sum() << endl;
    cout << "Product is:- " << l1->get_p() << endl;
    circularll<int> *l2 = new circularll<int>;
    l2->insert_at_tail(1);
    l2->insert_at_tail(2);
    l2->insert_at_tail(2);
    l2->insert_at_tail(3);
    l2->print();
    l2->moveOccur(2);
    l2->print();
}