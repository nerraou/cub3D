all:
	make -C mandatory

clean:
	make -C mandatory clean

fclean:
	make -C mandatory fclean

re:
	make -C mandatory re

bonus:
	make -C bonus

bonus_clean:
	make -C bonus clean

bonus_fclean:
	make -C bonus fclean

bonus_re:
	make -C bonus re

.PHONY: bonus
