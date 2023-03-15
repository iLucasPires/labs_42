ENCODER = encoder
DECODER = decoder

OBJECTS_DIR = ./objects
SOURCE_DIR = ./sources
INCLUDE_DIR = ./includes

SOURCES =	node_huffman.c frequency_huffman.c \
			tree_huffman.c dictionary_huffman.c read_file.c\
			aux_huffman.c memory.c encoder.c decoder.c \

ENCODER_SOURCES = sources/main_encoder.c
DECODER_SOURCES = sources/main_decoder.c

SUB_DIRS = $(shell find $(SOURCE_DIR) -type d)
VPATH = $(OBJECTS_DIR) $(SOURCE_DIR) $(SUB_DIRS)
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g3 -I$(INCLUDE_PATH)

all: $(ENCODER) $(DECODER)

$(ENCODER): $(OBJECTS)
	cc $(CFLAGS) $(INCLUDE_DIR) $(ENCODER_SOURCES) $(OBJECTS) -o $(ENCODER)

$(DECODER): $(OBJECTS)
	cc $(CFLAGS) $(INCLUDE_DIR) $(DECODER_SOURCES) $(OBJECTS) -o $(DECODER)

$(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(OBJECTS_DIR)
	cc $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(ENCODER)
	rm -f $(DECODER)

re: fclean all

.PHONY: all clean fclean re