// crupier_unittest.cc: Michael Castillo Polo
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "crupier.h"
#include "gtest/gtest.h"

using namespace Casino;
using namespace std;

TEST(Crupier, ConstructorParametrosDefecto) {
  Crupier c("33XX", "435SFZ");
  
  EXPECT_EQ("33XX", c.getDNI());
  EXPECT_EQ("", c.getNombre());
  EXPECT_EQ("", c.getApellidos());
  EXPECT_EQ("", c.getDireccion());
  EXPECT_EQ("", c.getLocalidad());
  EXPECT_EQ("", c.getProvincia());
  EXPECT_EQ("", c.getPais());
  EXPECT_EQ(", ", c.getApellidosyNombre());
  EXPECT_EQ("435SFZ", c.getCodigo());
}
 
TEST(Crupier, ConstructorParametros) {
  Crupier c("44XX", "4567PRT", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  
  EXPECT_EQ("44XX", c.getDNI());
  EXPECT_EQ("Carlos", c.getNombre());
  EXPECT_EQ("Gutierrez", c.getApellidos());
  EXPECT_EQ("C/ Mesa 1", c.getDireccion());
  EXPECT_EQ("Aguilar", c.getLocalidad());
  EXPECT_EQ("Sevilla", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Gutierrez, Carlos", c.getApellidosyNombre());
  EXPECT_EQ("4567PRT", c.getCodigo());
}

TEST(Crupier, FuncionSet) {
  Crupier c("33XX", "435SFZ");
	c.setCodigo("4321TRP");
	EXPECT_EQ("4321TRP", c.getCodigo());
} 
