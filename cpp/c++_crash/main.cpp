#include <cstdio>


struct College {
  char name[256];
};

void print_names(College* colleges, size_t n_colleges) {
  for (size_t i = 0; i < n_colleges; i++) { 
    printf("%s College\n", colleges[i].name);
  }
}


void copy_test()
{
  //constructor invoked
  College c;
  c.name = "test";
  printf("c: %p ", c);

  //copy constructor invoked
  College ccopy = c;
  printf("c: %p ", c);



}



void references_test()
{
    int i = 5;
    int& ref_i = i;
    ref_i = 6;
    printf("rf test i: %d\n", i);

    int j = 15;
    ref_i = j;
    printf("rf test: %d\n", ref_i);
    //j = 16;
    printf("rf test: %d\n", ref_i);
    printf("rf test i: %d\n", i);
    printf("rf test j: %d\n", j);
}

int main() {
    copy_test();
    

    references_test();

    return 0;

  College oxford[] = { "Magdalen", "Nuffield", "Kellogg" };
  print_names(oxford, sizeof(oxford) / sizeof(College));

    printf(" sizeof: %d\n", sizeof(College));
    printf(" sizeof oxford: %d\n", sizeof(oxford));

    int array[3] = {1,2,3};
    printf(" sizeof array: %d\n", sizeof(array));
    printf(" sizeof array: %d\n", sizeof(int));

    printf(" int: %d\n", array[4]);
    array[4] = 9;
    printf(" int: %d\n", array[4]);


}