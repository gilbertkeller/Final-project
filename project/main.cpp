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
   
   fstream ifile;
   ifile.open("/clam/u3/students/gmk83/Final-project/cpp-final-project-abs/project/data");
       if (!ifile) {
           cout << "Unable to open file";
           exit(1); // terminate with error 
       }
       ifile.close()
       return 0;
}