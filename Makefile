cxx = g++
cxx_include_libs = -lsfml-graphics -lsfml-window -lsfml-system
src_dir = src
build_dir = build#

compile = @$(cxx) -c $^ -o $(build_dir)/$^.o
link = @$(cxx) $(build_dir)/$^.o -o $(build_dir)/$@ $(cxx_include_libs)

mkdir_p = mkdir -p


main: $(src_dir)/main.cpp
	@$(mkdir_p) $(build_dir)/$(dir $^)
	$(compile)
	$(link)

events-explained: $(src_dir)/events-explained.cpp
	@$(mkdir_p) $(build_dir)/$(dir $^)
	$(compile)
	$(link)

simple-movement: $(src_dir)/simple-movement.cpp
	@$(mkdir_p) $(build_dir)/$(dir $^)
	$(compile)
	$(link)

elaborate-movement: $(src_dir)/elaborate-movement.cpp
	@$(mkdir_p) $(build_dir)/$(dir $^)
	$(compile)
	$(link)


clean:
	@rm -r $(build_dir)/*
