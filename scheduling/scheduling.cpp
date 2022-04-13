
#include "scheduling.h"


#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream> 

using namespace std;

#define R "3"
#define B "2"



Scheduling :: Scheduling(int n, int sa, int q){
    this->n = n;
    this->sa = sa;
    this->q = q;
}

 std::vector<std::vector<string> > Scheduling :: FIFO(){
    int cycle = 0;

    std::queue<std::queue<int> > wait_in_line;
    int run_to_block[n];
    int total_run[n];
    int total_block[n];
    int termination[n];

    std::vector<std::vector<string> > output;
    
    for(int i = 1; i <= n; i ++){
        std::queue<int> line;
        line.push(i);
        wait_in_line.push(line);
        total_run[i] = 0;
        run_to_block[i] = 2; // 0: blocl, 1: run, 2: ready 
        termination[i] = 0;
        total_block[i] = 0;
        std::vector<string> suboutput;
        output.push_back(suboutput);
    }
        std::vector<string> suboutput;
        output.push_back(suboutput);

    int current_run = 0;

    int terminate = 0;
    
    cout<<"Cycle"<<"   ";
    int copy = 1;
    while (copy <= n)
    {
        cout<<"P"<<copy<<" State"<<"    ";
        copy++;
    }
    cout<<"Comment"<<endl; // close line 

    while(!terminate){
        cycle++;

        // each cycle

        std::queue<int> next_in_line;  

        if (current_run == 0)
        {
            if (wait_in_line.size() != 0)
            {
                if (wait_in_line.front().size() == 1)
                {
                    current_run = wait_in_line.front().front();
                    wait_in_line.pop();   
                    run_to_block[current_run] = 1; 
                }
                else{
                    wait_in_line.front() = sort_queue(wait_in_line.front());
                    current_run = wait_in_line.front().front();
                    run_to_block[current_run] = 1;
                    wait_in_line.front().pop();
                }
                
            }
            // else{
            //     terminate = 2;
            //     break;
            // }
        }
        
        for (int i = 1; i <= n; i++)

        {
        // cout<<"cycle" << cycle <<endl;


        // cout<<"wait in line: "<<current_run<<endl;

        // cout<<"line: "<<current_run<<endl;

        // cout<<"run to block"<<run_to_block[i]<<endl;


            if (i == current_run)
            {
                if (total_run[i] % 3 == 0 && total_run[i] != 0 && total_block[i] == 0)
                {
                    run_to_block[i] = 0;
                    if (wait_in_line.size() != 0)
                    {
                        if (wait_in_line.front().size() == 1)
                        {
                            current_run = wait_in_line.front().front();
                            wait_in_line.pop();   
                            run_to_block[current_run] = 1; 
                        }
                        else{
                            wait_in_line.front() = sort_queue(wait_in_line.front());
                            current_run = wait_in_line.front().front();
                            run_to_block[current_run] = 1;
                            wait_in_line.front().pop();
                            }
                        
                    }
                        else{
                            current_run = 0;
                            // terminate = 2;
                            // break;
                            }
                }
            }
            
            if (i == current_run)
            {   // current run 
                    total_run[i] ++;

                    if (total_run[i] == 7)
                    {
                        // cout<<"terminate!!!!"<<endl;
                        std::stringstream ss;
                        ss << "Terminate";
                        output.at(i).push_back(ss.str());     
                        termination[i] = 1;
                        current_run = 0;
                    }

                    else{

                        std::stringstream ss;
                        if (total_run[i]%3 == 0)
                        {
                                ss << "Run(3,3) ";
                        }
                        else{
                                ss << "Run(" << (total_run[i])%3 << ",3) ";

                        }
                        output.at(i).push_back(ss.str());     
                    }
            }

            else{
                // currently not in run 
                if (run_to_block[i] == 0)
                {
                    total_block[i] ++;   
                    if (total_block[i] % 2 == 0)
                    {
                        std::stringstream ss;
                        ss << "Block(2,2)";
                        output.at(i).push_back(ss.str());  
                        run_to_block[i] = 2;
                        next_in_line.push(i);
                    } 
                    else{
                        std::stringstream ss;
                        ss << "Block(" << total_block[i]%2 << ",2) ";
                        output.at(i).push_back(ss.str());  
                    }
                    
                }
                if (run_to_block[i] == 2)
                {
                    std::stringstream ss;
                    ss << "Ready";
                    output.at(i).push_back(ss.str());    
                }
            }
            
        }
        if (next_in_line.size()!=0)
        {
            wait_in_line.push(next_in_line);
        }

        if (terminate!=2)
        {
            terminate = 1;
            for(int j = 1; j <= n; j ++)
            {
                if (!termination[j])
                {
                    // cout<<"terminate: "<<j<<endl;
                    terminate = 0;
                }
                
            }
        }
        
        
        
    }
   
    
    return output;
    
};

std::queue<int> Scheduling ::sort_queue(std::queue<int> &q)   
{
  std::vector<int> temp;
   while(!q.empty())
   {
       temp.push_back(q.front());
       q.pop();
   }
   sort(temp.begin(),temp.end());
   for(int i=0;i<temp.size();i++)
   {
       q.push(temp.back());
   }
   return q;
}




int Scheduling :: RR(){
    return 0;

};


