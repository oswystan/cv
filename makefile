#######################################################################
##                     Copyright (C) 2017 wystan
##
##       filename: makefile
##    description:
##        created: 2017-07-06 11:42:13
##         author: wystan
##
#######################################################################
.PHONY: all clean

bin := a.out
src := $(wildcard *.c *.cpp)
obj := $(src:.c=.o)
obj := $(obj:.cpp=.o)
ld_flags := -lopencv_core  -lopencv_imgproc -lstdc++ -lopencv_highgui

all: $(bin)

$(bin): $(obj)
	@gcc $^ -o $(bin) $(ld_flags)
	@echo "[gen] "$@
%.o:%.c
	@echo "[ cc] "$@
	@gcc -c $< -o $@
%.o:%.cpp
	@echo "[cpp] "$@
	@g++ -c $< -o $@

clean:
	@echo "cleaning..."
	@rm -f *.o $(bin)
	@echo "done."

#######################################################################
