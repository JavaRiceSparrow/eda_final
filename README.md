# eda_final

By running 
`g++ test.cpp -o test` 
`./test`
you could transform all the verilog file in /cases
and save them in /output

usage:
<!-- not finished -->
these three file are needed:

#include "module/module.h"
#include "module/modulePrinter.h"
#include "module/moduleTranser.h"

Three class:    module, modulePrinter, moduleTranser

Use module.read(filepath) to read verilog file(have be realiable file) to module.
module只能讀取一次，不可變。
Constructor of modulePrinter need one address of module, 
and it will use modulePrinter.normalWriteFile(output_ofstream) to print.
Constructor of moduleTranser will need two addresses of module, 
one is the origin(0,1,x value), one is the abc_format.
