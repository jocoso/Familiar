CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -MMD -MP
TARGET := familiar
SOURCES := \
	src/main.cpp \
	src/Familiar.cpp \
	src/Project.cpp \
	src/Task.cpp \
	src/User.cpp \
	src/ui/TerminalInterface.cpp

OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	./$(TARGET)
test:
	@echo "Tests not configure yet."
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)