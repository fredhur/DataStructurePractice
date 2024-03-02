#include <cstdio>


template <typename T>
struct Less
{
    bool operator ()(const T &lhs, const T& rhs) const
    {
        return lhs < rhs;
    }

};

template <typename T , class Cmp = Less<T>, size_t size = 100'000'0>
class PriorityQueue
{
public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;

    void push(const T& value)
    {
        heap[++hn] = value;

        for(size_t c = hn ;c >1 && cmp(heap[c], heap[c/2]); c= c/2)
        {
            swap(heap[c], heap[c/2]);
        }

    }
    const T& top() const 
    {
        return heap[1];
    }

    bool empty() const 
    {
        return hn ==0;
    }
    void pop()
    {
        swap(heap[1], heap[hn--]);
        
        size_t p = 1; size_t c =2;

        while(c<=hn)
        {
            if(c < hn && cmp(heap[c+1], heap[c]))
            {
                c++;
            }

            if(cmp(heap[c], heap[p]) == false)
            {
                break;
            }

            swap(heap[c], heap[p]);
            p = c;
            c = c*2;
        }
    }
    void clear() const
    {
        hn = 0;
    }


private:
    Cmp cmp;
    T heap[size]{}; 
    mutable size_t hn {0};

    void swap(T &a, T &b)
    {
        T t = a;
        a = b, b =t;
    }
};


int main()
{

    PriorityQueue<int> pq;


    pq.push(3), pq.push(1), pq.push(5);
    pq.push(1), pq.push(2);
    while(!pq.empty())
    {
        printf("%d ", pq.top());
        pq.pop();
    }puts("");
    return 0;
}