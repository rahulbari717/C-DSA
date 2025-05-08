# Makefile for ATS Resume Matcher

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable
TARGET = ats_matcher

# Source files
SRCS = main.c pdf_parser.c keyword_extractor.c matcher.c 
OBJS = $(SRCS:.c=.o)

# Default target
all: check_deps $(TARGET)

# Check for required dependencies
check_deps:
	@which pdftotext > /dev/null 2>&1 || \
	{ echo "Error: pdftotext not found. Please install poppler-utils:"; \
	  echo "  Debian/Ubuntu: sudo apt-get install poppler-utils"; \
	  echo "  Fedora/RHEL:   sudo dnf install poppler-utils"; \
	  echo "  macOS:         brew install poppler"; \
	  exit 1; }

# Build the final executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build complete: $(TARGET)"

# Individual object file rules
main.o: main.c pdf_parser.h keyword_extractor.h matcher.h 
	@$(CC) $(CFLAGS) -c main.c

pdf_parser.o: pdf_parser.c pdf_parser.h
	@$(CC) $(CFLAGS) -c pdf_parser.c

keyword_extractor.o: keyword_extractor.c keyword_extractor.h
	@$(CC) $(CFLAGS) -c keyword_extractor.c

matcher.o: matcher.c matcher.h
	@$(CC) $(CFLAGS) -c matcher.c


# Run the program
run: all
	@./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) *.o temp_resume_text.txt

# OS-specific dependency installation
install_deps_ubuntu:
	sudo apt-get update
	sudo apt-get install -y poppler-utils

install_deps_fedora:
	sudo dnf install -y poppler-utils

install_deps_macos:
	brew install poppler

# Help message
help:
	@echo "ATS Resume Matcher Makefile"
	@echo "---------------------------"
	@echo "Commands:"
	@echo "  make             - Build the project"
	@echo "  make run         - Run the executable"
	@echo "  make clean       - Clean object files and binary"
	@echo "  make install_deps_ubuntu  - Install dependencies on Ubuntu"
	@echo "  make install_deps_fedora  - Install dependencies on Fedora"
	@echo "  make install_deps_macos   - Install dependencies on macOS"
