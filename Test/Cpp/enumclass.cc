enum class  Test {A,B};


int main(int argc, char **argv)
{
  Test test = Test::A;
  switch (test) {
  case Test::A:
  {
    break;
  }
  default:
  {
    break;
  }
  }
  return 0;
}
