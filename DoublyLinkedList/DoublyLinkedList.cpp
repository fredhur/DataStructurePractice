#include <cstdio>

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;

    Node * alloc(const T&dat, Node *_prev, Node *_next)
    {
        data = dat;
        prev = _prev;
        next = _next;
        if(prev) prev->next = this;
        if(next) next ->prev = this;

        return this;
    }

    void del()
    {
        if(prev) prev->next = next;
        if(next) next ->prev = prev;
    }

};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head.next = &tail;
        tail.prev = &head;
        bcnt =0;
    }
    ~DoublyLinkedList() = default;
    void clear()
    {
        head.next = &tail;
        tail.prev = &head;
    }
    void PushbyIdx(const size_t idx, const T&value)
    {
        Node<T> *p = &head;
       
        size_t i = 0;
        for(;p != nullptr && i != idx; p = p->next, i++);

        if(i > idx)
        {
            p = tail.prev;
        }
        
        printf("insert after this(%d) \n", p->data);
        buf[bcnt++].alloc(value, p, p->next);


        
    }

    void Del(const size_t idx)
    {
        Node<T> *p = &head;
        p = p->next;
        size_t i = 0;
        for(;p != nullptr && i != idx; p = p->next, i++);


        if ( i > idx)
        {
            p = tail.prev;
        }

       
        p->del();
    }

    void PrintAll()
    {
        Node<T> *p = &head;

        p = p->next;
        for(;p != &tail;p=p->next)
        {
            printf("%d ", p->data);
        }
        puts("");
    }

private:

    Node <T> buf[1'000'0];
    size_t bcnt;
    Node <T> head{}, tail{};


};

DoublyLinkedList<int> dll;

int main()
{

    dll.PushbyIdx(0, 3);
    dll.PushbyIdx(1, 2);

    dll.PushbyIdx(0, 1);
    dll.PushbyIdx(0, 4);

    dll.PushbyIdx(3, 5);

    dll.PrintAll();


    dll.Del(0);
    dll.PrintAll();
    dll.Del(2);

    dll.PrintAll();

    return 0;
}