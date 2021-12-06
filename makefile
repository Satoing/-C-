main: src/main.cpp
	g++ -o bin/main src/*.cpp lib/acllib.a -lm -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -Iinclude -g -fexec-charset=GBK
run:main
	bin/main.exe
	@echo Executing 'run' complete!	