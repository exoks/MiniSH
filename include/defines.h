/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:17:12 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 15:37:58 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEFINES_H
# define DEFINES_H

/*###############################################################
#		* STANDART FD  :										#
###############################################################*/
# define STD_IN		        0
# define STD_OUT	        1
# define STD_ERROR	        2

/*###############################################################
#		* EXIT STATUS  :										#
###############################################################*/
# define PERMISSION_DINED	126
# define COMMAND_NOT_FOUND	127

/*###############################################################
#		* Define NULL  :										#
###############################################################*/
#ifndef NULL
#  include <sys/_types.h>
#  define NULL  __DARWIN_NULL
# endif  /* NULL */

/*###############################################################
#		* RETURN  :												#
###############################################################*/
# define FAILURE			0
# define SUCCESS			1
# define TRUE		        1
# define FALSE		        0
# define ERROR  	        -1

/*###############################################################
#		* Token type :		    							 	#
###############################################################*/
# define OTHER				0
# define START				0
# define PIPE				1
# define REDIR_OUT			2
# define REDIR_IN			3
# define SINGLE_QUOTES		4
# define DOUBLE_QUOTES		5
# define STRING				6
# define HERE_DOC			7
# define REDIR_APPEND		8
# define SEMICOLON			9
# define AND				10
# define OR					11
# define OPEN_PARENTHESIS	12
# define CLOSE_PARENTHESIS	13
# define END				14
# define COMMAND			15
# define SUBSHELL			16
# define OPERATOR			17
# define REDIR				18

/*###############################################################
#		* special char :		    						 	#
###############################################################*/
# define SINGLE_QUOTE	    '\''  
# define DOUBLE_QUOTE	    '"'
# define C_SPACE	        '\5'
# define S_SPACE	        "\5"
# define C_STAR	            '\2'
# define S_STAR	            "\2"

/*###############################################################
#		* Area :		    						 			#
###############################################################*/
# define MAIN_AREA			0
# define INTERPRETER		1
# define PARSER_AREA		2
# define LEXER_AREA			3

#endif /* DEFINES_H */
