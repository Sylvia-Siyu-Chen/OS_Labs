#include "scheduling.h"

#include <iostream>
# include <string> 
# include <vector>



using namespace std;

int main(){

    Scheduling s1 (3,1,2);

    std::vector<std::vector<std::string> > result = s1.FIFO();

    // cout<<"result size: "<<result.size()<<endl;
    // cout<<"result sub size: "<<result.at(1).size()<<endl;


    int max = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (max < result.at(i).size())
        {
            max = result.at(i).size();
        }
        
    }
    
    int cycle = 1;
    for (int j = 0; j < max; j++)
    {
        cout<<cycle<<"      ";
        cycle++;
        for (int i = 1; i < result.size(); i++){           
            try{
                cout<<result.at(i).at(j)<<"     ";      
            }
            catch(std::out_of_range vector){
                cout<<"               ";
            }
            
        }
        cout<<endl;
    }
    
    
}