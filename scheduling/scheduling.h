#include <queue>
#include <vector>
#include <string>

class Scheduling
{
private:
    int n;
    int sa; 
    int q;


public:
    Scheduling(int n, int sa, int q);

    std::vector<std::vector<std::string> > FIFO();
    int RR();
    int implement();
    std::queue<int> sort_queue(std::queue<int> &q);
    ~Scheduling(){};
};
