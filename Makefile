NAME = human
CC = c++
INCLUDE = ./include
LIB = ./lib -lglfw3 -lfreetype -lGL
CFLAGS = -Wall -Werror -Wextra
SRCS_DIR = ./src
OBJS_DIR = ./objs
SRCS = main.cpp init.cpp utils.cpp Matrix.cpp Shader.cpp Vector.cpp Camera.cpp Text.cpp Bone.cpp Model.cpp Animation.cpp Animator.cpp Quaternion.cpp Keyframe.cpp BoneTransform.cpp animations/walk.cpp
OBJS := $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

all: mkObjDir $(NAME)

mkObjDir:
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/animations

$(NAME): $(OBJS)
	@printf "\e[0;32mDone compiling objects!            \n\e[0m"
	@$(CC) $(CFLAGS) $(OBJS) ./src/glad.cpp -o $(NAME) -L $(LIB) -I$(INCLUDE)
	@echo "\e[0;32mProgram" $(NAME) "successfully created!\e[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE)
	@printf "\e[0;32mCompiling $@...        \e[0m\r"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\e[1;33mObjects files removed!\e[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\e[1;33mProgram file removed!\e[0m"
	@rm -rf gl.log

re: fclean all

.PHONY: all clean fclean re
