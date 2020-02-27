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
    badkan::TestCase tc;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
      ariel::Tree emptytree;
      ariel::Tree threetree;  
      threetree.insert(5);
      threetree.insert(3);
      threetree.insert(7);

      // Tests by Odelia Hochman https://github.com/OdeliaHochman/BinaryTree-cpp/blob/master/TreeTest.cpp
      ariel::Tree seventree;
      ariel::Tree fourrighttree;  //diagonal line
      ariel::Tree fourlefttree;   //diagonal line
      ariel::Tree ninetree;
      seventree.insert(50);
      seventree.insert(30);
      seventree.insert(70);
      seventree.insert(20);
      seventree.insert(40);
      seventree.insert(60);
      seventree.insert(80);
      fourrighttree.insert(22);
      fourrighttree.insert(35);
      fourrighttree.insert(44);
      fourrighttree.insert(59);
      fourlefttree.insert(22);
      fourlefttree.insert(15);
      fourlefttree.insert(9);
      fourlefttree.insert(3);

      // Tests by Evgeny Vendrov https://github.com/EvgenyVendrov/matala2CPP/blob/master/TreeTest.cpp
      ariel::Tree testingRemove;
      int insertArr[20];
      for (int i = 0; i < 20; i++) {
          insertArr[i] = rand();
          testingRemove.insert(insertArr[i]);
      }
      
      tc
      .setname("Empty tree")
      .CHECK_EQUAL(emptytree.size() ,0)
      .CHECK_OK   (emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_OK   (emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size() ,0)

      // Tests by Omer Paz https://github.com/omerpaz1/BTS-Cpp-Ex2-/blob/master/TreeTest.cpp
      .setname("Three tree")
      .CHECK_EQUAL (threetree.size(), 3)
      .CHECK_EQUAL (threetree.root(), 5)
      .CHECK_EQUAL (threetree.parent(3), 5)
      .CHECK_EQUAL (threetree.parent(7), 5)
      .CHECK_EQUAL (threetree.left(5), 3)
      .CHECK_EQUAL (threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_OK (threetree.insert(2))
      .CHECK_THROWS(threetree.right(3))
      .CHECK_THROWS(threetree.right(2))
      .CHECK_OK (threetree.insert(4))
      .CHECK_EQUAL (threetree.contains(4), true)
      .CHECK_EQUAL (threetree.parent(2),3)
      .CHECK_EQUAL (threetree.parent(4),3)
      .CHECK_THROWS(threetree.left(2))
      .CHECK_OK (threetree.insert(6))
      .CHECK_OK (threetree.insert(9))
      .CHECK_THROWS(threetree.insert(9))
      .CHECK_OK(threetree.remove(5))   //remove root
      // .CHECK_EQUAL (threetree.left(6), 3)
      // .CHECK_EQUAL (threetree.right(6), 7)
      .CHECK_EQUAL (threetree.size(), 6)
      // .CHECK_EQUAL (threetree.root(), 6)
      .CHECK_THROWS (threetree.remove(10))
    
      // Tests by Odelia Hochman https://github.com/OdeliaHochman/BinaryTree-cpp/blob/master/TreeTest.cpp
      .setname("seventree")
      .CHECK_EQUAL (seventree.size(),7)
      .CHECK_EQUAL (seventree.root(),50)
      .CHECK_EQUAL (seventree.contains(60),true)
      .CHECK_OK    (seventree.remove(80)) //remove leaf
      .CHECK_THROWS(seventree.remove(80)) 
      .CHECK_THROWS (seventree.right(70))   
      .CHECK_EQUAL (seventree.parent(40),30)
      .CHECK_EQUAL (seventree.parent(60),70)
      .CHECK_THROWS(seventree.parent(50))
      .CHECK_THROWS (seventree.left(20)) 
      .CHECK_EQUAL (seventree.left(50),30)
      .CHECK_OK    (seventree.remove(50))  // remove root
      .CHECK_OK    (seventree.print())
      // .CHECK_EQUAL (seventree.root(),60)
      // .CHECK_EQUAL (seventree.parent(70),60)
      .CHECK_THROWS(seventree.insert(40))   
      .CHECK_EQUAL (seventree.size(),5)
      .CHECK_OK    (seventree.print())

      .setname("fourrighttree")
      .CHECK_EQUAL (fourrighttree.size(),4)
      .CHECK_EQUAL (fourrighttree.root(),22)
      .CHECK_EQUAL (fourrighttree.contains(44),true)
      .CHECK_EQUAL (fourrighttree.right(44),59)
      .CHECK_OK    (fourrighttree.remove(59))  // remove leaf
      .CHECK_THROWS (fourrighttree.right(44))
      .CHECK_THROWS(fourrighttree.remove(59))
      .CHECK_EQUAL (fourrighttree.parent(35),22)
      .CHECK_THROWS(fourrighttree.parent(22))
      .CHECK_THROWS(fourrighttree.remove(29))   
      .CHECK_THROWS (fourrighttree.left(35)) 
      .CHECK_OK     (fourrighttree.remove(22))  // remove root with one child
      .CHECK_OK(fourrighttree.print())
      .CHECK_EQUAL (fourrighttree.root(),35)
      .CHECK_EQUAL (fourrighttree.size(),2)
      .CHECK_OK    (fourrighttree.print())

      .setname("fourlefttree")
      .CHECK_EQUAL (fourlefttree.size(),4)
      .CHECK_EQUAL (fourlefttree.root(),22)
      .CHECK_EQUAL (fourlefttree.contains(3),true)
      .CHECK_EQUAL (fourlefttree.left(15),9)
      .CHECK_OK    (fourlefttree.remove(9)) // remove 1 child
      .CHECK_EQUAL (fourlefttree.left(15),3)
      .CHECK_THROWS(fourlefttree.remove(9)) 
      .CHECK_EQUAL (fourlefttree.parent(3),15)
      .CHECK_THROWS(fourlefttree.parent(22))
      .CHECK_THROWS(fourlefttree.remove(73))
      .CHECK_THROWS (fourlefttree.right(3)) 
      .CHECK_OK  (fourlefttree.print())
      .CHECK_OK(fourlefttree.remove(22))
      .CHECK_OK  (fourlefttree.print())
      .CHECK_EQUAL (fourlefttree.root(),15)
      .CHECK_OK  (fourlefttree.print())
      .CHECK_EQUAL (fourlefttree.size(),2)
      .CHECK_OK    (fourlefttree.print())

      .setname("ninetree")
      .CHECK_THROWS (ninetree.root())
      .CHECK_EQUAL (ninetree.size(),0)
      .CHECK_OK    (ninetree.insert(3))
      .CHECK_OK    (ninetree.insert(1))
      .CHECK_OK    (ninetree.insert(10))
      .CHECK_EQUAL (ninetree.contains(3),true)
      .CHECK_OK    (ninetree.insert(5))
      .CHECK_OK    (ninetree.insert(4))
      .CHECK_OK    (ninetree.insert(7))
      .CHECK_OK    (ninetree.insert(16))
      .CHECK_OK    (ninetree.insert(15))
      .CHECK_OK    (ninetree.insert(20))
      .CHECK_EQUAL (ninetree.root(),3)
      .CHECK_EQUAL (ninetree.parent(1),3)
      .CHECK_OK    (ninetree.remove(3))
      .CHECK_EQUAL (ninetree.contains(3),false)
      // .CHECK_EQUAL (ninetree.root(),4)  //<--------problem--change 1 to 4
      .CHECK_OK    (ninetree.print())////////////
      // .CHECK_EQUAL (ninetree.parent(1),4)  //<-------problem (86)
      // .CHECK_EQUAL (ninetree.parent(16),10)
      // .CHECK_EQUAL (ninetree.right(5),7)
      .CHECK_OK    (ninetree.remove(10))
      .CHECK_EQUAL (ninetree.size(),7)
      .CHECK_EQUAL (ninetree.contains(10),false)
      // .CHECK_EQUAL (ninetree.parent(16),15)
      // .CHECK_THROWS (ninetree.left(16)) 
      .CHECK_OK    (ninetree.remove(1))
      // .CHECK_EQUAL (ninetree.root(),4) //<--------problem (94)
      .CHECK_EQUAL (ninetree.contains(30),false)
      .CHECK_THROWS(ninetree.remove(3))
      // .CHECK_THROWS (ninetree.left(5)) //<---------problem----OK-(EXCEPTION) (97)
      .CHECK_OK    (ninetree.remove(4))
      // .CHECK_THROWS (ninetree.left(5))
      .CHECK_EQUAL (ninetree.size(),5)
      .CHECK_OK (ninetree.print()) 

      // Tests by Evgeny Vendrov https://github.com/EvgenyVendrov/matala2CPP/blob/master/TreeTest.cpp
      .setname("Random removal tests")
      .CHECK_EQUAL(testingRemove.size(), 20)
      .CHECK_EQUAL(testingRemove.contains(insertArr[0]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[1]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[2]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[3]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[4]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[5]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[6]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[7]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[8]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[9]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[10]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[11]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[12]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[13]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[14]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[15]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[16]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[17]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[18]), true)
      .CHECK_EQUAL(testingRemove.contains(insertArr[19]), true)
      /////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[7]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[7]), false)
      .CHECK_EQUAL(testingRemove.size(), 19)
      //////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[0]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[0]), false)
      .CHECK_EQUAL(testingRemove.size(), 18)
      /////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[16]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[16]), false)
      .CHECK_EQUAL(testingRemove.size(), 17)
      /////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[10]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[10]), false)
      .CHECK_EQUAL(testingRemove.size(), 16)
      //////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[3]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[3]), false)
      .CHECK_EQUAL(testingRemove.size(), 15)
      //////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[9]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[9]), false)
      .CHECK_EQUAL(testingRemove.size(), 14)
      //////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[19]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[19]), false)
      .CHECK_EQUAL(testingRemove.size(), 13)
      /////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[1]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[1]), false)
      .CHECK_EQUAL(testingRemove.size(), 12)
      //////////////////////////////////////////////////////
      //tyring to remove a node already removed - > to check if the method will throw exception
      .CHECK_THROWS(testingRemove.remove(insertArr[19]))
      /////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[17]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[17]), false)
      .CHECK_EQUAL(testingRemove.size(), 11)
      ////////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[5]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[5]), false)
      .CHECK_EQUAL(testingRemove.size(), 10)
      // ///////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[13]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[13]), false)
      .CHECK_EQUAL(testingRemove.size(), 9)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[15]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[15]), false)
      .CHECK_EQUAL(testingRemove.size(), 8)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[2]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[2]), false)
      .CHECK_EQUAL(testingRemove.size(), 7)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[18]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[18]), false)
      .CHECK_EQUAL(testingRemove.size(), 6)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[12]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[12]), false)
      .CHECK_EQUAL(testingRemove.size(), 5)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[11]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[11]), false)
      .CHECK_EQUAL(testingRemove.size(), 4)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[4]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[4]), false)
      .CHECK_EQUAL(testingRemove.size(), 3)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[14]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[14]), false)
      .CHECK_EQUAL(testingRemove.size(), 2)
      //////////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[8]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[8]), false)
      .CHECK_EQUAL(testingRemove.size(), 1)
      ///////////////////////////////////////////////
      .CHECK_OK(testingRemove.remove(insertArr[6]))
      .CHECK_EQUAL(testingRemove.contains(insertArr[6]), false)
      .CHECK_EQUAL(testingRemove.size(), 0)
      ///////////////////////////////////////////////

      .print();
    } else {
      tc.print_signal(signal);
      return 1;
    }
}
