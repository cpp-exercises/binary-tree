/**
 * Grading file for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include "badkan.hpp"
#include "Tree.hpp"
using std::cout, std::endl;

int main() {
    ariel::Tree emptytree;
    ariel::Tree threetree;  
    threetree.insert(5);
    threetree.insert(3);
    threetree.insert(7);
    
    badkan::TestCase tc;
    if (setjmp(badkan::longjmp_buffer) == 0) {
      tc
      .setname("Empty tree")
      .CHECK_EQUAL(emptytree.size() ,0)
      .CHECK_OK   (emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_OK   (emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size() ,0)
      
      .setname("Three tree")
      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .print();
    } else {
      tc.print_signal(1);
    }
}
