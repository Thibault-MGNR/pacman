# project
VERSION = 0.1.0

# compiler
CXX = g++
LIBSFLAGS = -lSDL2 -lSDL2_image
CFLAGS = -std=c++17
DEFINES =
INCLUDE = include/
TEMPLATE = template/

# directories
BIN = bin
SRC = src
OBJ = .obj
LIB = bin
OUT = pac_man

# source files
SRCS := $(shell dir /s /b $(SRC)\*.cpp)
OBJS := $(patsubst $(SRC)\%.cpp,$(OBJ)\%.o,$(SRCS))

all: $(OUT)

release: CFLAGS = -Wall -Wextra -O2 -D NDEBUG
release: clean
release: $(OUT)

dbg: CFLAGS = -g3 -Wall
dbg: rebuild

dbgRebuild: CFLAGS = -g3
dbgRebuild: rebuild

rebuild: clean
rebuild: $(OUT)

test: $(TEST_OUT)

clean:
	@echo Suppression des fichiers .o dans le dossier $(OBJ)
	@-del /q $(OBJ)\*.o 2> nul

$(OUT): $(OBJS)
	@echo Compilation
	@$(CXX) $(OBJS) -I $(INCLUDE) -I $(TEMPLATE) -L $(LIB) -o $(BIN)\$(OUT) $(LIBSFLAGS) $(CFLAGS) $(DEFINES)

$(OBJ)\%.o: $(SRC)\%.cpp
	$(CXX) -o $@ -c $< -I $(INCLUDE) -I $(TEMPLATE) $(DEFINES) $(CFLAGS)

info:
	@echo -----------------------------------------------------
	@echo info :                
	@echo 	compiler                     : $(CXX)
	@echo 	compiler standart version    : $(STD_VERSION)
	@echo 	flags                        : $(CFLAGS)
	@echo 	defines                      : $(DEFINES)
	@echo 	lib name                     : $(DLL)
	@echo 	libs directory               : $(LIB)
	@echo 	binary directory             : $(BIN)
	@echo 	source code directory        : $(SRC)
	@echo 	compiled object directory    : $(OBJ)
	@echo 	include directory            : $(INCLUDE)
	@echo -----------------------------------------------------