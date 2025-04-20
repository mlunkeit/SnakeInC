#
# This file is part of Snake.
#
# Copyright (C) 2025 Malte Lunkeit
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build
INCDIR = include

# Target name
TARGET = ${BUILDDIR}/snake

# Find source code files
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/controller/*.c) $(wildcard $(SRCDIR)/model/*.c) $(wildcard $(SRCDIR)/view/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

# Main rule
all: $(TARGET)

# Create target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/model/%.o: $(SRCDIR)/model/%.c
	@mkdir -p $(BUILDDIR)/model
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for creation of object files
$(BUILDDIR)/view/%.o: $(SRCDIR)/view/%.c
	@mkdir -p $(BUILDDIR)/view
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/controller/%.o: $(SRCDIR)/controller/%.c
	@mkdir -p $(BUILDDIR)/controller  # Create the directory
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BUILDDIR)
