CC := gcc
CFLAGS := -std=c99 -Wall -Werror
UFLAGS := -lcheck -lpthread -lrt

CFILES_DIR := ./src
CFILES := $(wildcard $(CFILES_DIR)/*.c)

INC_DIR := ./inc
INCLUDES := $(wildcard $(INC_DIR)/*.h)

OBJ_DIR := ./out
OBJECTS := $(CFILES:$(CFILES_DIR)/%.c=$(OBJ_DIR)/%.o)

UNIT_DIR := ./unit_tests
UNITS := $(wildcard $(UNIT_DIR)/*.c)

UNIT_OBJECTS := $(UNITS:$(UNIT_DIR)/%.c=$(OBJ_DIR)/%.o)
UNIT_OBJECTS += $(filter-out $(OBJ_DIR)/main.o,$(OBJECTS))

APP = app.exe
UNIT_TEST = unit_tests.exe

.PHONY : unit clean run

$(APP): $(OBJECTS)
	$(CC) $^ -o $@

$(UNIT_TEST): $(UNIT_OBJECTS)
	$(CC) $(UNIT_OBJECTS) -o $@ $(UFLAGS)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(CFILES_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDES) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(UFLAGS) -c $< -o $@

run: $(APP)
	./$^

unit: $(UNIT_TEST)
	./$^

clean:
	$(RM) $(OBJ_DIR)/*.o *.exe
 