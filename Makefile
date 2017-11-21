CXX=g++    #Commande du compilateur

NAME=OpenGL

DEBUG       ?=  yes

LEVEL       ?=  3

COLOR		?=	yes

LIB			=	-l SDL2 -l SDL2_mixer -l pthread -l GL -l GLEW

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic -std=c++11

ifneq ($(DEBUG), no)
	CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
	CXXFLAGS	+=	-fdiagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

LANG = LANG=en LC_ALL=en_US.UTF-8

PATH_SRC	=	./src

SRC		+=		$(PATH_SRC)/main.cpp \
					 $(PATH_SRC)/Engine.cpp \
					  $(PATH_SRC)/Scene.cpp \

OBJ     =   $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LANG) $(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: ./$(NAME)

%.o:    %.cpp
	$(LANG) $(CXX) -c $(<) -o $(@) $(CXXFLAGS)
