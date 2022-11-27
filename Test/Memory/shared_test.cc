#include "zyAllocator.h"
#include <memory>
#include <iostream>
#include <vector>

using namespace zy;
using namespace std;

class Test
{
  public:
    Test()
    {
      cout << "Test::Test()" << endl;
    }

    Test(const Test&)
    {
      cout << "Test::Test(const Test&)" << endl;
    }

    Test& operator=(const Test&)
    {
      cout << "Test& operator=(const Test&)" << endl;
      return *this;
    }

    Test(Test&&)
    {
      cout << "Test(Test&&)" << endl;
    }

    ~Test()
    {
      cout << "~Test()" << endl;
    }
};

class TestAllocator : public Allocator
{
 private:
  const int ALLOC_HEAD_SIZE = sizeof(size_t);
  const int READ_ALLOC_SIZE_OFFSET = -(ALLOC_HEAD_SIZE);

 public:
  char* alloc_memory(std::size_t size)
  {
    size_t _alloc_size = size + ALLOC_HEAD_SIZE;
    void *ptr = ::malloc(_alloc_size);
    *static_cast<size_t*>(ptr) = _alloc_size;
    return static_cast<char*>(ptr) + ALLOC_HEAD_SIZE;
  }

  char* realloc_memory(void *ptr, size_t size)
  {
    if (ptr != nullptr)
    {
      ptr = static_cast<char*>(ptr) + READ_ALLOC_SIZE_OFFSET;
    }

    size_t _realloc_size = size + ALLOC_HEAD_SIZE;
    ptr = ::realloc(ptr, _realloc_size);
    *static_cast<size_t*>(ptr) = _realloc_size;
    return static_cast<char*>(ptr) + ALLOC_HEAD_SIZE;
  }

  void free_memory(void *ptr)
  {
    ::free(static_cast<char*>(ptr) + READ_ALLOC_SIZE_OFFSET);
  }

};

TestAllocator *g_allocator = new TestAllocator();



int main()
{
  shared_ptr<Test> p(g_new<Test,10>(g_allocator), [](Test *t){g_delete(t);});
  return 0;
}
