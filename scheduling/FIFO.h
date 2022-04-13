#include <queue>
#include <vector>
#include <string>

class FIFO
{
private:
    int n;
    int sa; 


public:
    FIFO(int n, int sa);

    std::vector<std::vector<std::string> > implementation();
    std::queue<int> sort_queue(std::queue<int> &q);
    ~FIFO(){};
};
