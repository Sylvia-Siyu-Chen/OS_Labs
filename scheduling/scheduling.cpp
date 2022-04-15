
#include "FIFO.h"
#include "RR.h"


#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream> 

using namespace std;

#define R "3"
#define B "2"


// FIFO scheduling 


FIFO :: FIFO(int n, int sa){
    this->n = n;
    this->sa = sa;
}


std::queue<int> FIFO ::sort_queue(std::queue<int> &q)   
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
};


 std::vector<std::vector<string> > FIFO :: implementation(){
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
        cout<<"P"<<copy<<" State"<<"          ";
        copy++;
    }
    
    cout<<endl;

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
        }

        
        for (int i = 1; i <= n; i++)

        {
            if (i == current_run)
            {   // current run 
                    total_run[i] ++;
                    

                    if (total_run[i] == 7)
                    {
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
                                ss << "Run(3/3) ";
                                run_to_block[i] = 0;

                                current_run = 0;
                        }

                        else{
                                ss << "Run(" << (total_run[i])%3 << "/3) ";
                    
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
                        ss << "Block(2/2)";
                        output.at(i).push_back(ss.str());  
                        run_to_block[i] = 2;
                        next_in_line.push(i);
                        
                    } 
                    else{
                        std::stringstream ss;
                        ss << "Block(" << total_block[i]%2 << "/2) ";
                        output.at(i).push_back(ss.str());  
                    }
                    
                }
                else if (run_to_block[i] == 2)
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
                    terminate = 0;
                }
                
            }
        }
    }
    
    return output;
    
};




// for RR scheduling 


RR::RR(int n, int sa, int q)
{
    this->n = n;
    this->sa = sa;
    this->q = q;
}

std::queue<int> RR ::rr_sort_queue(std::queue<int> &q)   
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




std::vector<std::vector<std::string> > RR:: rrimplement(){
    int cycle = 0;
    int run_switch = 0;

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
        cout<<"P"<<copy<<" State"<<"          ";
        copy++;
    }

    cout<<endl;

    while(!terminate){
        cycle++;
    
        std::queue<int> next_in_line;  

        if (run_switch >= q )
        {
            if (current_run!=0)
            {
                run_switch = 0;
                next_in_line.push(current_run);
                run_to_block[current_run] = 2;
                current_run = 0;
            }
            else{
                run_switch = 0;
                
            }
        }

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
                    wait_in_line.front() = rr_sort_queue(wait_in_line.front());
                    current_run = wait_in_line.front().front();
                    run_to_block[current_run] = 1;
                    wait_in_line.front().pop();
                }
                
            }

        }

        
        for (int i = 1; i <= n; i++)

        {

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
                                ss << "Run(3/3) ";
                                run_to_block[i] = 0;
                                current_run = 0;
                                run_switch = 0;
                        }

                        else{
                                ss << "Run(" << (total_run[i])%3 << "/3) ";
                                run_switch++;
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
                        ss << "Block(2/2)";
                        output.at(i).push_back(ss.str());  
                        run_to_block[i] = 2;
                        next_in_line.push(i);

                    } 
                    else{
                        std::stringstream ss;
                        ss << "Block(" << total_block[i]%2 << "/2) ";
                        output.at(i).push_back(ss.str());  
                    }
                    
                }
                else if (run_to_block[i] == 2)
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
                    terminate = 0;
                }      
                
            }
        }
    
    }
    
    return output;
};


RR::~RR()
{
}



