FILES = */*.cpp
EXEC_NAME = exec
LINKS = -lSDL2 -lSDL2_ttf

#This is the target that compiles our executable
all : $(FILES)
	g++ -std=c++17 $(INCLUDELIB) $(FILES) -w $(LINKS) -o $(EXEC_NAME)
