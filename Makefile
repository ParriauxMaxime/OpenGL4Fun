CXX=g++    #Commande du compilateur

NAME=OpenGL

DEBUG       ?=  yes

LEVEL       ?=  3

COLOR		?=	yes

LIB			=	-l SDL2 -l SDL2_mixer -l pthread

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic

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


PATH_SRC	=	./src

SRC		+=		$(PATH_SRC)/main.cpp \
					  $(PATH_SRC)/Engine.cpp

OBJ     =   $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: ./$(NAME)

%.o:    %.cpp
	$(CXX) -c $(<) -o $(@) $(CXXFLAGS)
