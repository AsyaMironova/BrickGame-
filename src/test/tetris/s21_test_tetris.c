#include "../../brick_game/tetris/tetris.h"
#include "s21_test_tetris.h"
#include <check.h>

// Тест функции init_tetris
START_TEST(test_init_tetris)
{
    TetrisGame game;
    init_tetris(&game);

    ck_assert_int_eq(game.state, MENU);
    ck_assert_int_eq(game.score, 0);
    ck_assert_int_eq(game.max_score, 0);
    ck_assert_int_eq(game.level, 1);
    ck_assert_int_eq(game.field[0][0], 0); // Поле должно быть очищено
}
END_TEST

// Тест функции rotate_piece
START_TEST(test_rotate_piece)
{
    TetrisGame game;
    init_tetris(&game);
    rotate_piece(&game);

    ck_assert_int_eq(game.current_piece.rotation, 1);  // Проверка на корректную ротацию
    rotate_piece(&game);  // Вторая ротация
    ck_assert_int_eq(game.current_piece.rotation, 2);
}
END_TEST

// Тест функции move_piece_left
START_TEST(test_move_piece_left)
{
    TetrisGame game;
    init_tetris(&game);
    int initial_x = game.current_piece.positions[0].x;

    move_piece_left(&game);
    ck_assert_int_lt(game.current_piece.positions[0].x, initial_x);  // Проверка на движение влево

    move_piece_left(&game);  // Повторное движение
    ck_assert_int_lt(game.current_piece.positions[0].x, initial_x - 1);  // Должно продолжить двигаться
}
END_TEST

// Тест функции move_piece_right
START_TEST(test_move_piece_right)
{
    TetrisGame game;
    init_tetris(&game);
    int initial_x = game.current_piece.positions[0].x;

    move_piece_right(&game);
    ck_assert_int_gt(game.current_piece.positions[0].x, initial_x);  // Проверка на движение вправо

    move_piece_right(&game);  // Повторное движение
    ck_assert_int_gt(game.current_piece.positions[0].x, initial_x + 1);  // Должно продолжить двигаться
}
END_TEST

// Тест функции move_piece_down
START_TEST(test_move_piece_down)
{
    TetrisGame game;
    init_tetris(&game);
    int initial_y = game.current_piece.positions[0].y;

    int result = move_piece_down(&game);
    ck_assert_int_eq(result, 1);  // Проверка на успешное движение вниз
    ck_assert_int_gt(game.current_piece.positions[0].y, initial_y);  // Координата Y должна увеличиться
}
END_TEST

// Тест функции clear_rows
START_TEST(test_clear_rows)
{
    TetrisGame game;
    init_tetris(&game);

    // Заполнение строки для теста
    for (int i = 1; i < FIELD_WIDTH - 1; i++) {
        game.field[FIELD_HEIGHT - 2][i] = 1;
    }

    int initial_score = game.score;
    clear_rows(&game);
    ck_assert_int_gt(game.score, initial_score);  // Очки должны увеличиться
}
END_TEST

// Тест функции lock_piece
START_TEST(test_lock_piece)
{
    TetrisGame game;
    init_tetris(&game);
    game.current_piece.positions[0] = (Point){5, 5};

    lock_piece(&game);
    ck_assert_int_eq(game.field[5][5], game.current_piece.type + 1);  // Проверка на закрепление фигуры на поле
}
END_TEST

// Тест функции spawn_new_piece
START_TEST(test_spawn_new_piece)
{
    TetrisGame game;
    init_tetris(&game);

    ck_assert(spawn_new_piece(&game));  // Функция должна успешно сгенерировать новую фигуру
    ck_assert_int_eq(game.state, MENU);  // Проверка на то, что игра не окончена
}
END_TEST

// Функция создания набора тестов
Suite *tetris_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Tetris");

    // Добавляем тесты в набор
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_init_tetris);
    tcase_add_test(tc_core, test_rotate_piece);
    tcase_add_test(tc_core, test_move_piece_left);
    tcase_add_test(tc_core, test_move_piece_right);
    tcase_add_test(tc_core, test_move_piece_down);
    tcase_add_test(tc_core, test_clear_rows);
    tcase_add_test(tc_core, test_lock_piece);
    tcase_add_test(tc_core, test_spawn_new_piece);

    suite_add_tcase(s, tc_core);

    return s;
}

// Основная функция для запуска всех тестов
int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = tetris_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
