# FastArray
*A fast and flexible 1D array with Expression Template support*

## Build
1. Create a build directory
    <pre><code>
    $ mkdir build
    $ cd build
    </code></pre>
1. Copy and tailor your CMake script
    <pre><code>
    $ cp ../doc/do-cmake
    </code></pre>
1. Build
    <pre><code>
    $ ./do-cmake
    $ make
    </code></pre>
1. Run it
    <pre><code>
    src/unit-tests
    </code></pre>

## TODO
 - Should operator= et al. check sizes and call resize()?
 - Debug error checking (size compatibility, bounds checking)
 - Math and Trig functions
 - Unary ops
