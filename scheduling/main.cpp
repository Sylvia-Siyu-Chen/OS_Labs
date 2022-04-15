#include "FIFO.h"
#include "RR.h"

#include <iostream>
# include <string> 
# include <vector>
# include <iomanip>


using namespace std;

void scheduling(int n, int sa, int q){

    std::vector<std::vector<std::string> > result;
    if(n == 1){
        FIFO f(n,sa);
        result = f.implementation();
    }
    else{
        if (sa == 1)
        {
        FIFO f(n,sa);
        result = f.implementation();
        }
        else if (sa == 2)
        {
        RR r(n, sa, q);
        result = r.rrimplement();
        }
    }



    int max = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (max < result.at(i).size())
        {
            max = result.at(i).size();
        }
        
    }
    
    int cycle = 0;
    for (int j = 0; j < max; j++)
    {
        cycle++;  
        cout<<cycle;
        for (int i = 1; i < result.size(); i++){           
            try{
                cout<<setw(18-(std::to_string(cycle).length()))<<result.at(i).at(j);      
            }
            catch(std::out_of_range vector){
                cout<<"                  ";
            }
        }
        cout<<endl;
    }

};

int main(){
    
    scheduling(2,2,2); // change n, sa, q here 

    return 0;

}