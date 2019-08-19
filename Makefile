# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: gpm

# This rule tells make how to build gpm from main.cpp
gpm:
	mkdir -p ./bin
	g++ -o ./bin/gpm ./src/main.cpp ./src/config/config.cpp ./src/colors/colors.cpp ./src/http/http.cpp ./src/install/install.cpp -lcurl

run:
	./bin/gpm

watch:
	while true; do $(MAKE) -q || $(MAKE); sleep 2; done
