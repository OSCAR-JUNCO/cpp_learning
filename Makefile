# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -std=c++2a -I./include

SRCDIR = src
BUILDDIR = build

SRCEXT = cpp
# Source files
SRCS := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# Object files
OBJS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.$(SRCEXT)=.o))
# Executable name
TARGET := myprogram

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -r $(BUILDDIR) $(TARGET)

.PHONY: clean