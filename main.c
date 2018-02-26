#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#include <math.h>
int main() {

  screen s;
  color c;
  c.red = 255;
  c.green = 255;
  c.blue = 255;
 
  struct matrix *edges;
  edges = new_matrix(4, 4);
  printf("new 4x4 matrix\n");
  print_matrix(edges);
  struct matrix * iden;
  iden = new_matrix(4,4);
  printf("Making 4x4 identity  matrix\n");
  ident(iden);
  print_matrix(iden);
  printf("\nAdding edges\n");
  add_edge(edges, 100, 100, 0, 100, 300, 0);
  add_edge(edges, 100, 300, 0, 300, 300, 0);
  add_edge(edges, 300, 300, 0, 300, 100, 0);
  add_edge(edges, 300, 100, 0, 100, 100, 0);
  print_matrix(edges);  
  struct matrix *m1 =  new_matrix(4, 4);
  struct matrix *m2 = new_matrix(4, 4);
  add_edge(m1,1,0,0,1,0,0);
  add_edge(m1, 3,2,3,2,3,4);
  add_edge(m2, 1,2,3,4,5,6);
  add_edge(m2, 6,5,4,3,2,1);
  printf("\nTesting matrix_mult m1*m2=m2\n");
  print_matrix(m1);
  printf("\n");
  print_matrix(m2);
  printf("\nmultiplied\n");
  matrix_mult(m1,m2);
  print_matrix(m2);
  clear_screen(s);
  draw_lines(edges, s, c);
  save_extension(s, "matrix.png");
  display(s);
  
  free_matrix(edges);
  free_matrix(iden);
  free_matrix(m1);
  free_matrix(m2);
}
