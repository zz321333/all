NAME = zzpool

HEADER = zzpool.h
SRC = zzpool.cpp
DEPS = zzdefines zzlog

OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o,$(SRC)))
FLAGS = $(addprefix -I../, $(DEPS))

build: $(OBJ)
	for i in $(HEADER); do \
		cp $$i $(INCLUDE_PATH); \
	done 
	@echo $(NAME) $@ finished.

$(OBJ_PATH)/%.cpp.o: %.cpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	@echo $(NAME) $@ funished.
