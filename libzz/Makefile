LIB = libzz.a
MODULES_PATH = ../modules
MODULES = zzlog zzdefines zzpool zzstring zzapp zzappparams
SUBDIRS = $(addprefix $(MODULES_PATH)/, $(MODULES))
CURRENT_PATH = $(shell pwd)
INCLUDE_PATH = $(CURRENT_PATH)/include
OBJ_PATH = $(CURRENT_PATH)/obj

build::
	mkdir -p $(INCLUDE_PATH)
	mkdir -p $(OBJ_PATH)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir INCLUDE_PATH=$(INCLUDE_PATH) OBJ_PATH=$(OBJ_PATH) CC=g++; \
	done
	ar rvs $(LIB) $(wildcard $(OBJ_PATH)/*.o)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean;\
	done
	rm -rf $(INCLUDE_PATH)
	rm -rf $(OBJ_PATH)
	rm -rf $(LIB)
