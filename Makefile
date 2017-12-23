# Compile vars
TARGETEXE := ./bin/nomad.exe
CPPFLAGS := -std=c++11 -g -Wall
LIB := -lsfml-graphics -lsfml-window -lsfml-system
PHONY := clean

# Directories and files
INCDIR := ./includes/nomad
SRCDIR := ./src/nomad
OBJDIR := ./build
INC := $(shell find $(INCDIR) -name '*.hpp')
SRC := $(shell find $(SRCDIR) -name '*.cpp')
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(SRC:%.cpp=%.o)))

nomad: $(OBJ)
	$(CXX) $(CPPFLAGS) -iquote $(INCDIR) -o $(TARGETEXE) $^ $(LIB)
	@echo "Compiation Complete"

$(OBJ): $(SRC)
	@echo "[Linking] $(notdir $(@))"
	$(CXX) $(CPPFLAGS) -iquote $(INCDIR) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o