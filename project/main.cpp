#include <string>
#include <vector>
#include <ruc-sci-comp/animate.hpp>
#include "sandpile.h"
#include "make_sandpile.h"
#include <fstream>

using namespace std;

//int main(int argc, char **argv)
int main()
{
   /*
   fstream ifile;
   ifile.open("/clam/u3/students/gmk83/Final-project/cpp-final-project-abs/project/data");
       if (!ifile) {
           cout << "Unable to open file";
           exit(1); // terminate with error 
       }
       ifile.close()
       return 0;
    */
    Sandpile grid(10,Row(10,4));
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
                
            }
        }
    }
}
