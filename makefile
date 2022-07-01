CC          = g++
CXXFLAGS    = -std=c++17 -I./include -Wall -Wextra -pedantic -Wpsabi -march=native -mavx -O3

SRC = ./src/hellsing.cpp     \
		./src/vec_avx_math.cpp  \
		./src/vec3_math.cpp  \
		./src/my_string.cpp 

TES = ./test/test.cpp        \
		./test/timer.cpp     \
		./src/vec3_math.cpp  \
		./src/my_string.cpp  \
		./src/vec_avx_math.cpp 

INC = ./include/vec_avx_math.h \
		./include/vec3_math.h

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

%.o : ./test/%.cpp ./src/my_string.cpp ./src/vec3_math.cpp ./src/vec_avx_math.cpp ${INC}
	${CC} -c -o $@ $< ${CFLAGS} ${CXXFLAGS} 

.PHONY : clean

clean:
	${RM} ${RMFLAGS} ${TES_OBJ} ${SRC_OBJ} ${OUT}
