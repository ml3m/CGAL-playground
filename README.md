# [Environment Setup 11] Build CGAL-based programs using CMake

## Preview (Torus)
<p align="center"><imgsrc="./Torus.png" /></a></p>


* Make a new directory for CGAL and navigate to it

`$ mkdir cgal`

`$ cd cgal`

* Extract Boost and CGAL tarball.

`$ tar -xvf CGAL-5.2.2.tar.xz`

`$ tar -xzvf boost_1_76_0.tar.gz`

* Make another directory for the test case and navigate to it

`$ mkdir test`

`$ cd test/`

* Generate the required CMake files using the provided script
* make sure to change the path depending on your project location.

`$ $HOME/path/to/cgal/CGAL-5.2.2/scripts/cgal_create_CMakeLists`

* Install missing prerequisites (GMP and MPFR libraries)

`$ sudo apt install libgmp-dev`
`$ sudo apt install libmpfr-dev`

* Run CMake with appropriate parameters for configuring CGAL and Boost

`$ cmake -DCGAL_DIR=/home/tuxriders/cgal/CGAL-5.2.2 -DCMAKE_BUILD_TYPE=Release -DBOOST_ROOT=/home/tuxriders/cgal/boost_1_76_0`

* Build the source code using GNU Make

`$ make`

* Run the compiled program

`$ ./heart`

* View the generated mesh in GMSH
`$ sudo apt install gmsh`
`$ gmsh heart.mesh`
