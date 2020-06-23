# eda_final

By running 
```
~ $ g++ test.cpp -o test
~ $ ./test
```
you could transform all the verilog file in /cases
and save them in /output

## 附註：
我放棄寫.cpp檔和makefile了，所以/module裏面的.cpp都是沒用的，不用管他


## usage:
 # it's not finished 

these three file are needed:

- #include "module/module.h"
- #include "module/modulePrinter.h"
- #include "module/moduleTranser.h"

Three class:    module, modulePrinter, moduleTranser

Use module.read(filepath) to read verilog file(have be realiable file) to module.
- module只能讀取一次，不可變。

Constructor of modulePrinter need one address of module, 
and it will use modulePrinter.normalWriteFile(output_ofstream) to print.
Constructor of moduleTranser will need two addresses of module, 
one is the origin(0,1,x value), one is the abc_format.
