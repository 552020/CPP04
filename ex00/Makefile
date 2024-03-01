# Compiler and Flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

# Target executable name
TARGET = animal

# Source and Object Files
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

# Create an obj directory if it doesn't exist
OBJDIR = obj

# Generate object files from source files in the obj directory
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# Define dependency files
DEPS = $(OBJS:.o=.d) 

# Build Rules

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile source files to object files in the obj directory
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS)  -c $< -o $@

# Include the dependency files
-include $(DEPS)

clean:
	rm -f $(OBJS) $(TARGET) 

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(TARGET) 

re: fclean all

.PHONY: all  clean fclean re
