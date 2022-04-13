#include <queue>
#include <vector>
#include <string>

class RR
{
private:
    int n;
    int sa; 
    int q;


public:
    RR(int n, int sa, int q);

    std::vector<std::vector<std::string> > rrimplement();
    std::queue<int> rr_sort_queue(std::queue<int> &q);
    ~RR();
};
