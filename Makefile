OUT = out/out
RESOBJ = res/out/resou.obj
RESRC = res/src/resou.rc
RESRES = res/out/resou.res
LIBS = -lgdi32

compile:
	g++ -I $(CURDIR) -o $(OUT)  start.cpp $(LIBS)

run: 
	out/out.exe


