#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

struct Matrix {
    int stanga=0,sus=0,width=0,height=0,latura=0;
    int n=0,m=0;
    int **mat;
};

void initMatrix(Matrix &m);
bool isInMatrix(Matrix m, int x, int y);
void int_gprint_check(char text[], char temp[], int temp_size, int lower_limit, int upper_limit);
void draw_matrix_in_window(Matrix &m, int WINDOW_WIDTH, int WINDOW_HEIGHT);
void redraw_red_cell(int i, int j, Matrix m);
void gwindow_read_int(int &value, int string_size, int max_string_size, int max_int_size, int min_int_size, int x, int y);
void gwindow_matrix_cell_read(Matrix &m, int &last_i, int &last_j, int &current_i, int &current_j, int mx, int my);
void Design_Matrix();
void Animation_Redraw_Cell(int COLOR, int i, int j, Matrix m);

#endif // MATRIXFUNCTIONS_H
