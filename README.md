declaring the frames needed to our Animate our Animation
declaring a grid from our sanpile
opening the file with if stream, argc is the number of arguments in the program
argv[1] means ther are two arguments passed into the terminal

while I am getting each line in infile and storing it in the buffer,
the vector ss is allowed to expand by using grid.emplace_back().
the vector will grow by inserting the numbers into rows and columns at the end of the matrix by using push back.

I can now collaspe the sand pile, first by declaring a flag to be true, then set the to flag to false while the flag is not stable, check the the rows and columns for 4 grains of sand or greater in the cell, if there are 4 or more grains of sand in a cell you can subtract 4 from the cell and add one to the cells up, down, left, or right of it. making sure you are not up against a corner or edge of the matrix. If it is up against a corner or edge, you have to subtract or add one to the row or column. subtract from a row means you can only go right, adding means you can only go left. Subtracting from a column means you can only up, adding to a column means you can only go down. 

ounce our sand pile is stable I can push back (expand or contract) our grid into our frames, and run our animation.

In the terminal I have to compile it first, then run the executible by typing in the path of the data file, then move the file into the animation. By the way I had problems with argc, I had to delete argc from the main to get it to run.

It is the same for the random generator. except I needed to check if there are 2 or more arguments. if there are 2 arguments, we can copy the vector with back inserter, and then place it at the end of the matrix. If there are three arguments then we can set up the size of sand pile, and the number of grains in the sand pile by using the random generator. then in the comand line you will have the three arguments, the executable file,  how big the matrix is, and how much sand you want to dump anywhere in the pile. 

I first hard coded a 10x10 sand pile, the animation ran perfectly, when I tested for a 50x50 sand pile, and ran the animation I ended up with a 50x50 grid, but a 10x10 sand pile was created inside the 50x50 grid. I realized I had to manually change the code each time I wanted to change to change the size the grid to get the correct animation. I then coded the program to dynamically expand, or contract the grid.

I then tested the random generator, in the terminal I ran the exe file which is argument one, arg two is the size, and arg three is the number of grains of sand. twenty three to six hundred and eighty seven calculations were made when running a ten by ten to one hundred by one hundred with at least onethousnd  grains of sand or higher, which ran very smooth. seventy four thousand plus calculations were made for larger grids, and up to one million grains of sand. My cpu could not handle that many calculations, I had to terminate the program because it took way to long to execute. I also notice if you do not drop enough grains of sand into the pile nothing happens.
