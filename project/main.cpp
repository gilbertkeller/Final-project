#include <string>
#include <vector>
#include <ruc-sci-comp/animate.hpp>
#include "sandpile.h"
#include "make_sandpile.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <random>


using Row = std::vector<int>;
using Sandpile = std::vector<Row>;
using Animation = std::vector<Sandpile>;
using namespace std;
/*
int main(int , char **argv)
{
  
   
    Animation animation_frames;
    Sandpile grid;
    ifstream infile(argv[1]);
   
    string buffer;
    while(getline(infile, buffer))
    {
        istringstream ss(buffer);
        copy(std::istream_iterator<int>(ss), {}, std::back_inserter(grid.emplace_back())); 
    }
    animation_frames.push_back(grid);
    unsigned int num_rows = grid.size();
    unsigned int num_cols = grid[0].size();

    bool is_stable = false;
    while(!is_stable)
    {
        is_stable = true;
        for(unsigned int Ridx = 0; Ridx < num_rows; Ridx ++)
        {
            for(unsigned int Cidx = 0; Cidx < num_cols; Cidx ++)
            { 
                if(grid[Ridx][Cidx] >= 4)
                {
                    grid[Ridx][Cidx] -= 4;
                    if(Ridx > 0)
                    {
                         grid[Ridx - 1][Cidx] += 1;
                         if( grid[Ridx - 1][Cidx] >= 4) 
                         {
                             is_stable = false;
                         }
                    } 
                    if(Ridx < num_rows-1)
                    {
                         grid[Ridx + 1][Cidx] += 1;
                         if(grid [Ridx + 1][Cidx])
                         {
                             is_stable = false;
                         }
                    }

                    if(Cidx > 0 )
                    { 
                        grid[Ridx][Cidx - 1] += 1;
                        if(grid[Ridx][Cidx - 1])
                        {
                            is_stable = false;
                        }
                    }
                    if(Cidx < num_cols - 1)
                    {
                        grid[Ridx][Cidx + 1] += 1;
                        if(grid[Ridx][Cidx +1])
                        {
                            is_stable = false;
                        }
                    }
                }
            }
        }
    animation_frames.push_back(grid);
    }
    animate(animation_frames);
}
*/

int main(int argc, char **argv)
{
    Sandpile grid;
    if(argc == 2)
    {
        string buffer;
        ifstream infile(argv[1]);
        while(getline(infile, buffer))
        {
            istringstream ss(buffer);
            copy(std::istream_iterator<int>(ss), {}, std::back_inserter(grid.emplace_back())); 
            
        } 
    }
    else if(argc == 3)
    {
        int s = stoi(argv[1]); //size of sand pile
        int n = stoi(argv[2]); //number of grains
        uniform_int_distribution<int> dis(0, s - 1);
        mt19937 engine(1337);
        grid.resize(s, Row(s));
        for(int i = 0; i < n; i++)
        {
            int ridx = dis(engine); 
            int cidx = dis(engine); 
            grid[ridx][cidx] += 1;
        }
    }
    Animation animation_frames;
    animation_frames.push_back(grid);
    
    unsigned int num_rows = grid.size();
    unsigned int num_cols = grid[0].size();
    
    bool is_stable = false;
    while(!is_stable)
    {
        is_stable = true;
        for(unsigned int Ridx = 0; Ridx < num_rows; Ridx ++)
        {
            for(unsigned int Cidx = 0; Cidx < num_cols; Cidx ++)
            { 
                if(grid[Ridx][Cidx] >= 4)
                {
                    grid[Ridx][Cidx] -= 4;
                    if(Ridx > 0)
                    {
                         grid[Ridx - 1][Cidx] += 1;
                         if( grid[Ridx - 1][Cidx] >= 4) 
                         {
                             is_stable = false;
                         }
                    } 
                    if(Ridx < num_rows-1)
                    {
                         grid[Ridx + 1][Cidx] += 1;
                         if(grid [Ridx + 1][Cidx])
                         {
                             is_stable = false;
                         }
                    }

                    if(Cidx > 0 )
                    { 
                        grid[Ridx][Cidx - 1] += 1;
                        if(grid[Ridx][Cidx - 1])
                        {
                            is_stable = false;
                        }
                    }
                    if(Cidx < num_cols - 1)
                    {
                        grid[Ridx][Cidx + 1] += 1;
                        if(grid[Ridx][Cidx +1])
                        {
                            is_stable = false;
                        }
                    }
                }
                
            }
        }
    
    animation_frames.push_back(grid);
    }
    animate(animation_frames);
}
