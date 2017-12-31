# Compile vars
TARGETEXE := ./bin/nomad.exe
CPPFLAGS := -std=c++17 -g -Wall
LIB := -lsfml-graphics -lsfml-window -lsfml-system
# -shared lib/libthor-d.so
PHONY := clean

# Directories and files
INCDIR := ./includes/nomad
SRCDIR := ./src/nomad
OBJDIR := ./build
INC := $(shell find $(INCDIR) -name '*.hpp')
SRC := $(shell find $(SRCDIR) -name '*.cpp')
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(SRC:%.cpp=%.o)))

nomad: $(OBJ)
	@echo "[Compiling Executable] $(TARGETEXE)"
	$(CXX) $(CPPFLAGS) -iquote $(INCDIR) -o $(TARGETEXE) $^ $(LIB)
	@echo "Compilation Complete"

$(OBJ):
	@echo "[Linking] $(notdir $(@))"
	$(CXX) $(CPPFLAGS) -iquote $(INCDIR) -c -o $@ $<

# Make rule bindings between OBJ and SRC
$(foreach x, $(join $(addsuffix :, $(OBJ)), $(SRC)), $(eval $x))

clean:
	rm -f $(OBJDIR)/*.o