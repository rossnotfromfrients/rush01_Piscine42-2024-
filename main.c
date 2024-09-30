/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant dinursul rodolhop vlucarel <>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:26:37 by mpierant dinu     #+#    #+#             */
/*   Updated: 2024/09/29 21:26:40 by mpierant dinu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h" // Подключение заголовочного файла с объявлениями функций и структур 
{

int	main(int argc, char **argv) // Главная функция, принимающая количество аргументов и массив строк // Main function taking the number of arguments and an array of strings
{
	t_clues	clues; // Объявление переменной типа t_clues для хранения подсказок // Declare a variable of type t_clues to hold the clues

	if (argc == 2) // Проверка, что передан ровно один аргумент (строка с подсказками) //  Check if exactly one argument (the clue string) is provided
	{
		if (put_val(argv[1], &clues) == 1) // Вызов функции для обработки строки подсказок // 
			return (1); // Если произошла ошибка, вернуть 1 // 
		initialize_grid_and_solve(clues); // Инициализация сетки и запуск решения // 
	}
	return (0); // Успешное завершение программы // 
}
