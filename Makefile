# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: gpm

# This rule tells make how to build gpm from main.cpp
gpm:
	mkdir -p ./bin
	g++ -o ./bin/gpm ./src/main.cpp ./src/colors/colors.cpp

run:
	./bin/gpm
