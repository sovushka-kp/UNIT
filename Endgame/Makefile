NAME = endgame

SRCS = src/main.c \
	src/mx_finish_game.c \
	src/mx_map.c \
	src/mx_menu.c \
	src/mx_prepare_image.c \
	src/mx_topi_virus.c \
	src/mx_topi.c \
	src/mx_virus.c \
	src/SDL.c \

OUT = main.o \
	mx_finish_game.o \
	mx_map.o \
	mx_menu.o \
	mx_prepare_image.o \
	mx_topi_virus.o \
	mx_topi.o \
	mx_virus.o \
	SDL.o \

INC = inc/virus.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SDL2 = -I ./Frameworks/SDL2.framework/Versions/A/Headers -F ./Frameworks -framework SDL2 -rpath ./frameworks
SDL3M = -I ./Frameworks/SDL2_image.framework/Headers -rpath ./Frameworks -framework SDL2_image
SDL4M = -I ./Frameworks/SDL2_ttf.framework/Headers -rpath ./Frameworks -framework SDL2_ttf

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) -I $(INC) $(SRCS) ${SDL2} ${SDL3M} ${SDL4M}
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf a.h
	@rm -rf main.c mx_finish_game.c mx_map.c mx_menu.c mx_prepare_image.c mx_topi_virus.c mx_topi.c mx_virus.c SDL.c\
	@rm -rf main.o mx_finish_game.o mx_map.o mx_menu.o mx_prepare_image.o mx_topi_virus.o mx_topi.o mx_virus.o SDL.o\

reinstall: uninstall clean all