cxx = g++
cxx_include_libs = -lsfml-graphics -lsfml-window -lsfml-system
build_dir = build


main: main.cpp
	@$(cxx) -c $^
	@$(cxx) main.o -o $(build_dir)/main $(cxx_include_libs)

events-explained: events-explained.cpp
	@$(cxx) -c $^
	@$(cxx) events-explained.o -o $(build_dir)/events-explained $(cxx_include_libs)


clean:
	@rm *.o