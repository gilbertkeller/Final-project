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

using Row = std::vector<int>;
using Sandpile = std::vector<Row>;
using Animation = std::vector<Sandpile>;
using namespace std;

//int main(int argc, char **argv)
int main()
{
  
    //uniform_int_distribution<int> dis(0, s);
    //mt19937 engine;
    /*
    ifstream infile("/clam/u3/students/gmk83/Final-project/cpp-final-project-abs/project/data.data");
    while(getline(data, istringstream ss(buffer)));
       if (!infile) 
       {
          cerr << "Could not load" << data << endl;
          return 1;
       }
       infile.close()
       return 0;
    copy(std::istream_iterator<int>(ss), {}, std::back_inserter(sandpile.emplace_back())); 
    */
    sandpile grid(10,Row(10,4));
    bool is_stable = false;
    while(!is_stable)
    {
        is_stable = true;
        for(int Ridx = 0; Ridx < 10; Ridx ++)
        {
            for(int Cidx = 0; Cidx < 10; Cidx ++)
            { 
                if(grid[Ridx][Cidx] >= 4)
                {
                    grid[Ridx][Cidx] -= 4;
                    grid[Ridx - 1][Cidx] += 1;
                    grid[Ridx + 1][Cidx] += 1;
                    grid[Ridx][Cidx - 1] += 1;
                    grid[Ridx][Cidx + 1] += 1;
                }
                if(grid[Ridx] < 0 || grid[Ridx] > 0)
                {
                    continue; // row out of bounds
                }

                if(grid[Cidx] < 0 || grid[Cidx] > o)
                {
                    continue; //column out of bounds
                }

                else if(grid[Ridx][Cidx] >= 3)
                {
                    grid[Ridx][Cidx] -= 3;
                    grid[Ridx - 2][Cidx - 2] += 1;
                    grid[Ridx + 2][Cidx + 2] += 1;
                    grid[Ridx - 2][Cidx - 2] += 1;
                    grid[Ridx + 2][Cidx + 2] += 1;
                }

                else if(grid[Ridx][Cidx] >= 2)
                {
                    grid[Ridx][Cidx] -= 2;
                    grid[Ridx - 3][Cidx - 3] += 1;
                    grid[Ridx + 3][Cidx + 3] += 1;
                    grid[Ridx - 3][Cidx - 3] += 1;
                    grid[Ridx + 3][Cidx + 3] += 1;
                }

                else if(grid[Ridx][Cidx] >= 1)
                {
                    grid[Ridx][Cidx] -= 1;
                    grid[Ridx - 4][Cidx - 4] += 1;
                    grid[Ridx + 4][Cidx + 4] += 1;
                    grid[Ridx - 4][Cidx - 4] += 1;
                    grid[Ridx + 4][Cidx + 4] += 1;
                }

                else 
                {
                     return 0;
                }
                
            }
        }
    }
   
}
