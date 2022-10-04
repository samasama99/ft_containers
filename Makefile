# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 10:46:58 by orahmoun          #+#    #+#              #
#    Updated: 2022/03/31 18:01:56 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	VARS	:

CXX 				=		c++

CXXFLAGS 		= 	-Wall -Wextra -Werror -std=c++98 -Ihelpers -Imap -Ivector -Istack -Ipair

HEADERS			=		map/ft_map.hpp \
								stack/ft_stack.hpp \
								pair/ft_pair.hpp \
								vector/ft_vector.hpp \
								helpers/enable_if.hpp \
								helpers/equal.hpp \
								helpers/helper.hpp \
								helpers/includes.hpp \
								helpers/is_integral.hpp \
								helpers/is_same.hpp \
								helpers/iterators_traits.hpp \
								helpers/lexicographical_compare.hpp \

all	: $(HEADERS)
	$(CXX) $(CXXFLAGS) tests/test_vector.cpp -o test_vector
	$(CXX) $(CXXFLAGS) tests/test_stack.cpp -o test_stack
	$(CXX) $(CXXFLAGS) tests/test_pair.cpp -o test_pair
	$(CXX) $(CXXFLAGS) tests/test_map.cpp -o test_map
	$(CXX) $(CXXFLAGS) tests/intra_main.cpp -DV -o intra_stl
	$(CXX) $(CXXFLAGS) tests/intra_main.cpp  -o intra_ft

clean :

fclean : 
	@rm -f test_map
	@rm -f test_stack
	@rm -f test_pair
	@rm -f test_vector
	@rm -f intra_stl
	@rm -f intra_ft

re	: fclean all
