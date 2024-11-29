# Compiler und Flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Verzeichnisse
SRCDIR = src
BUILDDIR = build
INCDIR = include

# Zielname
TARGET = ${BUILDDIR}/snake

# Quellcodedateien finden (auch main.c im src/ Verzeichnis)
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/controller/*.c) $(wildcard $(SRCDIR)/view/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

# Hauptregel
all: $(TARGET)

# Ziel erstellen
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Regel zum Erstellen von Objektdateien
$(BUILDDIR)/view/%.o: $(SRCDIR)/view/%.c
	@mkdir -p $(BUILDDIR)/view
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/controller/%.o: $(SRCDIR)/controller/%.c
	@mkdir -p $(BUILDDIR)/controller  # Erstelle das Verzeichnis
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -rf $(BUILDDIR)
