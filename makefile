CC          = g++
CFLAGS      = -Wall -Wextra -pedantic
CXXFLAGS    = -std=c++17 -I./include

SRC = ./src/hellsing.cpp     \
		./src/vec2_math.cpp  \
		./src/vec3_math.cpp  \
		./src/my_string.cpp 

TES = ./test/test.cpp        \
		./test/timer.cpp     \
		./src/vec2_math.cpp  \
		./src/my_string.cpp 

SRC_OBJ = ${SRC:.cpp=.o}

TES_OBJ = ${TES:.cpp=.o}

SRC_OUT = hellsing
TES_OUT = test

${OUT} : ${SRC_OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${CXXFLAGS} 

%.o : ./src/%.cpp 
	${CC} -c -o $@ $< ${CFLAGS} ${CXXFLAGS} 

$(TES_OUT) : ${TES_OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${CXXFLAGS}

%.o : ./test/%.cpp ./src/my_string.cpp ./src/vec2_math.cpp
	${CC} -c -o $@ $< ${CFLAGS} ${CXXFLAGS} 

.PHONY : clean

clean:
	${RM} ${RMFLAGS} ${TES_OBJ} ${SRC_OBJ} ${OUT}
