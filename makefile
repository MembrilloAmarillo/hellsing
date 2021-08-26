CC          = g++
CFLAGS      = -Wall -Wextra -pedantic
CXXFLAGS    = -std=c++17 -I./include

SRC = ./src/hellsing.cpp     \
		./src/vec2_math.cpp  \
		./src/vec3_math.cpp

OBJ = ${SRC:.cpp=.o}

OUT = hellsing

all: ${OUT}

${OUT} : ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${CXXFLAGS} 

%.o : ./src/%.cpp 
	${CC} -c -o $@ $< ${CFLAGS} ${CXXFLAGS} 

.PHONY : clean

clean:
	${RM} ${RMFLAGS} ${OBJ} ${OUT}
