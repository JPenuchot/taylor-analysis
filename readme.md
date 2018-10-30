# Taylor-based reachability analysis of continuous and hybrid systems

This project was made for the ["Software verification and introduction to hybrid systems analysis" course by Sylvie Putot](http://www.enseignement.polytechnique.fr/profs/informatique/Sylvie.Putot/Verif/index.html).

## Approach

The goal of this project is to bring a modern programming approach to hybrid system analysis using modern C++ metaprogramming techniques : polymorphic lambda functions, polymorphic types, all that being defined during **compile-time** and *not* during runtime. That way every single analysis is a **C++ program** itself, that way any single of them can be specifically optimized by the compiler.

That induces that analysis have now to be defined as C++ code, which comes with a drawback that is the need to compile them, however they also benefit from C++'s power : many numerical libraries, high performance compilers and high abstraction level.

The goal is then to provide a lightweight framework for such analysis : abstraction on automatas, interval algebra and so on.

## Requirements

This project only requires `CMake` and a `C++17` compliant compiler.

## Building

Just run `./build.sh` and voilà ! The binaries will be available as `bin/{Release,Debug}/prog`.
