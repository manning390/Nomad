TARGETC := $(wildcard ./src/Source/*.cpp)
TARGETO := $(TARGETC:./src/Source/%.cpp=./src/Objects/%.o)
TARGETD := $(TARGETO:./src/Objects/%.o=./src/deps/%.d)
HPPS := $(wildcard ./src/Headers/*.hpp)
TARGETEXE := ./nomad.exe
CPPFLAGS := -std=c++11 -g
LIB := -lsfml-graphics -lsfml-window -lsfml-system
INC := -iquote src/Headers


all: compile

compile: $(TARGETO)
	$(CXX) $(CPPFLAGS) -o $(TARGETEXE) $^ $(LIB)
	@echo "Compliation Complete"

#-include $(TARGETD)

./src/Objects/%.o:./src/Source/%.cpp $(HPPS)
	$(CXX) $(CPPFLAGS) $(INC) -c -o $@  $<

#./src/deps/%.d:./src/Objects/%.o $(HPPS)
#	$(CXX) $(CPPFLAGS) $< -MM -MT $(@:./src/deps/%.d=./src/Objects/%.o) >$@

clean:
	rm $(TARGETO) $(TARGETD) $(TARGETEXE)
	@echo "Cleaning Complete"