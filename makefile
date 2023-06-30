res.exe:repImp.o repApp.o
        c++ repImp.o repApp.o -o res.exe
repImp.o:repImp.c++
        c++ -c repImp.o
repApp.o:repApp.c++
        c++ -c repApp.o
