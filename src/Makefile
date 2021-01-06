dst = ../bin

c = $(wildcard *.c)
bin = $(patsubst %.c, %, $(c))

build: $(dst) $(addprefix $(dst)/, $(bin))
	@true

$(dst)/%: %.c
	gcc -o $@ $<
