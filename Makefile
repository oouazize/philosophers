NAME	=	philo

SRCS	=	philo.c ft_atoi.c routine.c get_time.c put_eat.c put_sleep.c \
			my_usleep.c init.c create.c check.c \

GCC		=	gcc -Werror -Wextra -Wall

RM	=	rm -f

all:	$(NAME)

$(NAME): $(SRCS)
	@$(GCC) $(SRCS) -o philo
	@echo " "
	@echo "\033[1;31m██████  ██   ██ ██ ██       ██████  "
	@echo "\033[1;31m██   ██ ██   ██ ██ ██      ██    ██ "
	@echo "\033[1;31m██████  ███████ ██ ██      ██    ██ "
	@echo "\033[1;31m██      ██   ██ ██ ██      ██    ██ "
	@echo "\033[1;31m██      ██   ██ ██ ███████  ██████  "
	@echo " "
	@echo " "
	@echo "\033[1;36m▐▌ DONE ▐▌"
	@echo " "



                                    
                                    


clean:
	@$(RM)

fclean:	clean
	@$(RM) $(NAME)
	@echo " "
	@echo "\033[1;34m▐▌ DONE ▐▌"
	@echo " "

re:	fclean $(NAME)