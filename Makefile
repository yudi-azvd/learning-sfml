cxx = g++
cxx_include_libs = -lsfml-graphics -lsfml-window -lsfml-system
build_dir = build#

compile = @$(cxx) -c $^ -o $(build_dir)/$^.o
link = @$(cxx) $(build_dir)/$^.o -o $(build_dir)/$@ $(cxx_include_libs)

main: main.cpp
	$(compile)
	$(link)

events-explained: events-explained.cpp
	$(compile)
	$(link)

simple-movement: simple-movement.cpp
	$(compile)
	$(link)

elaborate-movement: elaborate-movement.cpp
	$(compile)
	$(link)


clean:
	@rm $(build_dir)/*