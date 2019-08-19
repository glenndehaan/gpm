PREFIX_APP = /usr
PREFIX_CONFIG = /etc/gpm
BUILDDIR = ./bin
DESTDIR = ""

# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: gpm

# This rule tells make how to build gpm from main.cpp
gpm:
	mkdir -p $(BUILDDIR)
	g++ -o $(BUILDDIR)/gpm ./src/main.cpp ./src/config/config.cpp ./src/colors/colors.cpp ./src/http/http.cpp ./src/install/install.cpp -lcurl

.PHONY: watch
watch:
	while true; do $(MAKE) -q || $(MAKE); sleep 2; done

.PHONY: install
install:
	mkdir -p $(DESTDIR)$(PREFIX_APP)/bin
	mkdir -p $(DESTDIR)$(PREFIX_CONFIG)/gpm
	cp $(BUILDDIR)/gpm $(DESTDIR)$(PREFIX_APP)/bin/gpm
	cp ./config/registry.list $(DESTDIR)$(PREFIX_CONFIG)/gpm/registry.list

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX_APP)/bin/gpm
	rm -f $(DESTDIR)$(PREFIX_CONFIG)/gpm
