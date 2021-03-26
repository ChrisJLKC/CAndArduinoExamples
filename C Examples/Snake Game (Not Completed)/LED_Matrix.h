#ifndef _LED_MATRIX_H_
#define _LED_MATRIX_H_

void CLR_Matrix(void);
void init_LED_Matrix(void);
void LED_matrix_led_func(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16);
void line_and_push(int line_level_part_01, int line_level_part_02, int line_level_part_03);

#endif
